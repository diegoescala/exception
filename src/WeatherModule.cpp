#include "WeatherModule.h"

#include "DisplayMessage.h"
#include <vector>
#include <string>
#include <iostream>

WeatherModule::~WeatherModule()
{
    std::cout << "Destroying WM" << std::endl;
}


std::vector<DisplayMessage> WeatherModule::getMessages() {
    std::vector<DisplayMessage> messages;
    messages.push_back(std::string("It's rainy; grab an umbrella!"));
    return messages;
}
