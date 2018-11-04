#include <map>
#include <vector>
#include <iostream>
#include "../if-contains.h"

int main()
{
    std::map<int,char> map{{1,2},{3,4}};
    std::vector<size_t> vec{5,6,7};

    if(map contains 1)
    {
        std::cout << "map contains 1\n";
    }
    if(not (vec contains 4))
    {
        std::cout << "vec does not contain 4\n";
    }
    return 0;
}
