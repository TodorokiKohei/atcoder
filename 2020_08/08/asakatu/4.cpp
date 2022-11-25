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

vector<vector<int>> g;

int main(){
    int n, m;
    cin >> n >> m;
    g.resize(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    rep(i,n){
        queue<int> q;
        vector<int> dist(n, -1);
        q.push(i);
        dist[i] = 0;
        int ans = 0;
        while(!q.empty()){
            int  v = q.front(); q.pop();
            for(int d: g[v]){
                if (dist[d] != -1) continue;
                dist[d] = dist[v] + 1;
                q.push(d);
                if (dist[d] == 2) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}