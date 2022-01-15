// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
using namespace std;


int RomantoBase10(int romanTobase10Input)
{
	cout << "Changing number into Roman Numerals" << endl;
	int intnum, m, d, c, l, x, v, i, n;
	intnum = (int)romanTobase10Input;

	m = intnum / 1000;
	d = ((intnum % 1000) / 500);
	c = ((intnum % 500) / 100);
	l = ((intnum % 100) / 50);
	x = ((intnum % 50) / 10);
	v = ((intnum % 10) / 5);
	i = (intnum % 5);
	n = m + d + c + l + x + v + i;

	while (n > 0)
	{

		if (m > 0)
		{
			cout << "M";
			m--;
			n--;
		}

		else if (d > 0)
		{
			cout << "D";
			d--;
			n--;
		}
		else if (c > 0)
		{
			cout << "C";
			c--;
			n--;
		}
		else if (l > 0)
		{
			cout << "L";
			l--;
			n--;
		}
		else if (x > 0)
		{
			cout << "X";
			x--;
			n--;
		}
		else if (v > 0)
		{
			cout << "V";
			v--;
			n--;
		}
		else if (i > 0)
		{
			cout << "I";
			i--;
			n--;
		}
	}
	return romanTobase10Input;
}


//Function to retrun value of roman symbols
int valueOfRoman(char roman)
{
	switch (roman)
	{
	case 'I':return 1;
	case 'V':return 5;
	case 'X':return 10;
	case 'L':return 50;
	case 'C':return 100;
	case 'D':return 500;
	case 'M':return 1000;
	}
}

//Function to convert Roman Numerals to Integer
int romanToInt(string A)
{
	int i, n, ans = 0, p = 0;
	n = A.length() - 1;

	for (i = n; i >= 0; i--)
	{
		if (valueOfRoman(A[i]) >= p)
			ans = ans + valueOfRoman(A[i]);
		else
			ans = ans - valueOfRoman(A[i]);

		p = valueOfRoman(A[i]);
	}
	cout << "this is the number from roman numerals " << ans << endl;
	return ans;
}



int main()
{
	int input;
	int romanTobase10Input;
	do
	{
		cout << "\nPlease make your selection from the following" << endl;
		cout << "1. Base 10 to Roman Numeral" << endl << "2. Roman numeral to Base 10" << endl << "3. Add 2 Roman numerals" << endl << "4. Exit" << endl << endl;
		cout << "Your selection: "; cin >> input;

		if (input == 1)
		{
			cout << "You Selected 1. Base 10 to Roman Numeral" << endl;
			do
			{
				cout << "Enter a number between 1 and 9, 999" << endl;
				cout << "Your number: "; cin >> romanTobase10Input;
			} while (!romanTobase10Input > 0 && !romanTobase10Input < 10000 or cin.fail());
			RomantoBase10(romanTobase10Input); cout << endl;

		}
		else if (input == 2)
		{
			cout << "You Selected 2. Roman Numeral to Base 10" << endl;
			string s;
			int num;
			//cin >> s;
			cout << "Your selection: "; cin >> s;
			num = romanToInt(s);
		}
		else if (input == 3)
		{
			cout << "You Selected 3. Add 2 Roman Numerals" << endl << endl;

			string romNum1s;
			int romNum1;
			cout << "Input the First Roman Numeral: ";
			cin >> romNum1s;
			romNum1 = romanToInt(romNum1s);
			//cout << "Here is the result: " << romNum1 << endl;

			string romNum2s;
			int romNum2;
			cout << "Input the Second Roman Numeral: ";
			cin >> romNum2s;
			romNum2 = romanToInt(romNum2s);
			//cout << "Here is the result: " << romNum2 << endl;

			int totalRomNum = romNum1 + romNum2;
			cout << "The sum of: " << romNum1s << " + " << romNum2s << " = " << totalRomNum << endl;
			RomantoBase10(totalRomNum); cout << " = " << totalRomNum << endl;
			//cout << totalRomNum << endl;
		}
		else if (input != 4)
		{
			cout << "Invalid entry" << endl;
		}
	} while (input != 4);
	cout << "You Selected 4. Exit" << endl;
	cout << "Thank you." << endl;
	return 0;
}