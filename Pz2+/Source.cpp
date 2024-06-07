#include "stack.h"

int main()
{
    setlocale(LC_ALL, "");

    Stack* stack = new Stack;
    stack->prev = NULL;
    stack->data = 0;

    char symbol;
    int result;

    FILE* resFile;
    FILE* ptr;

    // input
    fopen_s(&ptr, "Test.txt", "r");
    if (ptr != NULL)
    {
        fscanf_s(ptr, "%c", &symbol, 1);
        stack->data = symbol - '0';
        while (!feof(ptr))
        {
            fscanf_s(ptr, "%c", &symbol, 1);

            if (symbol >= '0' && symbol <= '9')
            {
                stack = Push(stack, symbol - '0');
            }
            else if (symbol == '+')
            {
                stack = Push(stack, Pop(&stack) + Pop(&stack));
            }
            else if (symbol == '-')
            {
                stack = Push(stack, (Pop(&stack) - Pop(&stack)) * (-1));
            }
            else if (symbol == '*')
            {
                stack = Push(stack, Pop(&stack) * Pop(&stack));
            }
        }
    }
    else
    {
        printf_s("Could not open file result.txt\n");
        return 0;
    }

    // output
    fopen_s(&resFile, "result.txt", "w+");

    fprintf(resFile, "%d", Pop(&stack));

    fclose(resFile);
}
