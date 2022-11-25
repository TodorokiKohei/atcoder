#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int inf = 1 << 29;
const ll INF = 1LL << 60;

int main(){
    int n, m;
    cin >> n >> m;
    VL x(n);
    rep(i,n) cin >> x[i];
    VL c(n, 0);
    rep(i,m) {
        int ci, yi;
        cin >> ci >> yi;
        ci--;
        c[ci] = yi;
    }
    VVL ans(n+1, VL(n+1, -1));
    ans[0][0] = 0;
    rep(i,n){
        rep(j,n){
             if (ans[i][j] == -1) continue;
             // 裏が出た場合
             ans[i+1][0] = max(ans[i+1][0], ans[i][j]);
             // 表が出た場合
             ans[i+1][j+1] = max(ans[i+1][j+1], ans[i][j]+x[i]+c[j]);
        }
    }
    ll ansMax = 0;
    rep(i,n+1) ansMax = max(ansMax, ans[n][i]);
    cout << ansMax << endl;
    return 0;
}