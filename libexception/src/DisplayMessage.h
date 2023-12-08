#pragma once
#include "MessageIcon.h"
#include <string>

class DisplayMessage {
public:
    DisplayMessage(std::string text);
    
    inline const std::string& getText() const { return text_; }
    
private:
    MessageIcon icon_;
    std::string text_;
};
