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
    
    securenos::ConfigValue mtu(1500);
    
    assert(config.set("mtu", mtu));
    
    securenos::ConfigValue mtuValue(0);
    
    assert(config.get("mtu", mtuValue));
    assert(mtuValue.type() == securenos::ConfigValueType::INTEGER);
    assert(mtuValue.asInteger() == 1500);
    
    assert(config.set("mtu", securenos::ConfigValue(9000)));

    assert(config.get("mtu", mtuValue));
    assert(mtuValue.type() == securenos::ConfigValueType::INTEGER);
    assert(mtuValue.asInteger() == 9000);


    securenos::ConfigValue sshEnabled(true);
    
    assert(config.set("ssh_enabled", sshEnabled));
    
    securenos::ConfigValue sshValue(false);
    
    assert(config.get("ssh_enabled", sshValue));
    assert(sshValue.type() == securenos::ConfigValueType::BOOLEAN);
    assert(sshValue.asBoolean());


    assert(config.set("hostname", securenos::ConfigValue("SecureNOS")));
    assert(!config.set("", securenos::ConfigValue("Invalid")));

    assert(config.get("hostname", hostname));
    assert(hostname.asString() == "SecureNOS");

    assert(config.remove("hostname"));
    assert(!config.remove("hostname"));

    assert(!config.get("hostname", hostname));

    std::cout << "ConfigManager tests passed." << std::endl;

    return 0;
}
