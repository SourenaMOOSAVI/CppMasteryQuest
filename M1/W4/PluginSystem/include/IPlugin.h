#pragma once
#include <string>

class IPlugin {
public:
    virtual ~IPlugin() = default;
    virtual std::string name() const = 0;
    virtual std::string description() const = 0;
    // Execute plugin behaviour on input string, return result as string
    virtual std::string execute(const std::string& input) = 0;
};
