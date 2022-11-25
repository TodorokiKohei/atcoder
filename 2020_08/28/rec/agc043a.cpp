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

int dx[] = {0, 1};
int dy[] = {1, 0};

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];

    queue<P> q, q_next;
    vector<vector<int>> dist(h, vector<int>(w, -1)), ok(h, vector<int>(w, -1));
    if (s[0][0] == '.') dist[0][0] = 0;
    else dist[0][0] = 1;
    q_next.push(make_pair(0, 0));
    while(!q_next.empty()){
        P pos = q_next.front(); q_next.pop();
        int px = pos.first, py = pos.second;
        if (ok[py][px] == 1) continue;

        char c = s[py][px];
        ok[py][px] = 1;
        q.push(pos);
        while(!q.empty()){
            P p = q.front(); q.pop();
            int sx = p.first, sy = p.second;
            rep(i,2){
                int x = sx+dx[i], y = sy+dy[i];
                if (x >= w || y >= h) continue;
                if (ok[y][x] == 1) continue;
                if (s[y][x] == c){
                    q.push(make_pair(x, y));
                    ok[y][x] = 1;
                    dist[y][x] = dist[sy][sx];
                }else{
                    q_next.push(make_pair(x, y));
                    ok[y][x] = 0;
                    if (c == '.') dist[y][x] = dist[sy][sx] + 1;
                    else dist[y][x] = dist[sy][sx];
                }
            }
        }
    }
    cout << dist[h-1][w-1] << endl;
    return 0;
}