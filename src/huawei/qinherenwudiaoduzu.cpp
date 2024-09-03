#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// 判断一个任务和当前所有已选择的任务是否亲和
bool check(int a, vector<int>& used, unordered_map<int, unordered_set<int>>& unfam) {
    for (auto x : used) {
        if (unfam[x].count(a) || unfam[a].count(x)) {
            return false;
        }
    }
    return true;
}

int tim = INT_MAX;
int curtim = 0;
int ct = 1;
vector<int> used;

void dfs(unordered_map<int, unordered_set<int>>& unfam, vector<int>& times, int start, int n) {
    if ((int)used.size() >= ct) {
        if ((int)used.size() > ct) {
            ct = used.size();
            tim = curtim;
        } else {
            if (curtim < tim) tim = curtim;
        }
    }
    if (start > n) return;
    for (int i = start; i <= n; i++) {
        if (used.empty()) {
            used.push_back(i);
        } else {
            // 如果是亲和的
            if (check(i, used, unfam)) {
                used.push_back(i);
            } else {
                continue;
            }
        }
        curtim += times[i];
        dfs(unfam, times, i + 1, n);
        curtim -= times[i];
        used.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> times(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> times[i];
    }
    int m;
    cin >> m;
    unordered_map<int, unordered_set<int>> unfam;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unfam[a].insert(b);
        unfam[b].insert(a);
    }
    dfs(unfam, times, 1, n);
    cout << tim << endl;
    return 0;
}