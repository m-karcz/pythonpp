#include <iostream>
#include "../for-in.h"

int main()
{
    for(auto i in {1,2,3})
    {
        std::cout << i;
    }
    return 0;
}
