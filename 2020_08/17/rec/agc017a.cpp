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


ll choose(ll n, ll r){
    ll res = 1;
    for(int i = 1; i <= r; i++){
        res *= n--;
        res /= i;
    }
    return res;
}

int main(){
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int even = 0, odd = 0;
    rep(i,n){
        if (a[i] % 2 == 0) even++;
        else odd++;
    }
    ll ans;
    if (even == n){
        if (p == 0) ans = 1LL << even;
        else ans = 0;
    }else if (odd == n){
        ans = 0;
        if (p == 1) for(int i = 1; i <= odd; i += 2) ans += choose(odd, i);
        else for(int i = 0; i <= odd; i+=2 ) ans += choose(odd, i);
    }else{
        ll numE;
        numE = 1LL << even;
        if (p == 1) for(int i = 1; i <= odd; i += 2) ans += choose(odd, i);
        else for(int i = 0; i <= odd; i+=2 ) ans += choose(odd, i);
        ans *= numE;
    }
    cout << ans << endl;
    return 0;
}