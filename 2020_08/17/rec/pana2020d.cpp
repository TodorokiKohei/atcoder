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

vector<string> ans;

void dfs(int n, string s, char cMax){
    if (s.size() == n){
        ans.push_back(s);
        return;
    }else{
        for(char c = 'a'; c <= cMax+1; c++){
            dfs(n, s+c, max(c, cMax));
        }
    }
}

int main(){
    int n;
    cin >> n;
    dfs(n, "a", 'a');
    rep(i, ans.size()){
        cout << ans[i] << endl;
    }
    return 0;
}