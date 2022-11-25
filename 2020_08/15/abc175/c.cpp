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
    ll x, k, d;
    cin >> x >> k >> d;
    if (x >= 0){
        ll num = x / d;
        if (k <= num){
            cout << x - (d * k) << endl;
            return 0;
        } 
        k -= num;
        x -= d * num;
        if (k % 2 == 0) cout << abs(x) << endl;
        else cout << abs(x-d) << endl;
        return 0;
    }else{
        ll num = abs(x / d);
        if (k <= num){
            cout << abs(x + (d * k)) << endl;
            return 0;
        }
        k -= num;
        x += d * num;
        if (k % 2 == 0) cout << abs(x) << endl;
        else cout << abs(x + d) << endl;
        return 0;
    }
}