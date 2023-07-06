/*
*	Summary
*	- short multiple sequence whitespaces to one white space.
*/


#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main() {

	int  c;
	int inBlank;

	printf("Enter a text to short its multiple sequence whitespaces to one white space.\n");
	printf("\"To finish typing, enter EOF (Ctrl+Z in Windows) in empty line then press Enter or quite the app (Ctrl+C)\"\n\n");

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