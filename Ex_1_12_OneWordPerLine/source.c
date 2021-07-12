#include <stdio.h>

#define IN 1
#define OUT 0

int main() {

	printf("\n\n\t#### One word per line program ####\n\n");

	int c;
	int state;

	state = OUT;
	while (( c = getchar() ) == EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t') 
		{
			if(state == IN)
				putchar('\n');

			state = OUT;
		}
		else if(state == OUT)
		{
			printf("%c", c);
			state = IN;
		}
	}

	printf("\n\nDONE ..\n\n");
	return 0;
}