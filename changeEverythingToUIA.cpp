// #include "uia.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

// Hàm để xử lý chuỗi trong dấu nháy kép
string processStringLiteral(const string& str, const map<char, string>& letters) {
    string result = "I_u (";
    bool firstChar = true;
    
    for (char c : str) {
        if (!firstChar) {
            result += " ";
        }
        firstChar = false;
        
        if (isalpha(c)) {
            result += letters.at(c);
        }
        else if (c == ' ') {
            result += "A_a";
        }
        else {
            result += c;
        }
    }
    
    result += ")";
    return result;
}

// Khai báo hàm processWord
void processWord(const string& word, string& result, 
                const map<string, string>& cppKeywords,
                const map<string, string>& specialChars,
                const map<char, string>& numbers,
                const map<char, string>& letters);

// Hàm để đọc nội dung file
string readFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        return "";
    }
    string content((istreambuf_iterator<char>(file)),
                        istreambuf_iterator<char>());
    file.close();
    return content;
}

// Hàm để ghi nội dung vào file
void writeFile(const string& filename, const string& content) {
    ofstream file(filename);
    if (file.is_open()) {
        file << content;
        file.close();
    }
}

// Hàm chuyển đổi theo thứ tự ưu tiên
string convertToUIA(const string& content) {
    string result = content;
    cout << "\n=== Nội dung gốc ===\n" << result << "\n";
    
    // Bỏ qua các dòng #include
    istringstream iss(result);
    string line;
    string processedContent;
    bool firstLine = true;
    
    // Bước 1: Lọc bỏ các dòng #include
    while (getline(iss, line)) {
        // Bỏ qua dòng #include
        if (line.find("#include") != string::npos) {
            continue;
        }
        
        if (!firstLine) {
            processedContent += "\n";
        }
        processedContent += line;
        firstLine = false;
    }
    
    result = processedContent;
    
    // Thứ nhất: Các từ khóa C++ và tên function quan trọng
    map<string, string> cppKeywords = {
        // Từ khóa cơ bản
        {"using", "Aaaa"}, {"namespace", "Aaau"},
        {"std", "Aaai"}, {"int", "Aaua"}, {"void", "Aauu"},
        {"return", "Aaui"}, {"if", "Aaia"}, {"else", "Aaiu"},
        {"for", "Aaii"}, {"while", "Aa_a"}, {"do", "Aa_u"},
        {"switch", "Aa_i"}, {"case", "Aa_A"}, {"break", "Aa_I"},
        {"continue", "Aa_U"}, {"class", "Auaa"}, {"struct", "Auau"},
        {"public", "Auai"}, {"private", "Auua"}, {"protected", "Auuu"},
        {"const", "Auui"}, {"static", "Auia"}, {"virtual", "Auiu"},
        {"override", "Auii"}, {"final", "Au_a"}, {"template", "Au_u"},
        {"typename", "Au_i"}, {"auto", "Au_A"}, {"nullptr", "Au_I"},
        {"true", "Au_U"}, {"false", "Aiaa"}, {"new", "Aiau"},
        {"delete", "Aiai"}, {"this", "Aiua"}, {"sizeof", "Aiuu"},
        {"typeof", "Aiui"}, {"try", "Aiia"}, {"catch", "Aiiu"},
        {"throw", "Aiii"}, {"exception", "Ai_a"},
        
        // Từ khóa bổ sung
        {"char", "A_aa"}, {"double", "A_au"}, {"float", "A_ai"},
        {"long", "A_ua"}, {"short", "A_uu"}, {"unsigned", "A_ui"},
        {"signed", "A_ia"}, {"bool", "A_iu"}, {"enum", "A_ii"},
        {"union", "A_Aa"}, {"typedef", "A_Au"}, {"extern", "A_Ai"},
        {"inline", "A_Ia"}, {"explicit", "A_Iu"}, {"mutable", "A_Ii"},
        {"volatile", "A_Ua"}, {"register", "A_Uu"}, {"friend", "A_Ui"},
        {"operator", "Iaaa"}, {"export", "Iaau"},
        
        // Tên function quan trọng
        {"main", "Iaua"}, {"cout", "Iauu"}, {"cin", "Iaui"},
        {"endl", "Iaia"}, {"printf", "Iaiu"}, {"scanf", "Iaii"},
        {"malloc", "Ia_a"}, {"free", "Ia_u"}, {"calloc", "Ia_i"},
        {"realloc", "Ia_A"}, {"strlen", "Ia_I"}, {"strcpy", "Ia_U"},
        {"strcat", "Iuaa"}, {"strcmp", "Iuau"}, {"strstr", "Iuai"},
        {"strtok", "Iuua"}, {"memcpy", "Iuuu"}, {"memmove", "Iuui"},
        {"memset", "Iuia"}, {"memcmp", "Iuiu"}, {"atoi", "Iuii"},
        {"atof", "Iu_a"}, {"itoa", "Iu_u"}, {"rand", "Iu_i"},
        {"srand", "Iu_A"}, {"time", "Iu_I"}, {"clock", "Iu_U"},
        {"exit", "Iiaa"}, {"abort", "Iiau"}, {"assert", "Iiai"},
        {"fopen", "Iiua"}, {"fclose", "Iiuu"}, {"fread", "Iiui"},
        {"fwrite", "Iiia"}, {"fseek", "Iiiu"}, {"ftell", "Iiii"},
        {"rewind", "Ii_a"}, {"remove", "Ii_u"}, {"rename", "Ii_i"},
        {"tmpfile", "Ii_A"}, {"tmpnam", "Ii_I"}, {"setvbuf", "Ii_U"},
        {"fprintf", "I_aa"}, {"fscanf", "I_au"}, {"fgets", "I_ai"},
        {"fputs", "I_ua"}, {"getc", "I_uu"}, {"putc", "I_ui"},
        {"ungetc", "I_ia"}, {"fflush", "I_iu"}, {"feof", "I_ii"},
        {"ferror", "I_Aa"}, {"clearerr", "I_Au"}, {"perror", "I_Ai"},
        {"strerror", "I_Ia"}, {"setlocale", "I_Iu"}, {"localeconv", "I_Ii"},
        {"isalnum", "I_Ua"}, {"isalpha", "I_Uu"}, {"iscntrl", "I_Ui"},
        {"isdigit", "Uaaa"}, {"isgraph", "Uaau"}, {"islower", "Uaai"},
        {"isprint", "Uaua"}, {"ispunct", "Uauu"}, {"isspace", "Uaui"},
        {"isupper", "Uaia"}, {"isxdigit", "Uaiu"}, {"tolower", "Uaii"},
        {"toupper", "Ua_a"}, {"abs", "Ua_u"}, {"labs", "Ua_i"},
        {"div", "Ua_A"}, {"ldiv", "Ua_I"}, {"rand", "Ua_U"},
        {"srand", "Uuaa"}, {"malloc", "Uuau"}, {"calloc", "Uuai"},
        {"realloc", "Uuua"}, {"free", "Uuuu"}, {"abort", "Uuui"},
        {"exit", "Uuia"}, {"atexit", "Uuiu"}, {"system", "Uuii"},
        {"getenv", "Uu_a"}, {"bsearch", "Uu_u"}, {"qsort", "Uu_i"}
    };

    // Thứ hai: Các ký tự đặc biệt và toán tử kép
    map<string, string> specialChars = {
        // Toán tử kép
        {"<=", "Uiaa"}, {">=", "Uiau"}, {"==", "Uiai"}, {"!=", "Uiua"},
        {"++", "Uiuu"}, {"--", "Uiui"}, {"<<=", "Uiia"}, {">>=", "Uiiu"},
        {"+=", "Uiii"}, {"-=", "Ui_a"}, {"*=", "Ui_u"}, {"/=", "Ui_i"},
        {"%=", "Ui_A"}, {"&=", "Ui_I"}, {"|=", "Ui_U"}, {"^=", "U_aa"},
        {"<<", "U_au"}, {">>", "U_ai"}, {"&&", "U_ua"}, {"||", "U_uu"},
        {"->", "U_ui"}, {"::", "U_ia"},
        // Ký tự đặc biệt
        {".", "A_A"}, {",", "A_I"}, {";", "A_U"},
        {":", "I_a"}, {"\"", "I_u"}, {"'", "I_i"},
        {"{", "I_A"}, {"}", "I_I"}, {"(", "I_U"},
        {")", "U_a"}, {"[", "U_u"}, {"]", "U_i"},
        {"+", "U_A"}, {"-", "U_I"}, {"*", "U_U"},
        {"/", "a_a"}, {"=", "a_u"}, {"<", "a_i"},
        {">", "a_A"}, {"!", "a_I"}, {"?", "a_U"},
        {"_", "u_a"}, {"#", "u_u"}, {"$", "u_i"},
        {"%", "u_A"}, {"&", "u_I"}, {"|", "u_U"},
        {"\\", "i_a"}, {"@", "i_u"}, {"~", "Uu_A"},
        {"`", "Uu_I"}, {"^", "Uu_U"}
    };

    // Thứ ba: Các số
    map<char, string> numbers = {
        {'0', "A"}, {'1', "I"}, {'2', "U"},
        {'3', "a"}, {'4', "u"}, {'5', "i"},
        {'6', "Aa"}, {'7', "Au"}, {'8', "Ai"},
        {'9', "Ia"}
    };

    // Thứ tư: Bảng chữ cái
    map<char, string> letters = {
        {'A', "Aaa"}, {'B', "Aau"}, {'C', "Aai"}, {'D', "Aua"},
        {'E', "Auu"}, {'F', "Aui"}, {'G', "Aia"}, {'H', "Aiu"},
        {'I', "Aii"}, {'J', "Iaa"}, {'K', "Iau"}, {'L', "Iai"},
        {'M', "Iua"}, {'N', "Iuu"}, {'O', "Iui"}, {'P', "Iia"},
        {'Q', "Iiu"}, {'R', "Iii"}, {'S', "Uaa"}, {'T', "Uau"},
        {'U', "Uai"}, {'V', "Uua"}, {'W', "Uuu"}, {'X', "Uui"},
        {'Y', "Uia"}, {'Z', "Uiu"},
        {'a', "aaa"}, {'b', "aau"}, {'c', "aai"}, {'d', "aua"},
        {'e', "auu"}, {'f', "aui"}, {'g', "aia"}, {'h', "aiu"},
        {'i', "aii"}, {'j', "iaa"}, {'k', "iau"}, {'l', "iai"},
        {'m', "iua"}, {'n', "iuu"}, {'o', "iui"}, {'p', "iia"},
        {'q', "iiu"}, {'r', "iii"}, {'s', "uaa"}, {'t', "uau"},
        {'u', "uai"}, {'v', "uua"}, {'w', "uuu"}, {'x', "uui"},
        {'y', "uia"}, {'z', "uiu"}
    };

    // Map để theo dõi các vị trí đã được chuyển đổi
    map<size_t, bool> converted;

    // Bước 2: Thêm khoảng cách trước và sau ký tự đặc biệt nếu cần
    // Sắp xếp các ký tự đặc biệt theo độ dài giảm dần để xử lý toán tử kép trước
    vector<pair<string, string>> sortedSpecialChars(specialChars.begin(), specialChars.end());
    sort(sortedSpecialChars.begin(), sortedSpecialChars.end(),
         [](const auto& a1, const auto& b) { return a1.first.length() > b.first.length(); });

    for (const auto& specialChar : sortedSpecialChars) {
        size_t pos = 0;
        while ((pos = result.find(specialChar.first, pos)) != string::npos) {
            bool needSpaceBefore = false;
            bool needSpaceAfter = false;
            
            // Kiểm tra ký tự trước
            if (pos > 0 && result[pos-1] != ' ' && result[pos-1] != '\n' && result[pos-1] != '\t') {
                needSpaceBefore = true;
            }
            
            // Kiểm tra ký tự sau
            if (pos + specialChar.first.length() < result.length() && 
                result[pos + specialChar.first.length()] != ' ' && 
                result[pos + specialChar.first.length()] != '\n' && 
                result[pos + specialChar.first.length()] != '\t') {
                needSpaceAfter = true;
            }

            // Kiểm tra xem có phải là một phần của toán tử kép không
            bool isPartOfCompound = false;
            if (specialChar.first.length() == 1) {
                // Kiểm tra các trường hợp toán tử kép có thể
                string possibleCompound = specialChar.first;
                if (pos + 1 < result.length()) {
                    possibleCompound += result[pos + 1];
                    if (specialChars.find(possibleCompound) != specialChars.end()) {
                        isPartOfCompound = true;
                    }
                }
                if (pos > 0) {
                    possibleCompound = result[pos - 1] + specialChar.first;
                    if (specialChars.find(possibleCompound) != specialChars.end()) {
                        isPartOfCompound = true;
                    }
                }
            }
            
            // Chỉ thêm khoảng cách nếu không phải là một phần của toán tử kép
            if (!isPartOfCompound) {
                if (needSpaceBefore) {
                    result.insert(pos, " ");
                    pos++;
                }
                if (needSpaceAfter) {
                    result.insert(pos + specialChar.first.length(), " ");
                }
            }
            pos += specialChar.first.length() + (needSpaceBefore && !isPartOfCompound ? 1 : 0) + (needSpaceAfter && !isPartOfCompound ? 1 : 0);
        }
    }
    cout << "\n=== Sau khi thêm khoảng cách ===\n" << result << "\n";

    // Bước 3: Chuyển đổi từng từ theo thứ tự ưu tiên
    string newResult;
    iss.clear();
    iss.str(result);
    firstLine = true;
    
    while (getline(iss, line)) {
        // Xử lý khoảng trắng ở đầu dòng
        size_t spaceCount = 0;
        while (spaceCount < line.length() && line[spaceCount] == ' ') {
            newResult += ' ';
            spaceCount++;
        }
        
        // Xử lý phần còn lại của dòng
        string remainingLine = line.substr(spaceCount);
        bool inQuotes = false;
        string currentWord;
        string quotedString;
        bool firstWord = true;
        
        for (size_t i1 = 0; i1 < remainingLine.length(); i1++) {
            char c = remainingLine[i1];
            
            // Xử lý dấu nháy kép
            if (c == '"') {
                if (!inQuotes) {
                    // Bắt đầu chuỗi mới
                    if (!currentWord.empty()) {
                        // Xử lý từ đã tích lũy trước đó
                        if (!firstWord) newResult += " ";
                        firstWord = false;
                        processWord(currentWord, newResult, cppKeywords, specialChars, numbers, letters);
                        currentWord.clear();
                    }
                    inQuotes = true;
                } else {
                    // Kết thúc chuỗi
                    inQuotes = false;
                    // Xử lý chuỗi trong dấu nháy kép
                    if (!firstWord) newResult += " ";
                    firstWord = false;
                    newResult += processStringLiteral(quotedString, letters);
                    quotedString.clear();
                }
                continue;
            }
            
            // Nếu đang trong dấu nháy kép, thêm vào chuỗi
            if (inQuotes) {
                quotedString += c;
                continue;
            }
            
            // Xử lý khoảng trắng
            if (isspace(c)) {
                if (!currentWord.empty()) {
                    if (!firstWord) newResult += " ";
                    firstWord = false;
                    processWord(currentWord, newResult, cppKeywords, specialChars, numbers, letters);
                    currentWord.clear();
                }
                newResult += c;
                continue;
            }
            
            // Thêm ký tự vào từ hiện tại
            currentWord += c;
        }
        
        // Xử lý từ cuối cùng nếu còn
        if (!currentWord.empty()) {
            if (!firstWord) newResult += " ";
            processWord(currentWord, newResult, cppKeywords, specialChars, numbers, letters);
        }
        
        newResult += "\n";
    }
    
    // Xóa ký tự xuống dòng thừa ở cuối
    if (!newResult.empty() && newResult.back() == '\n') {
        newResult.pop_back();
    }
    
    cout << "\n=== Kết quả cuối cùng ===\n" << newResult << "\n";
    return newResult;
}

