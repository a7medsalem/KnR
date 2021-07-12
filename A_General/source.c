#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <math.h>

int e_number;

int main() 
{
	extern int e_number;
	int i_number;
	float eps = 10.0e-5;

	printf("%d %d", e_number, eps);

}
