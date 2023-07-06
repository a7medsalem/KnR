/*
*	Summary
*	- use backward for loop.
*/


#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {

	float fahr, celsius;

	printf("Celsius\t\tFahrenheit\n");
	printf("-------------------------\n");

	for (celsius = UPPER; celsius >= LOWER; celsius -= STEP)
	{
		fahr = ((9.0f / 5.0f) * celsius) + 32.0f;
		printf("%3.0f\t\t%6.1f\n", celsius, fahr);
	}
}