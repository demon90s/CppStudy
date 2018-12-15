#include <typeinfo>
#include <cstdio>

void func() {}

int main()
{
	printf("value of func: %p\n", func);
	printf("value of &func: %p\n", &func);
	printf("value of *func: %p\n", *func);

	printf("typename of func: %s\n", typeid(func).name());
	printf("typename of &func: %s\n", typeid(&func).name());
	printf("typename of *func: %s\n", typeid(*func).name());

	return 0;
}
