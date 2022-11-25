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

const int MAX_D = 50;
ll dp[100][2];

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int d = 0; d < MAX_D; d++){
        ll mask = 1LL<<(MAX_D-d-1);

        ll num1 = 0;
        rep(i,n) if (a[i] & mask) num1++;

        ll cost0 = num1 * mask;
        ll cost1 = (n-num1) * mask;

        if (dp[d][1] != -1){
            chmax(dp[d+1][1], dp[d][1] + max(cost0, cost1));
        }

        if (dp[d][0] != -1){
            if (k & mask) chmax(dp[d+1][1], dp[d][0] + cost0);
        }

        if (dp[d][0] != -1){
            if (k & mask) chmax(dp[d+1][0], dp[d][0] + cost1);
            else chmax(dp[d+1][0], dp[d][0] + cost0);
        }
    }
    cout << max(dp[MAX_D][0], dp[MAX_D][1]) << endl;

    return 0;
}