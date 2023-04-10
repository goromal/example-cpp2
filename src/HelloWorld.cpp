#include "example/HelloWorld.h"

std::string getHelloWorld(const std::string& name, const bool& exclaim)
{
    return std::string("Hello, ") + name + std::string((exclaim) ? "!" : ".");
}
