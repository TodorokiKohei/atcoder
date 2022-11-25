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

const int INF = 1<<30;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> x(n, 0);
    rep(i,n) cin >> x[i];
    int ans = INF;
    rep(i,n){
        if (i + k - 1 == n) break;
        int l = i;
        int r = i+k-1;
        int t1 = abs(x[l]) + abs(x[r] - x[l]);
        int t2 = abs(x[r]) + abs(x[l] - x[r]);
        ans = min(ans, min(t1, t2));
    }
    cout << ans << endl;
    return 0;
}