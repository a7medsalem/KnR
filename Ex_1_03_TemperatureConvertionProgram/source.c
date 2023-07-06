/*
*	Summary
*	- define variables.
*	- use while loop.
*	- use \t char and float format %x.yf to print nice look aligned table.
*	- print fahrenheit to celsius table.
*/

#include <stdio.h>

int main() {
	
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Fahrenheit\tCelsius\n");
	printf("-----------------------\n");

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = (5.0f/9.0f) * (fahr - 32.0f);
		printf("%3.0f\t\t%6.1f\n", fahr, celsius);
		fahr += step;
	}
}