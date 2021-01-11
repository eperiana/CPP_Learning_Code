#include <iostream>

int main(int argc, char const *argv[])
{
    short s0; /*On ne peut pas en déduire la valeur car elle est aléatoire*/
    int   i1 = 2;
    bool  b2{false};
    bool  b3{(bool) i1}; /* il faut caster i1 en bool*/ 
    bool* b4;
    unsigned       u5{0x10};
    unsigned short us6 = -10;
    unsigned long  ul7{b3 + u5 + us6}; /*valeur = 65543*/
    char c8{'a'}; /*il faut mettre des guillemets simples*/
    char c9 = -10;
    double  d10{(double) i1}; /*il faut caster i1 en double*/
    double* d11{&d10}; /*On ne peut pas convertir un double en double* il faut ajouter un &*/
    double& d12 = d10; /*Une référence nécessite toujours une initialisation*/
    const double d13{.0f};
    const int    i14 = i1;
    int* i15 = &i1; /*2*/
    int* i16 = (int*) b2;/*Il faut caster en int**/
    int  i17 = *i15;
    const int& i18 = i14;/*on essaye d'affecter un const à une référence que l'on pourra modifier, il faut utiliser un const-ref*/
    const int* i19{nullptr};
    const bool b20 = false; /*Il faut toujours initialiser une variable constante*/
    std::cout << ul7 << std::endl;
    return 0;
}

