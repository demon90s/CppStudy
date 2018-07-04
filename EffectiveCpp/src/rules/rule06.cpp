#include "rule06.h"

void Rule06()
{
	HomeForSale hs;
	//HomeForSale hs2(hs); // 不可访问copy构造函数

	HomeForSale2 hfs;
	//HomeForSale2 hfs2(hfs);	// copy构造函数已删除
}