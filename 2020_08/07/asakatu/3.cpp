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

int f(int x){
    return (x * (1 + x)) / 2;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        if (f(i) >= n){
            int ans = i;
            while(n > ans){
                cout << ans << endl;
                n -= ans;
                ans--;
            }
            cout << n << endl;
        }
    }
    return 0;
}