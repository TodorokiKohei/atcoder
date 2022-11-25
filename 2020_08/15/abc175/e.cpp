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

int a[3005][3005];
ll dp[3005][3005][4];

int main(){
    int R, C, n;
    cin >> R >> C >> n;
    rep(i,n){
        int r, c, v;
        cin >> r >> c >> v;
        a[r-1][c-1] = v;
    }

    rep(i,R) rep(j,C){
        for(int k = 2; k >= 0; k--){
            chmax(dp[i][j][k+1], dp[i][j][k] + a[i][j]);
        }

        rep(k, 4){
            chmax(dp[i+1][j][0], dp[i][j][k]);
            chmax(dp[i][j+1][k], dp[i][j][k]);
        }
    }

    ll ans = 0;
    rep(k, 4){
        chmax(ans, dp[R-1][C-1][k]);
    }
    cout << ans << endl;
    return 0;
}