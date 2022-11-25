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

#define N 100
ll A[N][N];
int n, m;

ll calc(int s1, int s2){
    ll sum = 0;
    rep(i,n){
        sum += max(A[i][s1], A[i][s2]);
    }
    return sum;
}

int main(){
    cin >> n >> m;
    rep(i,n) rep(j,m){
        cin >> A[i][j];
    }    
    ll ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = i+1; j < m; j++){
            ans = max(ans, calc(i,j));
        }
    }
    cout << ans << endl;
    return 0;
}