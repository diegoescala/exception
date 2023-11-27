#pragma once

#include "Display.h"

#include <atomic>
#include <vector>
#include <map>
#include <memory>

class Timer;
class ExceptionModule;

class ExceptionCore {
public:
    ExceptionCore();
    virtual ~ExceptionCore();
    
    void addModule(std::shared_ptr<ExceptionModule> module);
    
    inline void setIsRunning(bool status) { running_ = status; }
    
private:
    std::atomic<bool> running_;
    std::map<std::shared_ptr<ExceptionModule>, std::unique_ptr<Timer>> module_timers_;
    Display display_;
    std::unique_ptr<Timer> display_render_timer_;
    
};
