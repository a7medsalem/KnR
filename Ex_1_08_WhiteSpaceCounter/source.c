/*
*	Summary
*	- count white spaces in user input text.
* 	- allow multiple lines, use EOF to finish,
*		"enter an empty line and press ctrl+z to enter EOF in console".
*/

#include <stdio.h>

int main() {

	int c;
	long counter;

	counter = 0;
	while ((c = getchar()) != EOF)
	{
		// must press enter to take all inputs in count
		if(c == ' ' || c == '\n' || c == '\t')
			counter++;
	}

	printf("\n\n\tNumber of white spaces is %d\n\n", counter);
}