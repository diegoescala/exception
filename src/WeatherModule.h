#pragma once

#include "ExceptionModule.h"

#include <vector>
#include <string>

class DisplayMessage;

class WeatherModule : public ExceptionModule {
public:
    WeatherModule();
    WeatherModule(std::string msg);
    virtual ~WeatherModule();
    std::vector<DisplayMessage> getMessages();
private:
    std::string message_;
};
