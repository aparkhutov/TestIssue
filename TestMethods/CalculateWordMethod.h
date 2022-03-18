#pragma once

#include <string>
#include "BaseMethod.h"

namespace TestMethods
{
    class CalculateWord : public BaseMethod
    {
    public:
        CalculateWord(const std::string& file, const std::string& word)
            : m_filePath{ file },
            m_word{ word }
        {};

        ~CalculateWord() = default;

        void Execute() override;

    private:
        std::string m_filePath;
        std::string m_word;
    };
}
