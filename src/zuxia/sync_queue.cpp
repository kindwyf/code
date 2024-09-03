#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
using namespace std;

/*
 * T: 元素类型
 * capacity：最大容量
 */
template <typename T, size_t capacity>
struct SyncQueue {
public:
    // TODO
    SyncQueue(){};

    // 阻塞push
    void push(const T& value) {
        lock_guard<mutex> lock(m_mutex);
        not_full.wait(lock, [this] { return m_queue.size() < capacity; });
        m_queue.push(value);
        not_empty.notify_one();
    }

    // 非阻塞push
    int npush(const T& value) {
        lock_guard<mutex> lock(m_mutex);
        if (m_queue.size() < capacity) {
            m_queue.push(value);
            not_empty.notify_one();
            return 0;
        }
        return -1;
    }

    // 阻塞pop
    T pop() {
        lock_guard<mutex> lock(m_mutex);
        not_empty.wait(lock, [this] { return !m_queue.empty(); });
        T value = m_queue.front();
        m_queue.pop();
        not_full.notify_one();
        return value;
    }

    // 非阻塞pop
    int npop(T& value) {
        lock_guard<mutex> lock(m_mutex);
        if (!m_queue.empty()) {
            value = m_queue.front();
            m_queue.pop();
            not_full.notify_one();
            return 0;
        }
        return -1;
    }

    // 队列元素个数
    size_t size() const {
        lock_guard<mutex> lock(m_mutex);
        return m_queue.size();
    }

    // 判断队列是否为空
    bool empty() const {
        lock_guard<mutex> lock(m_mutex);
        return m_queue.empty();
    }

private:
    // TODO
    queue<T> m_queue;
    mutable mutex m_mutex;         // 互斥锁
    condition_variable not_full;   // 队列非满条件变量
    condition_variable not_empty;  // 队列非空条件变量
};
int main() {
    // TODO
    SyncQueue<int, 3> sq;
    return 0;
}
