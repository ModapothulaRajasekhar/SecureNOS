#include "config/config_manager.h"

#include <fstream>
#include <iostream>
#include <string>

namespace securenos
{

bool ConfigManager::initialize()
{
    std::cout << "[Config] Initializing configuration manager..." << std::endl;
    
    configFilePath_ = "config/secure_nos.conf";
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

bool ConfigManager::set(const std::string& key, const std::string& value)
{
    return set(key, ConfigValue(value));
}

bool ConfigManager::set(const std::string& key, const char* value)
{
    return set(key, ConfigValue(value));
}

bool ConfigManager::set(const std::string& key, int value)
{
    return set(key, ConfigValue(value));
}

bool ConfigManager::set(const std::string& key, bool value)
{
    return set(key, ConfigValue(value));
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

const std::string& ConfigManager::configFilePath() const
{
    return configFilePath_;
}

bool ConfigManager::save() const
{
    std::ofstream file(configFilePath_);

    if (!file.is_open())
    {
        return false;
    }

    for (const auto& entry : configuration_)
    {
        file << entry.first << "=";

        switch (entry.second.type())
        {
            case ConfigValueType::STRING:
                file << entry.second.asString();
                break;

            case ConfigValueType::INTEGER:
                file << entry.second.asInteger();
                break;

            case ConfigValueType::BOOLEAN:
                file << (entry.second.asBoolean() ? "true" : "false");
                break;
        }

        file << '\n';
    }

    return true;
}


bool ConfigManager::load()
{
    std::ifstream file(configFilePath_);

    if (!file.is_open())
    {
        return false;
    }

    std::string line;

    while (std::getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }

        const auto delimiter = line.find('=');

        if (delimiter == std::string::npos)
        {
            continue;
        }

        const std::string key = line.substr(0, delimiter);
        const std::string value = line.substr(delimiter + 1);

        if (key.empty())
        {
            continue;
        }
        
        if (value.empty())
        {
            continue;
        }

        if (value == "true")
        {
            configuration_.insert_or_assign(key, ConfigValue(true));
        }
        else if (value == "false")
        {
            configuration_.insert_or_assign(key, ConfigValue(false));
        }
        else
        {
            try
            {
                const int integerValue = std::stoi(value);
                configuration_.insert_or_assign(
                    key,
                    ConfigValue(integerValue)
                );
            }
            catch (const std::exception&)
            {
                configuration_.insert_or_assign(
                    key,
                    ConfigValue(value)
                );
            }
        }
    }

    return true;
}

} // namespace securenos
