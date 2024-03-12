/* 
小美拿到了一个n*n 的矩阵，其中每个元素是 0 或者 1。
小美认为一个矩形区域是完美的，当且仅当该区域内 0 的数量恰好等于 1 的数量。
现在，小美希望你回答有多少个i*i的完美矩形区域。你需要回答1<=i<=n的所有答案。

输入描述
第一行输入一个正整数n，代表矩阵大小。
接下来的n行，每行输入一个长度为n的01 串，用来表示矩阵。

输出描述
输出n行，第i行输出的I*I 完美矩形区域的数量。
*/


#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int helper(int startx, int starty, int endx, int endy, vector<vector<int>>& sums){
    return sums[endx+1][endy+1]-sums[startx][endy+1]-sums[endx+1][starty]+sums[startx][starty];
}

int main() {
    int n;
    cin>>n;
    //vector<vector<char>> nums(n, vector<char>(n));
    vector<vector<int>> nums(n, vector<int>(n, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>nums[i][j];
        }
    }
    vector<vector<int>> sums(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        sums[i][j] = sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+int(nums[i-1][j-1]);
      }
    }
    vector<int> res(n, 0);
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        for(int k=0; k<n; k++){
          if(i+k<n&&j+k<n){
            if(helper(i,j,i+k,j+k,sums)*2==pow(k+1, 2))
              res[k]++;
          }
        }
      }
    }
    for(auto r:res)
      cout<<r<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")