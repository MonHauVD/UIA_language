#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <program.uia>\n";
        return 1;
    }

    std::string inputFile = argv[1];
    
    // Sử dụng đường dẫn tương đối đến uia_compiler.exe
    std::string compileCommand = "UiaCompiler\\uia_compiler.exe \"" + inputFile + "\"";
    int compileResult = std::system(compileCommand.c_str());
    
    if (compileResult != 0) {
        std::cout << "Compilation failed!\n";
        return 1;
    }

    // Chạy file đã biên dịch
    std::string programName = inputFile.substr(0, inputFile.find_last_of("."));
    std::string runCommand = "\"" + programName + ".exe\"";
    return std::system(runCommand.c_str());
}
