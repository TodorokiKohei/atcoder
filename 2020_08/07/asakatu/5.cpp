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
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int absMax = 0, absMaxI = 0;
    rep(i,n) if ( chmax(absMax, abs(a[i]) )) absMaxI = i;

    cout << 2 * n - 2 << endl;
    rep(i,n){
        if (absMaxI != i) {
            printf("%d %d\n", absMaxI+1, i+1);
            a[i] += absMax;            
        }
    }
    if (a[absMaxI] < 0){
        for(int i = n-1; i > 0; i--){
            printf("%d %d\n", i+1, i);
            a[i-1] += a[i];
        }
    }else{
        for(int i = 1; i < n; i++){
            printf("%d %d\n", i, i+1);
            a[i] += a[i-1];
        }
    }
    return 0;
}