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
    rep(i,h) cin >> s[i];

    vector<vector<bool>> visited(h, vector<bool>(w));
    ll ans = 0;
    rep(i,h) rep(j,w){
        if (visited[i][j]) continue;
        if (s[i][j] == '.') continue;
        queue<P> q;
        q.push(P(j, i));
        visited[i][j] = true;
        ll cnt = 1, b = 1;
        while(!q.empty()){
            P p = q.front(); q.pop();
            int sx = p.first, sy = p.second;
            bool isWhite;
            if (s[sy][sx] == '.') isWhite = true;
            else isWhite = false;
            for(int i = 0; i < 4; i++){
                int x = sx + dx[i], y = sy + dy[i];
                if (x < 0 || x == w || y < 0 || y == h) continue;
                if (visited[y][x]) continue;
                if (isWhite){
                    if (s[y][x] == '#'){
                        q.push(P(x, y));
                        visited[y][x] = true;
                        cnt++;
                        b++;
                    }
                }else{
                    if (s[y][x] == '.'){
                        q.push(P(x, y));
                        visited[y][x] = true;
                        cnt++;
                    }
                }
            }
        }
        ans += b * (cnt - b);
    }
    cout << ans << endl;
    return 0;
}