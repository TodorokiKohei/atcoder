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

int h, w, k;
vector<string> s;
int ans;

void dfs(vector<int> hUse, vector<int> wUse, int n){
    if (hUse.size() + wUse.size() == h + w){
        int sum = 0;
        rep(i, h) rep(j, w){
            if (hUse[i] == 1) continue;
            if (wUse[j] == 1) continue;
            if (s[i][j] == '#') sum++;
        }
        if (sum == k) ans++;
        return;
    }

    if (hUse.size() < h){
        for(int i = 0; i <= 1; i++){
            hUse.push_back(i);
            dfs(hUse, wUse, n+1);
            hUse.pop_back();
        }
    } else{
        for(int i = 0; i <= 1; i++){
            wUse.push_back(i);
            dfs(hUse, wUse, n+1);
            wUse.pop_back();
        }
    }
}

int main(){
    cin >> h >> w >> k;
    s.resize(h);
    rep(i,h) cin >> s[i];
    vector<int> hUse, wUse;
    ans = 0;
    dfs(hUse, wUse, 0);
    cout << ans << endl;
}