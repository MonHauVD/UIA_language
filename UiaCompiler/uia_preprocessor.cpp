#include <iostream>
#include <fstream>
#include <string>
#include <regex>

class UIAPreprocessor {
public:
    static bool processFile(const std::string& inputFile, const std::string& outputFile) {
        std::ifstream inFile(inputFile);
        std::ofstream outFile(outputFile);
        
        if (!inFile.is_open() || !outFile.is_open()) {
            std::cerr << "Error: Cannot open file " << inputFile << " or " << outputFile << std::endl;
            return false;
        }

        // Thêm các include cần thiết
        outFile << "#include \"UiaCompiler/uia_library.h\"\n\n";
        
        std::string line;
        while (std::getline(inFile, line)) {
            // Xử lý từng dòng code
            outFile << line << "\n";
        }
        
        return true;
    }
};
