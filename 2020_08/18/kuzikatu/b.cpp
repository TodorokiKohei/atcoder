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
    string t;
    cin >> t;
    int n = 0, s = 0, w = 0, e = 0;
    rep(i,t.size()){
        if (t[i] == 'N') n++;
        else if (t[i] == 'S') s++;
        else if (t[i] == 'W') w++;
        else if (t[i] == 'E') e++;
    }   
    if (n != 0 && s == 0) cout << "No" << endl;
    else if (n == 0 &&s != 0) cout << "No" << endl;
    else if (w != 0 && e == 0) cout << "No" << endl;
    else if (w == 0 && e != 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}