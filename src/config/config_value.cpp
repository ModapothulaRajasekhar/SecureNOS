#include "config/config_value.h"

namespace securenos
{

ConfigValue::ConfigValue(const std::string& value)
    : type_(ConfigValueType::STRING),
      value_(value)
{
}

ConfigValue::ConfigValue(const char* value)
    : type_(ConfigValueType::STRING),
      value_(std::string(value))
{
}

ConfigValue::ConfigValue(int value)
    : type_(ConfigValueType::INTEGER),
      value_(value)
{
}

ConfigValue::ConfigValue(bool value)
    : type_(ConfigValueType::BOOLEAN),
      value_(value)
{
}

ConfigValueType ConfigValue::type() const
{
    return type_;
}

const std::string& ConfigValue::asString() const
{
    return std::get<std::string>(value_);
}

int ConfigValue::asInteger() const
{
    return std::get<int>(value_);
}
bool ConfigValue::asBoolean() const
{
    return std::get<bool>(value_);
}

} // namespace securenos
