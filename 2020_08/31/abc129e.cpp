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

const int mod = 1e9+7;
int dp[100005][2];

int main(){
    string s;
    cin >> s;
    int n = s.size();
    dp[0][0] = 1;
    rep(i,n){
        {
            if (s[i] == '0'){
                dp[i+1][0] = dp[i][0];
                dp[i+1][1] = dp[i][1];
            }else{
                dp[i+1][1] = (dp[i][0] + dp[i][1]) % mod;
            }
        }

        {
            if (s[i] == '0'){
                (dp[i+1][1] += dp[i][1]*2 % mod) %= mod;
            }else{
                (dp[i+1][0] += dp[i][0]*2 % mod) %= mod;
                (dp[i+1][1] += dp[i][1]*2 % mod) %= mod;
            }
        }
    }
    int ans = (dp[n][0] + dp[n][1]) % mod;
    cout << ans << endl;
    return 0;
}