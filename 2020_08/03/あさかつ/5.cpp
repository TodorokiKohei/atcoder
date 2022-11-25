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

bool canConvert(string w1, string w2){
    int cnt = 0;
    for(int i = 0; i < w1.size(); i++) if (w1[i] != w2[i]) cnt++;
    return (cnt == 1);
}

int main(){
    int n;
    string f, l;
    cin >> f >> l >> n;

    vector<string> words(n+2);
    for(int i = 1; i <= n; i++) cin >> words[i];
    words[0] = f;
    words[n+1] = l;

    if (f == l){
        cout << 0 << endl;
        cout << f << endl;
        cout << l << endl;
        return 0;
    }

    vector<vector<int>> g(n+2);
    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= n+1; j++){
            if (canConvert(words[i], words[j])) g[i].push_back(j);
        }
    }

    vector<int> dist(n+2, -1), parent(n+2, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int d: g[v]){
            if (dist[d] != -1) continue;
            dist[d] = dist[v] + 1;
            parent[d] = v;
            q.push(d);
        }
    }

    if (parent[n+1] == -1){
        cout << -1 << endl;
        return 0;
    }

    vector<string> ans;
    ans.push_back(l);
    int p = parent[n+1];
    while(p != -1){
        ans.push_back(words[p]);
        p = parent[p];
    }
    reverse(all(ans));

    cout << dist[n+1]-1 << endl;
    rep(i, ans.size()){
        cout << ans[i] << endl;
    }
    return 0;
}