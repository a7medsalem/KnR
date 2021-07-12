#define TRUE 1
#define FALSE 0



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