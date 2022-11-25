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

ll modpow(ll x, ll n, int mod){
    if (n == 0){
        return 1;
    }
    ll half = modpow(x, n/2, mod);
    ll res = (half * half) % mod;
    if (n&1) res = (res * x) % mod;
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<ll> d(n);
    int mx = 0;
    rep(i,n){
        int x;
        cin >> x;
        if (i == 0 && x != 0){
            cout << 0 << endl;
            return 0;
        }
        d[x]++;
        mx = max(mx, x);
    }
    if (n > 1 && d[0] > 1){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    const int mod = 998244353;
    for(int i = 1; i <= mx; i++){
        ans *= modpow(d[i-1], d[i], mod);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}