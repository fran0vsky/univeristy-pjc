#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

//porownywanie wprowadzonych wartosci

auto main() -> int {
    auto liczby = std::vector<int>(10);
    std::cout << "Podaj 10 liczb: \n";
    for (auto i = 0; i < liczby.size(); i++) { //zczytywanie
        std::cin >> liczby[i];
    }
    for (auto wyswietlanie : liczby) {// wyswitlanie
        std::cout << wyswietlanie << " ";
    } std::cout << "\n";
//^tutaj można fmt::println, ale głównie robione na podstawie 1szego wykładu
    auto srodek = liczby.begin() +liczby.size()/2; //środek vectora
    std::ranges::sort(liczby.begin(), srodek);
    std::ranges::sort(srodek, liczby.end());
    for (auto showPart1 : liczby){
        std::cout << showPart1 << " ";
    }
    auto czyTakieSame = std::ranges::equal(
            liczby.begin(), srodek,
            srodek, liczby.end()
    );
    std::cout << "\n" << czyTakieSame << "\n" ;
//^nie musimy tego wyświetlać
    if (czyTakieSame == 1){
        std::cout << "Polowki sa rowne ";
    }else{
        std::cout << "Polowki nie sa rowne ";
    }

    //Porównywanie wprowadzanych wartości (druga wersja)
    auto vec1 = std::vector<int>();
    auto vec2 = std::vector<int>();

    //uzupełniamy pierwszy wektor
    std::cout << "first vector: ";
    int val;
    for (int i = 0; i < 5; ++i) {
        std::cin >> val;
        vec1.push_back(val);
    }
    //uzupełniamy drugi wektor
    std::cout << "second vector: ";
    for (int i = 0; i < 5; ++i) {
        std::cin >> val;
        vec2.push_back(val);
    }
    //oba sortujemy
    std::ranges::sort(vec1);
    std::ranges::sort(vec2);
    std::cout<<(vec1 == vec2);
}
