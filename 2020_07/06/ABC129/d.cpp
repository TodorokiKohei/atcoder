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
    int h, w;
    cin >> h >>  w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<int>> l(h, vector<int>(w, 0)), r(h, vector<int>(w, 0)), u(h, vector<int>(w, 0)), d(h, vector<int>(w, 0));
    rep(row, h) rep(col, w){
        if (s[row][col] == '#'){
            l[row][col] = -1;
            u[row][col] = -1;
            continue;
        }
        if (col-1 >= 0) l[row][col] = l[row][col-1]+1;
        if (row-1 >= 0) u[row][col] = u[row-1][col]+1;
    }
    for(int row = h-1; row >= 0; row--){
        for(int col = w-1; col >= 0; col--){
            if (s[row][col] == '#'){
                r[row][col] = -1;
                d[row][col] = -1;
                continue;
            }
            if (col+1 != w) r[row][col] = r[row][col+1]+1;
            if (row+1 != h) d[row][col] = d[row+1][col]+1;
        }
    }

    int ans = 0;
    rep(row, h) rep(col, w){
        if (s[row][col] == '#') continue;
        int sum = l[row][col] + r[row][col] + d[row][col] + u[row][col] + 1;
        ans = max(ans, sum);
    }
    cout << ans << endl;
}