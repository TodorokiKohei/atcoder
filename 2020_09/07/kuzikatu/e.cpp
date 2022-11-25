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

const int mod = 1e9+7;

int main(){
    string l;
    cin >> l;
    int n = l.size();
    VVL dp(n+1, VL(2));
    dp[0][0] = 1;
    rep(i,n){
        if (l[i] == '1'){
            dp[i+1][1] += dp[i][0];
            dp[i+1][1] += dp[i][1];

            dp[i+1][0] += dp[i][0] * 2;
            dp[i+1][0] %= mod;
            dp[i+1][1] += dp[i][1] * 2;
            dp[i+1][1] %= mod;
        }else{
            dp[i+1][0] += dp[i][0];
            dp[i+1][1] += dp[i][1];

            dp[i+1][1] += dp[i][1] * 2;
            dp[i+1][1] %= mod;
        }
    }
    ll ans = (dp[n][0] + dp[n][1]) % mod;
    cout << ans << endl;
    return 0;
}