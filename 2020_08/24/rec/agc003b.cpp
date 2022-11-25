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
    vector<ll> a(n+1);
    rep(i,n) cin >> a[i+1];
    a.push_back(0);
    bool ok = false;
    ll ans = 0;
    ll sum = 0;
    for(int i = 1; i <= n+1; i++){
        if (a[i] != 0 && !ok){
            ok = true;
        }else if (a[i] == 0 && ok){
            ok = false;
            ans += sum / 2;
            sum = 0;
        }
        if (ok) sum += a[i];
    }
    cout << ans << endl;
    return 0;
}