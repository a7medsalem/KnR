/*
*	Summary
*	- count number of words in given text.
* 	- allow multiple lines, use EOF to finish,
*		"enter an empty line and press ctrl+z to enter EOF in console".
*/


#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		nc++;
		if (c == '\n')
			nl++;

		if (c == ' ' || c == '\t' || c =='\\' || c == '\n') 
		{
			state = OUT;
		}
		else if(state == OUT)
		{
			state = IN;
			nw++;
		}
	}

	printf("\n\n\tnumber of words is %d\n\n", nw);
}