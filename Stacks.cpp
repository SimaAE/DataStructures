#include <iostream>
#include <time.h>
#include <stdio.h>
#include <Windows.h>

int stack[10], top;
using namespace std;

void push(int[], int);
void pop(int[]);
void display(int[]);

int main()
{
    int choice = 0;
    int item = 0;
    bool exit = false;
    
    while (!exit)
    {
        cout << "Stack Menu" << endl;
        cout << "1: Display" << endl;
        cout << "2: Push" << endl;
        cout << "3: Pop" << endl;
        cout << "4: Exit" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "The current content(s) of the stack is/are:" << endl;
            display(stack);
            break;
        case 2:
            clock_t start, end;
            start = clock();

            cout << "Please enter item to push:" << endl;
            cin >> item;
            push(stack, item);
            cout << "Item '" << item << "' added." << endl;

            end = clock();
            cout << "It took " << (end - start) / 1000.00 << " seconds to complete the push." << endl;

            break;
        case 3:
            pop(stack);
            break;
        case 4:
            exit = true;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}

void push(int stack[], int item)
{
    top++;
    stack[top] = item;
}

void pop(int stack[])
{
    int deletedItem;
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        deletedItem = stack[top];
        top--;
        cout << deletedItem << " has been removed from the stack." << endl;
    }
}

void display(int stack[])
{
    for (int i = top; i > 0; i--)
    {
        cout << stack[i] << endl;
    }
}