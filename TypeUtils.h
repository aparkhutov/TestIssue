#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <unordered_map>

namespace TypeUtils
{
    enum class Mode
    {
        unknown,
        words,
        checksum
    };

    inline Mode GetModeByString(const std::string& value) noexcept
    {
        if (value.compare("words") == 0)
            return Mode::words;
        if (value.compare("checksum") == 0)
            return Mode::checksum;
        return Mode::unknown;
    };

    class Arguments
    {
    public:
        void Init(const std::vector<std::string>& parameters);

        inline bool IsShowHelp() const noexcept
        {
            return m_showHelp;
        }

        inline Mode GetMode() const noexcept
        {
            return m_mode;
        }

        inline const std::string& GetFilePath() const noexcept
        {
            return m_filePath;
        }

        const std::string& GetParameter(const std::string& name) const
        {
            auto it = m_knownParams.find(name);
            if (it != m_knownParams.end())
                return it->second;
            
            std::string message = "Parameter not found: ";
            message += name;
            throw std::invalid_argument(message);
        }

    private:
        bool m_showHelp = false;
        std::string m_filePath;
        Mode m_mode = Mode::unknown;
        std::unordered_map<std::string, std::string> m_knownParams;
    };
}
