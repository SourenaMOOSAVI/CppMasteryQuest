#include <iostream>
#include <filesystem>
#include <string>
#include "IPluginManager.h"

int main(int argc, char** argv) {
    std::string pluginsDir = "plugins";
    if (argc > 1) pluginsDir = argv[1];

    PluginManager pm;
    std::cout << "Plugin CLI — scanning directory: " << pluginsDir << "\n";

    try {
        for (const auto& ent : std::filesystem::directory_iterator(pluginsDir)) {
            if (ent.is_regular_file()) {
                auto ext = ent.path().extension().string();
                if (ext == ".so" || ext == ".dll" || ext == ".dylib") {
                    pm.loadPlugin(ent.path().string());
                }
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Error scanning plugins: " << e.what() << "\n";
    }

    auto names = pm.listPlugins();
    if (names.empty()) {
        std::cout << "No plugins loaded.\n";
        return 0;
    }

    std::cout << "Available plugins:\n";
    for (auto& n : names) std::cout << " - " << n << "\n";

    std::cout << "\nEnter plugin name to run: ";
    std::string sel;
    std::getline(std::cin, sel);

    IPlugin* plugin = pm.get(sel);
    if (!plugin) {
        std::cout << "Plugin not found.\n";
        return 0;
    }

    std::cout << "Input for plugin '" << sel << "': ";
    std::string input;
    std::getline(std::cin, input);

    std::string output = plugin->execute(input);
    std::cout << "Output: " << output << "\n";

    // manager destructor unloads plugins
    return 0;
}
