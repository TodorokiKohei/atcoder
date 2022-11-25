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
    vector<int> a(n+1);
    vector<int> b(n+1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    for(int i = n; i >= 1; i--){
        int sum = 0;
        for(int j = i * 2; j <= n; j += i){
            sum += b[j];
        }
        if (sum % 2 != a[i]){
            b[i] = 1;
            ans++;
        } 
    }
    cout << ans << endl;
    for(int i = 1; i <= n; i++){
        if (b[i] == 1) cout << i << " ";
    }
    cout << endl;
}