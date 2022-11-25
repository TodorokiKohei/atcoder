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
    int n;
    cin >> n;
    n--;
    vector<int> c(n), s(n), f(n);
    rep(i,n) cin >> c[i] >> s[i] >> f[i];
    for(int i = 0; i < n; i++){
        int t = c[i] + s[i];
        for(int j = i+1; j < n; j++){
            if (t <= s[j]){
                t = s[j];
                t += c[j];
            }else{
                t = f[j] * ceil((double)t / f[j]);
                t += c[j];
            }
        }
        cout << t << endl;
    }
    cout << 0 << endl;
    return 0;
}