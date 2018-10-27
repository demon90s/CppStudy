// 条款28：避免返回 handles 指向对象内部成分
#ifndef __RULE28_H__
#define __RULE28_H__

#include <memory>
#include <cstdio>

extern void Rule28();

namespace rule28
{
	class Point {
	public:
		Point(int x, int y) : x_(x), y_(y) {}
		void SetX(int x) { x_ = x; }
		void SetY(int y) { y_ = y; }

		int GetX() const { return x_; }
		int GetY() const { return y_; }

	private:
		int x_, y_;
	};

	struct Rect {
		Point ulhs;		// upper left-hand corner 左上角
		Point lrhs;		// lower right-hand corner 右下角
	};

	class Rectangle {
	public:
		Rectangle(const Rect rect) : pData_(std::make_shared<Rect>(rect)) {}
		void Print() const {
			printf("ulhs: {%d, %d}\n", upperLeft().GetX(), upperLeft().GetY());
			printf("lrhs: {%d, %d}\n", lowerRight().GetX(), lowerRight().GetY());
		}

		// 虽然返回引用避免了拷贝，并可以通过编译，但却是错误的
		// 原因是允许用户修改内部数据
		Point& upperLeft_BUG() const { return pData_->ulhs; }
		Point& lowerRight_BUG() const { return pData_->lrhs; }

		// 返回 const handle 是一种解决办法
		const Point& upperLeft() const { return pData_->ulhs; }
		const Point& lowerRight() const { return pData_->lrhs; }

	private:
		std::shared_ptr<Rect> pData_;
	};

	inline void bug()
	{
		// 用户可以修改内部数据
		Point ulhs(10, 10);
		Point lrhs(20, 20);

		Rect rect{ ulhs, lrhs };

		Rectangle rectangle(rect);
		auto &ulhs_ref = rectangle.upperLeft_BUG();
		ulhs_ref.SetX(0); // 这种事情应该不被允许

		rectangle.Print();
	}

	inline void bug2()
	{
		// 尽管使用了正确的返回 handle 的函数，仍然要避免一个问题：空悬
		const Point* ulhs_p = nullptr;

		{
			Point ulhs(10, 10);
			Point lrhs(20, 20);

			Rect rect{ ulhs, lrhs };

			Rectangle rectangle(rect);
			ulhs_p = &rectangle.upperLeft();
			rectangle.Print();
		}
		
		printf("%d", ulhs_p->GetX()); // 所绑定的对象已经不存在！
	}
}

#endif // __RULE28_H__