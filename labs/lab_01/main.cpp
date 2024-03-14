#include <iostream>
#include <vector>
#include <string>

auto boxPrint(std::vector<std::string> vec, char frame = '*') -> void {
//najpierw musimy znajeźć najdłuższe dłowo , od niego będzie zależeć kształt
    int maxSize = 0;
    for (auto str: vec) {
        if (str.size() > maxSize) {
            maxSize = str.size();
        }
    }
//wyświetlenie pierwszej linii
    for (int i = 0;i < maxSize + 2; ++i) {
        std::cout <<frame;
    }
    std::cout << "\n";
// przechodzimy do wyświetlenia zawartości wektora
    for (auto str: vec) {
        std::cout << frame << str;
        for (int i = str.size();i < maxSize;++i) { //ilość spacji
            std::cout << " ";
        }
        std::cout << frame << "\n";
    }
// Wyświetlenie ostatniego wiersza (drugi sposób)
    std::cout <<std::string(maxSize+ 2, frame) << "\n\n";
}

auto main() -> int {
    boxPrint({"a", "quick", "brown", "fox"});
    boxPrint({"a", "quick", "brown", "fox"}, '*');
    boxPrint({"a", "quick", "brown", "fox"}, '#');
    boxPrint(std::vector<std::string>{"a", "quick", "brown", "fox"}, '#');
    boxPrint({""});
    boxPrint({});
    boxPrint({}, '#');
    boxPrint({"", "hmmmm", ""});
    boxPrint({"", "", ""});
    return 0;
}
