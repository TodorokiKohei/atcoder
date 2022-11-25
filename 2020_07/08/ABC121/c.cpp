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
    vector<pair<int, int>> ab(n);
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        ab[i] = make_pair(a, b);
    }
    sort(all(ab));
    int i = 0;
    ll ans = 0;
    while(m){
        ll num = min(m, ab[i].second);
        ans += ab[i].first * num;
        m -= num;
        i++;
    }
    cout << ans << endl;
}