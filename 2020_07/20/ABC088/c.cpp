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

int c[3][3];
int n = 3;

int main(){
    rep(i,n)rep(j,n) cin >> c[i][j];
    for(int a1 = 0; a1 <= 100; a1++){
        int b1 = c[0][0] - a1;
        int b2 = c[0][1] - a1;
        int b3 = c[0][2] - a1;

        int a2 = c[1][0] - b1;
        int a3 = c[2][0] - b1;

        if (a2+b2 != c[1][1]) continue;
        if (a2+b3 != c[1][2]) continue;
        if (a3+b2 != c[2][1]) continue;
        if (a3+b3 != c[2][2]) continue;
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}