#ifndef CONFIGURATION_READER_H
#define CONFIGURATION_READER_H

#include <string>
#include <fstream>
#include <iostream>
#include <queue>
#include <logger/Logger.h>
#include "../../3rd_party/json/json/json.h"

namespace config
{
    class JSONParser
    {
    public:
        JSONParser(const std::string &fileName);
        ~JSONParser();

        void getUINT8t(const std::vector<std::string> &hierarchyQueue, uint8_t &value);
        void getUINT16t(const std::vector<std::string> &hierarchyQueue, uint16_t &value);
        void getUINT32t(const std::vector<std::string> &hierarchyQueue, uint32_t &value);
        void getUINT64t(const std::vector<std::string> &hierarchyQueue, uint64_t &value);
        void getString(const std::vector<std::string> &hierarchyQueue, std::string &value);

    private:
        Json::Value getFromLeaf(const std::vector<std::string> &hierarchyQueue);

        std::string fileName_;
        std::fstream file_;
        Json::Value fileRoot_;

        utility::Logger& logger_;
    };
}
#endif
