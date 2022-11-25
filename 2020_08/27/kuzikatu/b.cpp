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

string ans;

void dfs(string f, int sum, string s, int i){
    if (i == 4){
        if (sum == 7){
            ans = f + "=7";
        }
        return;
    }
    dfs(f + "+" + s[i], sum+(s[i]-'0'), s, i+1);
    dfs(f + "-" + s[i], sum-(s[i]-'0'), s, i+1);
}

int main(){
    string s;
    cin >> s;
    dfs({s[0]}, s[0]-'0', s, 1);
    cout << ans << endl;
    return 0;
}