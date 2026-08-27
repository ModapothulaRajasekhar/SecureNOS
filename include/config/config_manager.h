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
    
    bool set(const std::string& key, const std::string& value);
    bool set(const std::string& key, const char* value);
    bool set(const std::string& key, int value);
    bool set(const std::string& key, bool value);
    
    

    bool get(const std::string& key, ConfigValue& value) const;

    bool remove(const std::string& key);
    const std::string& configFilePath() const;
    bool save() const;
    bool load();

private:
    std::unordered_map<std::string, ConfigValue> configuration_;
    std::string configFilePath_;
};

} // namespace securenos

#endif // SECURENOS_CONFIG_MANAGER_H
