/*
 * foo.c
 */

int i = 100000;

int Get()
{
	return i;
}

int* GetAddress()
{
	return &i;
}
