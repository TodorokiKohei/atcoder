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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int mx = 0;
    rep(i,n) {
        if (a[i] == k){
            cout << "POSSIBLE" << endl;
            return 0;
        }
        mx = max(mx, a[i]);
    }
    if (mx < k){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int g = a[0];
    for(int i = 1; i < n; i++){
        g = __gcd(g, a[i]);
    }
    if (g == 1) cout << "POSSIBLE" << endl;
    else if (k % g == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}