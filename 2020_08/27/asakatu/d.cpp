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
    int n = s.size();
    ll aCnt = 0;
    ll ans = 0;
    int i = 0;
    while(i < n){
        if (i + 2 < n && s.substr(i, 3) == "ABC"){            
            ans += aCnt + 1;
            aCnt++;
            i += 3;
        }
        else if (i + 1 < n && s.substr(i, 2) == "BC"){
            ans += aCnt;
            i += 2;
        }
        else if (s[i] == 'A'){
            aCnt++;
            i++;
        }else{
            aCnt = 0;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}