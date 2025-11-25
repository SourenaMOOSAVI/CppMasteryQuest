#include "IPlugin.h"
#include "IPluginAPI.h"
#include <string>

class EchoPlugin : public IPlugin {
public:
    std::string name() const override { return "echo"; }
    std::string description() const override { return "Echoes the input string"; }
    std::string execute(const std::string& input) override {
        return "Echo: " + input;
    }
};

extern "C" IPlugin* create_plugin() {
    return new EchoPlugin();
}

extern "C" void destroy_plugin(IPlugin* p) {
    delete p;
}
