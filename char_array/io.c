#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c;
    while (scanf_s("%c", &c) != EOF)
    {
        printf("%c", c);
    }
    return 0;
}
