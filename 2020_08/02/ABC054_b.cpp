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

int n, m;
vector<string> a, b;

bool match(int r, int c){
    if (c + m > n) return false;
    if (r + m > n) return false;
    for(int i = 0; i < m; i++){
        if (a[r+i].substr(c, m) != b[i]) return false;
    }   
    return true;
}

int main(){
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];

    rep(row, n) rep(col,n){
        if (match(row, col)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}