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

ll f(ll r){
    return (r * (r + 1)) / 2;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    vector<double> E(n);
    rep(i,n){
        E[i] = (double)f(p[i]) / p[i];
    }

    vector<double> sum(n+1);
    sum[0] = 0;
    rep(i,n) sum[i+1] = sum[i] + E[i];
    double ans = 0;
    for(int i = 1; i <= n; i++){
        if (i + k - 1 > n) break;
        ans = max(ans, sum[i+k-1] - sum[i-1]);
    }
    printf("%.10lf\n", ans);
    return 0;
}