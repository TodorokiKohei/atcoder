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
    vector<string> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) rep(j,n){
        if (i == j) continue;
        int x1 = i, y1 = j, x2 = j, y2 = i;
        if (a[x1][y1] == 'W' && a[x2][y2] == 'L') continue;
        if (a[x1][y1] == 'L' && a[x2][y2] == 'W') continue;
        if (a[x1][y1] == 'D' && a[x2][y2] == 'D') continue;
        cout << "incorrect " << endl;
        return 0;
    }
    cout << "correct" << endl;
    return 0;
}