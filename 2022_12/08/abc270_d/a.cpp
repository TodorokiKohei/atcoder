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
    int n, k;
    cin >> n >> k;
    VI a(k);
    rep(i,k) cin >> a[i];
    VVL dp(2, VL(n+1));
    rep(i,n+1) {
        dp[0][i] = 0;
        dp[1][i] = INF;
    }
    dp[0][0] = 0; dp[1][0] = 0;
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < k; j++){
            if (a[j] > i) break;
            chmax(dp[0][i], dp[1][i-a[j]] + a[j]);
            chmin(dp[1][i], dp[0][i-a[j]]);
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}