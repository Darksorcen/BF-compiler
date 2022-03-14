#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
#include <fstream>

int main(int argc, char **argv)
{
    std::unordered_map<char, std::string> dict_symbols = {
        {'>', 	"    ptr++;\n"},
        {'<', 	"    ptr--;\n"},
        {'+', 	"    ++(*ptr);\n"},
        {'-', 	"    --(*ptr);\n"},
        {'.',	"    putchar(*ptr);\n"},
        {',',	"    (*ptr) = getchar();\n"},
        {'[',	"    while(*ptr) {\n"},
        {']',	"    }\n"}
    };
    std::string test_str = "++>+++<[-]";
    std::string code = "#include \"stdio.h\"\nint main()\n{\n    char array[30000] = {0};\n    unsigned char *ptr = array;\n";

    if (argv[1] == NULL || argv[2] == NULL)
    {
        std::cout << "No files given" << std::endl;
        return 0;
    }
    else if (argc > 3)
    {
        std::cout << "Too many arguments" << std::endl;
        return 0;
    }
    std::string line;
    std::ifstream bf_file { argv[1] };
    std::cout << argv[1] << std::endl;
    while (std::getline(bf_file >> std::ws, line))
    {
        for (auto character : line)
        {
            code += dict_symbols[character];
        }
    }
    code += "    return 0;\n}";
    std::ofstream c_file { argv[2] };
    c_file << code;
    return 0;
}
