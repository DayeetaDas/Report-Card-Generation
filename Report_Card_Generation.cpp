/*Generates a report card for a student*/
#include "pch.h"//the necessary header files are included
#include<iostream>
#include<string>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct Student//data structure with the attributes a student can have is declared
{
	int roll;
	int cl;
	string name;
	string sub[3];
	int marks[3];
};
string temp1;//necessary identifiers are declared
int temp;
int add;
Student s1;
int sum = 0; double avg;
void take_input()//the details of the student is taken as input
{
	cout << "Enter the roll no:";
	cin >> s1.roll;
	while (!cin >> s1.roll)
	{
		cout << "Enter the roll no:";
		cin >> s1.roll;
	}
	cout << "Enter the class:";
	cin >> s1.cl;
	while (s1.cl > 12 || s1.cl < 1 || (!cin >> s1.cl))
	{
		cout << "Enter the class:";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> s1.cl;
	}
	cout << "Enter the name:";
	cin >> s1.name;
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the name of the subject:";
		cin >> s1.sub[i];
		cout << "Enter the marks:";
		cin >> s1.marks[i];
		while (s1.marks[i]>100 || s1.marks[i]<0||(!cin>>s1.marks[i]))
		{
			cout << "Enter the marks:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> s1.marks[i];
		}
	}
}
void display()//the details of the student are displayed
{
	cout << "Roll No:" << s1.roll << endl;
	cout << "Name:" << s1.name << endl;
	cout << "Class:" << s1.cl << endl;
	cout << "Subjects:\t Marks:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << s1.sub[i] << "\t\t " << s1.marks[i] << endl;
	}
}
void avg_per()//the average and average percentage are displayed
{
	for (int i = 0; i < 3; i++)
	{
		sum += s1.marks[i];
	}
	avg = sum / 3;
	cout << "The average marks of the student is:" << avg << endl;
	cout << "The total percentage obtained is :" << avg <<"%"<< endl;
}
void highest()//the highest marks along with the subject name is displayed
{
	for (int i = 0; i < 3; i++)
	{
		if (temp <= s1.marks[i])
		{
			temp = s1.marks[i];
			add = i;
		}
	}
	cout << "The highest score is " << temp << " in " << s1.sub[add] << endl;
}
void lowest()//the lowest marks along with the subject name is displayed
{
	for (int i = 0; i < 3; i++)
	{
		if (temp >= s1.marks[i])
		{
			temp = s1.marks[i];
			add = i;
		}
	}
	cout << "The lowest score is " << temp << " in " << s1.sub[add] << endl;
}
void sort_highest()//the marksheet is sorted in the decending order
{
	cout << "The marks sorted out in descending order:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (s1.marks[j] <= s1.marks[j + 1])
			{
				temp = s1.marks[j];
				temp1 = s1.sub[j];
				s1.marks[j] = s1.marks[j + 1];
				s1.sub[j] = s1.sub[j + 1];
				s1.marks[j + 1] = temp;
				s1.sub[j + 1] = temp1;
			}
		}
		cout << s1.sub[i] << " " << s1.marks[i] << endl;
	}
}
void sort_lowest()//the marksheet is sorted in ascending order
{
	cout << "The marks sorted out in ascending order:" << endl;
	for (int i=0; i<3; i++)
	{
		for (int j=i+1; j<3; j++)
		{
			if (s1.marks[j+1] <= s1.marks[j])
			{
				temp = s1.marks[i];
				temp1 = s1.sub[i];
				s1.marks[i] = s1.marks[j];
				s1.sub[i] = s1.sub[j];
				s1.marks[j] = temp;
				s1.sub[j] = temp1;
			}
		}
		cout << s1.sub[i] << " " << s1.marks[i] << endl;
	}
}
int main()//start of main
{
	take_input();
	display();
	avg_per();
	highest();
	lowest();
	sort_highest();
	sort_lowest();
	return 0;
}//end of main