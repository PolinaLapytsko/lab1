#include "Name.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;

Name::Name()
{
	name = "";
	surname = "";
	secondName = "";
	age = 0;
}

Name::Name(const string& name,
	const string& surname,
	const string& secondName,
	const int& age) : name(name), surname(surname), secondName(secondName), age(age) 
{}

Name::~Name()
{}

void Name::filePrint() const
{
	ofstream out;
	out.open("Text.txt",ios::app);
	if (!out){
		cout << "Cannot open file";
	}
	out << name << ' ';
	out << surname << ' ';
	out << secondName << ' ';
	out << age;
	out << endl;
	out.close();
}

void Name::windowPrint() const
{
	cout << name << ' ';
	cout << surname << ' ';
	cout << secondName << ' ';
	cout << age;
	cout << endl;
}

