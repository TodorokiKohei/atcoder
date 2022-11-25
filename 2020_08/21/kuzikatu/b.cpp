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

ll const INF = 1LL<<60;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    double avg = 0;
    rep(i,n) avg += x[i];
    avg /= n;

    ll ans = INF;
    rep(i,2){
        int pos = i == 0 ? floor(avg) : ceil(avg);
        ll sum = 0;
        rep(j,n) sum += (x[j] - pos) * (x[j] - pos);
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}