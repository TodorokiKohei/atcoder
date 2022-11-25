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
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), ans;
    rep(i,n) cin >> a[i+1];
    for(int i = n; i > 0; i--){
        ll sum = 0;
        for(int j = i; j <= n; j += i) sum += b[j];
        if (sum % 2 != a[i]){
            b[i]++;
            ans.push_back(i);
        }
    }
    int sz = ans.size();
    reverse(all(ans));
    cout << sz << endl;
    for(int i = 0; i < sz; i++){
        printf("%d%c", ans[i], i == sz-1 ? '\n': ' ');
    }
    return 0;
}