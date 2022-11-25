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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
    }

    int s, t;
    cin >> s >> t;
    s--; t--;
    vector<vector<int>> dist(n, vector<int>(3, -1));
    queue<P> q;
    dist[s][0] = 0;
    q.push(P(s,0));
    while(!q.empty()){
        int p = q.front().first;
        int d = q.front().second;
        q.pop();
        for(int v: g[p]){
            int dd = (d + 1) % 3;
            if (dist[v][dd] != -1) continue;
            q.push(P(v,dd));
            dist[v][dd] = dist[p][d] + 1;
        }
    }
    int ans = dist[t][0];
    if (ans != -1) ans /= 3;
    cout << ans << endl;
    return 0;
}