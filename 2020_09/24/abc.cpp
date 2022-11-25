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

int main(){
    ll k;
    cin >> k;
    ll q = k / 50;
    ll r = k % 50;
    VL a(50, 49);
    rep(i, 50) a[i] += q;
    rep(i, 50){
        if (i < r) a[i] += 1;
        else a[i] -= r;
    }

    cout << 50 << endl;
    rep(i, 50) printf("%lld%c", a[i], i == 49 ? '\n' : ' ');

    // rep(ki, k){
    //     ll mx = 0;
    //     int mxi = 0;
    //     rep(i, 50) if (chmax(mx, a[i])) mxi = i;
    //     rep(i, 50) {
    //         if (i == mxi) a[i] -= 50;
    //         else a[i]++;
    //     }
    //     printf("No.%d MAX=%lld\n", ki+1, mx);
    // }

    // cout << 50 << endl;
    // rep(i, 50) printf("%lld%c", a[i], i == 49 ? '\n' : ' ');
    return 0;
}