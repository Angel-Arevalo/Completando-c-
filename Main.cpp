#include <iostream>
#include "String.cpp"

int main()
{
    String x = toLowerCase("HELLO");
    String y(x);
    String m = x + y + " my name is Angel ";
    m += 'w';
    std::cout <<(m.toUpperCase())<< std::endl;
    return 0;
}
