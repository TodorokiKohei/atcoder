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

const int INF = 1<<30;

int main(){
    int h, w;
    cin >> h >> w;
    int ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;
    ch--; cw--; dh--; dw--;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    queue<P> q, q_warp, q_tmp;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    vector<vector<int>> ok(h, vector<int>(w, -1));
    q_warp.push(make_pair(ch, cw));
    dist[ch][cw] = 0;
    while(!q_warp.empty()){
        P pos_warp = q_warp.front(); q_warp.pop();
        if (ok[pos_warp.first][pos_warp.second] != -1) continue;
        ok[pos_warp.first][pos_warp.second] = 1;
        q.push(pos_warp);
        q_tmp.push(pos_warp);
        while(!q.empty()){
            P pos = q.front(); q.pop();
            int sx = pos.second;
            int sy = pos.first;
            rep(i, 4){
                int x = sx + dx[i];
                int y = sy + dy[i];
                if (x < 0 || x >= w) continue;
                if (y < 0 || y >= h) continue;
                if (s[y][x] == '#') continue;
                if (ok[y][x] != -1) continue;
                dist[y][x] = min(dist[y][x], dist[sy][sx]);
                ok[y][x] = 1;
                q.push(make_pair(y, x));
                q_tmp.push(make_pair(y, x));
            }
        }
        while(!q_tmp.empty()){
            P pos = q_tmp.front(); q_tmp.pop();
            int sx = pos.second;
            int sy = pos.first;
            for(int x = sx-2; x <= sx+2; x++){
                for(int y = sy-2; y <= sy+2; y++){
                    if (x < 0 || x >= w) continue;
                    if (y < 0 || y >= h) continue;
                    if (s[y][x] == '#') continue;
                    if (ok[y][x] != -1) continue;
                    dist[y][x] = min(dist[y][x], dist[sy][sx]+1);
                    q_warp.push(make_pair(y, x));
                }
            }
        }
    }
    if (ok[dh][dw] == -1) cout << -1 << endl;
    else cout << dist[dh][dw] << endl;
    return 0;
}