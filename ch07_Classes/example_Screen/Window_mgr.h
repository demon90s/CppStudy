#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include "Screen.h"

class Window_mgr
{
private:
	// 默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
	std::vector<Screen> screens{Screen(24, 80, ' ')};
};

#endif
