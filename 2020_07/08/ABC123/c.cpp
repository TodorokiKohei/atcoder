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
    ll n;
    vector<ll> a(5);
    cin >> n;
    rep(i,5) cin >> a[i];
    int minI = 0;
    ll minNum = INF;
    rep(i,5) {
        if (chmin(minNum, a[i])) minI = i;
    }

    ll ans = 4;
    ans += ceil((double)n/a[minI]);
    cout << ans << endl;
}