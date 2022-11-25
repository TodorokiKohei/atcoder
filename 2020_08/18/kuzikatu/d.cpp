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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    int white = 0;
    rep(i,h) rep(j,w) if (s[i][j] == '.') white++;

    queue<P> q;
    vector<vector<int>> dist(h, vector<int>(w, -1));
    q.push(make_pair(0,0));
    dist[0][0] = 0;
    while(!q.empty()){
        P v = q.front(); q.pop();

        for(int i = 0; i < 4; i++){
            int x = v.first + dx[i], y = v.second + dy[i];
            if (x >= w || y >= h || x < 0 || y < 0) continue;
            if (s[y][x] == '#') continue;
            if (dist[y][x] != -1) continue;
            q.push(make_pair(x, y));
            dist[y][x] = dist[v.second][v.first] + 1;
        }
    }

    if (dist[h-1][w-1] == -1) cout << -1 << endl;
    else cout << white - dist[h-1][w-1] - 1 << endl;
    return 0;
}