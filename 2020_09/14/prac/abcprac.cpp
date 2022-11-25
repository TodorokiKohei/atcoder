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
    int h, w, k;
    cin >> h >> w >> k;
    VVL dp(h+1, VL(w, 0));
    dp[0][0] = 1;
    rep(hi, h) rep(wi, w) rep(li, 1<<(w-1)){
        bool ok = true;
        rep(i, w-2){
            bool seq = ((li >> i) & 1) && ((li >> (i+1)) & 1);
            if (seq){
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        bool okRight = (wi != w-1) && ((li >> wi) & 1);
        bool okLeft = (wi != 0) && ((li >> (wi-1)) & 1);

        // 右に移動
        if (okRight){
            dp[hi+1][wi+1] += dp[hi][wi];
            dp[hi+1][wi+1] %= mod;
        }

        // 左に移動
        if (okLeft){
            dp[hi+1][wi-1] += dp[hi][wi];
            dp[hi+1][wi-1] %= mod;
        }

        // そのまま下に移動
        if (!okRight && !okLeft){
            dp[hi+1][wi] += dp[hi][wi];
            dp[hi+1][wi] %= mod;
        }
    }
    cout << dp[h][k-1] << endl;
    return 0;
}