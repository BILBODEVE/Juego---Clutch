#include <iostream>
#include "../includes/global.h"

using namespace std;

void separador(int tamaño, const char symbol)
{
    for (int i = 0; i < tamaño; i++)
        cout << symbol;

    cout << endl;
}