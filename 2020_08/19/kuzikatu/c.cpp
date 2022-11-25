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

const int mod = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    rep(i,m){
        int j;
        cin >> j;
        a[j] = 1;
    }

    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i = 0; i <= n; i++){
        if (i + 1 <= n && a[i+1] != 1) {
            dp[i+1] += dp[i];
            dp[i+1] %= mod;
        }
        if (i + 2 <= n && a[i+2] != 1){
            dp[i+2] += dp[i];
            dp[i+2] %= mod;
        } 
    }
    cout << dp[n] << endl;
    return 0;
}