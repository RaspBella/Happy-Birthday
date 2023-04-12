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

int main(void)
{
    struct Birthday birthday;

    char* name = getlogin(); // get the username, only works on posix systems

    char* path = malloc(PATH_START_SIZE + strlen(name) + PATH_END_SIZE); // allocate memory for the path
    strcpy(path, PATH_START);
    strcat(path, name);
    strcat(path, PATH_END);

    FILE* fptr = fopen(path, "r"); // open in read mode
    if (fptr == NULL) // if read fails it's because the file doesn't exist
    {
	fptr = fopen(path, "w"); // open in write mode
	fprintf(fptr, "#Y/M/D\n%d/%d/%d", DEFAULT_BIRTHDAY_YEAR, DEFAULT_BIRTHDAY_MONTH, DEFAULT_BIRTHDAY_DAY); // write the default birthday

	// set birthday values to default birthday values
	birthday.year = DEFAULT_BIRTHDAY_YEAR; 
	birthday.month = DEFAULT_BIRTHDAY_MONTH;
	birthday.day = DEFAULT_BIRTHDAY_DAY;
    }
    else // otherwise it's read because the file exists
    {
	fscanf(fptr, "#Y/M/D\n%d/%d/%d", &birthday.year, &birthday.month, &birthday.day); // set birthday values to values in file
    }
    fclose(fptr); // close the file

    free(path); // free the allocated memory

    time_t now_seconds = time(NULL); // current time in seconds since epoch
    struct tm now = *localtime(&now_seconds); // use the current time to make a tm structure
    now.tm_year += 1900; // correct the year
    now.tm_mon++; // correct the month

    *name &= ~(1 << 5); // set the 5th bit of the first character to 0 so the character will be upercase

    if (now.tm_mon == birthday.month && now.tm_mday == birthday.day) // if now is birthday
    {
	printf("Happy Birthday %s, You are %d years old today!\n", name, now.tm_year - birthday.year); // :)
    }
    else
    {
	printf("Sorry %s it is not your birthday today\n", name); // :(
    }

    return 0;
}
