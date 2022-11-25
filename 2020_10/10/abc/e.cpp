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

const int inf = 1 << 30;
const ll INF = 1LL << 60;

const int mod = 1000000007;
struct mint {
    ll x; // typedef long long ll;
    mint(ll x=0):x((x%mod+mod)%mod){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
    mint operator+(const mint a) const { return mint(*this) += a;}
    mint operator-(const mint a) const { return mint(*this) -= a;}
    mint operator*(const mint a) const { return mint(*this) *= a;}
    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const { return pow(mod-2);}
    mint& operator/=(const mint a) { return *this *= a.inv();}
    mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}

mint pow2[4000005];

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    VVI l(h, VI(w)), r(h, VI(w)), u(h, VI(w)), d(h, VI(w));
    rep(i, h) rep(j, w){
        if (s[i][j] == '#') continue;
        if (i != 0) u[i][j] += u[i-1][j];
        if (j != 0) l[i][j] += l[i][j-1];
        u[i][j] += 1;
        l[i][j] += 1;
    }
    rrep(i, h) rrep(j, w){
        if (s[i][j] == '#') continue;
        if (i != h-1) d[i][j] += d[i+1][j];
        if (j != w-1) r[i][j] += r[i][j+1];
        d[i][j] += 1;
        r[i][j] += 1;
    }

    ll cnt = 0;
    rep(i,h) rep(j,w) if (s[i][j] == '.') cnt++;

    pow2[0] = 1;
    rep(i, 4000005) pow2[i+1] = pow2[i] * 2;

    mint ans = 0;
    rep(i,h) rep(j,w){
        if (s[i][j] == '#') continue;
        ll num = l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3;
        ans += (pow2[num] - 1) * pow2[cnt-num];
    }
    view(ans);
    return 0;
}