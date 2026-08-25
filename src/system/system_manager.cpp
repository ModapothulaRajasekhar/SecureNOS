#include "system/system_manager.h"

#include <iostream>

namespace securenos
{

bool SystemManager::initialize()
{
    std::cout << "[System] Initializing SecureNOS..." << std::endl;

    return true;
}

bool SystemManager::start()
{
    std::cout << "[System] Starting SecureNOS..." << std::endl;

    return true;
}

void SystemManager::run()
{
    std::cout << "[System] SecureNOS is running..." << std::endl;
}



} // namespace securenos
