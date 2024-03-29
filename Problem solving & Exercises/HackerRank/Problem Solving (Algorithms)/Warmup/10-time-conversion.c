/*
 ? Link: https://www.hackerrank.com/challenges/time-conversion/problem
 * Difficulty: Easy
 * Name: Time Conversion
 *
 * Tags: Algorithms, Warmup
 *
 * Summary:
 * convert time from 12-hour AM/PM format to 24-hour format
 * 07:05:45PM --> 19:05:45
 */

#include <stdio.h>

char *TimeConvertion(const char *str)
{
	int i;							  // index
	static char str24[] = "HH:MM:SS"; // for example HH:MM:SS ++ '\0

	for (i = 2; i < 8; i++) // copy the minutes and seconds from str to str24
	{
		str24[i] = str[i];
	}

	if (str[8] == 'A') // if AM
	{
		if (str[0] == '1' && str[1] == '2') // if 12 AM
		{
			str24[0] = '0'; // change the hours to 00
			str24[1] = '0';
		}
		else
		{
			str24[0] = str[0];
			str24[1] = str[1];
		}
	}

	if (str[8] == 'P')
	{
		if (str[0] == '1' && str[1] == '2')
		{
			str24[0] = '1';
			str24[1] = '2';
		}
		else
		{
			int num = 0;			// number of hours
			for (i = 0; i < 2; i++) // loop until : is found
			{
				num = num * 10;			  // multiply the number by 10 to shift the number to the left
				num = num + str[i] - '0'; // add the number to the right of the shifted number (previous number)
			}
			num = num + 12; // add 12 to the number of hours

			str24[0] = (num / 10) + '0'; // get the first digit of the number of hours and add it to index 0
			str24[1] = (num % 10) + '0'; // get the second digit of the number of hours and add it to index 1
		}
	}

	return str24;
}

int main()
{
	char str[] = "HH:MM:SSAM"; // for example HH:MM:SSAM + '\0

	fgets(str, 10, stdin); // read from stdin

	puts(TimeConvertion(str));

	return 0;
}