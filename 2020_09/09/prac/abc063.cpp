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
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    int sum = 0;
    rep(i,n) sum += s[i];

    VVI dp(n+1, VI(sum+1, -1));
    dp[0][0] = 1;
    rep(i,n){
        rep(j, sum+1){
            if (dp[i][j] == -1) continue;
            chmax(dp[i+1][j], dp[i][j]);
            if (j + s[i] <= sum){
                dp[i+1][j+s[i]] = 1;
            }
        }
    }
    int ans = 0;
    rep(i, sum+1){
        if (dp[n][i] == 1 && i % 10 != 0) ans = i;
    }
    cout << ans << endl;
    return 0;
}