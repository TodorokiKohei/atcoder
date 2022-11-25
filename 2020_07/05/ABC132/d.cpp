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

mint choose(int n, int r){
    // if (n < r) return mint(0);
    mint x = 1, y = 1;
    for(int i = 0; i < r; i++){
        x *= n-i;
        y *= i+1;
    }
    return x / y;
}

int main(){
    int n, k;
    cin >> n >> k;
    mint ans = 0;
    for(int i = 1; i <= k; i++){
        ans = choose(k-1, i-1) * choose(n-k+1, i);
        printf("%lld\n", ans.x);
    }
    return 0;
}