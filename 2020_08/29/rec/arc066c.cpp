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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    map<int, int> mp;
    rep(i,n){
        mp[a[i]]++;
    }
    ll ans = 1;
    const int mod = 1e9+7;
    if (n % 2 == 1){
        if (mp.find(0) == mp.end() || mp[0] != 1){
            cout << 0 << endl;
            return 0;
        }
        for(int i = 2; i <= n-1; i += 2){
            if (mp[i] != 2){
                cout << 0 << endl;
                return 0;
            }
            ans *= 2;
            ans %= mod;
        }
    }else{
        for(int i = 1; i <= n-1; i += 2){
            if (mp[i] != 2){
                cout << 0 << endl;
                return 0;
            }
            ans *= 2;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}