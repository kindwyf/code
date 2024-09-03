#include <cstring>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// struct hash_pair {
//     template <class T1, class T2>
//     size_t operator()(const pair<T1, T2>& p) const {
//         auto hash1 = hash<T1>{}(p.first);
//         auto hash2 = hash<T2>{}(p.second);
//         return hash1 ^ hash2;
//     }
// };

int main() {
    int n;
    cin >> n;
    string a[4];
    unordered_set<string> ex;
    map<pair<string, string>, int> umap1;
    while (n--) {
        string s, t;
        cin >> s;
        stringstream ss(s);
        int i = 0;
        while (getline(ss, t, ',')) {
            a[i++] = t;
        }
        if (ex.count(a[0] + a[1] + a[2])) {
            continue;
        } else {
            ex.emplace(a[0] + a[1] + a[2]);
        }
        int num = stoi(a[3]);
        if (num <= 0 || num >= 100) continue;
        umap1[{a[1], a[2]}] += num;
    }

    int m;
    cin >> m;
    unordered_map<string, int> umap2;
    while (m--) {
        string s, t;
        cin >> s;
        stringstream ss(s);
        int i = 0;
        while (getline(ss, t, ',')) {
            a[i++] = t;
        }
        umap2[a[0]] = stoi(a[1]);
    }
    map<string, int> umap3;
    for (auto [c, t] : umap1) {
        umap3[c.first] += umap2[c.second] * t;
    }
    for (auto [c, m] : umap3) {
        cout << c << "," << m << endl;
    }
    return 0;
}