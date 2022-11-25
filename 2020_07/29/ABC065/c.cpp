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


const ll mod = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;
    if (abs(n-m) > 1){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    ll x = 1;
    for(int i = 1; i <= n; i++){
        x *= i;
        x %= mod;
    }
    ll y = 1;
    for(int i = 1; i <= m; i++){
        y *= i;
        y %= mod;
    }
    ans = x * y % mod;
    
    if (n == m) ans = ans * 2 % mod;
    cout << ans << endl;
}