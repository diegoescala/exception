#pragma once
#include "DisplayMessage.h"
#include <vector>
#include <mutex>
#include <map>

class Display {
public:
    void addMessages(ptrdiff_t sourceId, const std::vector<DisplayMessage>& messages);
    void renderMessages();
    
private:
    std::map<ptrdiff_t, std::vector<DisplayMessage>> messages_;
    std::mutex mutex_;
};

