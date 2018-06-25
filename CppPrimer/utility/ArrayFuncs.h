/*
 * 一些操作Array的模板
 */

namespace utility
{

extern void Test_ArrayFuncs();

/*
 * 返回数组的元素的个数
 */
template <typename T, int N> inline
int ArrayItemCount(T (&arr)[N])
{
	return N;
}

/*
 * 清空数组元素，元素应当是POD类型
 */
template <typename T, int N> inline
void ClearArray(T (&arr)[N])
{
	memset(arr, 0, sizeof(arr));
}

/*
 * 测试下标是否合法
 */
template <typename T, int N> inline
bool IsValidArrayIndex(T (&arr)[N], int idx)
{
	return idx >= 0 && idx < N;
}

/*
 * 返回元素, 返回nullptr代表失败
 */
template <typename T, int N> inline
T* GetArrayItem(T (&arr)[N], int idx)
{
	if (idx >= 0 && idx < N)
	{
		return &arr[idx];
	}
	return nullptr;
}

/*
 * 设置元素的值，返回是否成功
 * T必须是可赋值的类型
 */
template <typename T, int N> inline
bool SetArrayItem(T (&arr)[N], int idx, const T &v)
{
	if (idx >= 0 && idx < N)
	{
		arr[idx] = v;
		return true;
	}
	return false;
}

}
