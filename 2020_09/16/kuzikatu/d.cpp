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

ll f(ll x){
    if (x % 2 == 0){
        if ((x / 2) % 2 == 0) return x;
        else return x ^ f(x-1);
    }else{
        if ((x / 2) % 2 == 0) return 1;
        else return 0;
    }
}

int main(){
    ll a, b;
    cin >> a >> b;
    ll ans = f(b) ^ f(a-1);
    cout << ans << endl;
    return 0;
}
