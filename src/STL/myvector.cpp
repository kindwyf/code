#include<iostream>
#include<cassert>
#include<iterator>
using namespace std;

template <class T>

class vector{
  

  public:
    typedef T* iterator;
    
    iterator begin(){
      return _start;
    }

    iterator end(){
      return _finish;
    }

    size_t size(){
      return _finish - _start;
    }

    size_t capacity(){
      return _endofstorage - _start;
    }

    // 构造函数
    vector(size_t n, const T& val){
      reserve(n);
      for(size_t i=0; i<n; i++)
        push_back(val);
    }

    // 拷贝构造
    vector(const vector<T>& vec){
      reverse(vec.capacity());
      for(const auto& e:vec)
        push_back(e);
    }

    // 析构
    ~vector(){
      delete[] _start;
      _start=_finish=_endofstorage=nullptr;
    }

    // 重载[]
    T& operator[](size_t pos){
      assert(pos<size());
      return *(_start+pos);
    }

    // 扩容
    void reserve(size_t n){
      if(n>capacity()){
        size_t oldsize = size();
        T* tmp = new T[n];
        if(_start!=nullptr){
          for(size_t i=0; i<oldsize; i++){
            tmp[i] = _start[i];
          }
          delete[] _start;
        }
        _start = tmp;
        // delete tmp;
        _finish = _start + oldsize;
        _endofstorage = _start + n;
      }
    }

    void push_back(const T& val){
      if(_finish==_endofstorage){
        size_t newcapacity = capacity()==0?4:capacity()*2;
        reserve(newcapacity);
      }
      *_finish = val;
      _finish++;
    }

    void pop(){
      assert(size()>0);
      _finish--;
    }

    private:
      iterator _start = nullptr;
      iterator _finish = nullptr;
      iterator _endofstorage = nullptr;
};

int main(){
  vector<int> nums(3, 0);
  cout<<nums.size()<<" "<<nums.capacity()<<endl;
  nums.push_back(4);
  cout<<nums.size()<<" "<<nums.capacity()<<endl;
  cout<<*(nums.end()-1)<<endl;
  nums.pop();
  cout<<*(nums.end()-1)<<endl;
  return 0;
}