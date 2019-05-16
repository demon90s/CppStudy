#include "instance.h"

static SomeMgr *some_mgr = nullptr;

SomeMgr* SomeMgr::Instance()
{
    if (!some_mgr) {
        some_mgr = new SomeMgr();
    }

    return some_mgr;
}

bool SomeMgr::ReInit()
{
    SomeMgr *temp = new SomeMgr();
    if (!temp->Init()) {
        delete temp;
        return false;
    }

    if (some_mgr)
        delete some_mgr;

    some_mgr = temp;
    return true;
}

bool SomeMgr::Init()
{
    some_value_ = 100;
    return true;
}