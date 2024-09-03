#include <climits>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k, x;
        cin >> n >> k >> x;
        unordered_set<int> uset;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            uset.insert(A[i]);
        }
        int mem = 0;
        for (int i = 0; i <= n; i++) {
            if (!uset.count(i)) {
                mem = i;
                break;
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = min(res, k * i + x * mem);
            mem = min(mem, A[i]);
        }
        cout << res << endl;
    }
}