# Project layout for "PluginSystem"

Below is the structure for "PluginSystem" project.

```plaintext
PluginSystem/
├── CMakeLists.txt
├── include/
│   ├── IPlugin.h
│   ├── PluginAPI.h
│   └── PluginManager.h
├── src/
│   ├── PluginManager.cpp
│   └── main.cpp
├── plugins/
│   ├── CMakeLists.txt
│   ├── EchoPlugin/
│   │   ├── CMakeLists.txt
│   │   └── EchoPlugin.cpp
│   └── MathPlugin/
│       ├── CMakeLists.txt
│       └── MathPlugin.cpp
└── tests/
    ├── CMakeLists.txt
    └── test_loading.cpp
```

## Build & run

To build the project, navigate to the root directory (`PluginSystem`) and run:

```bash
mkdir -p build && cd build
cmake ..
cmake --build . -- -j$(nproc)

# build should produce:
# - plugin_cli (executable)
# - plugins/echo.so and plugins/math.so under build/plugins/.../ (CMake places them in plugin build dir)
# To run the CLI and have it look for plugins in the local tree, either:
# 1) copy the produced .so files into a ./plugins directory next to plugin_cli, or
# 2) run the executable with the path to the built plugins folder.

# Example if you copy .so/.dylib files into PluginSystem/plugins:
./plugin_cli plugins
```
