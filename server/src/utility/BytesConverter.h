#ifndef BYTES_CONVERTER_H
#define BYTES_CONVERTER_H

#include <vector>
#include <string>
#include <cstdint>

namespace utility
{
    class BytesConverter
    {
    public:
        static void appendUINT16toVectorOfUINT8(uint16_t number, std::vector<uint8_t>& vec);
        static uint16_t fromVectorOfUINT8toUINT16(const std::vector<uint8_t> &vec, uint16_t variablePosition);

        static void appendUINT32toVectorOfUINT8(uint32_t number, std::vector<uint8_t>& vec);
        static uint32_t fromVectorOfUINT8toUINT32(const std::vector<uint8_t> &vec, uint16_t variablePosition);

        static void appendUINT64toVectorOfUINT8(uint64_t number, std::vector<uint8_t>& vec);
        static uint64_t fromVectorOfUINT8toUINT64(const std::vector<uint8_t> &vec, uint16_t variablePosition);

        static void appendStringToVectorOfUINT8(std::string data, std::vector<uint8_t>& vec);
        static std::string fromVectorOfUINT8toString(const std::vector<uint8_t> &vec, uint16_t variablePosition);
    };
}
#endif
