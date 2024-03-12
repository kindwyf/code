#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_map>
using namespace std;


string minWindow(string s, string t) {
 unordered_map<char,int>ht,hs;
  for(char c:t) ht[c]++;
  string res;
  int cnt=0;
  for(int i=0,j=0;i<(int)s.size();i++)
  {
      hs[s[i]]++;
      if(hs[s[i]]<=ht[s[i]]) ++cnt;
      while(j<i&&hs[s[j]]>ht[s[j]]) hs[s[j++]]--;
      if(cnt==(int)t.size())
      {
          if(res.empty()||(int)res.size()>i-j+1) res=s.substr(j,i-j+1);
      }
  }
  return res;
}

int main(){
  string s = "ADOBECODEBANC", t="ABC";
  cout<<minWindow(s, t)<<endl;
}