// Zadanie_1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <sstream>
#include <math.h>

using namespace std;

double ipow(double base, int exp)
{
	double result = 1ULL;
	while (exp)
	{
		if (exp & 1)
		{
			result *= (double)base;
		}
		exp >>= 1;
		base *= base;
	}
	return result;
}

string ConvertFromSymbolic(string str)
{
	string str1;
	string str2;
	string output;

	bool more_digits = false;

	for (int i = 0; i < str.length(); i++)
	{

		if (isdigit(str[i]) && !more_digits)
		{
			str1 += str[i];
		}
		else
		{
			if (i != 0)
			{
				if (str[i] == '.' && !more_digits)
				{
					str1 += str[i];
				}
				else
				{
					str2 += str[i];
					more_digits = true;
				}

			}
		}
	}

	double int1 = stod(str1);


	if (str2 == "M")
	{
		output = to_string((double)(int1 * ipow(10, 6)));
		return output;
	}
	else if (str2 == "B")
	{
		output = to_string((double)(int1 * ipow(10, 9)));
		return output;
	}
	else if (str2 == "T")
	{
		output = to_string((double)(int1 * ipow(10, 12)));
		return output;
	}
	else if (str2 == "Qa")
	{
		output = to_string((double)(int1 * ipow(10, 12))) + to_string(ipow(10, 3)).erase(0, 1);
		return output;
	}
	else if (str2 == "Qi")
	{
		output = to_string((double)(int1 * ipow(10, 12))) + to_string(ipow(10, 6)).erase(0, 1);
		return output;
	}
	else if (str2 == "Sx")
	{
		output = to_string((double)(int1 * ipow(10, 12))) + to_string(ipow(10, 9)).erase(0, 1);
		return output;
	}
	else if (str2 == "Sp")
	{
		output = to_string((double)(int1 * ipow(10, 12))) + to_string(ipow(10, 12)).erase(0, 1);
		return output;
	}
	else if (str2 == "Oc")
	{
		output = to_string((double)(int1 * ipow(10, 12))) + to_string(ipow(10, 16)).erase(0, 1);
		return output;
	}
	else
	{
		return 0;
	}

}

int main()
{
	cout << (ConvertFromSymbolic("4M")) << endl;
	cout << (ConvertFromSymbolic("54T")) << endl;
	cout << (ConvertFromSymbolic("5.434B")) << endl;
	cout << (ConvertFromSymbolic("84340000Oc")) << endl;
	cout << (ConvertFromSymbolic("943400000Oc")) << endl;



	return 1;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln