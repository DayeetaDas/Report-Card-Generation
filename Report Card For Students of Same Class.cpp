#include "pch.h"
#include<iostream>
#include<string>
#include<stdio.h>
#include<conio.h>
using namespace std;
int i = 0, j = 0;
struct Student
{
	int roll[3];
	string name[3];
	int cl[3];
	int maths[3];
	int eng[3];
	int sc[3];
	int sum = 0;
	double avg;
};
Student s1;
int temp;
string temp1;
void take_input()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the roll no:";
		cin >> s1.roll[i];
		while (!cin >> s1.roll[i])
		{
			cout << "Enter the roll no:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> s1.roll[i];
		}
		cout << "Enter the name:";
		cin >> s1.name[i];
		cout << "Enter the class:";
		cin >> s1.cl[i];
		while (s1.cl[i] > 12 || s1.cl[i] < 1 || (!cin>>s1.cl[i]))
		{
			cout << "Enter the class:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> s1.cl[i];
		}
		cout << "Enter the marks in Maths:";
		cin >> s1.maths[i];
		while (s1.maths[i] > 100 || s1.maths[i] < 0 || (!cin >> s1.maths[i]))
		{
			cout << "Enter the marks in Maths:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> s1.maths[i];
		}
		cout << "Enter the marks in English:";
		cin >> s1.eng[i];
		while (s1.eng[i] > 100 || s1.eng[i] < 0 || (!cin >> s1.eng[i]))
		{
			cout << "Enter the marks in English:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> s1.eng[i];
		}
		cout << "Enter the marks in Science:";
		cin >> s1.sc[i];
		while (s1.sc[i] > 100 || s1.sc[i] < 0 || (!cin >> s1.sc[i]))
		{
			cout << "Enter the marks in Science:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> s1.sc[i];
		}
	}
}
void display()
{
	cout << "Roll:\t\tName:\t\tMaths:\t\tEnglish:\t\tScience:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << s1.roll[i] << "\t\t" << s1.name[i] << "\t\t" << s1.maths[i] << "\t\t" << s1.eng[i] << "\t\t\t" << s1.sc[i] << endl;
	}
}
void sort_highest()
{
	cout << "The marks sorted out from the highest rank is as follows:" << endl;
	cout << "Maths:\t\t Name:" << endl;
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 2; j++)
		{
			if (s1.maths[j] <= s1.maths[j + 1])
			{
				temp = s1.maths[j];
				temp1 = s1.name[j];
				s1.maths[j] = s1.maths[j + 1];
				s1.name[j] = s1.name[j + 1];
				s1.maths[j + 1] = temp;
				s1.name[j + 1] = temp1;
			}
		}
		cout << s1.name[i] << "\t\t" << s1.maths[i] << endl;
	}
	cout << "English:\t\tName:" << endl;
	for ( i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (s1.eng[j] <= s1.eng[j + 1])
			{
				temp = s1.eng[j];
				temp1 = s1.name[j];
				s1.eng[j] = s1.eng[j + 1];
				s1.name[j] = s1.name[j + 1];
				s1.eng[j + 1] = temp;
				s1.name[j + 1] = temp1;
			}
		}
		cout << s1.name[i] << "\t\t\t" << s1.eng[i] << endl;
	}
	cout << "Science:\t\tName:" << endl;
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 2; j++)
		{
			if (s1.sc[j] <= s1.sc[j + 1])
			{
				temp = s1.sc[j];
				temp1 = s1.name[j];
				s1.sc[j] = s1.sc[j + 1];
				s1.name[j] = s1.name[j + 1];
				s1.sc[j + 1] = temp;
				s1.name[j + 1] = temp1;
			}
		}
		cout << s1.name[i] << "\t\t\t" << s1.sc[i] << endl;
	}
}
void sort_lowest()
{
	cout << "The marks sorted out from the lowest rank is as follows:" << endl;
	cout << "Maths:\t\t\tName:" << endl;
	for ( i = 0; i < 3; i++)
	{
		for ( j = i + 1; j < 3; j++)
		{
			if (s1.maths[i] >= s1.maths[j])
			{
				temp = s1.maths[i];
				temp1 = s1.name[i];
				s1.maths[i] = s1.maths[j];
				s1.name[i] = s1.name[j];
				s1.maths[j] = temp;
				s1.name[j] = temp1;
			}
		}
		cout << s1.name[i] << "\t\t\t" << s1.maths[i] << endl;
	}
	cout << "English:\t\tName:" << endl;
	for ( i = 0; i < 3; i++)
	{
		for ( j = i + 1; j < 3; j++)
		{
			if (s1.eng[i] >= s1.eng[j])
			{
				temp = s1.maths[i];
				temp1 = s1.name[i];
				s1.eng[i] = s1.eng[j];
				s1.name[i] = s1.name[j];
				s1.eng[j] = temp;
				s1.name[j] = temp1;
			}
		}
		cout << s1.name[i] << "\t\t\t" << s1.eng[i] << endl;
	}
	cout << "Science:\t\tName:" << endl;
	for ( i = 0; i < 3; i++)
	{
		for ( j = i + 1; j <3; j++)
		{
			if (s1.sc[i] >= s1.sc[j])
			{
				temp = s1.sc[i];
				temp1 = s1.name[i];
				s1.sc[i] = s1.sc[j];
				s1.name[i] = s1.name[j];
				s1.sc[j] = temp;
				s1.name[j] = temp1;
			}
		}
		cout << s1.name[i] << "\t\t\t" << s1.sc[i] << endl;
	}
}
int main()
{
	take_input();
	display();
	sort_highest();
	sort_lowest();
	return 0;
}
