/*
*	Summary
*	- remove comments from given file "single/multi/nested comments".
*/


#include <stdio.h>

#define TRUE 1
#define FALSE 0

int c, holded;
int quoted, escape, inSingleComment, inMultiComment;
int removeCounter;
void newQuote(void);
void newBackSlash(void);
void newForwardSlash(void);
void newStar(void);
void newCharacter(void);
void EarseChar(int);

int isTrue(int);
int isFalse(int);
int can(int);
int cannot(int);
int is(int);
int isnot(int);

int main() {

	FILE* file = freopen("testfile.txt", "r", stdin);

	extern int quoted, escape, inSingleComment, inMultiComment, removeCounter, c;


	quoted = escape = inSingleComment, inMultiComment = FALSE;
	while ((c = getchar()) != EOF)
	{

		if (c == '\"') 
		{
			newQuote();
		}
		else if (c == '\\') 
		{
			newBackSlash();
		}
		else if (c == '/') 
		{
			newForwardSlash();
		}
		else if(c == '*')
		{
			newStar();
		}
		else if (c == '\n') 
		{
			inSingleComment = FALSE;
		}
		else 
		{
			newCharacter();
		}


		if (isnot(inSingleComment) && isnot(inMultiComment))
		{
			printf("%c", c);
		}
		if (removeCounter > 0) 
		{
			EarseChar(removeCounter);
			removeCounter = 0;
		}
	}

	printf("\n\n\n\n");
	fclose(stdin);
	return 0;
}


void newQuote(void)
{
	extern int quoted, escape;

	if (is(quoted) && can(escape))
	{
		escape = FALSE;

	}
	else if (is(quoted) && cannot(escape))
	{
		quoted = FALSE;
	}
	else if(isnot(quoted))
	{
		quoted = TRUE;
	}
}

void newBackSlash(void)
{
	extern int quoted, escape;
	
	if (is(quoted) && cannot(escape)) 
	{
		escape = TRUE;
	}
	else if (is(quoted) && can(escape)) 
	{
		escape = FALSE;
	}
}

void newForwardSlash(void) 
{
	extern int quoted, escape;
	extern int c, holded;
	extern int removeCounter;

	if (isnot(quoted))
	{
		if (holded == '/') 
		{
			inSingleComment = TRUE;
			removeCounter = 1;
		}
		else if (holded == '*')
		{
			inMultiComment = FALSE;
			removeCounter = 2;
		}
		else
		{
			holded = c;
		}
	}
	
}

void newCharacter(void) 
{
	extern int quoted, escape, c;

	holded = c;
	if (is(quoted) && can(escape)) 
	{
		escape = FALSE;
	}
}

void newStar(void) 
{
	extern int quoted, escape;
	extern c, holded;

	if (is(quoted)) 
	{

	}
	else if (is(inMultiComment)) 
	{
		holded = '*';
	}
	else if (isnot(quoted) && holded == '/')
	{
		inMultiComment = TRUE;
	}
}

void EarseChar(int count) 
{
	for (int i = 0; i < count; i++)
		printf("\b");

	for (int i = 0; i < count; i++)
		printf(" ");
}

int isTrue(int i) 
{
	if (i == TRUE)
		return TRUE;
	else
		return FALSE;
}
int isFalse(int i)
{
	if (i == FALSE)
		return TRUE;
	else
		return FALSE;
}
int can(int i) 
{
	return isTrue(i);
}
int cannot(int i)
{
	return isFalse(i);
}
int is(int i)
{
	return isTrue(i);
}
int isnot(int i)
{
	return isFalse(i);
}



