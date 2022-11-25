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
using PD = pair<P, int>;
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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    vector<vector<P>> warp(26);
    P start, goal;
    rep(i,h) rep(j,w){
        if (a[i][j] == 'S') {
            start.first = j, start.second = i;
        }else if ('a' <= a[i][j] && a[i][j] <= 'z'){
            warp[a[i][j] - 'a'].push_back(P(j, i));
        }else if (a[i][j] == 'G'){
            goal.first = j, goal.second = i;
        }
    }
    queue<PD>  q;
    VVI dist(h, VI(w, inf));
    vector<bool> usedWarp(26);
    q.push(pair(start, 0));
    dist[start.second][start.first] = 0;
    while(!q.empty()){
        PD pd = q.front(); q.pop();
        P p = pd.first;
        int x = p.first, y = p.second;
        int d = pd.second;
        if (dist[y][x] > d) continue;
        rep(i, 4){
            int tx = x + dx[i], ty = y + dy[i];
            if (tx < 0 || tx >= w || ty < 0 || ty >= h) continue;
            if (a[ty][tx] == '#') continue;
            if (dist[ty][tx] <= d + 1) continue;
            dist[ty][tx] = d + 1;
            q.push(PD(P(tx, ty), dist[ty][tx]));
        }
        if ('a' <= a[y][x] && a[y][x] <= 'z'){
            int i = a[y][x] - 'a';
            if (usedWarp[i]) continue;
            rep(j, sz(warp[i])){
                if (warp[i][j] == p) continue;
                P toP = warp[i][j];
                int tx = toP.first, ty = toP.second;
                if (dist[ty][tx] <= d + 1) continue;
                dist[ty][tx] = d + 1;
                q.push(PD(P(tx, ty), dist[ty][tx]));
            } 
            usedWarp[i] = true;
        }
    }

    int ans;
    if (dist[goal.second][goal.first] == inf) ans = -1;
    else ans = dist[goal.second][goal.first];
    cout << ans << endl;
    return 0;
}