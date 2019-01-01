/*
 * 练习4.16：尽管下面的语句合法，但它们实际执行的行为可能和预期的不一样，为什么？应该如何修改？
 * (a) if (p = getPtr() != 0)	(b) if (i = 1024)
 */

/*
 * (a) error:  can not convert‘bool’ to ‘int*’ in assignment, 应该改成if ((p = getPtr()) != 0)
 r
 * (b) 先给i赋值为1024，然后判断i是否等于0（结果永远为true），实际应该是if (i == 1024)
 */

int *getPtr()
{
	return nullptr;
}

int main()
{
	int *p = nullptr;

	//if (p = getPtr() != 0);
	if ((p = getPtr()) != 0);

	return 0;
}
