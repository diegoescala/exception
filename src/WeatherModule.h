#pragma once

#include "ExceptionModule.h"

#include <vector>

class DisplayMessage;

class WeatherModule : public ExceptionModule {
public:
    virtual ~WeatherModule();
    std::vector<DisplayMessage> getMessages();
};
