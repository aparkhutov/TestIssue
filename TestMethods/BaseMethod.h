#pragma once

namespace TestMethods
{
    class BaseMethod
    {
    public:
        virtual void Execute() = 0;
        virtual ~BaseMethod() = default;
    };
}