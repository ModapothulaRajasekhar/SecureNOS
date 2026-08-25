#ifndef SECURENOS_SYSTEM_MANAGER_H
#define SECURENOS_SYSTEM_MANAGER_H

#include <atomic>
#include "config/config_manager.h"

namespace securenos
{

class SystemManager
{
public:
    SystemManager() = default;
    ~SystemManager() = default;

    bool initialize();
    bool start();
    void run(const std::atomic<bool>& shutdownRequested);
    void shutdown();
private:
    ConfigManager configManager_;
};

} // namespace securenos

#endif // SECURENOS_SYSTEM_MANAGER_H
