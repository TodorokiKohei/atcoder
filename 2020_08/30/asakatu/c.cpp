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

int main(){
    int n;
    cin >> n;
    vector<int> a;
    a.push_back(0);
    rep(i,n){
        int x;
        cin >> x;
        a.push_back(x);
    }
    a.push_back(0);
    ll sum = 0;
    rep(i, a.size()-1) sum += abs(a[i+1] - a[i]);
    for(int i = 1; i <= n; i++){
        ll ans = sum;
        ans -= abs(a[i] - a[i-1]);
        ans -= abs(a[i+1] - a[i]);
        ans += abs(a[i+1] - a[i-1]);
        cout << ans << endl;
    }
    return 0;
}