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
    ll n, m;
    cin >> n >> m;
    VL sq(n*n+1, -1);
    for(int i = 0; i <= n; i++){
        sq[i*i] = i;
    }

    VVL cnt(n, VL(n, -1));
    queue<P> q;
    q.push({0, 0});
    cnt[0][0] = 0;
    while(!q.empty()) {
        P p = q.front();
        q.pop();
        rep(i,n) {
            ll x = abs(i-p.first);
            ll y2 = m - x*x;
            if (y2 < 0) continue;
            if (y2 > n*n || sq[y2] == -1) continue;
            ll y = sq[y2];
            if (p.second-y >= 0 && cnt[p.second-y][i] == -1){
                cnt[p.second-y][i] = cnt[p.second][p.first]+1;
                q.push({i, p.second-y});
            } 
            if (p.second+y < n && cnt[p.second+y][i] == -1) {
                cnt[p.second+y][i] = cnt[p.second][p.first]+1;
                q.push({i, p.second+y});
            }
        }
    }
    rep(i,n) {
        rep(j, n) {
            cout << cnt[i][j];
            if (j == n-1) cout << endl;
            else cout << " ";
        }
    }
    return 0;
}