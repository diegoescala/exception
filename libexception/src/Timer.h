#pragma once

#include <chrono>
#include <functional>
#include <atomic>
#include <condition_variable>
#include <mutex>

class Timer {
public:
    typedef std::chrono::milliseconds Interval;
    Timer(Interval, std::function<void ()>&&);
    void stop();
    
private:
    Interval interval_;
    std::function<void ()> func_;
    std::atomic<bool> is_running_;
    std::condition_variable exit_;
    std::mutex op_mutex_;
};
