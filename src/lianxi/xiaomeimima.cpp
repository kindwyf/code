/*
小美准备登录美团，需要输入密码，小美忘记了密码，只记得密码可能是
n个字符串中的一个。小美会按照密码的长度从小到大依次尝试每个字符串，对于相同长度的字符串，小美随机尝试，并且相同的密码只会尝试一次。小美想知道，她最少需要尝试多少次才能登录成功，最多需要尝试多少次才能登录成功。

小美不会重新尝试已经尝试过的字符串。成功登录后会立即停止尝试。

输入描述

第一行输入一个整数 n(1<=n<=1000)代表密码字符串的个数。

第二行输入一个只由小写字母组成的字符串 s(1<=|s|<=1000)代表正确的密码。

接下来 n 行，每行输入一个长度不超过 1000的字符串，代表小美记得的密码。

输出描述

在一行上输出两个整数，表示最少和最多尝试次数。
*/

#include <cstddef>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    size_t len = s.size();
    int pre = 0, equal = 0;
    unordered_set<string> uset1;
    unordered_set<string> uset2;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        if (tmp.size() < len && !uset1.count(tmp)) {
            pre++;
            uset1.insert(tmp);
        } else if (tmp.size() == len && !uset2.count(tmp)) {
            equal++;
            uset2.insert(tmp);
        }
    }
    cout << pre + 1 << " " << pre + equal << endl;
    return 0;
}