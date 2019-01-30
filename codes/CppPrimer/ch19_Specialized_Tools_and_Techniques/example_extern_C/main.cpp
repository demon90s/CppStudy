// example: 链接指示，extern "C"（758）

#include <cstdio>

using namespace std;

#ifdef __cplusplus
extern "C"
#endif 
int strlen_custom(const char *str);

int main()
{
	printf("%d\n", strlen_custom("Hello World"));

	return 0;
}
