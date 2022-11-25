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
    string s;
    cin >> s;

    int ans = 0;
    rep(i,3){
        if (s[i] == 'R'){
            int sum = 1;
            if (i + 1 < 3 && s[i+1] == 'R') sum++;
            if (i + 2 < 3 && s[i+1] == 'R' && s[i+2] == 'R') sum++;
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}