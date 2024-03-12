#include<iostream>
#include<vector>
using namespace std;

vector<int> fa;
vector<int> ranks;

int find(int x){
    if(fa[x]!=x){
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

void merge(int x, int y){
    int rootx = find(x);
    int rooty = find(y);
    if(rootx!=rooty){
        if(ranks[rootx]<ranks[rooty])
            fa[rootx] = rooty;
        else if(ranks[rootx]>ranks[rooty])
            fa[rooty] = rootx;
        else{
            fa[rootx] = rooty;
            ranks[rooty]++;
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> nums(m, vector<int>(3));
    for(int i=0; i<m; i++)
        cin>>nums[i][0]>>nums[i][1]>>nums[i][2];
    fa.resize(n+1);
    for(int i=1; i<=n; i++){
        fa[i] = i;
    }
    ranks.resize(n+1, 0);
    for(int i=0; i<m; i++){
        if(nums[i][0]==1)
            merge(nums[i][1], nums[i][2]);
        else{
            if(find(nums[i][1])==find(nums[i][2]))
                cout<<"Y"<<endl;
            else cout<<"N"<<endl;
        }
    }
    return 0;
}