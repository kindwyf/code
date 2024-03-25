#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 解析字符串表示的元组
vector<vector<int>> parseTuple(string s) {
    vector<vector<int>> tuple;
    vector<int> stack;
    for (char c : s) {
        if (c == '[') {
            stack.clear();
        } else if (isdigit(c)) {
            int num = 0;
            while (isdigit(c)) {
                num = num * 10 + (c - '0');
                s.erase(s.begin());
                c = s[0];
            }
            stack.push_back(num);
            continue;
        } else if (c == ']') {
            tuple.push_back(stack);
        }
    }
    return tuple;
}

// 比较两个元组是否相同
bool compareTuples(vector<vector<int>>& t1, vector<vector<int>>& t2) {
    if (t1.size() != t2.size()) return false;
    for (size_t i = 0; i < t1.size(); ++i) {
        if (t1[i].size() != t2[i].size()) return false;
        for (size_t j = 0; j < t1[i].size(); ++j) {
            if (t1[i][j] != t2[i][j]) return false;
        }
    }
    return true;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        vector<vector<int>> tuple1 = parseTuple(s1);
        for(auto x:tuple1)
          for(auto y:x) 
            cout<<y<<" "; 
        cout<<endl;
        vector<vector<int>> tuple2 = parseTuple(s2);
        for(auto x:tuple1)
          for(auto y:x) 
            cout<<y<<" "; 
        cout<<endl;
        if (compareTuples(tuple1, tuple2)) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    return 0;
}
