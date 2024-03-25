// #include <iostream>
// #include <vector>
// using namespace std;

// class foo{
//     public:
//     foo(){cout<<"struct"<<endl;}
//     foo(int x):_x(x){cout<<"fuck"<<endl;}
//     foo(const foo&){
//         cout<<"copy"<<endl;
//     }
//     foo(foo&&) noexcept{
//         cout<<"move"<<endl;
//     }

//     private:
//      int _x = 0;
// };

// int main(){
//     foo a,b;
//     vector<foo> s;
//     cout<<s.capacity()<<endl;
//     s.push_back(a);
//     cout<<s.capacity()<<endl;
//     //s.push_back(b);
//     s.emplace_back(1);
//     cout<<s.capacity()<<endl;
//     s.emplace_back();
//     cout<<s.capacity()<<endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int step = 0;
// int res = 0;
// int nex[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

// int panduan(vector<vector<int>>& field, int x, int y, int h, int w, int move){
//     // 说明上下移动
//     if(move==0||move==2){
//         for(int j=y; j<y+w; j++){
//             if(field[x][j]==1)
//                 return 0;
//         }
//     }
//     else{
//         for(int i=x; i<x+h; i++){
//             if(field[i][y]==1)
//                 return 0;
//         }
//     }
//     return 1;
// }

// void fill(vector<vector<int>>& field, int x, int y, int h, int w, int move){
//     // 向上移动，原来最下面一行变成0
//     // 新的上面一行变成1
//     if(move==0){
//         for(int j=y; j<y+w; j++){
//             field[x+h-1][j] = 0;
//             field[x-1][j] = 1;
//         }    
//     }
//     // 向右移动，原来最左边一列变成0
//     else if(move==1){
//         for(int i=x; i<x+h; i++){
//             field[i][y] = 0;
//             field[i][y+w] = 1;
//         }
//     }
//     // 向下移动，原来最上面一行变成0
//     else if(move==2){
//         for(int j=y; j<y+w; j++){
//             field[x][j] = 0;
//             field[x+h][j] = 1;
//         }
//     }
//     // 向左移动，原来最右边一列变成0
//     else{
//         for(int i=x; i<x+h; i++){
//             field[i][y+w-1] = 0;
//             field[i][y-1] = 1;
//         }
            
//     }
//     return;
// }

// void unfill(vector<vector<int>>& field, int x, int y, int h, int w, int move){
//     // 向上移动，原来最下面一行变成0
//     // 新的上面一行变成1
//     if(move==0){
//         for(int j=y; j<y+w; j++){
//             field[x+h-1][j] = 1;
//             field[x-1][j] = 0;
//         }    
//     }
//     // 向右移动，原来最左边一列变成0
//     else if(move==1){
//         for(int i=x; i<x+h; i++){
//             field[i][y] = 1;
//             field[i][y+w] = 0;
//         }
//     }
//     // 向下移动，原来最上面一行变成0
//     else if(move==2){
//         for(int j=y; j<y+w; j++){
//             field[x][j] = 1;
//             field[x+h][j] = 0;
//         }
//     }
//     // 向左移动，原来最右边一列变成0
//     else{
//         for(int i=x; i<x+h; i++){
//             field[i][y+w-1] = 1;
//             field[i][y-1] = 0;
//         }
            
//     }
//     return;
// }

// void dfs(vector<vector<int>>& field, vector<vector<int>>& visited, int x, int y, int h, int w){
//     if(x==1||y==1||x+h==(int)field.size()||y+w==(int)field[0].size()){
//         res = max(res, step);
//     }
//     for(int i=0; i<4; i++){
//         int nextx = x+nex[i][0];
//         int nexty = y+nex[i][1];
//         if(nextx<1||nextx>(int)field.size()-h||nexty<1||nexty>(int)field[0].size()-w) return;
//         if(panduan(field, nextx, nexty, h, w, i)&&!visited[nextx][nexty]){
//             step++;
//             visited[nextx][nexty] = 1;
//             fill(field, x, y, h, w, i);
//             dfs(field, visited, nextx, nexty, h, w);
//             unfill(field, x, y, h, w, i);
//             visited[nextx][nexty] = 0;
//             step--;
//         }
//     }
// }

// int main() {
//     int n,m,h,w,x,y;
//     cin>>n>>m>>h>>w>>x>>y;
//     vector<vector<int>> field(n+1, vector<int>(m+1, 0));
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=m; j++){
//             cin>>field[i][j];
//         }
//     }
//     vector<vector<int>> visited(n+1, vector<int>(m+1, 0));
//     visited[x][y] = 1;
//     dfs(field, visited, x, y, h, w);
//     cout<<res;
//     return 0;
// }
// // 64 位输出请用 printf("%lld")


// #include <algorithm>
// #include <climits>
// #include <iostream>
// #include <vector>
// using namespace std;

// int sum(vector<int>& nums, int begin, int end, int m, int k){
//     int res = 0;
//     for(int i=begin; i<=end; i++){
//         if(m>0){
//             res += -1*nums[i]*k;
//             m--;
//         }else
//             res += nums[i];
//     }
//     return res;
// }

// int main() {
//     int T;
//     cin>>T;
//     while(T--){
//         int n,m,k,d;
//         cin>>n>>m>>k>>d;
//         vector<int> nums(n, 0);
//         for(int i=0; i<n; i++)
//             cin>>nums[i];
//         sort(nums.begin(), nums.end(), [](int a, int b){return a>b;});
//         // for(auto x:nums) cout<<x<<" ";
//         // cout<<endl;
//         int res = INT_MIN;
//         for(int i=0; i<=d; i++){
//             res = max(res, sum(nums, i, n-1, m ,k));
//         }
//         cout<<res<<endl;
//         return 0;
//     }
// }
// 64 位输出请用 printf("%lld")

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 这是x所有可以到达的节点
void find(unordered_map<int, vector<int>>& umap, vector<int>& visited, int x){
    visited[x] = 1;
    for(auto y:umap[x]){
        if(!visited[y])
            find(umap, visited, y);
    }
    return;
}

int main() {
    int n, m;
    cin>>n>>m;
    unordered_map<int, vector<int>> umap;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        umap[x].push_back(y);
    }
    int res = 0;
    vector<vector<int>> visited(n+1, vector<int>(n+1,0));
    for(int i=1; i<=n; i++){
        find(umap, visited[i], i);
    }
    for(int i=1; i<=n; i++){
        bool index = true;
        for(int j=1; j<=n; j++){
            if(!visited[i][j]&&!visited[j][i]){
                index = false;
                break;
            }
        }
        if(index) res++;
    }
    cout<<res<<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")