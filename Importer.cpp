// Assn4-Importer-RyanMatthews.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <fstream>
using namespace std;

int main()
{
	string associatedData = ", ";
	fstream my_stream;
	my_stream.open("Data-To-Read-From.txt");

	while (getline(my_stream, associatedData))
	{
		associatedData += " Associated Data";
		cout << associatedData << "\n";
	}
	my_stream.close();
}