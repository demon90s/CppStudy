#include "QueryResult.h"

using namespace std;

ostream &print(ostream &os, const QueryResult &qr, std::pair<size_t, size_t> *line_range)
{
	// 如果找到了单词，打印出现次数和所有出现的位置
	os << qr.sought << " occurs " << qr.lines->size() << " time(s)" << endl;

	// 打印单词出现的每一行
	for (auto num : *qr.lines) // 对set中每个单词
		// 避免行号从0开始给用户带来的困惑
	{
		size_t line_num = num + 1;
		if (line_range && (line_num < line_range->first || line_num > line_range->second))
			continue;

		os << "\t(line " << num + 1 << ") "
			<< *(qr.file->begin() + num) << endl;
	}
	return os;
}
