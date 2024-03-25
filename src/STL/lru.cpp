#include<iostream>
#include<unordered_map>
#include<list>
#include<utility>
// #include <bits/stdc++.h>

using namespace std;

class LRUCache{
  public:
    LRUCache(int _capacity){
      capacity = _capacity;
    }

    int get(int key){
      auto it = umap.find(key);
      if(it==umap.end())
        return -1;
      auto temp = *(it->second);
      LRUlist.erase(it->second);
      umap.erase(it);
      LRUlist.push_front(temp);
      umap.emplace(key, LRUlist.begin());
      return temp.second;
    }

    void put(int key, int value){
      auto it = umap.find(key);
      if(it!=umap.end()){
        LRUlist.erase(it->second);
        umap.erase(it);
      }
      LRUlist.push_front({key, value});
      umap.emplace(key, LRUlist.begin());
      if((int)LRUlist.size()>capacity){
        umap.erase(LRUlist.back().first);
        LRUlist.pop_back();
      }
    }
  private:
    int capacity;
    list<pair<int, int>> LRUlist;
    unordered_map<int, list<pair<int, int>>::iterator> umap;
};

int main(){
  LRUCache* lRUCache = new LRUCache(2);
  lRUCache->put(1, 1); // 缓存是 {1=1}
  lRUCache->put(2, 2); // 缓存是 {1=1, 2=2}
  cout<<lRUCache->get(1)<<endl;    // 返回 1
  lRUCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
  cout<<lRUCache->get(2)<<endl;    // 返回 -1 (未找到)
  lRUCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
  cout<<lRUCache->get(1)<<endl;    // 返回 -1 (未找到)
  cout<<lRUCache->get(3)<<endl;    // 返回 3
  cout<<lRUCache->get(4)<<endl;    // 返回 4
  delete(lRUCache);
  return 0;
}