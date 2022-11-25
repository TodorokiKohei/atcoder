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
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    vector<int> cnt(60);
    rep(i,n){
        rep(j, 60){
            if (a[i] & 1LL<<j) cnt[j]++;
        }
    }

    ll ans = 0;
    for(int i = -1; i < 60; i++){
        if (i != -1 && !(k & 1LL<<i)) continue;

        ll sum = 0;
        for(int j = 0; j < 60; j++){
            ll ketaNum = 1LL<<j;
            if (j < i){
                sum += ketaNum * max(cnt[j], n-cnt[j]);
            }else if (i == j){
                sum += ketaNum * cnt[j];
            }else{
                if (k & ketaNum) sum += ketaNum * (n-cnt[j]);
                else sum += ketaNum * cnt[j];
            }
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}