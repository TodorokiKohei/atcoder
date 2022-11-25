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

int main(){
    string s;
    cin >> s;
    reverse(all(s));
    const int n = 13;
    int keta = 1;
    vector<ll> dp(n);
    dp[0] = 1;
    rep(i, s.size()){
        vector<ll> nextDp(n);
        if (s[i] == '?'){
            for(int val = 0; val <= 9; val++){
                for(int r = 0; r < n; r++){
                    nextDp[(val * keta + r) % n] += dp[r];
                    nextDp[(val * keta + r) % n] %= mod;
                }
            }
        }else{
            int val = s[i] - '0';
            for(int r = 0; r < n; r++){
                nextDp[(val * keta + r) % n] += dp[r];
                nextDp[(val * keta + r) % n] %= mod;
            }
        }
        dp = nextDp;
        keta *= 10;
        keta %= n;
    }   
    cout << dp[5] << endl;
    return 0;
}