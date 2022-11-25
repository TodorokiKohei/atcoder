#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll g = __gcd(c, d);
    ll l = c * d / g;
    ll ans = b - a + 1;
    ans -= (b/c - a/c);
    if (a % c == 0) ans--;
    ans -= (b/d - a/d);
    if (a % d == 0) ans--;
    ans += (b/l - a/l);
    if (a % l == 0) ans++;
    cout << ans << endl;
}