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

void factorize(ll n, vector<ll> &cnt){
    for (ll i = 2; i*i <= n; ++i){
        if (n%i) continue;
        while (n%i == 0){
            n /= i;
            cnt[i]++;
        }
    }
    if(n != 1) cnt[n]++;
}

int main(){
    int n;
    cin >> n;
    vector<ll> cnt(n+1);
    for(int i = 2; i <= n; i++){
        factorize(i, cnt);
    }
    ll ans = 1;
    const int mod = 1e9+7;
    for(int i = 2; i <= n; i++){
        ans *= cnt[i]+1;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}