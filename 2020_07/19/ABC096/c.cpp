#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 0, -1,0};
int dy[] = {0, 1, 0, -1};

int main(){
    int h , w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    rep(row,h) rep(col,w){
        if (s[row][col] == '.') continue;
        bool ok = false;
        rep(i, 4){
            int x, y;
            x = col+dx[i];
            y = row+dy[i];
            if (x < 0 || x >= w || y < 0 || y >= h) continue;
            if (s[y][x] == '#') ok = true;
        }
        if (!ok){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}