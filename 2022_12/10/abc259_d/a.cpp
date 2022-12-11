#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

#include <atcoder/all>
using namespace atcoder;

const int inf = 1 << 29;
const ll INF = 1LL << 60;

int main(){
    int n;
    ll sx, sy, tx, ty;
    cin >> n >> sx >> sy >> tx >> ty;

    vector<ll> x(n), y(n), r(n);
    rep(i,n) {
        ll xi, yi, ri;
        cin >> xi >> yi >> ri;
        x[i] = xi; y[i] = yi; r[i] = ri;
    }

    dsu uf(n);
    rep(i,n) rep(j,n) {
        if (i >= j) continue;
        ll d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
        ll rdp = (r[i] + r[j]) * (r[i] + r[j]);
        ll rdm = (r[i] - r[j]) * (r[i] - r[j]);
        if (d > rdp || d < rdm) continue;
        uf.merge(i, j);
    }

    vector<int> sc, tc;
    rep(i,n) {
        ll rd = r[i] * r[i];
        ll sd = (x[i]-sx)*(x[i]-sx) + (y[i]-sy) * (y[i]-sy);
        ll td = (x[i]-tx)*(x[i]-tx) + (y[i]-ty) * (y[i]-ty);
        if (rd == sd) sc.push_back(i);
        if (rd == td) tc.push_back(i);
    }
    rep(i, sz(sc)) rep(j, sz(tc)) {
        if (uf.same(sc[i], tc[i])) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}