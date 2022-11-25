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

int n;
ll k;
vector<ll> a;

bool f(ll x){
    ll cnt = 0;
    rep(i,n){
        cnt += (a[i]-1)/x;
    }
    if (cnt <= k) return true;
    else return false;
}

int main(){
    cin >> n >> k;
    a.resize(n);
    rep(i,n) cin >> a[i];
    ll ng = 0, ok = 1e9;
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        if (f(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}