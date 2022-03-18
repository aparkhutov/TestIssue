#pragma once

#include <memory>
#include "../TypeUtils.h"
#include "BaseMethod.h"
#include "CalculateChecksumMethod.h"
#include "CalculateWordMethod.h"

using namespace TypeUtils;
using namespace TestMethods;

namespace TestMethodsFactory {
    std::unique_ptr<BaseMethod> GetCalculateMethod(Arguments param)
    {
        switch (param.GetMode())
        {
        case Mode::words:
            return std::make_unique<CalculateWord>(param.GetFilePath(), param.GetParameter("-v"));
        case Mode::checksum:
            return std::make_unique<CalculateChecksum>(param.GetFilePath());
        }
        throw std::range_error("Unknown method");
    };
}
