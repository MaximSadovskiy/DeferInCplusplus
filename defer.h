#ifndef DEFER_H
#define DEFER_H

#include <functional>

class Defer__ {
public:
    using FuncPtr = std::function<void()>;

    Defer__(FuncPtr func) noexcept : func_(func) {}
    ~Defer__() noexcept { func_(); }
    Defer__& operator=(const Defer__&) = delete;
    Defer__(const Defer__&) = delete;
private:
    FuncPtr func_;
};

#define CONCAT(a, b) a ## b
#define CONCAT_EXPAND(a, b) CONCAT(a,b)
#define defer(text) Defer__ CONCAT_EXPAND(defer,__COUNTER__)([&](){text});

#endif // DEFER_H