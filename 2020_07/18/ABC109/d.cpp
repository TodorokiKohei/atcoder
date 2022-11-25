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

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h) rep(j, w) cin >> a[i][j];
    int ans = 0;
    vector<vector<int>> ope;
    rep(i, h-1) rep(j, w){
        if (a[i][j] % 2 == 0) continue;
        a[i][j]--;
        a[i+1][j]++;
        ans++;
        ope.push_back({i,j, i+1, j});
    }
    rep(j, w-1){
        if (a[h-1][j] % 2 == 0) continue;
        a[h-1][j]--;
        a[h-1][j+1]++;
        ans++;
        ope.push_back({h-1,j, h-1, j+1});
    }
    cout << ans << endl;
    rep(i, ope.size()){
        printf("%d %d %d %d\n", ope[i][0]+1, ope[i][1]+1, ope[i][2]+1, ope[i][3]+1);
    }
    return 0;
}