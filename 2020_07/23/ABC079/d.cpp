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

#define N 10
int C[N][N];

const int INF = 1<<30;


int main(){
    int h, w;
    cin >> h >> w;
    rep(i, N) rep(j, N) cin >> C[i][j];
    vector<vector<int>> A(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> A[i][j];

    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                C[i][j] = min(C[i][j], C[i][k] + C[k][j]);
            }
        }
    }
    
    // 
    ll ans = 0;
    rep(i,h) rep(j,w){
        if (A[i][j] == -1) continue;
        ans += C[ A[i][j] ][1];
    }
    cout << ans << endl;
}

