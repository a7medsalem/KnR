/*
*	Summary
*	- short multiple sequance whitespaces to one white space.
*/


#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {

	int  c;
	int inBlank;

	inBlank = FALSE;
	while ((c = getchar()) != EOF)
	{
		// must press enter to take all inputs in count
		if (c == ' ' || c == '\n' || c == '\t') {
			
			if (inBlank == FALSE)
				putchar(c);

			inBlank = TRUE;
		}
		
		else {
			inBlank = FALSE;
			putchar(c);
		}
	}
}