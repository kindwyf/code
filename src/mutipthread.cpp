#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
bool turn = true;  // 控制交错打印的标志

void printEven(int maxNum) {
    for (int i = 0; i < maxNum; i += 2) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return turn; });  // 等待turn为true
        std::cout << "Even: " << i << std::endl;
        turn = false;
        cv.notify_all();  // 通知其他线程
    }
}

void printOdd(int maxNum) {
    for (int i = 1; i < maxNum; i += 2) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !turn; });  // 等待turn为false
        std::cout << "Odd : " << i << std::endl;
        turn = true;
        cv.notify_all();  // 通知其他线程
    }
}

int main() {
    std::thread evenThread(printEven, 10);
    std::thread oddThread(printOdd, 10);

    evenThread.join();
    oddThread.join();

    return 0;
}

// std::mutex mtx;  // 全局互斥锁

// void print_thread(int id) {
//     // std::lock_guard<std::mutex> guard(mtx);  // 创建lock_guard，自动加锁
//     //  std::cout << "Thread " << id << ": Hello World!" << std::endl;
//     for (int i = 0; i < 100; i++) {
//         // std::lock_guard<std::mutex> guard(mtx);
//         std::cout << id;
//     }
// }

// int main() {
//     std::thread threads[2];

//     for (int i = 0; i < 2; ++i) {
//         threads[i] = std::thread(print_thread, i);  // 创建线程
//     }

//     for (int i = 0; i < 2; ++i) {
//         threads[i].join();  // 等待线程完成
//     }

//     return 0;
// }