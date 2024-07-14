#include <iostream>
#include "String.cpp"
#include "List.cpp"

int main()
{
    List<int> x;
    List<String> w;
    w.add("Hello");
    w.add("world");

    for (int i = 10; i < 20; i++) x.add(i);

    List<int> y = x;
    y.remove(5);
    y.remove(4);

    std::cout << x;
    std::cout << y;
    std::cout << w;

    return 0;
}
