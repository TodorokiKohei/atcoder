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

const ll INF = 1LL<<60;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> f(n, vector<int>(10));
    vector<vector<ll>> p(n, vector<ll>(11));

    rep(i,n) rep(j, 10) cin >> f[i][j];
    rep(i,n) rep(j, 11) cin >> p[i][j];

    ll ans = -INF;
    for(int i = 1; i < 1<<10; i++){
        vector<int> isOpen(10);
        rep(j, 10) if (i>>j & 1) isOpen[j] = 1;
        vector<int> cnt(n);
        rep(j, n) rep(k, 10){
            if (isOpen[k] == 1 && f[j][k] == 1) cnt[j]++;
        }
        ll sum = 0;
        rep(j, n) sum += p[j][cnt[j]];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}