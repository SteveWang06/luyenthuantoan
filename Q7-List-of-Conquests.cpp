// In Act I, Leporello is telling Donna Elvira about his master’s long list of conquests:
// “This is the list of the beauties my master has loved, a list I’ve made out myself: take
// a look, read it with me. In Italy six hundred and forty, in Germany two hundred and
// thirty-one, a hundred in France, ninety-one in Turkey; but in Spain already a thousand and
// three! Among them are country girls, waiting-maids, city beauties; there are countesses,
// baronesses, marchionesses, princesses: women of every rank, of every size, of every age.”
// (Madamina, il catalogo questo)
// As Leporello records all the “beauties” Don Giovanni “loved” in chronological order, it is very
// troublesome for him to present his master’s conquest to others because he needs to count the number
// of “beauties” by their nationality each time. You are to help Leporello to count.
// Input
// The input consists of at most 2000 lines. The first line contains a number n, indicating that there will
// be n more lines. Each following line, with at most 75 characters, contains a country (the first word)
// and the name of a woman (the rest of the words in the line) Giovanni loved. You may assume that the
// name of all countries consist of only one word.
// Output
// The output consists of lines in alphabetical order. Each line starts with the name of a country, followed
// by the total number of women Giovanni loved in that country, separated by a space.
// Sample Input
// 3
// Spain Donna Elvira
// England Jane Doe
// Spain Donna Anna
// Sample Output
// England 1
// Spain 2



// Trong Hồi I, Leporello đang kể với Donna Elvira về danh sách dài những cuộc chinh phục của chủ nhân mình:
// "Đây là danh sách các người đẹp mà chủ tôi đã yêu, một danh sách do chính tôi ghi lại: hãy nhìn xem, đọc cùng tôi. Ở Ý có sáu trăm bốn mươi người, ở Đức hai trăm ba mươi mốt, một trăm ở Pháp, chín mươi mốt ở Thổ Nhĩ Kỳ; nhưng ở Tây Ban Nha đã có một ngàn lẻ ba! Trong số đó có gái quê, hầu gái, mỹ nhân thành thị; có bá tước phu nhân, nữ nam tước, hầu tước phu nhân, công chúa: phụ nữ ở mọi tầng lớp, mọi vóc dáng, mọi độ tuổi."
// (Madamina, il catalogo questo)

// Vì Leporello ghi chép tất cả các “người đẹp” mà Don Giovanni đã “yêu” theo thứ tự thời gian, nên thật phiền phức khi anh ta phải trình bày những cuộc chinh phục của chủ mình cho người khác, bởi vì anh cần phải đếm số lượng “người đẹp” theo từng quốc tịch mỗi lần. Bạn sẽ giúp Leporello đếm số lượng đó.

// Dữ liệu vào (Input)
// Dữ liệu đầu vào gồm nhiều nhất 2000 dòng. Dòng đầu tiên chứa một số nguyên n, biểu thị rằng sẽ có n dòng tiếp theo.
// Mỗi dòng tiếp theo, dài không quá 75 ký tự, chứa tên một quốc gia (từ đầu tiên) và tên một người phụ nữ (phần còn lại của dòng) mà Giovanni đã yêu.
// Bạn có thể giả sử rằng tên của tất cả các quốc gia chỉ gồm một từ.

// Dữ liệu ra (Output)
// Dữ liệu đầu ra gồm các dòng theo thứ tự chữ cái. Mỗi dòng bắt đầu với tên quốc gia, theo sau là số lượng phụ nữ mà Giovanni đã yêu ở quốc gia đó, cách nhau bởi một dấu cách.


#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    map<string, int> m;
    while (n--) {
        string s;
        getline(cin, s);
        m[s.substr(0, s.find(' '))]++;
    }
    for (auto& p : m) cout << p.first << " " << p.second << "\n";

}













