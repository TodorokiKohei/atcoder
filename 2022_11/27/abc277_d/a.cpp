#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int inf = 1 << 29;
const ll INF = 1LL << 60;

int main(){
    int n, m;
    cin >> n >> m;
    VL a(n);
    ll sum = 0;
    rep(i,n) {
        cin >> a[i];
        sum += a[i];
    }
    sort(all(a));
    rep(i,n) a.push_back(a[i]);
    ll ans = INF;
    ll conSum = a[0];
    for(int i = 1; i < 2*n; i++){
        if (a[i] - a[i-1] == 0 || a[i] - ((a[i-1]+1)%m) == 0) {
            conSum += a[i];
            continue;
        }
        if ((sum-conSum) < ans) ans = max(sum-conSum, 0LL);
        conSum = a[i];
    }
    if ((sum-conSum) < ans) ans = max(sum-conSum, 0LL);
    cout << ans << endl;
    return 0;
}