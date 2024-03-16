#include <vector>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <algorithm>
#include <set>

auto fun1(int& a) ->void ;

auto main() -> int {
    auto vec = std::vector<int>{1, 2, 3};
    fmt::println("{}", vec);
    fmt::println("@{}#", fmt::join(vec, " "));
    fmt::println("{} and {}", vec, vec);
    fmt::println("{0} and {0}", vec);

    auto vec2 = std::vector<int>{2,4,3,1,2,3,4,5,1};
    //std::ranges::sort(vec2);
    //[x,y)
    //std::ranges::sort(vec2.begin(),vec2.end());
    std::ranges::sort(vec2.begin(),vec2.begin() + 5);
    fmt::println("{}", vec2);
    vec2.erase(vec2.begin() + 4);
    fmt::println("{}", vec2);
    //[x,y)
    vec2.erase(vec2.begin(), vec2.begin() + 2);
    fmt::println("{}", vec2);

    auto set1 = std::set<int>(); // posortowane unikalne wartosci
    set1.insert(2);
    set1.insert(1);
    set1.insert(2);
    set1.insert(4);
    set1.insert(3);
    set1.insert(3);
    fmt::println("{}", set1);
    auto vec3 = std::vector<int>{2,4,3,1,2,3,4,5,1};
    auto set2 = std::set(vec3.begin(),vec3.end());
    fmt::println("{}", set2);
    fmt::println("[{}]", fmt::join(set2, ", "));
    vec3 = std::vector(set2.begin(), set2.end());
    fmt::println("{}", vec3);

    auto b = 7;
    fun1(b);
    fmt::println("{}", b);
}