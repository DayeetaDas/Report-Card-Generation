/* This program generates a report card for multiple students and compares their average scores*/
#include "pch.h"//the necessary header files are included
#include<iostream>
#include<string>
#include<conio.h>
#include<stdio.h>
using namespace std;
struct Student//the structure containing the attributes of a student is declared
{
	int roll;
	string name;
	int cl;
	string sub[3];
	int marks[3];
	int sum = 0;
	double avg;
};
Student s1[3];//the copies of 3 students are made in this particular program
int temp, add;//the necessary identifiers are declared
string temp1;
void take_input()//the details of the student is taken as input
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the roll no:";
		cin >> s1[i].roll;
		while (!cin>>s1[i].roll)
		{
			cout << "Enter the roll no:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> s1[i].roll;
		}
		cout << "Enter the name:";
		cin >> s1[i].name;
		cout << "Enter the class:";
		cin >> s1[i].cl;
		while (s1[i].cl > 12 || s1[i].cl < 1 || (!cin >> s1[i].cl))
		{
			cout << "Enter the class:";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> s1[i].cl;
		}
		for (int j = 0; j < 3; j++)
		{
			cout << "Enter the name of the subject:";
			cin >> s1[i].sub[j];
			cout << "Enter the marks obtained:";
			cin >> s1[i].marks[j];
			while (s1[i].marks[j] > 100 || s1[i].marks[j] < 0 || (!cin >> s1[i].marks[j]))
			{
				cout << "Enter the marks obtained:";
				cin.clear();
				cin.ignore(256, '\n');
				cin >> s1[i].marks[j];
			}
		}
	}
}
void display()//the details of the student are displayed
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Roll:" << s1[i].roll << endl;
		cout << "Name:" << s1[i].name << endl;
		cout << "Class:" << s1[i].cl << endl;
		cout << "Subjects: \t Marks:" << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << s1[i].sub[j] << "\t\t " << s1[i].marks[j] << endl;
		}
	}
}
void avg_per()//the average percetange of each student is displayed
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			s1[i].sum += s1[i].marks[j];
		}
		s1[i].avg = s1[i].sum / 3;
		cout << "The average percentage of " << s1[i].name << " is " << s1[i].avg <<"%"<< endl;
	}
}
void find_highest()//the highest scorer based on total average percent is displayed
{
	for (int i = 0; i < 3; i++)
	{
		if (temp <= s1[i + 1].avg)
		{
			temp = s1[i].avg;
			add = i;
		}
	}
	cout << "The highest scorer is " << s1[add].name << " with an average percent of " << temp << "%" << endl;
}
void find_lowest()//the lowest scorer based on total average percent is displayed
{
	for (int i = 0; i < 3; i++)
	{
		if (temp>= s1[i].avg)
		{
			temp = s1[i].avg;
			add = i;
		}
	}
	cout << "The lowest scorer is " << s1[add].name << " with an average percent of " << temp << "%" << endl;
}
void sort_highest()//the names and average scores of the students are displayed in descending order
{
	cout << "Prints the Name of the scorer and the score in descending order" << endl;
	cout << "Name:\t\tAverage" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j =0; j < 3; j++)
		{
			if (s1[j].avg <= s1[j+1].avg)
			{
				temp = s1[j].avg;
				temp1 = s1[j].name;
				s1[j].avg = s1[j+1].avg;
				s1[j].name = s1[j+1].name;
				s1[j+1].avg = temp;
				s1[j+1].name = temp1;
			}
		}
		cout << s1[i].name << "\t\t" << s1[i].avg << endl;
	}
}
void sort_lowest()//the names and average scores of the students are displayed in ascending order
{
	cout << "Prints the name of the scorer and the score in ascending order" << endl;
	cout << "Name:\t\tAverage" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = i+1; j < 3; j++)
		{
			if (s1[j+1].avg <= s1[j].avg)
			{
				temp = s1[i].avg;
				temp1 = s1[i].name;
				s1[i].avg = s1[j].avg;
				s1[i].name = s1[j].name;
				s1[j].avg = temp;
				s1[j].name = temp1;
			}
		}
		cout << s1[i].name << "\t\t" << s1[i].avg << endl;
	}
}
int main()//start of main
{
	take_input();
	display();
	avg_per();
	find_highest();
	find_lowest();
	sort_highest();
	sort_lowest();
	return 0;
}//end of main