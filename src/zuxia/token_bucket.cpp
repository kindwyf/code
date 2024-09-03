#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

// 获取当前时间，简单起见我们的时间粒度是秒
struct FastTime {
    static int seconds_since_epoch();
};
int FastTime::seconds_since_epoch() {
    auto now = chrono::system_clock::now();
    auto seconds = chrono::time_point_cast<chrono::seconds>(now);
    return seconds.time_since_epoch().count();
}

struct TokenBucket {
    /**
     * @brief Construct a new Token Bucket object
     *
     * @param tokens_per_second 每秒添加的token个数
     * @param capacity 桶中最多可以容纳多少个token
     */
    TokenBucket(int tokens_per_second, int capacity) : tokens_per_second(tokens_per_second), m_capacity(capacity) {
        last_time = FastTime::seconds_since_epoch();
        m_tokens = capacity;
    }
    /**
     * @brief 申请request个token
     *
     * @param request
     * @return int 实际拿到的token数量
     */
    int allocate(int request) {
        lock_guard<mutex> lock(m_mutex);
        refill();
        int tokens_to_allocate = min(request, m_tokens);
        m_tokens -= tokens_to_allocate;
        return tokens_to_allocate;
    }

private:
    int tokens_per_second;  // 每秒添加的token个数
    int m_capacity;         // 桶中最多可以容纳多少个token
    int m_tokens;           // 当前令牌数量
    int last_time;          // 上次更新时间
    mutex m_mutex;          // 互斥锁

    // 更新令牌数量
    void refill() {
        int current_time = FastTime::seconds_since_epoch();
        int elapsed = current_time - last_time;
        m_tokens = min(m_tokens + elapsed * tokens_per_second, m_capacity);
        last_time = current_time;
    }
};

int main() {
    TokenBucket tkb(2, 10);
    for (int i = 0; i < 5; ++i) {
        this_thread::sleep_for(chrono::seconds(1));
        std::cout << "allocate " << tkb.allocate(6) << " tokens" << std::endl;
    }
    return 0;
}