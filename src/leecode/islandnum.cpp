#include<iostream>
#include<vector>
using namespace std;


  int nex[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
  void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int x, int y){
      visited[x][y] = 1;
      for(int i=0; i<4; i++){
          int nextx = x+nex[i][0];
          int nexty = y+nex[i][1];
          if(nextx<0||nextx>(int)grid.size()-1||nexty<0||nexty>(int)grid[0].size()-1)
              continue;
          if(!visited[nextx][nexty]&&grid[nextx][nexty]=='1')
              dfs(grid, visited, nextx, nexty);
      }
      return;
  }
  int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
      vector<vector<int>> visited(n, vector<int>(m,0));
      int res = 0;
      for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
              if(!visited[i][j]&&grid[i][j]=='1'){
                  res++;
                  dfs(grid, visited, i, j);
              }
          }
      }
      return res;
  }


int main(){
  vector<vector<char>> grid = 
  {{'1','1','1','1','0'},
  {'1','1','0','1','0'},
  {'1','1','0','0','0'},
  {'0','0','0','0','0'}};
  cout<<numIslands(grid)<<endl;
}