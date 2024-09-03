#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> fa;
unordered_map<int, int> umap;

int find(int x) {
    if (fa[x] != x) {
        return find(fa[x]);
    }
    return fa[x];
}

int main() {
    int n;
    cin >> n;
    fa.resize(n);
    for (int i = 0; i < n; i++) fa[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp > 0) {
                int rootx = find(i);
                int rooty = find(j);
                if (rootx != rooty) {
                    fa[rooty] = rootx;
                    umap[rootx] += tmp;
                }
            }
        }
    }
    vector<int> res;
    for (auto [a, b] : umap) {
        res.push_back(b);
    }
    sort(res.begin(), res.end());
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    return 0;
}