#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <sstream>
#include <map>

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
            // Xử lý chuỗi ký tự đặc biệt
            line = processStringLiterals(line);
            // Xử lý số
            line = processNumbers(line);
            outFile << line << "\n";
        }
        
        return true;
    }

private:
    static std::string processStringLiterals(const std::string& line) {
        std::string result = line;
        std::regex stringPattern("I_u\\s*\\(([^)]+)\\)");
        
        std::smatch matches;
        while (std::regex_search(result, matches, stringPattern)) {
            std::string content = matches[1];
            std::string processedContent = "\"";
            
            // Xử lý từng ký tự trong chuỗi
            std::istringstream iss(content);
            std::string token;
            while (iss >> token) {
                processedContent += convertTokenToChar(token);
            }
            processedContent += "\"";
            
            // Thay thế chuỗi gốc bằng chuỗi đã xử lý
            result = std::regex_replace(result, stringPattern, processedContent, std::regex_constants::format_first_only);
        }
        
        return result;
    }

    static std::string processNumbers(const std::string& line) {
        std::string result = line;
        std::regex numberPattern("iiii\\s*\\(([^)]+)\\)");
        
        std::smatch matches;
        while (std::regex_search(result, matches, numberPattern)) {
            std::string content = matches[1];
            std::string processedContent;
            int number = 0;
            
            // Xử lý từng ký tự trong số
            std::istringstream iss(content);
            std::string token;
            while (iss >> token) {
                std::string digit = convertTokenToChar(token);
                number = number * 10 + std::stoi(digit);
            }
            
            processedContent = std::to_string(number);
            
            // Thay thế chuỗi gốc bằng chuỗi đã xử lý
            result = std::regex_replace(result, numberPattern, processedContent, std::regex_constants::format_first_only);
        }

        // Xử lý các số đơn lẻ không nằm trong iiii()
        std::regex singleNumberPattern("\\b(A|I|U|a|u|i|Aa|Au|Ai|Ia)\\b");
        std::string::const_iterator searchStart(result.cbegin());
        std::string::const_iterator searchEnd(result.cend());
        std::string newResult;
        
        while (std::regex_search(searchStart, searchEnd, matches, singleNumberPattern)) {
            newResult += result.substr(searchStart - result.cbegin(), matches.position());
            newResult += convertTokenToChar(matches.str());
            searchStart = matches.suffix().first;
        }
        newResult += result.substr(searchStart - result.cbegin());
        
        return newResult;
    }

    static std::string convertTokenToChar(const std::string& token) {
        static const std::map<std::string, std::string> tokenMap = {
            // Số
            {"A", "0"},
            {"I", "1"},
            {"U", "2"},
            {"a", "3"},
            {"u", "4"},
            {"i", "5"},
            {"Aa", "6"},
            {"Au", "7"},
            {"Ai", "8"},
            {"Ia", "9"},

            // Ký tự đặc biệt
            {"A_a", " "},
            {"A_u", "\n"},
            {"A_i", "\t"},
            {"A_A", "."},
            {"A_I", ","},
            {"A_U", ";"},
            {"I_a", ":"},
            {"I_i", "\\"},
            {"I_A", "{"},
            {"I_I", "}"},
            {"I_U", "("},
            {"U_a", ")"},
            {"U_u", "["},
            {"U_i", "]"},
            {"U_A", "+"},
            {"U_I", "-"},
            {"U_U", "*"},
            {"a_a", "/"},
            {"a_u", "="},
            {"a_i", "<"},
            {"a_A", ">"},
            {"a_I", "!"},
            {"a_U", "?"},
            {"u_a", "_"},
            {"u_u", "#"},
            {"u_i", "$"},
            {"u_A", "%"},
            {"u_I", "&"},
            {"u_U", "|"},
            {"i_a", "\\"},
            {"i_u", "@"},
            
            // Chữ cái viết hoa
            {"Aaa", "A"},
            {"Aau", "B"},
            {"Aai", "C"},
            {"Aua", "D"},
            {"Auu", "E"},
            {"Aui", "F"},
            {"Aia", "G"},
            {"Aiu", "H"},
            {"Aii", "I"},
            {"Iaa", "J"},
            {"Iau", "K"},
            {"Iai", "L"},
            {"Iua", "M"},
            {"Iuu", "N"},
            {"Iui", "O"},
            {"Iia", "P"},
            {"Iiu", "Q"},
            {"Iii", "R"},
            {"Uaa", "S"},
            {"Uau", "T"},
            {"Uai", "U"},
            {"Uua", "V"},
            {"Uuu", "W"},
            {"Uui", "X"},
            {"Uia", "Y"},
            {"Uiu", "Z"},
            
            // Chữ cái viết thường
            {"aaa", "a"},
            {"aau", "b"},
            {"aai", "c"},
            {"aua", "d"},
            {"auu", "e"},
            {"aui", "f"},
            {"aia", "g"},
            {"aiu", "h"},
            {"aii", "i"},
            {"iaa", "j"},
            {"iau", "k"},
            {"iai", "l"},
            {"iua", "m"},
            {"iuu", "n"},
            {"iui", "o"},
            {"iia", "p"},
            {"iiu", "q"},
            {"iii", "r"},
            {"uaa", "s"},
            {"uau", "t"},
            {"uai", "u"},
            {"uua", "v"},
            {"uuu", "w"},
            {"uui", "x"},
            {"uia", "y"},
            {"uiu", "z"}
        };
        
        auto it = tokenMap.find(token);
        if (it != tokenMap.end()) {
            return it->second;
        }
        return token; // Nếu không tìm thấy trong map, giữ nguyên token
    }
};
