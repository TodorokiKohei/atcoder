#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<ll>> dp(2, vector<ll>(n));
    dp[0][0] = a[0];
    dp[1][0] = -a[0];
    for(int i = 0; i < n-1; i++){
        dp[0][i+1] = max(dp[0][i]+a[i+1], dp[1][i]-a[i+1]);
        dp[1][i+1] = max(dp[0][i]-a[i+1], dp[1][i]+a[i+1]);
    }
    cout << dp[0][n-1] << endl;
}