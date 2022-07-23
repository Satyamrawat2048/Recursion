#include<bits/stdc++.h> 
using namespace std;

vector<string> getpath(int n) {
    if(n==0) return {""};
    if(n<0) return {};
    
    vector<string> s1= getpath(n-1) ;
    vector<string> s2= getpath(n-2) ;
    vector<string> s3= getpath(n-3) ;
    
    vector<string> str ;
    
    for(string s: s1)
    str.push_back('1'+s) ;
    
    for(string s: s2)
    str.push_back('2'+s) ;
    
    for(string s: s3)
    str.push_back('3'+s) ;
    
    return str;
}

int main() {
  int n;
  cin >> n;
  vector<string> ans = getpath(n);
  int cnt = 0;

  cout << '[';
  for (string str : ans) {
    if (cnt != ans.size() - 1)
      cout << str << ", ";
    else
      cout << str;
    cnt++;
  }
  cout << ']';
}