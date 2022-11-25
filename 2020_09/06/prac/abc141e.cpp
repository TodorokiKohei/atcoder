#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> dp(n+1, vector<int>(n+1));
    rrep(i,n ){
        rrep(j,n){
            if (s[i] == s[j]) dp[i][j] = dp[i+1][j+1] + 1;
            else dp[i][j] = 0;
        }
    }

    int ans = 0;
    rep(i,n){
        rep(j,n){
            if (i >= j) continue;
            int now = min(dp[i][j], j-i);
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}