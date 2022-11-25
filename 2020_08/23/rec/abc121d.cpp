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

ll oddSolve(ll x) {return ((x+1) / 2) % 2;}

ll solve(ll x){
    if (x % 2 == 1) return oddSolve(x);
    else return oddSolve(x+1) ^ (x+1);
}

int main(){
    ll a, b;
    cin >> a >> b;
    cout << (solve(b) ^ solve(a-1)) << endl;
    return 0;
}