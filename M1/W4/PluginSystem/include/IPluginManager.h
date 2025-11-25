#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include "IPluginAPI.h"

// PluginManager loads shared libraries and exposes plugin instances.
class PluginManager {
public:
    PluginManager() = default;
    ~PluginManager();

    // Load a shared library file (absolute or relative path). Returns true on success.
    bool loadPlugin(const std::string& path);

    // Unload all plugins.
    void unloadAll();

    // List loaded plugin names.
    std::vector<std::string> listPlugins() const;

    // Get plugin instance by name, or nullptr.
    IPlugin* get(const std::string& name) const;

private:
    struct PluginRecord {
        void* handle = nullptr;           // dlopen handle (or Windows HMODULE)
        IPlugin* instance = nullptr;      // plugin instance returned by create
        DestroyPluginFn destroy = nullptr;// function to destroy instance
    };

    std::unordered_map<std::string, PluginRecord> plugins_;
};
