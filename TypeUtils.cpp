#include "TypeUtils.h"

void TypeUtils::Arguments::Init(const std::vector<std::string>& parameters)
{
    if (!parameters.size())
        m_showHelp = true;

    auto it = parameters.begin();
    while (it != parameters.end())
    {
        if (it->compare("-h") == 0)
        {
            m_showHelp = true;
        }
        else if (it->compare("-f") == 0)
        {
            if (!m_filePath.empty() || ++it == parameters.end() || it->empty())
                throw std::invalid_argument("Invalid argument: -f, value not found");

            if (!std::filesystem::exists(*it))
                throw std::invalid_argument("Invalid argument: -f, file not exist");

            m_filePath = *it;
        }
        else if (it->compare("-m") == 0)
        {
            if (m_mode != Mode::unknown)
                throw std::invalid_argument("Invalid argument: -m, value already set");

            if (++it == parameters.end() || it->empty())
                throw std::invalid_argument("Invalid argument: -m, value not found");

            m_mode = GetModeByString(*it);
        }
        else if (!it->empty() && it->at(0) == '-')
        {
            std::string key = *it;

            // Change if need support unknown flag-arguments

            if (++it == parameters.end() || it->empty())
            {
                std::string message = "Invalid argument: ";
                message += key;
                message += ", value not found";
                throw std::invalid_argument(message);
            }
            m_knownParams[key] = *it;
        }
        it++;
    }

    // Check required parameters

    if (!m_showHelp)
    {
        if (m_filePath.empty())
            throw std::invalid_argument("File argument not set. Argument: -f");
        if (m_mode == Mode::unknown)
            throw std::invalid_argument("Mode argument not set. Argument: -m");
        if (m_mode == Mode::words && m_knownParams.count("-v") == 0)
            throw std::invalid_argument("Argument '-v' not set for 'words' mode.");
    }
}