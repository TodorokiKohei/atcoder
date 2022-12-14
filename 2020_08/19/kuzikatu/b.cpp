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
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    rep(i, n) rep(j, m){
        cin >> a[i][j];
    }
    int ans = 0;
    rep(i,n) {
        int sum = c;
        rep(j, m){
            sum += a[i][j] * b[j];
        }
        if (sum > 0) ans++;
    }
    cout << ans << endl;
    return 0;
}