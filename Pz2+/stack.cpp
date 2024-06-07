#include "stack.h"


Stack* Push(Stack* stack, int num)
{
	if (stack->prev == NULL && stack->data == 0) {
		stack->data = num;
		return stack;
	}
	else {
		Stack* new_el = new Stack;
		new_el->data = num;
		new_el->prev = stack;
		return new_el;
	}
	
}


int Pop(Stack** stack)
{
	int num;

	if ((*stack)->prev != NULL)
	{
		Stack* last = *stack;
		num = (*stack)->data;
		*stack = (*stack)->prev;
		delete last;
	}

	else
	{
		num = (*stack)->data;
		(*stack)->data = 0;
		stack = NULL;
	}
	return num;

}



//int MathAction(Stack** stack, char action)
//{
//
//}