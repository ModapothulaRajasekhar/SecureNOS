#include "config/config_manager.h"

#include <cassert>
#include <iostream>
#include <string>


int main()
{
    securenos::ConfigManager config;

    assert(config.initialize());
    assert(config.configFilePath() == "config/secure_nos.conf");
    
    assert(config.load());

    securenos::ConfigValue loadedHostname("");
    assert(config.get("hostname", loadedHostname));
    assert(loadedHostname.type() == securenos::ConfigValueType::STRING);
    assert(loadedHostname.asString() == "SecureNOS");

    securenos::ConfigValue loadedMtu(0);
    assert(config.get("mtu", loadedMtu));
    assert(loadedMtu.type() == securenos::ConfigValueType::INTEGER);
    assert(loadedMtu.asInteger() == 1500);

    securenos::ConfigValue loadedSsh(false);
    assert(config.get("ssh_enabled", loadedSsh));
    assert(loadedSsh.type() == securenos::ConfigValueType::BOOLEAN);
    assert(loadedSsh.asBoolean());

    std::cout << "Load test passed." << std::endl;
 
    assert(config.set("hostname", "SecureNOS"));
    assert(config.set("mtu", 1500));
    assert(config.set("ssh_enabled", true));

    assert(config.save());
    
    assert(config.set("hostname", "Changed"));
    assert(config.set("mtu", 9000));
    assert(config.set("ssh_enabled", false));

    assert(config.load());

    securenos::ConfigValue roundTripHostname("");
    assert(config.get("hostname", roundTripHostname));
    assert(roundTripHostname.type() == securenos::ConfigValueType::STRING);
    assert(roundTripHostname.asString() == "SecureNOS");

    securenos::ConfigValue roundTripMtu(0);
    assert(config.get("mtu", roundTripMtu));
    assert(roundTripMtu.type() == securenos::ConfigValueType::INTEGER);
    assert(roundTripMtu.asInteger() == 1500);

    securenos::ConfigValue roundTripSsh(false);
    assert(config.get("ssh_enabled", roundTripSsh));
    assert(roundTripSsh.type() == securenos::ConfigValueType::BOOLEAN);
    assert(roundTripSsh.asBoolean());

    std::cout << "Save/load round-trip test passed." << std::endl;


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
