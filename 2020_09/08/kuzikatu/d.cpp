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
    cin >> n;
    VI a(n), b(n), c(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    rep(i,n) cin >> c[i];
    sort(all(a));
    sort(all(b));
    sort(all(c));

    ll ans = 0;
    for(int i = 0; i < n; i++){
        int bi = b[i];
        auto itrA = lower_bound(all(a), bi);
        if (itrA == a.begin()) continue;
        itrA--;
        auto itrC = upper_bound(all(c), bi);

        ll numA = itrA - a.begin() + 1;
        ll numC = n - (itrC - c.begin());
        ans += numA * numC;
    }
    cout << ans << endl;
    return 0;
}