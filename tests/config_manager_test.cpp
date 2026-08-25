#include "config/config_manager.h"

#include <cassert>
#include <iostream>
#include <string>

int main()
{
    securenos::ConfigManager config;

    assert(config.initialize());
    
    std::string hostname;
   
    assert(config.get("hostname", hostname));
    assert(hostname == "SecureNOS");

    assert(config.set("hostname", "SecureNOS"));
    assert(!config.set("", "Invalid"));


    assert(config.get("hostname", hostname));
    assert(hostname == "SecureNOS");

    assert(config.remove("hostname"));
    assert(!config.remove("hostname"));

    assert(!config.get("hostname", hostname));

    std::cout << "ConfigManager tests passed." << std::endl;

    return 0;
}
