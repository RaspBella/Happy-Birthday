#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define DEFAULT_BIRTHDAY_YEAR 2006
#define DEFAULT_BIRTHDAY_MONTH 4
#define DEFAULT_BIRTHDAY_DAY 13

#define PATH_START "/home/"
#define PATH_START_SIZE 6
#define PATH_END "/.config/birthday.conf"
#define PATH_END_SIZE 22

struct Birthday
{
    int year;
    int month;
    int day;
};
