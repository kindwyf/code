#include<iostream>
#include<vector>
#include<list>
#include<mutex>
using namespace std;

class HashTable{
  private:
    int size;
    vector<list<pair<int, int>>> ht;
    //vector<mutex> locks;
  
  public:
    HashTable(int _size){
      size = _size;
      ht.resize(_size);
      //locks.resize(_size);
    }

    void put(int key, int value){
      int idx = key%size;
      //locks[idx].lock();
      ht[idx].push_back({key, value});
      //locks[idx].unlock();
    }

    int find(int key){
      int idx = key%size;
      //locks[idx].lock();
      for(auto x:ht[idx]){
        if(x.first==key){
          //locks[idx].unlock();
          return x.second;
        }   
      }
      //locks[idx].unlock();
      return -1;
    }

    void del(int key){
      int idx = key%size;
      //locks[idx].lock();
      for(auto it=ht[idx].begin(); it!=ht[idx].end(); it++){
        if(it->first==key){
          it = ht[idx].erase(it);
          //locks[idx].unlock();
          return;
        } 
      }
    }
};

int main(){
  HashTable hat(7);
  hat.put(1, 78);
  hat.put(8, 79);
  hat.put(2, 37);
  cout<<hat.find(8)<<endl;
  hat.del(8);
  cout<<hat.find(8)<<endl;
  return 0;
}