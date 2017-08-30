#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
// in gcc 7.1 still have to use experimental namespace/headers
#include <experimental/functional>
#include <experimental/algorithm>
 
int main()
{
    std::string in = "Lorem ipsum dolor sit amet, consectetur adipiscing elit,"
                     " sed do eiusmod tempor incididunt ut labore et dolore magna aliqua";
    std::string needle = "pisci";
    auto it = std::experimental::search(in.begin(), in.end(),
                   std::experimental::boyer_moore_searcher(
                       needle.begin(), needle.end()));
    if(it != in.end())
        std::cout << "The string " << needle << " found at offset "
                  << it - in.begin() << '\n';
    else
        std::cout << "The string " << needle << " not found\n";
}