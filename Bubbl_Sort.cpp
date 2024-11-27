#include<bits/stdc++.h>
using namespace std;

#define sz 5

class student
{
	public:
		int rn;
		string name;
};

class bubble
{
	public:
		student s[sz];
		void create();
		void display();
		void sort();
};

void bubble::create()
{
	cout << "Enter the Roll Number and Name for " << sz << " students" << endl;
	for(int i = 0; i < sz; i++)
	{
		cin >> s[i].rn >> s[i].name;
	}
}

void bubble::display()
{
	cout << "Roll No" << '\t' << "Name" << endl;
	for(int i = 0; i < sz; ++i)
	{
		cout << s[i].rn << '\t' << s[i].name << endl;
	}
	cout << endl;
}

void bubble::sort()
{
	bool swapped;
	for(int i = 0; i < sz - 1; i++)
	{
		swapped = false;
		for(int j = 0; j < sz - i - 1; j++)
		{
			if(s[j].rn > s[j + 1].rn)
			{
				swap(s[j],s[j + 1]);
				swapped = true;
			}
		}
		if(swapped) break;
	}
}

int main()
{
	bubble b;
	int ch;
	do
	{
		cout << "1.Create List of Students\n2.Display\n3.Sort\nEnter your choice: ";
		cin >> ch;
		switch(ch)
		{
			case 1:
				b.create();
				break;
			case 2:
				b.display();
				break;
			case 3:
				b.sort();
				break;
			default:
				cout << "Invalid Choice!" << "\n";
				break;
		}
	}while(ch != 0);
}