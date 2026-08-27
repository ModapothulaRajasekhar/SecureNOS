#ifndef SECURENOS_CONFIG_VALUE_H
#define SECURENOS_CONFIG_VALUE_H

#include <string>
#include <variant>

namespace securenos
{

enum class ConfigValueType
{
    STRING,
    INTEGER,
    BOOLEAN
};

class ConfigValue
{
public:
    ConfigValue(const std::string& value);
    ConfigValue(const char* value);
    ConfigValue(int value);
    ConfigValue(bool value);

    ConfigValueType type() const;

    const std::string& asString() const;
    int asInteger() const;
    bool asBoolean() const;

private:
    ConfigValueType type_;
    std::variant<std::string, int, bool> value_;
};

} // namespace securenos

#endif // SECURENOS_CONFIG_VALUE_H
