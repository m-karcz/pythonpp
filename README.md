# pythonpp
Write cpp programs in python style

Main goal of this header lib is to introduce new 'keywords' to make code more simply to read with minimal overhead.

However, due to macros usage, _pythonpp.h_ should be last include on list(ex. possible clash 'keyword' _in_ with _std::ios::in_).

Example:

```cpp
#include <map>
#include <cstdio>
#include "pythonpp.h"

int main()
{
    std::map<int, bool> dict{{1,true},{3,false}};
    if(dict contains 3)  //<-- here new 'keyword' contains
    {
        puts("dict contains 3");
    }
    else
    {
        puts("dict does not contain 3");
    }
    return 0;
}
