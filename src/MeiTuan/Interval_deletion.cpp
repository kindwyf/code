/*
小美拿到了一个大小为n的数组，她希望删除一个区间后，使得剩余所有元素的乘积末尾至少有k个0。
小美想知道，一共有多少种不同的删除方案？

输入描述
第一行输入两个正整数n，k。第二行输入n个正整数ai，代表小美拿到的数组。
1<=n,k<=10^5
1<=ai<=10^9

输出描述
一个整数，代表删除的方案数。

示例输入
5 2
2 5 3 4 20
示例输出
4
示例说明
第一个方案，删除[3]。
第二个方案，删除[4]。
第三个方案，删除[3,4]。
第四个方案，删除[2]。
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findx(int value, int x){
  int count = 0;
  while(value!=0&&value%x==0){
    count++;
    value /= x;
  }
  return count;
}

int main(){
  int n, k;
  cin>>n>>k;
  vector<int> nums(n, 0);
  vector<int> nums2(n, 0);
  vector<int> nums5(n, 0);
  int count2=0, count5=0, count0=0;
  for(int i=0; i<n; i++){
    cin>>nums[i];
    int x = findx(nums[i], 2);
    int y = findx(nums[i], 5);
    nums2[i] = x;
    nums5[i] = y;
    count2 += x;
    count5 += y;
  }
  count0 = min(count2, count5); 
  // 区间内最多有need2个2，need5个5
  int need = count0 - k;
  int need2 = count2-count0;
  int need5 = count5-count0;
  int res = 0;
  for(int i=0; i<n; i++){
    int a = 0, b = 0;
    for(int j=i; j<n; j++){
      a += nums2[j];
      b += nums5[j];
      if(min(a, b)<=need&&a<=need2&&b<=need5)
        res++;
    }
  }
  cout<<res<<endl;
  return 0;
}