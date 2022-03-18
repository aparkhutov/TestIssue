#include <iostream>
#include <fstream>
#include <array>
#include "CalculateChecksumMethod.h"

void TestMethods::CalculateChecksum::Execute()
{
    constexpr size_t c_bufSize = 1024;

    std::ifstream file;
    file.open(m_filePath, std::ios::in | std::ios::binary);
    uint32_t hash = 0;
    std::array<char, c_bufSize> buf = {};
    std::streamsize readcount = 0;
    
    do
    {
        file.read(buf.data(), c_bufSize);
        readcount = file.gcount();
        for (int i = 0; i < readcount; i++)
        {
            hash ^= static_cast<uint32_t>(buf[i]) << ((i % 4) * 8);
        }
    } while (readcount == c_bufSize);

    std::cout << "Checksum: " << std::hex << hash << std::endl;
};
