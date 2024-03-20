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


