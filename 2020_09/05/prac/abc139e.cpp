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


vector<int> dp;
vector<bool> visited, calculated;
int dfs(int v, vector<vector<int>> &to){
    if (visited[v]){
        if (!calculated[v]) return -1;
        else return dp[v];
    }
    visited[v] = true;
    dp[v] = 1;
    for(int d: to[v]){
        int res = dfs(d, to);
        if (res == -1) return -1;
        dp[v] = max(dp[v], res+1);
    }
    calculated[v] = true;
    return dp[v];
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n-1));
    rep(i,n) rep(j,n-1){
        cin >> a[i][j];
        a[i][j]--;
    } 

    // 試合にIDを付与
    int v = 0;
    vector<vector<int>> gameId(n, vector<int>(n, -1));
    rep(i,n) rep(j,n){
        if (i < j){
            gameId[i][j] = v++;
        }
        else {
            gameId[i][j] = gameId[j][i];
        }
    }

    // 試合に辺を追加していく
    vector<vector<int>> to(v);
    rep(i,n) rep(j,n-2){
        int id1 = gameId[i][a[i][j]];
        int id2 = gameId[i][a[i][j+1]];
        to[id1].push_back(id2);
    }

    // 最長経路を求める
    dp.resize(v);
    visited.reserve(v);
    calculated.resize(v);
    int ans = 0;
    rep(i, v){
        int res = dfs(i, to);
        if (res == -1){
            cout << -1 << endl;
            return 0;
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}