#include <stdio.h>
#include <math.h>


int htoi(const char[]);

int main() 
{
	int result;
	char hex[] = "0x125CCB9";

	result = htoi(hex);
	printf("hex value %s equals %d", hex, result);

}


int htoi(const char str[])
{
	int length, result;

	length = result = 0;
	while (str[length] != '\0')
		length++;

	if (length < 3)
		return 0;

	if ((str[0] != '0') && (str[1] != 'x' || str[1] != 'X'))
		return 0;


	for (int i = length-1; i > 1; i--)
	{
		int power = length - 1 - i;

		if ('9' >= str[i] && str[i] >= '0')
			result += pow(16, power) * (str[i] - '0');

		else if ('f' >= str[i] && str[i] >= 'a')
			result += pow(16, power) * (str[i] - 'a' + 10);

		else if ('F' >= str[i] && str[i] >= 'A')
			result += pow(16, power) * (str[i] - 'A' + 10);
	}

	return result;
}
