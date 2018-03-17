#include "PeriphManager.h"
#include <protocol/DataResponse.h>

using namespace std;
using namespace communication;
using namespace peripherials;

PeriphManager *PeriphManager::instance_= nullptr;
std::mutex PeriphManager::periphManagerMutex_;

PeriphManager::PeriphManager()
{}

PeriphManager::~PeriphManager()
{}

PeriphManager &PeriphManager::getInstance()
{
    if (!instance_)
    {
        lock_guard<mutex> lock(periphManagerMutex_);
        if (!instance_)
        {
            instance_ = new PeriphManager();

            initialize();
        }
    }

    return *instance_;
}

void PeriphManager::initialize()
{

}

void PeriphManager::readConfig(const std::string &configFile)
{

}

void PeriphManager::initBroadcastFucntion(function<void(shared_ptr<Response>)> broadcastFunction)
{
    broadcastFunction_ = broadcastFunction;
}

void PeriphManager::runBlindsDOWNOnTime(uint32_t epochTime)
{
    lock_guard<mutex> lock(commandMutex_);

}

void PeriphManager::runBlindsUPOnTime(int32_t epochTime)
{
    lock_guard<mutex> lock(commandMutex_);

}

void PeriphManager::runBlindsUP()
{
    lock_guard<mutex> lock(commandMutex_);

}

void PeriphManager::runBlindsDOWN()
{
    lock_guard<mutex> lock(commandMutex_);

}

void PeriphManager::runBlindsStatus()
{
    lock_guard<mutex> lock(commandMutex_);

}

void PeriphManager::runAutomaticBlinds()
{
    lock_guard<mutex> lock(commandMutex_);

}

void PeriphManager::runTemperatureDemand()
{
    lock_guard<mutex> lock(commandMutex_);

}

void PeriphManager::runUserOutOfHome()
{
    lock_guard<mutex> lock(commandMutex_);

}

void PeriphManager::runSnapshot()
{
    lock_guard<mutex> lock(commandMutex_);

}

void PeriphManager::broadcast(shared_ptr<Response> response)
{
    broadcastFunction_(response);
}