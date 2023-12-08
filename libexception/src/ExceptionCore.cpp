#include "ExceptionCore.h"
#include "ExceptionModule.h"
#include "Timer.h"

ExceptionCore::ExceptionCore():
    running_(true)
{
    display_render_timer_ = 
        std::unique_ptr<Timer>(new Timer(
            std::chrono::milliseconds(2000), 
            [&]()
            {
                this->display_.renderMessages();
                
            }));
}

ExceptionCore::~ExceptionCore() {
    for (auto& mt : module_timers_) {
        mt.second->stop();
    }
    module_timers_.clear();
}

void ExceptionCore::addModule(std::shared_ptr<ExceptionModule> module)
{
    module_timers_[module] = std::unique_ptr<Timer>(new Timer(std::chrono::milliseconds(1000), [&](){
        auto messages = module->getMessages();
        this->display_.addMessages((ptrdiff_t)(module.get()), messages);
    }));
}
