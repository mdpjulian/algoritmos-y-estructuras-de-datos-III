#include <iostream>
#include "./String.hpp"

void TestOCFString(String s2)
{
   std::cout << s2 << std::endl;
}

int main()
{
    String s1("Hola Mundo");
    String s2 = s1;
    String vec[10];

    TestOCFString(s2); //Esta función muestra el contenido de s2 por pantalla con cout

    return 0;
}