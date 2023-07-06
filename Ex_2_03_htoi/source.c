/*
*	Summary
*	- htoi function to convert hex string value to an integer.
*	- The function doesn't check for invalid input.
*/


#include <stdio.h>
#include <math.h>

#define INPUT_LIMIT 17

int htoi(const char[]);

int main() 
{
	int result;
	int count = 0;
	char hex[INPUT_LIMIT];

	char c;
	while (count < INPUT_LIMIT - 1 && (c = getchar()) != EOF && c != '\n')
	{
		hex[count++] = c;
	}
	hex[count] = '\0';

	result = htoi(hex);
	printf("hex value %s equals %d", hex, result);

}


int htoi(const char str[])
{
	int length, result, startLimit;

	length = result = startLimit = 0;
	while (str[length] != '\0')
		length++;

	if (length > 0 && length < 3 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		return 0;


	if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
		startLimit = 2;


	for (int i = length-1; i >= startLimit; i--)
	{
		int power = length - 1 - i;

		if ('9' >= str[i] && str[i] >= '0')
			result += pow(16, power) * ((char)str[i] - '0');

		else if ('f' >= str[i] && str[i] >= 'a')
			result += pow(16, power) * ((char)str[i] - 'a' + 10);

		else if ('F' >= str[i] && str[i] >= 'A')
			result += pow(16, power) * ((char)str[i] - 'A' + 10);
	}

	return result;
}
