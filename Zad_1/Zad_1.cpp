// Zadanie_1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <sstream>
#include <math.h>

#define TRUE true
#define FALSE false
//bo dużymi literami jest ładniej

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

double convert_symbol_to_zeros(string symbol)
{
	if		(symbol == "M")		return  6;
	else if (symbol == "B")		return  9;
	else if (symbol == "T")		return 12;
	else if (symbol == "Qa")	return 15;
	else if (symbol == "Qi")	return 18;
	else if (symbol == "Sx")	return 21;
	else if (symbol == "Sp")	return 24;
	else if (symbol == "Oc")	return 27;
	else						return  0;
}

int get_dot_pos(string input)
{
	size_t index = input.find('.');
	return static_cast<int>(index);
}

int get_fraction_part_len(string input, int dot_pos)
{
	if (dot_pos == -1) return -1;
	return (static_cast<int>(input.length()) - (dot_pos + 1));
}

string ConvertFromSymbolic(string str)
{
	string number_part;
	string symbol_part;

	bool more_digits = TRUE;

	for (int i = 0; i < str.length(); i++)
	{

		if (isdigit(str[i]) && more_digits)
		{
			number_part += str[i];
		}
		else
		{
			if (i != 0)
			{
				if (str[i] == '.' && more_digits)
				{
					number_part += str[i];
				}
				else
				{
					symbol_part += str[i];
					more_digits = FALSE;
				}

			}
		}
	}

	double number = stod(number_part);
	int zeros = static_cast<int>(convert_symbol_to_zeros(symbol_part));
	int dot_pos = get_dot_pos(str);

	string output = "";

	if (dot_pos > -1)
	{

	}

	for (int i = zeros; i > 0; i--)
	{

	}

	return "";
}

int main()
{
	cout << (ConvertFromSymbolic("4M")) << endl;
	cout << (ConvertFromSymbolic("54T")) << endl;
	cout << (ConvertFromSymbolic("5.434B")) << endl;
	cout << (ConvertFromSymbolic("84340000Oc")) << endl;
	cout << (ConvertFromSymbolic("943400000Oc")) << endl;
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