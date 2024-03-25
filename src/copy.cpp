#include <iostream>
#include <cstring>
using namespace std;

class Copy{
  private:
    char* p;

  public:
    Copy():p(nullptr){}

    Copy(const char* _p):p(new char[strlen(_p)+1]){
      strcpy(p, _p);
    }

    ~Copy(){
      delete[] p;
    }

    // 拷贝构造:
    // 浅拷贝
    Copy(const Copy& other):p(other.p){};
    

    // 深拷贝
    // Copy(const Copy& other):a(other.a), p(new char[strlen(other.p)+1]){
    //   strcpy(p, other.p);
    // }
    Copy& operator=(const Copy& other){ // &是引用
      if(this==&other) // &是取地址，&other是指针 
        return *this;
      p = new char[strlen(other.p)+1];
      strcpy(p, other.p);
      return *this;
    }

    // 移动构造
    //Copy()
};

int main(){
  char p[] = "hello word";
  Copy* _old = new Copy(p);
  Copy  _new1(*_old);
  Copy _new2;
  _new2 = *_old;
  delete _old;
  return 0;
}