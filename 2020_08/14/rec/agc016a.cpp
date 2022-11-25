#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    string s;
    cin >> s;
    map<char, vector<int>> mp;
    rep(i,s.size()){
        if (mp[s[i]].size() == 0){
            mp[s[i]].push_back(0);
        }
        mp[s[i]].push_back(i+1);
    }
    int ans = 100;
    for(char c = 'a'; c <= 'z'; c++){
        if (mp.find(c) == mp.end()) continue;
        mp[c].push_back(s.size()+1);
        int num = 0;
        rep(i, mp[c].size()-1){
            num = max(num, mp[c][i+1] - mp[c][i]-1);
        }
        ans = min(ans, num);
    }
    
    cout << ans << endl;
    return 0;
}   