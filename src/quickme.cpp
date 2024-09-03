#include <iostream>
using namespace std;

#define ll long long

// calculate a^b%c
ll quickpow(ll a, ll b, ll c) {
    ll res = 1;
    a %= c;
    while (b) {
        if (b % 2 == 1) {
            res *= a;
            res %= c;
        }
        a *= a;
        a %= c;
        b /= 2;
    }
    return res;
}

int main() {
    ll a = 18;
    ll b = 23;
    ll c = 1e9 + 7;
    cout << quickpow(a, b, c) << endl;
    return 0;
}