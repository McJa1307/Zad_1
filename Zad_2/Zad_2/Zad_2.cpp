// Zada_2.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.
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
//bo du¿ymi literami jest ³adniej

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
	if (symbol == "M")		return  6;
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

	int zeros = convert_symbol_to_zeros(symbol_part);
	int dot_pos = get_dot_pos(number_part);
	int fraction_part_len = get_fraction_part_len(number_part, dot_pos);

	string output = "";

	if (fraction_part_len > 0)
	{
		if (zeros >= fraction_part_len)
		{
			output = number_part.erase(dot_pos, 1);
			zeros -= fraction_part_len;
		}
		else
		{
			output = number_part.erase(dot_pos, 1).insert(dot_pos + zeros, ".");
			zeros = 0;
		}
	}
	else if (fraction_part_len == 0)
	{
		output = number_part.erase(dot_pos, 1);
	}
	else
	{
		output = number_part;
	}

	for (int i = zeros; i > 0; i--)
	{
		output += "0";
	}

	return output;
}

int main()
{
	cout << (ConvertFromSymbolic("4.2222222M")) << endl;
	cout << (ConvertFromSymbolic("4.222222222222M")) << endl;
	cout << (ConvertFromSymbolic("4.222222M")) << endl;
	cout << (ConvertFromSymbolic("4.222M")) << endl;
	cout << (ConvertFromSymbolic("4M")) << endl;
	cout << (ConvertFromSymbolic("54T")) << endl;
	cout << (ConvertFromSymbolic("5.434B")) << endl;
	cout << (ConvertFromSymbolic("1Oc")) << endl;
	cout << (ConvertFromSymbolic("84340000Oc")) << endl;
	cout << (ConvertFromSymbolic("943400000Oc")) << endl;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotycz¹ce rozpoczynania pracy:
//   1. U¿yj okna Eksploratora rozwi¹zañ, aby dodaæ pliki i zarz¹dzaæ nimi
//   2. U¿yj okna programu Team Explorer, aby nawi¹zaæ po³¹czenie z kontrol¹ Ÿród³a
//   3. U¿yj okna Dane wyjœciowe, aby sprawdziæ dane wyjœciowe kompilacji i inne komunikaty
//   4. U¿yj okna Lista b³êdów, aby zobaczyæ b³êdy
//   5. Wybierz pozycjê Projekt > Dodaj nowy element, aby utworzyæ nowe pliki kodu, lub wybierz pozycjê Projekt > Dodaj istniej¹cy element, aby dodaæ istniej¹ce pliku kodu do projektu
//   6. Aby w przysz³oœci ponownie otworzyæ ten projekt, przejdŸ do pozycji Plik > Otwórz > Projekt i wybierz plik sln