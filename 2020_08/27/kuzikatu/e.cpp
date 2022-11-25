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
    vector<ll> t(n), a(n);
    rep(i,n) cin >> t[i];
    rep(i,n) cin >> a[i];

    vector<ll> minh(n), maxh(n);
    minh[0] = t[0], maxh[0] = t[0];
    minh[n-1] = a[n-1], maxh[n-1] = a[n-1];
    ll ht = t[0];
    for(int i = 1; i < n-1; i++){
        if (chmax(ht, t[i])){
            minh[i] = ht;
            maxh[i] = ht;
        }else{
            minh[i] = 1;
            maxh[i] = ht;
        }
    }

    ll ha = a[n-1];
    bool ok = ha >= ht;
    for(int j = n-2; j >= 0; j--){
        if (!ok){
            if (chmax(ha, a[j])){
                if (maxh[j] < ha){
                    cout << 0 << endl;
                    return 0;
                }else if (maxh[j] == ha){
                    ok = true;
                }
                minh[j] = ha;
            }
            maxh[j] = ha;
        }else{
            if (chmax(ha, a[j])){
                cout << 0 << endl;
                return 0;
            }
        }
    }

    if (ha != ht){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    const int mod = 1e9+7;
    rep(i, n){
        ans *= (maxh[i]-minh[i]+1);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}