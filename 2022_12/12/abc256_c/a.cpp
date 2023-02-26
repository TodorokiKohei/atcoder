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

int h1, h2, h3, w1, w2, w3;
ll ans = 0;

void dfs(VI &vec){
    if (sz(vec) == 4) {
        int r11 = vec[0], r12 = vec[1], r21 = vec[2], r22 = vec[3];
        int r13 = h1 - (r11 + r12);
        int r23 = h2 - (r21 + r22);
        int r31 = w1 - (r11 + r21);
        int r32 = w2 - (r12 + r22);
        if (r13 <= 0 || r23 <= 0 || r31 <= 0 || r32 <= 0) return;
        int r33_h = h3 - (r31 + r32);
        int r33_w = w3 - (r13 + r23);
        if (r33_h == r33_w && r33_h > 0) ans++;
        return;
    }
    for(int i = 1; i <= 30; i++) {
        vec.push_back(i);
        dfs(vec);
        vec.pop_back();
    }
}

int main(){   
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
    VI vec;
    dfs(vec);
    cout << ans << endl;
    return 0;
}