#ifndef TEMPLATE_BUILD
#define TEMPLATE_BUILD

template<typename T>
int compare(const T &left, const T &right)
{
	if (left < right) return -1;
	else if (left > right) return 1;
	else return 0;
}

#endif
