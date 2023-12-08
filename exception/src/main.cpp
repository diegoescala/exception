#include "ExceptionCore.h"
//#include "WeatherModule.h"

#include <iostream>
#include <thread>

int main(int argc, char** argv) {
    std::cout << "hai exception" << std::endl;
    {
        ExceptionCore core;
        // core.addModule(std::make_shared<WeatherModule>("It's rainy; grab an umbrella!"));
        // std::this_thread::sleep_for(std::chrono::milliseconds(4500));
        // core.addModule(std::make_shared<WeatherModule>("It's sunny; wear some sunscreen!"));
        // std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    }
    std::cout << "bai exception" << std::endl;
    return 0;
}
