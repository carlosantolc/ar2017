/*Archivo donde se generarán las pruebas necesarias según:
	Número de casos: S
	Tamaño de las cadenas: N
	Tamaño de la subcadena: M
	Creando dos arrays de tamaño N y una cifra M, S veces
*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

static const char alfabeto[] =
"abcdefghijklmnopqrstuvwxyz";

char genRandom()
{
    return alfabeto[rand() % (sizeof(alfabeto) - 1)];
}

int main(int argc, char const *argv[]) {

	cout << "4000" << endl;

	for (int n = 5; n <=100; n=n+5)
	{
		for (int m = 5; m <= 100; m=m+5)
		{
			for (int j = 0; j < 10; ++j)
			{				
				cout << n << " " << m << endl;

			}
		}
	}
	return 0;
}