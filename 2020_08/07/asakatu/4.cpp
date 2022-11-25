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
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<vector<int>> ans(h, vector<int>(w));
    int now = 0;
    rep(i,h) rep(j, w){
        if (a[now] == 0) now++;
        ans[i][j] = now+1;
        a[now]--;
    }
    rep(i,h){
        if (i % 2 != 0) reverse(all(ans[i]));
    }

    rep(i,h){
        rep(j,w){
            printf("%d%c", ans[i][j], j == w-1 ? '\n' : ' ');
        }
    }
    return 0;
}