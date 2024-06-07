#pragma once
#include <iostream>
using namespace std;

struct Stack
{
    int data;
    Stack* prev;
};


Stack* Push(Stack* stack, int num);
int Pop(Stack** stack);