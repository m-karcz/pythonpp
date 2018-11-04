#include <map>
#include <vector>
#include <iostream>
#include "../if-in.h"

int main()
{
    std::map<int,char> map{{1,2},{3,4}};
    std::vector<size_t> vec{5,6,7};

    if(1 in map)
    {
        std::cout << "map contains 1\n";
    }
    if(not (4 in vec))
    {
        std::cout << "vec does not contain 4\n";
    }
    return 0;
}
