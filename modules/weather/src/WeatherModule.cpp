#include "WeatherModule.h"

#include "DisplayMessage.h"
#include <vector>
#include <string>
#include <iostream>

WeatherModule::WeatherModule(std::string msg):
  message_(std::move(msg))
{
}


WeatherModule::~WeatherModule()
{
    std::cout << "Destroying WM" << std::endl;
}


std::vector<DisplayMessage> WeatherModule::getMessages() {
    std::vector<DisplayMessage> messages;
    messages.push_back(message_);
    return messages;
}

extern "C" void print() {
    printf("herro world\n");
}
