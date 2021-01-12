#include <iostream>
#include <vector>

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

int count_a_occurences(const std::string& s);

void update_loop(const float& dt, std::string& errors_out);

bool are_all_positives(const std::vector<int>& values, std::vector<int>& negative_indices_out);

std::string concatenate(const std::string& str1, const std::string& str2);

int main(int argc, char const *argv[])
{
    const int x{10};
    auto tmp = add(x,x);
    int& y = tmp;
    another_add_to(&y,y);
    add_to(y,2);
    std::cout << y << std::endl;
    return 0;
}

/*
    Question 2: 
    Le passage par valeur est juste une simple copie de la valeur des arguments, la modification ne sera que locale à l'intérieur de la méthode
    Le passage par référence renvoie une copie de l'adresse mémoire de la variable donc toute modification est répercutée dans la suite du programme
    Le passage par référence constante est la même chose que le passage par référence sauf que l'on aura juste accès en lecture à la référence
*/
