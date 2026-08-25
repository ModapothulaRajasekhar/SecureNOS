#include "system/system_manager.h"

#include <iostream>

namespace securenos
{

bool SystemManager::initialize()
{
    std::cout << "[System] Initializing SecureNOS..." << std::endl;

    return true;
}

} // namespace securenos
