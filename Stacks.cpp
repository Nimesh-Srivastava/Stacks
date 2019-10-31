#include "stdafx.h"
#include<iostream>
#include<conio.h>

using namespace std;

int pop(int[], int&);
int push(int[], int&, int);
void display(int[], int);

const int siz = 5;

int main()
{
	int stack[siz], item, top = -1, res;
	char ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		system("cls");
		cout << "\n\tEnter item for insertion : ";
		cin >> item;
		res = push(stack, top, item);
		if (res == -1)
		{
			cout << "\n\tStack overflow!!!";
			cout << "\n\tAborting!!!";
			goto end;
		}
		cout << "\n\n\tNow the stack is : ";
		display(stack, top);
		cout << "\n\n\tWant to enter more(y/n) : ";
		cin >> ch;
	}
	system("cls");
	cout << "\n\n\tNow deletion begins........";
	ch = 'y';
	while (ch == 'y' || ch == 'Y')
	{
		res = pop(stack, top);
		if (res == -1)
		{
			cout << "\n\n\tUnderflow!!!";
			cout << "\n\tAborting!!!";
			goto end;
		}
		cout << "\n\n\tNow the stack is :";
		display(stack, top);
		cout << "\n\n\tElement deleted : " << res;
		cout << "\n\n\tWant to delete more(y/n) : ";
		cin >> ch;
		system("cls");
	}
end :
	_getch();
	return 0;
}

int push(int stack[], int &top, int item)
{
	if (top == siz - 1)
	{
		return -1;
	}
	else
	{
		top++;
		stack[top] = item;
	}
	return 0;
}

int pop(int stack[], int &top)
{
	int ret;
	if (top == -1)
	{
		return -1;
	}
	else
	{
		ret = stack[top];
		top--;
	}
	return ret;
}

void display(int stack[], int top)
{
	if (top == -1)
	{
		cout << "\n\t(No element to show. Stack empty)";
		return;
	}
	cout << "\n\t" << stack[top] << " <-- top\n";
	for (int i = top-1;i >= 0;i--)
	{
		cout << "\t" << stack[i] << endl;
	}
}