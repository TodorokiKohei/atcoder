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

int main(){
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    for(int i = 1; i < n; i++){
        if (a[i-1] + a[i] < x) continue;
        int eat = min(a[i], a[i]+a[i-1]-x);
        a[i] -= eat;
        ans += eat;
    }

    if (a[0] > x){
        ans += a[0] - x;
    }
    cout << ans << endl;
    return 0;
}