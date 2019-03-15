#pragma once

#include <unordered_map>
#include <string>

class MemoryCounter
{
public:
    MemoryCounter(const std::string &classname)
    {
        classname_ = classname;
        ++count_cache_[classname_];
    }

    ~MemoryCounter()
    {
        --count_cache_[classname_];
    }

    static int GetMemoryBlocks(const std::string &classname);

private:
    std::string classname_;
    static std::unordered_map<std::string, int> count_cache_;
};