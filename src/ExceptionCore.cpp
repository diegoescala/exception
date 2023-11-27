#include "ExceptionCore.h"
#include "ExceptionModule.h"
#include "Timer.h"

ExceptionCore::ExceptionCore():
    running_(true)
{
}

ExceptionCore::~ExceptionCore() {
    for (auto& mt : module_timers_) {
        mt.second->stop();
    }
    module_timers_.clear();
}

void ExceptionCore::addModule(std::shared_ptr<ExceptionModule> module)
{
    module_timers_[module] = new Timer(std::chrono::milliseconds(1000), [&](){
        auto messages = module->getMessages();
        this->display_.addMessages((ptrdiff_t)(module.get()), messages);
    });
}
