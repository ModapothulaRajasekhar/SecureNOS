#ifndef SECURENOS_SYSTEM_MANAGER_H
#define SECURENOS_SYSTEM_MANAGER_H

namespace securenos
{

class SystemManager
{
public:
    SystemManager() = default;
    ~SystemManager() = default;

    bool initialize();
    bool start();
    void run();
    void shutdown();
};

} // namespace securenos

#endif // SECURENOS_SYSTEM_MANAGER_H
