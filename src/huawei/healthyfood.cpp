#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
vector<int> vv;
string s;
int low, high, x;
long long dp[1005], ans;
int main() {
    cin >> low >> high;
    getchar();
    getline(cin, s);
    stringstream ss(s);
    dp[0] = 1;
    while (ss >> x) {
        for (int j = x; j <= 1000; j++) {
            dp[j] += dp[j - x];
        }
    }
    for (int i = low; i <= high; i++) {
        ans += dp[i];
    }
    cout << ans << endl;
    return 0;
}