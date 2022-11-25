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
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    for(int i = 1; i < n; i++){
        if (a[i] + a[i-1] >= l){
            cout << "Possible" << endl;
            for(int j = 1; j < i; j++) cout << j << endl;
            for(int j = n-1; j >= i; j--) cout << j << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}