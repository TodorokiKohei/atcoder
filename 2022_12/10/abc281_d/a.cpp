#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int inf = 1 << 29;
const ll INF = 1LL << 60;

int main(){
    int n;
    ll k, d;
    cin >> n >> k >> d;
    VL a(n);
    rep(i,n) cin >> a[i];

    vector<vector<vector<ll>>> dp(n+1, VVL(d, VL(k+1, -INF)));
    dp[0][0][0] = 0;
    rep(i,n) {
        rep(j, d) {
            rep(x, k+1) {
                chmax(dp[i+1][j][x], dp[i][j][x]);
            }
            rep(x, k) {
                if (dp[i][j][x] == -INF) continue;
                ll num = dp[i][j][x] * d + j;
                chmax(dp[i+1][(j+a[i])%d][x+1], (num+a[i])/d);
            }
        }
    }
    if (dp[n][0][k] == -INF) cout << -1 << endl;
    else cout << dp[n][0][k]*d << endl;
    return 0;
}