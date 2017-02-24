#include "Name.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <new>

using namespace std;

int Menu();
void Read();
void Write();
void dynamicMemory();

int cnt = 1;
int i = 0;
Name* arr = new Name[cnt];

void main()
{
	string name;
	string surname;
	string secondName;
	int age;

	ifstream fin("Text.txt");
	try										//is file exist?
	{
		if (!fin) throw 10;
	}
	catch (int a)
	{
		cout << "Error!" << endl;
		cout << "No file" << endl;
	}

	try										//is file open?
	{
		if (fin.fail()) throw 10;
	}
	catch (int a)
	{
		cout << "Error!" << endl;
		cout << "Can not open file!" << endl;
	}

	while (fin >> name >> surname >> secondName >> age)
	{
		dynamicMemory();
		arr[i] = Name(name, surname, secondName, age);
		i++;
	}
	fin.close();

	for (int j = 0; j < i; j++)
	{
		arr[j].windowPrint();
	}
	system("pause");

	bool b = true;
	while (b){
		int choice = Menu();
		switch (choice){
		case 1:{
				   system("cls");
				   string name;
				   string surname;
				   string secondName;
				   int age;
				   fflush(stdin);
				   cout << "Name: ";
				   getline(cin, name);
				   cout << "Surname: ";
				   getline(cin, surname);
				   cout << "Second Name: ";
				   getline(cin, secondName);
				   cout << "Age: ";
				   cin >> age;

				   dynamicMemory();
				   arr[i] = Name(name, surname, secondName, age);
				   i++;
				   break;
		}

		case 2:{
				   system("cls");
				   try								//write inform into the file?
				   {
					   if (i == 0) throw 10;
				   }
				   catch (int a)
				   {
					   system("cls");
					   cout << "Error!" << endl;
					   cout << "You can not write information into the file!" << endl;
				   }
				   int cnt = 0;
				   try									//is memory enough?
				   {
					   if (i >= 100000) throw 10;
					   remove("Text.txt");
					   for (int j = 0; j < i; j++)
						   arr[j].filePrint();
				   }
				   catch (int a)
				   {
					   system("cls");
					   cout << "Error!" << endl;
					   cout << "The file size limit is exceeded" << endl;
				   }

				   system("pause");
				   break;
		}
		case 3:{
				   b = false;
				   break;
		}
		}
	}
}

int Menu(){
	int choice;
	system("cls");
	cout << "1 - Add" << endl;
	cout << "2 - Record" << endl;
	cout << "3 - End" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	return choice;
}

void dynamicMemory()
{
	if (i == cnt)
	{
		cnt *= 2;
		bad_alloc exept;
		Name* tmp;
		try															//new exeption
		{
			if (!(tmp = new Name[cnt])) throw exept;
		}
		catch (bad_alloc exept)
		{
			system("cls");
			cout << "Dynamic Memory Error! " << exept.what()<<endl;
		}
		tmp = new Name[cnt];
		for (int j = 0; j < i; j++)
			tmp[j] = Name(arr[j]);
		delete[] arr;
		arr = tmp;
	}
}