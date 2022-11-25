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

const int mod = 1e9+7;

int main(){
    int n;
    cin >> n;
    VL a(n);
    rep(i,n) cin >> a[i];

    ll ans = 0;
    ll d = 1;
    rep(i, 60){
        ll cnt0 = 0, cnt1 = 0;
        rep(j, n){
            if ((a[j]>>i) & 1) cnt1++;
            else cnt0++;
        }
        ll cnt = (cnt1 * cnt0) % mod;
        ans += (d * cnt) % mod;
        ans %= mod;
        d *= 2;
        d %= mod;
    }
    cout << ans << endl;
    return 0;
}