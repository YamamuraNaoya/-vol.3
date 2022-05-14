#include <bits/stdc++.h>
using namespace std;

void chmax(int& a, const int& b){
  if(a < b) a = b;
  return;
}

int main(){
  string s = "ナンジ、ブンガクトカガクノチカラヲシンジヨ";
  string t = "ジョウホウブンセキシテカイゼンアクション";
  cout << s << endl;
  cout << t << endl;
  int k = 3; //UTF-8では日本語は3バイト
  int n = s.size()/k, m = t.size()/k;
  vector<vector<int>> dp(n+1, vector<int>(m+1));
  //dp[i][j]:=sのi文字目,tのj文字目まで見た時のsとtの最大共通部分列の長さ
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      chmax(dp[i+1][j+1], dp[i+1][j]);
      chmax(dp[i+1][j+1], dp[i][j+1]);
      if(s.substr(3*i,k)==t.substr(3*j,k)){
	//kバイト分見てi文字目とj文字目の一致判定をする
	chmax(dp[i+1][j+1], dp[i][j]+1);
      }
    }
  }
  string ans;
  int i = n-1, j = m-1;
  //後ろから答えを復元
  while(i >= 0 && j >= 0){
    if(s.substr(3*i,k)==t.substr(3*j,k)){
      ans += s.substr(3*i,k);
      //cout << ans.substr(ans.size()-3,3);
      i--;
      j--;
    }else if(dp[i+1][j+1]==dp[i+1][j]){
      j--;
    }else{
      i--;
    }
  }
  //ansには逆順で答えが入っているので後ろから出力
  int l = ans.size();
  for(int i = l-k; i >= 0; i -= k){
    cout << ans.substr(i,k);
  }
  cout << endl;
}      
