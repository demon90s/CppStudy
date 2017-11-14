#include "utility.h"

void SetBit(unsigned long *flag, size_t bit)
{
	*flag |= 1UL << bit;
}

void ClearBit(unsigned long *flag, size_t bit)
{
	*flag &= ~(1UL << bit);
}

bool IsBitSet(const unsigned long *flag, size_t bit)
{
	return *flag & (1UL << bit);
}

int str_replace(std::string &s, const std::string &old_val, const std::string &new_val)
{
	int cnt = 0;
	if (old_val.length() > s.length() || old_val.length() == 0) {
		return cnt;
	}

	for (size_t i = 0; i < s.length();) {
		std::string str_tmp = s.substr(i, old_val.length());
		if (str_tmp == old_val) {
			s.replace(i, old_val.length(), new_val);
			i += new_val.length();
			++cnt;
		}
		else {
			++i;
		}
	}

	return cnt;
}

const char *read_name(const char *p, std::string *name)
{
	*name = "";

	if (p && *p && isalpha(*p))
	{
		const char *start = p;
		while (p && *p && 
			  (isalnum(*p)
		       || *p == '_') )
		{
			++p;
		}

		if (p - start > 0) name->assign(start, p - start);
		return p;
	}
	return 0;
}
