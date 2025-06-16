#include <iostream>
#include <string>
#include "uia_compiler.cpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: uia_compiler <input_file.uia>\n";
        return 1;
    }

    std::string inputFile = argv[1];
    
    if (UIACompiler::compile(inputFile)) {
        std::cout << "Compilation successful!\n";
        return 0;
    } else {
        std::cout << "Compilation failed!\n";
        return 1;
    }
}
