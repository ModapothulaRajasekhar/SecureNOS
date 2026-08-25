#include "system/system_manager.h"

#include <iostream>
#include <csignal>
#include <atomic>


std::atomic<bool> shutdownRequested{false};

void signalHandler(int signal)
{
    if (signal == SIGINT)
    {
        shutdownRequested.store(true);
    }
}

int main()
{   
    std::signal(SIGINT, signalHandler);
   
    std::cout << "========================================" << std::endl;
    std::cout << "       SecureNOS Network OS" << std::endl;
    std::cout << "       Version: 0.1.0" << std::endl;
    std::cout << "========================================" << std::endl;

    securenos::SystemManager systemManager;

    if (!systemManager.initialize())
    {
        std::cerr << "[System] Initialization failed." << std::endl;
        return 1;
    }

    std::cout << "[System] Initialization successful." << std::endl;
   
    if (!systemManager.start())
    {
        std::cerr << "[System] Startup failed." << std::endl;
        return 1;
    }

    std::cout << "[System] Startup successful." << std::endl;
    systemManager.run(shutdownRequested);
    systemManager.shutdown();
    return 0;
}
