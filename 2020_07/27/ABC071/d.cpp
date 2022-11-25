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

int main(){
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> tate(n);
    rep(i,n) if (s1[i] == s2[i]) tate[i] = 1;
    mint ans;
    int i = 0;
    while(i < n){
        if (i == 0){
            if (tate[i]){
                ans = 3;
                i++;
            }else{
                ans = 3*2;
                i+=2;
            }

        }
        else{
            if (tate[i]){
                if (tate[i-1]){
                    ans *= 2;
                }
                i++;
            }else{
                if (tate[i-1]){
                    ans *= 2;
                }else{
                    ans *= 3;
                }
                i += 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}