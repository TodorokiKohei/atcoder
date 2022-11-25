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

const int mod = 2019;

int main(){
    ll l, r;
    cin >> l >> r;
    r = min(l + 2019, r);
    ll ans = 2020;
    for(ll i = l; i < r; i++){
        for(ll j = i+1; j <= r; j++){
            ans = min(ans, i * j % mod);
        }
    }
    cout << ans << endl;
    return 0;
}