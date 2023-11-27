#include "Timer.h"
#include <thread>
#include <iostream>

Timer::Timer(Timer::Interval interval,
             std::function<void () >&& func):
        interval_(interval),
        func_(std::move(func)),
        is_running_(true)
{
    std::thread([this]() {
        while (is_running_) {
            std::this_thread::sleep_for(interval_);
            if (is_running_)
            {
                func_();
            }
        }
        std::cout << "Timer exiting" << std::endl << std::flush;
        exit_.notify_one();
    }).detach();
    
}

void Timer::stop() {
    is_running_ = false;
    std::unique_lock<std::mutex> lk(op_mutex_);
    exit_.wait(lk);
    std::cout << "Timer stopped" << std::endl;
}
