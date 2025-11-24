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
