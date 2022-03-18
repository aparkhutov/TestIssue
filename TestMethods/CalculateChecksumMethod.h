#pragma once

#include <string>
#include "BaseMethod.h"

namespace TestMethods
{
    class CalculateChecksum : public BaseMethod
    {
    public:
        CalculateChecksum(const std::string& file)
            : m_filePath{ file } {};

        ~CalculateChecksum() = default;

        void Execute() override;

    private:
        std::string m_filePath;
    };
}