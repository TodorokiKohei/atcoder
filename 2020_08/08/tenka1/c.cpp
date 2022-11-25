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
    string s;
    cin >> n >> s;
    vector<int> kuro(n), siro(n);
    if (s[0] == '#') kuro[0] = 1;
    for(int i = 1; i < n; i++){
         if (s[i] == '#') kuro[i] = kuro[i-1] + 1;
         else kuro[i] = kuro[i-1];
    }
    if (s[n-1] == '.') siro[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        if (s[i] == '.') siro[i] = siro[i+1]+1;
        else siro[i] = siro[i+1];
    }

    int ans = n;
    for(int i = 0; i < n; i++){
        int ope;
        if (i == 0){
            ope = min(siro[0], kuro[n-1]);
        }
        else{
            ope = kuro[i-1] + siro[i];
        }
        ans = min(ans, ope);
    }
    cout << ans << endl;
    return 0;
}