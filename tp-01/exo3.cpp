#include <iostream>

int add(int a, int b)
{
    return a + b;
}

void add_to(int& a, int b)
{
    a += b;
}

void another_add_to(int* a, int b)
{
    *a += b;
}

int main(int argc, char const *argv[])
{
    const int x{10};
    int y = add(x,x);
    another_add_to(&y,y);
    add_to(y,2);
    std::cout << y << std::endl;
    return 0;
}
