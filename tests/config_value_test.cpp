#include "config/config_value.h"

#include <cassert>
#include <iostream>
#include <string>
#include <stdexcept>

int main()
{
    securenos::ConfigValue hostname("SecureNOS");
    assert(hostname.type() == securenos::ConfigValueType::STRING);
    assert(hostname.asString() == "SecureNOS");
    try
    {
      hostname.asInteger();
      assert(false);
    }
    catch (const std::bad_variant_access&)
    {
    } 
   
    securenos::ConfigValue mtu(1500);
    assert(mtu.type() == securenos::ConfigValueType::INTEGER);
    assert(mtu.asInteger() == 1500);

    securenos::ConfigValue sshEnabled(true);
    assert(sshEnabled.type() == securenos::ConfigValueType::BOOLEAN);
    assert(sshEnabled.asBoolean());

    std::cout << "ConfigValue tests passed." << std::endl;

    return 0;
}
