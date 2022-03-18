#include <iostream>
#include <fstream>
#include "CalculateWordMethod.h"

void TestMethods::CalculateWord::Execute()
{
    const size_t c_lineBufSize = 1024;

    std::ifstream file(m_filePath);
    std::string line;
    size_t count = 0;

    while (!file.eof())
    {
        getline(file, line);
        auto offset = line.find(m_word);
        while (offset != std::string::npos)
        {
            count++;
            offset = line.find(m_word, offset + m_word.size());
        }
    }

    std::cout << "Word count: " << count << std::endl;
};
