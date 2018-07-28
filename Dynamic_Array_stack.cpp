// Dynamic_Array_stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"

using namespace std;

struct stack
{
	int top;
	int capacity;
	int *arr;
};

struct stack* init();
int isFull(stack*);
void push(stack*,int);
int pop(stack*);
void doublestack(stack*);
void display(stack*);

int _tmain(int argc, _TCHAR* argv[])
{
	int data;
	int choice;
	struct stack* s;
	s = init();
	while(1)
	{
		cout<<"\n1: Push 2: Pop 3:Display\n";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"Enter data\n";
			cin>>data;
			push(s,data);
			break;
		case 2:
			int result;
			result = pop(s);
			cout<<result;
			break;
		case 3:
			display(s);
			break;
		default:
			cout<<"Wrong entry\n";
			exit(0);
		}
	}
	return 0;
}

struct stack* init()
{
	struct stack* s = (stack*) malloc(sizeof(stack));
	if(!s)
		return NULL;
	s->top = -1;
	s->capacity = 1;
	s->arr = (int*) malloc(sizeof(int));
	if(!s->arr)
		return NULL;
	return s;
}

void doubleStack(stack* s)
{
	s->capacity = s->capacity *2;
	s->arr = (int*) realloc(s->arr,s->capacity*(sizeof(int)));
}

int isFull(stack* s)
{
	return (s->top == s->capacity-1);
}

void push(stack* s, int data)
{
	if(isFull(s))
	{
		doubleStack(s);
	}
	s->top++;
	s->arr[s->top] = data;
	
}

int pop(stack* s)
{
	int data;
	if(s->top == -1)
	{
		cout<<"Stack empty\n";
		return -1;
	}

	else
	{
		data = s->arr[s->top];
		s->top--;
	}

	return data;
}

void display(stack* s)
{
	if(s->top == -1)
	{
		cout<<"Stack empty\n";
	}

	else
	{
		for(int i=0;i<=s->top;i++)
		{
			cout<<s->arr[i];
		}
	}
}