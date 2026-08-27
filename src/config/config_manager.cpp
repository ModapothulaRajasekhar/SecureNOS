#include "config/config_manager.h"

#include <iostream>

namespace securenos
{

bool ConfigManager::initialize()
{
    std::cout << "[Config] Initializing configuration manager..." << std::endl;

    configuration_.clear();
    configuration_.insert_or_assign("hostname", ConfigValue("SecureNOS"));

    return true;
}

bool ConfigManager::set(const std::string& key, const ConfigValue& value)
{
    if (key.empty())
    {
        return false;
    }

    configuration_.insert_or_assign(key, value);

    return true;
}

bool ConfigManager::get(const std::string& key, ConfigValue& value) const
{
    auto it = configuration_.find(key);

    if (it == configuration_.end())
    {
        return false;
    }

    value = it->second;

    return true;
}

bool ConfigManager::remove(const std::string& key)
{
    auto it = configuration_.find(key);

    if (it == configuration_.end())
    {
        return false;
    }

    configuration_.erase(it);

    return true;
}

} // namespace securenos
