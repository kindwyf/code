#include <cstddef>
#include <cstring>
#include <iostream>
using namespace std;

class Copy {
private:
    char* p = nullptr;

public:
    Copy() : p(nullptr) {}

    Copy(const char* _p) : p(new char[strlen(_p) + 1]) {
        cout << "深拷贝构造函数" << endl;
        strcpy(p, _p);
    }

    ~Copy() {
        if (p) delete[] p;
        p = nullptr;
    }

    // 拷贝构造:
    // 浅拷贝
    Copy(const Copy& other) : p(other.p) { cout << "浅拷贝构造" << endl; };

    // 深拷贝
    // Copy(const Copy& other):p(new char[strlen(other.p)+1]){
    //   strcpy(p, other.p);
    // }
    Copy& operator=(const Copy& other) {  // &是引用
        cout << "深拷贝构造" << endl;
        // 证同测试，自我赋值
        if (this == &other)  // &是取地址，&other是指针
            return *this;
        p = new char[strlen(other.p) + 1];  // 如果new抛出异常，则p指向了被删除的char
        strcpy(p, other.p);
        return *this;
    }

    // 移动构造
    Copy(Copy&& other) {
        cout << "移动构造" << endl;
        p = other.p;
        delete[] other.p;
    }
};

int main() {
    char p[] = "hello word";
    Copy* _old = new Copy(p);
    // Copy _old(p);
    Copy _new1(*_old);  // new1和old内部指针指向同一片空间
                        // Copy _new2;
                        //  Copy* _new2 = _old;
                        //_new2 = *_old;
                        //  delete _new2;
    delete _old;
    //_old = nullptr;
    return 0;
}