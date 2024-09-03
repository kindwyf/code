#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

unordered_map<int, vector<pair<int, int>>> umap;
vector<int> visited;
int n;
int ans = 1;
int res = 0;

void dfs(int start, int p) {
    for (auto [x, y] : umap[start]) {
        if (visited[x] || p < y || start == x) continue;
        ans++;
        res = max(res, ans);
        visited[x] = 1;
        dfs(x, y);
        visited[x] = 0;
        ans--;
    }
    return;
}

int main() {
    cin >> n;
    visited.resize(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp) umap[i].emplace_back(j, tmp);
        }
    }
    int start;
    vector<pair<int, int>> result;
    auto cmp = [](const pair<int, int>& l, const pair<int, int>& r) {
        if (l.second == r.second) {
            return l.first <= r.first;
        }
        return l.second > r.second;
    };
    while (cin >> start) {
        visited[start] = 1;
        res = 0;
        dfs(start, 10);
        result.emplace_back(start, res);
        visited[start] = 0;
        if (cin.get() == '\n') break;
    }
    sort(result.begin(), result.end(), cmp);
    cout << result.begin()->first << endl;
    return 0;
}