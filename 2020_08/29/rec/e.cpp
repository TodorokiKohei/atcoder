#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    map<int, ll> mp;
    const int mod = 1e9+7;
    ll ans = 1;
    mp[-1] = 3;
    for(int i = 0; i < n; i++){
        int x = a[i];
        if (x == 0){
            ans *= mp[-1];
            mp[-1]--;
        }else{
            ll cnt = mp[x-1];
            if (mp.find(x) != mp.end()) cnt -= mp[x];
            ans *= cnt;
        }
        ans %= mod;
        mp[x]++;
    }
    cout << ans << endl;
    return 0;
}