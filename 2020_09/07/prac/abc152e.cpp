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

struct osak{
    vector<int> d;
    osak(int n) :d(n+1, 1) {
        for(int i = 2; i <= n; i++){
            if (d[i] != 1) continue;
            for(int j = i; j <= n; j += i){
                if (d[j] == 1) d[j] = i;
            }
        }
    }
    vector<P> factorize(int x){
        vector<P> res;
        int y = d[x];
        int cnt = 1;
        while(x != 1){
            x /= y;
            if (d[x] != y){
                res.push_back(P(y, cnt));
                cnt = 0;
            }
            y = d[x];
            cnt++;
        }
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    VI a(n);
    rep(i,n) cin >> a[i];
    osak osk(1e6);
    map<int, int> mp;
    rep(i,n){
        auto res = osk.factorize(a[i]);
        rep(j, res.size()){
            chmax(mp[res[j].first], res[j].second);
        }
    }
    mint l = 1;
    for(auto m: mp){
        mint p = m.first;
        p = p.pow(m.second);
        l *= p;
    }
    vector<mint> b(n);
    rep(i,n){
        b[i] = l / a[i];
    }
    mint ans = 0;
    rep(i,n){
        ans += b[i];
    }
    cout << ans.x << endl;
    return 0;
}