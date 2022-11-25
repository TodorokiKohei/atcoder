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
    vector<int> p(n);
    rep(i,n){
        cin >> p[i];
        p[i]--;
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        if (p[i]-i == 0){
            if (i == 0) swap(p[i], p[i+1]);
            else if (i == n-1) swap(p[i], p[i-1]);
            else{
                if ((p[i+1] - i-1) == 0) swap(p[i], p[i+1]);
                else swap(p[i], p[i-1]);
            }
            ans++;
        }
    }
    cout << ans << endl;
}