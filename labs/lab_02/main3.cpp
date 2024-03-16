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
