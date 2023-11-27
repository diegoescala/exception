#pragma once
#include "DisplayMessage.h"
#include <vector>

class ExceptionModule {
public:
    virtual std::vector<DisplayMessage> getMessages() = 0;
    virtual ~ExceptionModule() {}    
};
