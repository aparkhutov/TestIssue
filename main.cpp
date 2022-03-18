// main.cpp : Defines the entry point for the application.

#include <fstream>
#include <filesystem>
#include <vector>
#include <unordered_map>

#include "TypeUtils.h"
#include "Utils.h"
#include "TestMethods/BaseMethod.h"
#include "TestMethods/TestMethodsFactory.h"

/*
Напишите (консольную) программу, принимающую на вход имя файла и набор параметров. В зависимости от параметров программа должна работать в трёх режимах:
1. test -f Test.tst -m words -v mother — печатает количество слов «mother» в файле «Test.tst»
2. test -f Test.tst -m checksum — печатает 32-битную чексумму, рассчитанную по алгоритму checksum = word1 + word2 + ... + wordN (word1..wordN – 32-хбитные слова, представляющие содержимое файла)
3. test -h — печатает информацию о программе и описание параметров.
При написании тестового задания мы ожидаем увидеть пример качественного production-кода на С++ (а не «чистом» С, несмотря на некоторую избыточность С++ для данной задачи),  в частности:
- соблюдение единого стиля кодирования
- разумное расходование памяти
- расчёт на производительность
- расчёт на расширяемость
- следование принципам ООП там, где это уместно
- использование modern C++ best practices
*/

using namespace TypeUtils;
using namespace TestMethods;

int main(int argc, char* argv[])
{
    std::vector<std::string> strArgs;
    for (size_t i = 1; i < argc; i++)
    {
        strArgs.emplace_back(argv[i]);
        //std::cout << strArgs.back() << std::endl;
    }
    
    try
    {
        Arguments param;
        param.Init(strArgs);

        if (param.IsShowHelp())
        {
            Utils::ShowHelp();
            return 0;
        }

        auto method = TestMethodsFactory::GetCalculateMethod(param);
        method->Execute();
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
};
