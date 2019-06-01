// 练习14.50：在初始化ex1和ex2的过程中，可能用到哪些类类型的转换序列呢？说明
// 初始化是否正确并解释原因。

#include <iostream>

using namespace std;

struct LongDouble {
	LongDouble(double _v = 0.0) : v(_v) {}
	operator double() { cout << "operator double" << endl; return v; }
	operator float() { cout << "operator float" << endl; return (float)v; }

	double v;
};

int main()
{
	LongDouble ldObj;
	//int ex1 = ldObj; // error: conversion from ‘LongDouble’ to ‘int’ is ambiguous
	
	float ex2 = ldObj;
	cout << ex2 << endl; // 正确，调用float版本的

	return 0;
}
