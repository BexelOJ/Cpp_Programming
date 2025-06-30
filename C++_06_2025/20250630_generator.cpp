#include <iostream>
#include <coroutine>
#include <optional>

using namespace std;

template<typename T>
struct Generator {
    struct promise_type;
    using handle_type = coroutine_handle<promise_type>;

    struct promise_type {
        T current_value;
        suspend_always yield_value(T value) {
            current_value = value;
            return {};
        }
        suspend_always initial_suspend() { return {}; }
        suspend_always final_suspend() noexcept { return {}; }
        Generator get_return_object() {
            return Generator{handle_type::from_promise(*this)};
        }
        void return_void() {}
        void unhandled_exception() { std::exit(1); }
    };

    handle_type h;

    Generator(handle_type h) : h(h) {}
    ~Generator() { if (h) h.destroy(); }

    T next() {
        h.resume();
        return h.promise().current_value;
    }
};

Generator<int> fibGen() {
    int a = 0, b = 1;
    while (true) {
        co_yield a;
        auto temp = a;
        a = b;
        b = temp + b;
    }
}

int main() {
    auto gen = fibGen();
    for (int i = 0; i < 10; ++i)
        cout << gen.next() << " ";
}

