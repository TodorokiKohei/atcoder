#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n;
    ll k;
    cin >> n >> k;
    VL a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    sort(all(a));
    sort(rall(b));
    ll ng = -1, ok = 1e18;
    while(abs(ng - ok) > 1){
        ll cnt = k;
        ll mid = (ok + ng) / 2;
        bool clear = true;
        rep(i,n){
            ll score = a[i] * b[i];
            if (mid > score) continue;
            ll diff = score - mid;
            cnt -= ceil((double)diff / b[i]);
            if (cnt < 0){
                clear = false;
                break;
            }
        }
        if (clear) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}