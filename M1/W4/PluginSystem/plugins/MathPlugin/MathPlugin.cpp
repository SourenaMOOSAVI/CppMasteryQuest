#include "IPlugin.h"
#include "IPluginAPI.h"
#include <string>
#include <sstream>

class MathPlugin : public IPlugin {
public:
    std::string name() const override { return "math"; }
    std::string description() const override { return "Adds two integers provided as 'a b'"; }

    std::string execute(const std::string& input) override {
        std::istringstream iss(input);
        int a = 0, b = 0;
        if (!(iss >> a >> b)) return "error: provide two integers, e.g. '3 4'";
        return std::to_string(a + b);
    }
};

extern "C" IPlugin* create_plugin() {
    return new MathPlugin();
}

extern "C" void destroy_plugin(IPlugin* p) {
    delete p;
}
