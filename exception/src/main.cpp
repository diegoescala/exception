#include "ExceptionCore.h"

#include <iostream>
#include <thread>
#include <sstream>
#include <dlfcn.h>

void loadModule(ExceptionCore& core, const std::string& moduleName) {
    std::stringstream filename;
    filename << "modules/lib" << moduleName << ".dylib";
    void* dylib = dlopen(filename.str().c_str(), RTLD_LAZY);
    void (*print)()= (void(*)())dlsym(dylib, "print");

    if (print == NULL) {
        std::cout << "unable to load print function!" << std::endl;
        dlclose(dylib);
    } else {
        print();
    }

    dlclose(dylib);

}

int main(int argc, char** argv) {
    std::cout << "hai exception" << std::endl;

    {
        ExceptionCore core;
        loadModule(core, "WeatherModule");
        // core.addModule(std::make_shared<WeatherModule>("It's rainy; grab an umbrella!"));
        // std::this_thread::sleep_for(std::chrono::milliseconds(4500));
        // core.addModule(std::make_shared<WeatherModule>("It's sunny; wear some sunscreen!"));
        // std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    }
    std::cout << "bai exception" << std::endl;
    return 0;
}
