#pragma once
#include "IPlugin.h"

extern "C" {

// Factory exported by each plugin
using CreatePluginFn = IPlugin* (*)();

// Destroy function exported by each plugin
using DestroyPluginFn = void (*)(IPlugin*);
}
