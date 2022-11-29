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
    int n, q;
    cin >> n >> q;
    unordered_map<int, unordered_set<int>> u;
    rep(i,q) {
        int t, a, b;
        cin >> t >> a >> b;
        a--; b--;
        if (t == 1) {
            u[a].insert(b);
        }else if (t == 2) {
            u[a].erase(b);
        }else if (t == 3) {
            if (u[a].find(b) != u[a].end() && u[b].find(a) != u[b].end()) {
                cout << "Yes" << endl;
            }else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}