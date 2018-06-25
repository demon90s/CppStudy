// 练习16.11：下面List的定义是错误的。应如何修正它？
/*
 * template<typename elemType> class ListItem;
 * template<typename elemType> class List {
 * public:
 *     List<elemType>();
 *     List<elemType>(const List<elemType> &);
 *     List<elemType>& operator=(const List<elemType> &);
 *     ~List();
 *     void insert(ListItem *ptr, elemType value);
 * private:
 *     ListItem *fron, *end;
 * };
 */

#include <iostream>

using namespace std;

// 修正如下
template<typename elemType> class ListItem;
template<typename elemType> class List {
public:
    List<elemType>() {}
    List<elemType>(const List<elemType> &);
    List<elemType>& operator=(const List<elemType> &);
    ~List() {}
    void insert(ListItem<elemType> *ptr, elemType value);
private:
    ListItem<elemType> *fron, *end;
};

int main()
{
	List<int> list;

	return 0;
}
