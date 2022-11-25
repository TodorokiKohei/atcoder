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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<pair<int, int>> cb(m);
    rep(i,m){
        int b, c;
        cin >> b >> c;
        cb[i] = make_pair(c, b);
    }

    sort(all(a));
    sort(rall(cb));

    int start = 0;
    int sum = 0;
    rep(i,m){
        if (sum > n) break;
        int c = cb[i].first;
        int b = cb[i].second;
        int cnt = 0;
        for(int j = start; j < n; j++){
            if (a[j] >= c || cnt == b) break;
            a[j] = c;
            start = j + 1;
            cnt++;
            sum++;
        }
    }

    ll ans = 0;
    rep(i,n){
        ans += a[i];
    }
    cout << ans << endl;
}