// Hàm phụ trợ để xử lý từ
void processWord(const string& word, string& result, 
                const map<string, string>& cppKeywords,
                const map<string, string>& specialChars,
                const map<char, string>& numbers,
                const map<char, string>& letters) {
    // Kiểm tra nếu là số có nhiều chữ số
    bool isMultiDigit = true;
    for (char c : word) {
        if (!isdigit(c)) {
            isMultiDigit = false;
            break;
        }
    }
    if (isMultiDigit && word.length() > 1) {
        result += word; // Giữ nguyên số có nhiều chữ số
        return;
    }
    
    // Thứ nhất: Kiểm tra từ khóa C++
    auto it = cppKeywords.find(word);
    if (it != cppKeywords.end()) {
        result += it->second;
    }
    // Thứ hai: Kiểm tra ký tự đặc biệt và toán tử kép
    else {
        auto it = specialChars.find(word);
        if (it != specialChars.end()) {
            result += it->second;
        }
        // Thứ ba và thứ tư: Chuyển đổi từng ký tự trong từ
        else {
            for (char c : word) {
                if (isdigit(c)) {
                    result += numbers.at(c);
                }
                else if (isalpha(c)) {
                    result += letters.at(c);
                }
                else {
                    result += c;
                }
            }
        }
    }
}

int main() {
    string inputFile;
    cout << "Nhập tên file cần chuyển đổi: ";
    getline(cin, inputFile);

    string content = readFile(inputFile);
    if (content.empty()) {
        cout << "Không thể đọc file!" << endl;
        return 1;
    }

    // Giữ nguyên dòng #include "uia.h" nếu có
    string includeLine = "#include \"uia.h\"";
    
    // Chuyển đổi nội dung
    string converted = convertToUIA(content);
    
    // Tạo tên file output
    string outputFile = inputFile.substr(0, inputFile.find_last_of('.')) + ".uia";
    
    // Ghi file với #include "uia.h" ở đầu nếu có
    ofstream outFile(outputFile);
        // outFile << includeLine << "\n\n";
    outFile << converted;
    outFile.close();

    cout << "Đã chuyển đổi thành công! File mới: " << outputFile << endl;
    return 0;
}
