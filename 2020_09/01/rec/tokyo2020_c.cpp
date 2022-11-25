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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, k){
        vector<int> b(n+2);
        rep(j, n){
            int v = a[j];
            int l = max(j+1-v, 0), r = min(j+1+v+1, n+1);
            b[l]++; b[r]--;
        }
        int mn = n+1;
        rep(j,n){
            b[j+1] += b[j];
            a[j] = b[j+1];
            mn = min(mn, a[j]);
        }
        if (mn == n) break;
    }
    rep(i, n) printf("%d%c", a[i], i == n-1 ? '\n':' ');
    return 0;
}