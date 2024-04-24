#include <iostream>

using namespace std;

void recursive(int* count, int answers, int score)
{
    if (answers)
    {
        recursive(count, answers - 1, 0);
        
        score += 10;
        if (score == 70)
            ++*count;
        if (score == 100)
            return;
        recursive(count, answers - 1, score);
    }
}

int main(int argc, char const *argv[])
{
    int c = 0, a = 30, s = 0;
    recursive(&c, a, s);
    cout << c;
    return 0;
}
