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

ll dp[105][4][4][4];

int main(){
    int n;
    cin >> n;
    rep(j, 4) rep(k, 4) rep(l, 4) {
        if (j == 0 && k == 1 && l == 2) continue;   // ACG
        if (j == 0 && k == 2 && l == 1) continue;   // AGC
        if (j == 2 && k == 0 && l == 1) continue;   // GAC
        dp[3][j][k][l] = 1;
    }

    for(int i = 3; i < n; i++){
        int ni = i + 1;
        rep(j, 4) rep(k, 4) rep(l, 4){
            rep(c, 4){
                if (k == 0 && l == 2 && c == 1) continue;   // ~AG + C
                if (k == 0 && l == 1 && c == 2) continue;   // ~AC + G
                if (k == 2 && l == 0 && c == 1) continue;   // ~GA + C
                if (j == 0 && l == 2 && c == 1) continue;   // A~G + C
                if (j == 0 && k == 2 && c == 1) continue;   // AG~ + C
                dp[ni][k][l][c] += dp[i][j][k][l];
                dp[ni][k][l][c] %= mod;
            }
        }
    }
    ll ans = 0;
    rep(j, 4) rep(k, 4) rep(l, 4) {
        ans += dp[n][j][k][l];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}