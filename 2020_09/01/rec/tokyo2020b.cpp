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
    int a, v, b, w, t;
    cin >> a >> v >> b >> w >> t;
    if (v <= w){
        cout << "NO" << endl;
        return 0;
    }

    int dis = abs(a - b);
    int k = ceil((double)dis / (v - w));
    if (k <= t){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}