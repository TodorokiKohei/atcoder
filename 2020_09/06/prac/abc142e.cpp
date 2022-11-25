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


const int INF = 1<<30;

int main(){
    int n, m;
    cin >> n >> m;
    VI a(m), b(m);
    VVI c(m, VI(n, -1));
    rep(i,m){
        cin >> a[i] >> b[i];
        rep(j, b[i]){
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    VI dp(1<<n, INF);
    dp[0] = 0;
    rep(i,m){
        int now = 0;
        rep(j,b[i]){
            now |= 1<<c[i][j];
        }
        rep(j, 1<<n){
            dp[j | now] = min(dp[j | now], dp[j] + a[i]);
        }
    }
    if (dp[(1<<n)-1] == INF) cout << -1 << endl;
    else cout << dp[(1<<n)-1] << endl;
    return 0;
}