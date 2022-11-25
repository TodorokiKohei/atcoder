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
    int n, m;
    cin >> n >> m;
    if (n < m) swap(n, m);
    if (n - m >= 2){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    for(int i = n; i > 0; i--){
        ans *= i;
        ans %= mod;
    }
    for(int i = m; i > 0; i--){
        ans *= i;
        ans %= mod;
    }

    if (n == m){
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}