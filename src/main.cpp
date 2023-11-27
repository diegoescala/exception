#include "ExceptionCore.h"
#include "WeatherModule.h"
#include "Timer.h"

#include <iostream>
#include <thread>

void print() {
    std::cout << "hei" << std::endl;
}

int main(int argc, char** argv) {
    std::cout << "hai exception" << std::endl;
    {
        ExceptionCore core;
        core.addModule(std::make_shared<WeatherModule>());
        Timer t(std::chrono::milliseconds(1000), print);
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        t.stop();
        std::cout << "bai exception" << std::endl;
    }
    return 0;
}
