#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n, t;
    cin >> n >> t;
    VP ab(n);
    rep(i,n) cin >> ab[i].first >> ab[i].second;
    sort(all(ab));
    VVL dp(n+1, VL(t+1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= t; j++){
            dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
            if (j != t){
                int col = min(j+ab[i].first, t);
                dp[i+1][col] = max(dp[i+1][col], dp[i][j] + ab[i].second);
            }
        }
    }
    cout << dp[n][t] << endl;
    return 0;
}