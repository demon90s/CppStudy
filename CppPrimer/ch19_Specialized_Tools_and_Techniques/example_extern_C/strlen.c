int strlen_custom(const char *c)
{
	int len = 0;
	while (*c++)
	{
		++len;
	}
	return len;
}
