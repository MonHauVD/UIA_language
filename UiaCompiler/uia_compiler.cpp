#include <iostream>
#include <string>
#include <cstdlib>
#include "uia_preprocessor.cpp"

class UIACompiler {
public:
    static bool compile(const std::string& inputFile) {
        // Kiểm tra đuôi file
        if (inputFile.substr(inputFile.find_last_of(".") + 1) != "uia") {
            std::cerr << "Error: Input file must have .uia extension\n";
            return false;
        }

        // Tạo tên file tạm
        std::string tempCppFile = inputFile.substr(0, inputFile.find_last_of(".")) + ".cpp";
        
        // Preprocess file
        if (!UIAPreprocessor::processFile(inputFile, tempCppFile)) {
            std::cerr << "Error: Failed to preprocess file\n";
            return false;
        }

        // Biên dịch file C++
        std::string outputExe = inputFile.substr(0, inputFile.find_last_of(".")) + ".exe";
        std::string compileCommand = "g++ \"" + tempCppFile + "\" -o \"" + outputExe + "\"";
        
        int result = std::system(compileCommand.c_str());
        
        // Xóa file tạm
        std::remove(tempCppFile.c_str());
        
        return result == 0;
    }
};
