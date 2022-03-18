#pragma once

#include <iostream>

namespace Utils {
    const char* const c_helpMeassage =
        "\ttest - f Test.tst - m words - v mother - prints the number of words \"mother\" in the file \"Test.tst\"\n"
        "\ttest - f Test.tst - m checksum - prints a 32-bit checksum,\n\t\tcalculated by the algorithm: checksum = word1 + word2 + ... + wordN\n\t\t(word1..wordN - 32-bit words representing the contents of the file)\n"
        "\ttest - h - prints information about the program and a description of the parameters.";

    void ShowHelp()
    {
        std::cout << c_helpMeassage << std::endl;
    };
}
