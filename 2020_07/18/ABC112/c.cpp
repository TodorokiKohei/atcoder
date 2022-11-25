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
    vector<int> x(n), y(n), h(n);
    rep(i,n) cin >> x[i] >> y[i] >> h[i];
    rep(cx, 101) rep(cy, 101){
        bool ok = true;
        int ans = -1;
        rep(i,n){
            if (h[i] == 0) continue;
            int H = h[i] + abs(cx - x[i]) + abs(cy - y[i]);
            if (ans == -1){
                ans = H;
            }else{
                if (ans != H){
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) continue;
        rep(i,n){
            if (h[i] != 0) continue;
            int dist = abs(cx - x[i]) + abs(cy - y[i]);
            if (ans > dist){
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        printf("%d %d %d\n", cx, cy, ans);
    }
}