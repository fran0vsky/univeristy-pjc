#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

//suma dwoch liczb

auto sumOfTwo(std::vector<int> vec, int val) -> bool {
    //zmienne potrzebne do śledzenia wynikowych indeksów
    int left = 0;
    int right = vec.size() - 1;
    while (left < right) { // waruek, szukamy do momentu aż indeksy się przetną
        int sum = vec[left] + vec[right];
        if (sum == val) { //sprawdzamy czy już osiągneliśmy naszą poszukiwaną wartośc
            std::cout << "Indices: " << left << " " << right << std::endl;
            return true;
        } else if (sum < val) left++; // jedynym sposobem na zwiększenie wartości jest przesunięcie lewego indeksu w prawo (korzystamy z tego że wartości w wektorze są posortowane)
        else right--; // dla zmniejszenia sumy przesówamy prawy index w lewo
    }
    return false;
}
auto main() -> int {
    //suma dwóch cyfr
    auto vec = std::vector<int>{1,2,3,4,5,6};
    std::ranges::sort(vec); //sortowanie wektora
    sumOfTwo(vec,9);
}