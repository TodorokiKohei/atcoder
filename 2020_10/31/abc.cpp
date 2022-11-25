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

void solve(VL a, int n, int k){
        VL ap, am;
    rep(i,n){
        if (a[i] < 0) am.push_back(a[i]);
        else ap.push_back(a[i]);
    }

    if (k == n){
        mint ans = 1;
        rep(i,k) ans *= a[i];
        cout << ans << endl;
    }else if (sz(am) == n && k % 2 == 1){
        mint ans = 1;
        sort(rall(am));
        rep(i,k) ans *= am[i];
        cout << ans << endl;
    }else{
        mint ans = 1;
        sort(rall(ap));
        sort(all(am));

        int leftp = 0, leftm = 0;
        while(k > 1){
            if (leftp+1 >= sz(ap)){
                ans *= (am[leftm] * am[leftm+1]);
                leftm += 2;
                k -= 2;
            } else if(leftm+1 >= sz(am)){
                ans *= ap[leftp];
                leftp++;
                k--;
            } else{
                if (ap[leftp] * ap[leftp+1] > am[leftm] * am[leftm+1]){
                    ans *= ap[leftp];
                    leftp++;
                    k--;
                }else{
                    ans *= (am[leftm] * am[leftm+1]);
                    leftm += 2;
                    k -= 2;
                }
            }
        }
        if (k == 1) ans *= ap[leftp];
        cout << ans << endl;
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    VL a(n);
    rep(i,n) cin >> a[i];
    solve(a, n, k);

    // random_device rand_seed;//非決定論的乱数生成器
    // mt19937_64 engine(rand_seed());//メルセンヌ・ツイスタで乱数を生成する
    // while(true){
    //     n = engine() % (ll)2e5 + 1;
    //     k = n - 1;
    //     if (n < k) continue;
    //     VL a(n);
    //     rep(i,n){
    //         ll ai = engine() % (ll)2e5 + 1;
    //         ai -= 2e5;
    //         a[i] = ai;
    //     }
    //     solve(a, n, k);
    // }
    return 0;
}