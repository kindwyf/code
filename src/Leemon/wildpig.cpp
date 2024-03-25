#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> nums(n, 0);
  vector<int> res(n, -1);
  map<int, int> mp;
  for(int i=0; i<n; i++){
    cin>>nums[i];
    mp[nums[i]]++;
  }
  for(int i=0; i<n; i++){
    auto it = mp.upper_bound(nums[i]);
    if(it!=mp.end())
      res[i]=it->first;
    mp[nums[i]]--;
    if(mp[nums[i]]==0){
      mp.erase(nums[i]);
    }
  }
  for(auto x:res)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}