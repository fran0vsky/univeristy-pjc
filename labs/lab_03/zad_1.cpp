#include <algorithm>
#include <vector>
#include <fmt/ranges.h>
#include <fmt/core.h>

auto isPositive(int a) -> bool;

auto main() -> int {
    auto numbers = std::vector<int>{-2, 4, 6, 5, 1, -4, 2};
    auto iter = std::ranges::find(numbers,
                                  4);// find pozwala nam znalezc element o konkretnej wartości, zwraca iterator do tego elementu
    fmt::println("{}", *iter); // pobranie wartości
    fmt::println("{}", *numbers.end());

    //poprawne zabezpieczenie
    iter = std::ranges::find(numbers,
                             8); // jeżeli takiego elementu nie ma zostanie zwrócony iterator do pierwszego elementu poza zakresem (.end())
    if (iter != numbers.end()) {
        fmt::println("{}", *iter);
    } else {
        fmt::println("No such element");
    }


    //min max
    auto maxNumber = std::ranges::max(numbers);//wartosc
    auto maxIter = std::ranges::max_element(numbers); //iterator
    auto minNumber = std::ranges::min(numbers);//wartość
    auto minIter = std::ranges::min_element(numbers); //iterator

    fmt::println(
            "min: {}\nmax: {}\nminElementIter: {}\nmaxElementIter: {}",
            minNumber, maxNumber, *minIter, *maxIter
    );

    auto vec = std::vector<int>{3, 4, 5, 2, 7, 8, 11, 5, 3, 8};
    auto it = vec.end() - 3;
    std::ranges::swap(*(vec.begin() + 3), *it);
    fmt::println("swap 1 {}", vec);
    std::ranges::iter_swap(vec.begin() + 5, it); //zwróć uwagę co będzie podmienione
    fmt::println("swap 2 {}", vec);

    //sortowanie
    auto strVec = std::vector<std::string>{"ala", "ma", "kota", "!"};
    std::ranges::sort(strVec, std::ranges::less());//ASC
    fmt::println("sorted ascending  {}", strVec);
    std::ranges::sort(strVec, std::ranges::greater()); //DES
    fmt::println("sorted {}", strVec);
    //sortujemy po dlugosci
    //kolekjca , komparator, projekcja
    std::ranges::sort(strVec, std::ranges::greater(), std::ranges::size);
    fmt::println("sorted by size {}", strVec);
    //dodanie domyslnego komparatora
    std::ranges::sort(strVec, {}, std::ranges::size); // DOMYŚLNA WARTOŚĆ FUNKCJI
    fmt::println("sorted by size {}", strVec);

    //komparator -  to narzędzie, które pozwala sterować zasadą porządkowania elementów w algorytmach . przyjmuje dwa parametry i zwraca bool zwraca true gdy pierwszy element powinien być po lewej stronie
    //projekcja - pozwala na patrzenie na obiekt przez inny pryzmat — przez inną cechę. przyjmuje jeden element i zwraca go w oczekiwanej przez nas formie (innym typie)
    //predykat -  to funkcja, która coś testuje. Przyjmuje pojedynczy argument i zwraca true jeżeli spełnia on jakiś warunek.

    //Tworzenie wlasnych lambd
    auto positiveNumber = std::ranges::find_if(numbers, isPositive);

    if (positiveNumber != numbers.end()) {
        fmt::println(
                "The first positive number is: {}",
                *positiveNumber
        );
    } else {
        fmt::println("No positive numbers found");
    }