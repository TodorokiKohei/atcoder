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

int main(){
    int x, y;
    cin >> x >> y;
    vector<int> g(13);
    g[1] = g[3] = g[5] = g[7] = g[8] = g[10] = g[12] = 1;
    g[4] = g[6] = g[9] = g[11] = 2;
    g[2] = 3;
    if (g[x] == g[y]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}