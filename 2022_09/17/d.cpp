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
    int n; 
    cin >> n;
    map<P, int> mp;
    int dx[] = {-1, -1, 0, 0, 1, 1};
    int dy[] = {-1, 0, -1, 1, 0, 1};
    rep(i,n){
        int x, y;
        cin >> x >> y;
        mp[make_pair(x,y)] = 1;
    }

    int ans = 0;
    for(auto p: mp){
        P key = p.first;
        if (p.second == 0) continue;
        mp[key] = 0;
        queue<P> q;
        q.push(key);
        while(!q.empty()){
            P pos = q.front();
            q.pop();
            rep(i, 6){
                P nextPos = make_pair(pos.first + dx[i], pos.second + dy[i]);
                if (mp.count(nextPos) == 0) continue;
                if (mp[nextPos] == 0) continue;
                q.push(nextPos);
                mp[nextPos] = 0;
            }
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}