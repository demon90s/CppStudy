// example: 控制实例化（597）

/*
 * make后，使用nm命令观察compare符号信息
 * nm Application.o -> U，表明compare没有定义过，需要链接
 * nm TemplateBuild.o -> W，弱链接符号，具有一个默认的定义
 */

#include <iostream>
#include "Application.h"

using namespace std;

int main()
{
	func();

	return 0;
}
