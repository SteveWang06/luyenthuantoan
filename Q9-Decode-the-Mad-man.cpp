// Once in BUET, an old professor had gone completely mad. He started talking with some peculiar
// words. Nobody could realize his speech and lectures. Finally the BUET authority fall in great trouble.
// There was no way left to keep that man working in university. Suddenly a student (definitely he was
// a registered author at UVA ACM Chapter and hold a good rank on 24 hour-Online Judge) created
// a program that was able to decode that professor’s speech. After his invention, everyone got comfort
// again and that old teacher started his everyday works as before.
// So, if you ever visit BUET and see a teacher talking with a microphone, which is connected to a
// IBM computer equipped with a voice recognition software and students are taking their lecture from
// the computer screen, don’t get thundered! Because now your job is to write the same program which
// can decode that mad teacher’s speech!
// Input
// The input file will contain only one test case i.e. the encoded message.
// The test case consists of one or more words.
// Output
// For the given test case, print a line containing the decoded words. However, it is not so hard task to
// replace each letter or punctuation symbol by the two immediately to its left alphabet on your standard
// keyboard.
// Sample Input
// k[r dyt I[o
// Sample Output
// how are you



#include <iostream>
#include <string>
using namespace std;

int main() {
    string encodedMessage;
    string keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"; // Bàn phím chuẩn QWERTY
    getline(cin, encodedMessage); // Đọc toàn bộ dòng đầu vào

    string decodedMessage = "";

    for (char c : encodedMessage) {
        if (c == ' ') {
            decodedMessage += ' '; // Giữ nguyên khoảng trắng
        } else {
            // Tìm vị trí của ký tự trên bàn phím và thay thế bằng ký tự cách 2 vị trí bên trái
            size_t pos = keyboard.find(tolower(c));
            if (pos != string::npos && pos >= 2) {
                decodedMessage += keyboard[pos - 2];
            }
        }
    }

    cout << decodedMessage << endl; // Xuất thông điệp đã giải mã
    return 0;
}



