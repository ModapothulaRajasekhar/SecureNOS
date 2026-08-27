#ifndef SECURENOS_CONFIG_MANAGER_H
#define SECURENOS_CONFIG_MANAGER_H

#include <string>
#include <unordered_map>
#include "config/config_value.h"

namespace securenos
{

class ConfigManager
{
public:
    ConfigManager() = default;
    ~ConfigManager() = default;

    bool initialize();

    bool set(const std::string& key, const ConfigValue& value);

    bool get(const std::string& key, ConfigValue& value) const;

    bool remove(const std::string& key);

private:
    std::unordered_map<std::string, ConfigValue> configuration_;
};

} // namespace securenos

#endif // SECURENOS_CONFIG_MANAGER_H
