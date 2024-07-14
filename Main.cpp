#include <iostream>
#include "String.cpp"
#include "List.cpp"

int main()
{
    List<int> x;

    for (int i = 0; i < 10; i++) x.add(i);
    x.add(0);

    std::cout << x;

    return 0;
}
