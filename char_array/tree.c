#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 1000
#define STACK_SIZE 1000

int main(int argc, char const *argv[])
{
    char input[INPUT_SIZE];
    fgets(input, INPUT_SIZE, stdin);

    int stack[STACK_SIZE];
    int top = 0;

    for (int i = 0; input[i] != '\0'; ++i)
    {
        if (input[i] == '(')
        {
            stack[top++] = i;
        }
        else if (input[i] == ')')
        {
            int index = stack[--top];
            char sign = input[index - 1];
            strncpy(&input[index - 1], &input[index], i - index + 1);
            input[i] = sign;
        }
    }

    printf("%s", input);
    return 0;
}
