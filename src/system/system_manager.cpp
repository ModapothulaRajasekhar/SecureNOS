#include "system/system_manager.h"

#include <iostream>
#include <chrono>
#include <thread>


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

void SystemManager::run(const std::atomic<bool>& shutdownRequested)
{
    std::cout << "[System] SecureNOS is running..." << std::endl;
     
    while (!shutdownRequested.load())
    {
       std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void SystemManager::shutdown()
{
    std::cout << "[System] Shutting down SecureNOS..." << std::endl;
}

} // namespace securenos
