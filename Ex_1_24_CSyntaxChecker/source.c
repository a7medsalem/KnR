/*
*	Summary
*	- check for given c code file syntax errors "does not check for semicolons ;".
*/


#include <stdio.h>
#include "Boolean.h"
#include "Error.h"

int c, holded;
int quoted, singleQuoted, escape, inSingleComment, inMultiComment;
int removeCounter;

void newSingleQuote(void);
void newQuote(void);
void newBackSlash(void);
void newForwardSlash(void);
void newStar(void);
void newCharacter(void);
void EarseChar(int);


#define NON 0
#define PARENTHE 101
#define BRAKET 105
#define BRACE 110
int parentheCount, bracketCount, braceCount, stackCount;
int lastOpenedType;
int parentheseStack[1000];

void handleParenthese(void);
void openParenthe(void);
void closeParenthe(void);
void openBracket(void);
void closeBracket(void);
void openBrace(void);
void closeBrace(void);

int getNextTab(int, int);



#define FILE_1 "t1_correct_syntix.txt"
#define FILE_2 "t2_file_with_errors.txt"

int main() {

	FILE* file = freopen(FILE_2, "r", stdin);

	extern int quoted, singleQuoted, escape, inSingleComment, inMultiComment, removeCounter, c;
	extern int parentheCount, bracketCount, braceCount;
	extern int errorCount;
	extern char* errorMessage;
	int col, row;


	for (int i = 0; i < 1000; i++)
	{
		parentheseStack[i] = NON;
	}

	col = 0; row = 1;
	errorCount = 0;
	parentheCount = bracketCount = braceCount = 0;
	quoted = escape = inSingleComment, inMultiComment = FALSE;
	while ((c = getchar()) != EOF)
	{
		col++;

		switch (c)
		{
			case '\"':
				newQuote();
				break;

			case '\\':
				newBackSlash();
				break;

			case '/':
				newForwardSlash();
				break;

			case '*':
				newStar();
				break;

			case '\n':
				inSingleComment = FALSE;
				break;

			case '\t':
				col = getNextTab(col, 8);
				break;

			case '\'':
				newSingleQuote();
				break;

			case '[':
			case ']':
			case '{':
			case '}':
			case '(':
			case ')':
				if (isnot(quoted) && isnot(inSingleComment) && isnot(inMultiComment) && isnot(singleQuoted))
					handleParenthese();
				break;

			default:
				newCharacter();
				break;
		}


		printf("%c", c);
		if (c == '\n') {
			row++;
			col = 0;
		}

		if (errorCount != 0)
		{
			printf("\n");
			for (int i = 0; i < col-1; i++)
				printf(" ");
			printf("^");

			printf("\n\nError @%d,%d : %s\n", row, col, errorMessage);
			break;
		}
	}

	if (stackCount != 0)
		throws("Parenthese are not aligned");


	printf("\n\n\n\n");
	fclose(stdin);
	return 0;
}


void newSingleQuote(void) 
{
	extern int quoted, escape, singleQuoted;
	if(isnot(quoted))
	{
		if(is(singleQuoted))
		{
			singleQuoted = FALSE;
		}
		else
			singleQuoted = TRUE;
	}
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
	else if (isnot(quoted))
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

void handleParenthese(void)
{
	extern int c;

	switch (c)
	{
		case '[':
			openBracket();
			break;
		case ']':
			closeBracket();
			break;
		case '{':
			openBrace();
			break;
		case '}':
			closeBrace();
			break;
		case '(':
			openParenthe();
			break;
		case ')':
			closeParenthe();
			break;

		default:
			break;
	}

}


void openParenthe(void) 
{
	extern int lastOpenedType;
	extern int parentheCount, stackCount;
	extern int parentheseStack[];

	parentheCount++;
	parentheseStack[++stackCount] = PARENTHE;
}
void closeParenthe(void) 
{
	extern int lastOpenedType;
	extern int parentheCount, stackCount;
	extern int parentheseStack[];


	if (parentheseStack[stackCount] != PARENTHE)
		throws("extra or overlapped PARENTHE");

	parentheseStack[stackCount--] = NON;
	parentheCount--;
}
void openBracket(void)
{
	extern int lastOpenedType;
	extern int bracketCount, stackCount;
	extern int parentheseStack[];

	bracketCount++;
	parentheseStack[++stackCount] = BRAKET;
}
void closeBracket(void) 
{
	extern int lastOpenedType;
	extern int bracketCount, stackCount;
	extern int parentheseStack[];

	if (parentheseStack[stackCount] != BRAKET)
		throws("extra or overlapped BRAKET");

	parentheseStack[stackCount--] = NON;
	bracketCount--;
}
void openBrace(void) 
{
	extern int lastOpenedType;
	extern int braceCount, stackCount;
	extern int parentheseStack[];

	braceCount++;
	parentheseStack[++stackCount] = BRACE;
}
void closeBrace(void)
{
	extern int lastOpenedType;
	extern int braceCount, stackCount;
	extern int parentheseStack[];

	if (parentheseStack[stackCount] != BRACE)
		throws("extra or overlapped BRACE");

	parentheseStack[stackCount--] = NON;
	braceCount--;
}


int getNextTab(int col, int tabspacing)
{
	int remind;
	int add;

	add = 0;
	if ((remind = col % tabspacing) > 0)
		add = tabspacing - remind;

	return col + add;
}

