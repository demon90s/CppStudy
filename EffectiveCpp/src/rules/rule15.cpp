#include "rule15.h"
#include <memory>

using namespace rule15;

void Rule15()
{
	{
		std::shared_ptr<Investment> pInv(createInvestment());

		//int days = daysHeld(pInv);	// 错误！需要原始指针
		int days = daysHeld(pInv.get());
	}

	FontHandle f2;
	{
		Font f(getFont());
		int newFontSize = 10;
		changeFontSize(f.get(), newFontSize);

		changeFontSize(f, newFontSize);

		// 隐式转换是危险的
		f2 = f;
	}
	// f2 被 dangle ，因 f 析构时释放了底层资源
}