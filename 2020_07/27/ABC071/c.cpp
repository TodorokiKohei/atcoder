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

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> isUsed(n);
    sort(all(a));
    int cnt = 0;
    ll x, y;
    for(int i = n-1; i  > 0; i--){
        if (a[i] == a[i-1] && isUsed[i] == 0){
            isUsed[i-1] = 1;
            cnt++;
            if (cnt == 1) x = a[i];
            else {
                y = a[i];
                break;
            }
        }
    }
    ll ans = x * y;
    if (cnt == 2) cout << ans << endl;
    else cout << 0 << endl;
    return 0;
}