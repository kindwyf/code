#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n,s;
  cin>>n>>s;
  vector<int> nums(n, 0);
  for(int i=0; i<n; i++){
    cin>>nums[i];
  }
  vector<int> dp(s+1, 0);
  for(int i=0; i<n; i++){
    for(int j=s; j>=nums[i]; j--){
      dp[j] = max(dp[j], dp[j-nums[i]]+nums[i]);
    }
  }
  cout<<dp[s-1]<<endl;
  return 0;
}