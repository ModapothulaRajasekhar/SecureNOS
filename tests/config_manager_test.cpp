#include "config/config_manager.h"

#include <cassert>
#include <iostream>
#include <string>


int main()
{
    securenos::ConfigManager config;

    assert(config.initialize());

    securenos::ConfigValue hostname("");

    assert(config.get("hostname", hostname));
    assert(hostname.type() == securenos::ConfigValueType::STRING);
    assert(hostname.asString() == "SecureNOS");
   
    std::cout << "Hostname test passed." << std::endl;

    securenos::ConfigValue mtuValue(0);

    assert(config.set("mtu", 1500));

    assert(config.get("mtu", mtuValue));
    assert(mtuValue.type() == securenos::ConfigValueType::INTEGER);
    assert(mtuValue.asInteger() == 1500);

    std::cout << "MTU test passed." << std::endl; 
   

    securenos::ConfigValue sshValue(false);

    assert(config.set("ssh_enabled", true));

    assert(config.get("ssh_enabled", sshValue));
    assert(sshValue.type() == securenos::ConfigValueType::BOOLEAN);
    assert(sshValue.asBoolean());

    std::cout << "SSH test passed." << std::endl;
    
    assert(config.set("mtu", 9000));

    assert(config.get("mtu", mtuValue));
    assert(mtuValue.type() == securenos::ConfigValueType::INTEGER);
    assert(mtuValue.asInteger() == 9000);

    assert(config.set("mtu", true));

    assert(config.get("mtu", mtuValue));
    assert(mtuValue.type() == securenos::ConfigValueType::BOOLEAN);
    assert(mtuValue.asBoolean());

    assert(config.set("hostname", "SecureNOS"));

    assert(config.get("hostname", hostname));
    assert(hostname.type() == securenos::ConfigValueType::STRING);
    assert(hostname.asString() == "SecureNOS");

    assert(!config.set("", "Invalid"));

    assert(config.remove("hostname"));
    assert(!config.remove("hostname"));

    assert(!config.get("hostname", hostname));
    
    std::cout << "ConfigManager tests passed." << std::endl; 

    return 0;
}
