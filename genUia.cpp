#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

// Hàm kiểm tra xem từ có hợp lệ không
bool isValidWord(const string& word) {
    // Kiểm tra ký tự đầu tiên
    char firstChar = word[0];
    if (firstChar != 'A' && firstChar != 'I' && firstChar != 'U' &&
        firstChar != 'a' && firstChar != 'u' && firstChar != 'i') {
        return false;
    }

    // Kiểm tra các ký tự còn lại
    for (size_t i = 1; i < word.length(); i++) {
        char c = word[i];
        // Kiểm tra ký tự cuối không được là dấu cách
        if (i == word.length() - 1 && c == ' ') {
            return false;
        }
        // Kiểm tra không có 2 dấu cách liên tiếp
        if (c == ' ' && word[i-1] == ' ') {
            return false;
        }

        // Kiểm tra ký tự hợp lệ dựa trên vị trí
        if (i > 0 && word[i-1] == ' ') {
            // Sau dấu cách: được dùng A, I, U, a, i, u
            if (c != 'A' && c != 'I' && c != 'U' && 
                c != 'a' && c != 'i' && c != 'u' && c != ' ') {
                return false;
            }
        } else {
            // Các vị trí khác: chỉ được dùng a, i, u và dấu cách
            if (c != 'a' && c != 'i' && c != 'u' && c != ' ') {
                return false;
            }
        }
    }
    return true;
}

// Hàm đệ quy để sinh các ký tự
void generateRecursive(string& word, int pos, int n, const vector<char>& otherChars, ofstream& outFile) {
    if (pos == n) {
        if (isValidWord(word)) {
            outFile << word << endl;
        }
        return;
    }
    
    for (char c : otherChars) {
        word[pos] = c;
        generateRecursive(word, pos + 1, n, otherChars, outFile);
    }
}

// Hàm sinh từ theo phương pháp nhị phân
void generateWords(int n, ofstream& outFile) {
    // Tạo vector chứa tất cả các ký tự có thể dùng
    vector<char> firstChars = {'A', 'I', 'U', 'a', 'u', 'i'};
    vector<char> otherChars = {'a', 'u', 'i', ' ', 'A', 'I', 'U'};
    
    // Sinh tất cả các tổ hợp có thể
    string word(n, ' ');  // Khởi tạo từ với độ dài n
    
    // Duyệt qua tất cả các ký tự có thể cho vị trí đầu tiên
    for (char first : firstChars) {
        word[0] = first;
        generateRecursive(word, 1, n, otherChars, outFile);
    }
}

int main() {
    const int n = 4;  // Độ dài mặc định của từ
    ofstream outFile("uia.txt");
    
    if (!outFile.is_open()) {
        cout << "Không thể mở file uia.txt" << endl;
        return 1;
    }
    
    for (int i = 1; i <= n; i++)
    {
        generateWords(i, outFile);
    }
    
    outFile.close();
    
    cout << "Đã sinh xong các từ và lưu vào file uia.txt" << endl;
    return 0;
}
