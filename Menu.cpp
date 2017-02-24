#include "Name.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <new>

int main()
{
	int choice;
	system("cls");
	cout << "1 - Add" << endl;
	cout << "2 - Record" << endl;
	cout << "3 - End" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}