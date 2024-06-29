#include <iostream>
#include "String.cpp"

int main()
{
    String x("HELLO");
    String y("WORLD");
    std::cout << x.getlength() << "\n\n";
    std::cout << x << "\n\n";
    std::cout << y.getlength() << "\n\n";
    std::cout << y << "\n\n";
    x += "world";
    std::cout << x.getlength() << "\n\n";
    std::cout << x.toLowerCase() << "\n\n";
    return 0;
}
