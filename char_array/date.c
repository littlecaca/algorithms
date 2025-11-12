#include <math.h>
#include <stdio.h>
#include <stdbool.h>

int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0); 
}


int get_day_of_year(int year, int month, int day)
{
    months[2] = is_leap(year) ? 29 : 28;
    int res = 0;
    for (int i = 1; i < month; ++i)
    {
        res += months[i];
    }
    return res + day;
}

typedef struct __Date
{
    int year;
    int month;
    int day;
} Date;

int days_of_year(int year)
{
    return (is_leap(year) ? 366 : 365);
}

int get_dis_of_dates(Date d1, Date d2)
{
    int res = 0;
    for (int y = d1.year; y < d2.year; ++y)
    {
        res += days_of_year(y);
    }
    return res - get_day_of_year(d1.year, d1.month, d1.day) 
             + get_day_of_year(d2.year, d2.month, d2.day);
}


Date adjust_date(Date d1, int days)
{
    Date d0 = {1, 1, 1};
    int adjusted_days = get_dis_of_dates(d0, d1) + days;
    
    int y = 1;
    while (adjusted_days >= days_of_year(y))
    {
        adjusted_days -= days_of_year(y);
        ++y;
    }

    months[2] = is_leap(y) ? 29 : 28;

    int m = 1;
    while (adjusted_days >= months[m])
    {
        adjusted_days -= months[m];
        ++m;
    }

    int d = 1 + adjusted_days;

    d0.year = y; d0.month = m; d0.day = d;
    return d0;
}



int main(int argc, char const *argv[])
{
    printf("the day of 2024/9/5 %d\n", get_day_of_year(2024, 9, 5));
    Date d1 = {2024, 12, 12}, d2 = {2024, 9, 5};
    printf("the dis of 2012/12/12 and 2024/9/5 %d\n", get_dis_of_dates(d1, d2));

    Date res = adjust_date(d2, -10000);
    printf("10000 days ago of 2024/9/5 is %d/%d/%d\n", res.year, res.month, res.day);
    return 0;
}
