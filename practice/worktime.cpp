#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <fstream>
using namespace std;

vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int to_seconds(string &record1, string &record2)
{
    int day = 0;
    int month1 = stoi(record1.substr(5, 2)),
        month2 = stoi(record2.substr(5, 2));
    for (int i = month1; i != month2; ++i)
    {
        day += days[i - 1];
    }
    int day1 = stoi(record1.substr(8, 2)),
        day2 = stoi(record2.substr(8, 2));
    day += day2 - day1;

    int hour = stoi(record2.substr(11, 2)) - stoi(record1.substr(11, 2)),
        minute = stoi(record2.substr(14, 2)) - stoi(record1.substr(14, 2)),
        second = stoi(record2.substr(17, 2)) - stoi(record1.substr(17, 2));
    return day * 3600 * 24 + hour * 3600 + minute * 60 + second;
}

int main()
{
    vector<string> lines;
    string line;
    int res = 0;
    ifstream file("C:\\Users\\siso kaffer\\Downloads\\records.txt");
    if (!file.is_open())
    {
        cout << "cann't be opened" << endl;
        return -1;
    }
    while (getline(file, line))
    {
        lines.push_back(std::move(line));
    }

    sort(lines.begin(), lines.end());

    for (int i = 0; i < lines.size(); i += 2)
    {
        res += to_seconds(lines[i], lines[i + 1]);
    }
    cout << res;
    return 0;
}