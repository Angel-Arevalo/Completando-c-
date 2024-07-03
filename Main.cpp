#include <iostream>
#include "String.cpp"

int main()
{
    String x = "HELLO";
    String y("hello");
    x += y;
    x += " s;";
    std::cout <<( x + ' '+ x)<< std::endl;
    return 0;
}
