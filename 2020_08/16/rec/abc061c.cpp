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
    ll k;
    cin >> n >> k;
    vector<P> ope(n);
    rep(i,n){
        int a, b;
        cin >> a >> b;
        ope[i] = make_pair(a, b);
    }
    sort(all(ope));
    ll num = 0;
    rep(i,n){
        num += ope[i].second;
        if (k <= num){
            cout << ope[i].first << endl;
            return 0;
        }
    }
    return 0;
}