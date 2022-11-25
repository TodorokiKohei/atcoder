#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a--; b--; c--; d--;
    string s;
    cin >> s;
    int x, y;
    x = b;
    y = min(c, d);

    bool ok1 = false;
    for(int i = x; i <= y; i++){
        if (s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') ok1 = true;
    }

    int u, v;
    u = a;
    v = max(c, d);
    bool ok2 = true;
    for(int i = u; i < v; i++){
        if (s[i] == '#' && s[i+1] == '#') ok2 = false;
    }

    if (!ok2){
        cout << "No" << endl;
    }
    else{
        if (c > d && !ok1) cout << "No" << endl;
        else cout << "Yes" << endl; 
    } 
    return 0;
}