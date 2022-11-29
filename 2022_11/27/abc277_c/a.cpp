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
    map<int, vector<P>> br;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        br[a].push_back(make_pair(b, i));
        br[b].push_back(make_pair(a, i));
    }

    queue<int> q;
    vector<bool> isUsed(n, false);
    int ans = 0;
    q.push(0);
    while(!q.empty()){
        int fl = q.front();
        q.pop();
        if (ans < fl) ans = fl;
        for (auto flBr : br[fl]) {
            if (isUsed[flBr.second]) continue;
            q.push(flBr.first);
            isUsed[flBr.second] = true;
        }
    }
    cout << ans+1 << endl;
    return 0;
}