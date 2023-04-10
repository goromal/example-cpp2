#include <boost/program_options.hpp>
#include <iostream>

#include "example/HelloWorld.h"

int main(int argc, char* argv[])
{
    bool exclaim = false;

    boost::program_options::options_description args_desc("Options");
    // clang-format off
    args_desc.add_options()
        ("help,h", "print usage")
        ("name,n", boost::program_options::value<std::string>()->required(), "name to say hello to")
        ("exclaim,e", boost::program_options::bool_switch(&exclaim), "whether to exclaim");
    // clang-format on

    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, args_desc), vm);
    boost::program_options::notify(vm);

    if (vm.count("help"))
    {
        std::cout << args_desc << std::endl;
        return 0;
    }

    std::cout << getHelloWorld(vm["name"].as<std::string>(), vm["exclaim"].as<bool>()) << std::endl;
    return 0;
}
