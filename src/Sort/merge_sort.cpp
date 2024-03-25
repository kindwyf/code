#include<iostream>
#include<vector>
using namespace std;

void merge_sort(vector<int>& nums, int left, int right){
  if(left>=right) return;
  int mid = (left+right)/2;
  merge_sort(nums, left, mid);
  merge_sort(nums, mid+1, right);
  int begin1 = left, end1 = mid;
  int begin2 = mid+1, end2 = right;
  int idx = left;
  vector<int> tmp(nums.size());
  while(begin1<=end1&&begin2<=end2){
    if(nums[begin1]<=nums[begin2])
      tmp[idx++] = nums[begin1++];
    else
      tmp[idx++] = nums[begin2++];
  }
  while(begin1<=end1)
    tmp[idx++] = nums[begin1++];
  while(begin2<=end2)
    tmp[idx++] = nums[begin2++];
  while(left<=right){
    nums[left] = tmp[left];
    left++;
  }
}

int main(){
  vector<int> nums = {2,14,516,64,788,4,32,45,67};
  merge_sort(nums, 0, nums.size()-1);
  for(auto x:nums)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}
