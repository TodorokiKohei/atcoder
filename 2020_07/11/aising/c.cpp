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

int solve(int a, int b, int c){
    double d = sqrt(b*b - 4*a*c);
    if (d < 0) return 0;
    if (floor(d != d)) return 0;
    double x = (-b + d) / 2 * a;
    double y = (-b - d) / 2 * a;
    int ans = 0;
    if (floor(x) == x && x > 0) ans++;
    if (floor(y) == y && y > 0) ans++;
    return ans;
}

int f(int n){
    int ans = 0;
    for(int i = 1; i*i <= n; i++){
        for(int j = 1; j*j <= n; j++){
            ans += solve(1, i + j, (i*i + j*j + i*j - n));
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cout << f(i) << endl;
    }
    return 0;
}