#include "Display.h"
#include <iostream>
#include <thread>

void Display::addMessages(ptrdiff_t sourceId, const std::vector<DisplayMessage>& messages) {
    std::lock_guard<std::mutex> lk(mutex_);
    messages_[sourceId] = messages;
}

void Display::renderMessages() {
    std::lock_guard<std::mutex> lk(mutex_);
    std::cout << "---" << std::endl;
    for (auto& message_list : messages_) {
        for (auto& message : message_list.second) {
            std::cout << message.getText() << std::endl;
        }
    }
    std::cout << "---" << std::endl;
}
