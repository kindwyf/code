#include<iostream>
#include<cstring>
#include<cassert>
using namespace std;

class MyString{
  private:
    size_t size=0;
    char* str=nullptr;
  
  public:
    MyString(){
      size = 0;
      str = nullptr;
    }

    MyString(const char* _str){
      //cout<<"我是构造函数"<<endl;
      size = strlen(_str);
      str = new char[size+1];
      strcpy(str, _str);
    }

    ~MyString(){
      delete[] str;
      size = 0;
    }

    char& operator[](const size_t pos){
      assert(pos<size);
      return str[pos];
    }

    MyString& operator=(const MyString& other){
      //cout<<"我是重载等于号"<<endl;
      if(str){
        if(strcmp(str, other.str)==0){
          return *this;
        }
        delete[] str;
      }
      size = strlen(other.str);
      str = new char[size+1];
      strcpy(str, other.str);
      return *this;
    }

    MyString operator+(const MyString& other){
      //cout<<"我是重载加号"<<endl;
      size_t len = other.size+size;
      char* temp = new char[len+1];
      strcpy(temp, str);
      strcat(temp, other.str);
      MyString x(temp);
      delete[] temp;
      return x;
    }

    // ostream& operator<<(ostream& os){
    //   os << str;
    //   return os;
    // }
    void get(){
      cout<<str<<endl;
    }

    // 拷贝构造
    MyString(const MyString& other){
      //cout<<"我是拷贝构造"<<endl;
      if(str){
        delete[] str;
      }   
      size = strlen(other.str);
      str = new char[size+1];
      strcpy(str, other.str);
    }
};

int main(){
  MyString a("hello world");
  a.get();
  //cout<<a<<endl;
  //MyString b(a);
  MyString b;
  MyString* c = new MyString("abc");
  b = *c+a;
  b.get();
  delete(c);
  // cout<<b<<endl;
  return 0;
}

