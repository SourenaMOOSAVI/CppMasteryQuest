#include "IPluginManager.h"
#include <dlfcn.h>
#include <iostream>

PluginManager::~PluginManager() {
    unloadAll();
}

bool PluginManager::loadPlugin(const std::string& path) {
    // open shared object
    void* handle = dlopen(path.c_str(), RTLD_NOW);
    if (!handle) {
        std::cerr << "dlopen failed: " << dlerror() << " for " << path << "\n";
        return false;
    }

    // clear errors
    dlerror();

    // resolve factory and destructor
    auto create = reinterpret_cast<CreatePluginFn>(dlsym(handle, "create_plugin"));
    auto destroy = reinterpret_cast<DestroyPluginFn>(dlsym(handle, "destroy_plugin"));

    const char* dlsym_err = dlerror();
    if (dlsym_err) {
        std::cerr << "dlsym error: " << dlsym_err << " for " << path << "\n";
        dlclose(handle);
        return false;
    }

    if (!create || !destroy) {
        std::cerr << "Plugin " << path << " missing create_plugin/destroy_plugin\n";
        dlclose(handle);
        return false;
    }

    IPlugin* instance = nullptr;
    try {
        instance = create();
    } catch (const std::exception& e) {
        std::cerr << "create_plugin threw: " << e.what() << "\n";
        dlclose(handle);
        return false;
    } catch (...) {
        std::cerr << "create_plugin threw unknown exception\n";
        dlclose(handle);
        return false;
    }

    if (!instance) {
        std::cerr << "create_plugin returned nullptr for " << path << "\n";
        dlclose(handle);
        return false;
    }

    std::string name = instance->name();
    if (plugins_.count(name)) {
        std::cerr << "Plugin with name '" << name << "' already loaded\n";
        // clean up
        destroy(instance);
        dlclose(handle);
        return false;
    }

    PluginRecord rec;
    rec.handle = handle;
    rec.instance = instance;
    rec.destroy = destroy;
    plugins_.emplace(name, std::move(rec));

    std::cout << "Loaded plugin '" << name << "' from " << path << "\n";
    return true;
}

void PluginManager::unloadAll() {
    for (auto& [name, rec] : plugins_) {
        if (rec.instance && rec.destroy) {
            rec.destroy(rec.instance);
            rec.instance = nullptr;
        }
        if (rec.handle) {
            dlclose(rec.handle);
            rec.handle = nullptr;
        }
    }
    plugins_.clear();
}

std::vector<std::string> PluginManager::listPlugins() const {
    std::vector<std::string> out;
    out.reserve(plugins_.size());
    for (const auto& kv : plugins_) out.push_back(kv.first);
    return out;
}

IPlugin* PluginManager::get(const std::string& name) const {
    auto it = plugins_.find(name);
    return (it != plugins_.end()) ? it->second.instance : nullptr;
}
