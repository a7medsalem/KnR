/*
*	Summary
*	- define parametric functions.
*	- convert from fehrenheit to celsius table.
*/

#include <stdio.h>


double toCelsius(double);
double toFahrenheit(double);

int main() {

	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Fehrenheit\tCelsius\n");
	printf("-----------------------\n");

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = toCelsius(fahr);
		printf("%3.0f\t\t%6.1f\n", fahr, celsius);
		fahr += step;
	}

	return 0;
}


double toFahrenheit(double celsius) {
	return ((9.0f / 5.0f) * celsius) + 32.0f;
}

double toCelsius(double fahrenheit) {
	return (5.0f / 9.0f) * (fahrenheit - 32.0f);
}