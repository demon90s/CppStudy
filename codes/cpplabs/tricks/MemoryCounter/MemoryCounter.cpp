#include "MemoryCounter.h"

std::unordered_map<std::string, int> MemoryCounter::count_cache_;

int MemoryCounter::GetMemoryBlocks(const std::string &classname)
{
    auto it = count_cache_.find(classname);
    if (it == count_cache_.end()) {
        return 0;
    }

    return it->second;
}