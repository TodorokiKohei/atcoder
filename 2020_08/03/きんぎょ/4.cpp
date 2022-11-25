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
    vector<bool> dp(s.size()+1);
    vector<string> t = {"dream", "dreamer", "erase", "eraser"};
    dp[0] = true;   
    for(int i = 0; i < s.size(); i++){
        if (dp[i]){
            for(string tt: t){
                if (s.substr(i, tt.size()) == tt) dp[i+tt.size()] = true;
            }
        }
    }
    if (dp[s.size()]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}