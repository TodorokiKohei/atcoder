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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<pair<int, int>>> parent(h, vector<pair<int, int>>(w, make_pair(-1, -1)));
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    parent[0][0] = make_pair(-2, -2);
    while(!q.empty()){
        pair<int, int> v = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int x = v.first + dx[i];
            int y = v.second + dy[i];
            if (x < 0 || x >= w || y < 0 || y >= h) continue;
            if (s[y][x] == '#' || parent[y][x] != make_pair(-1, -1)) continue;
            q.push(make_pair(x, y));
            parent[y][x] = v;
        }
    }

    if (parent[h-1][w-1] == make_pair(-1, -1)){
        cout << -1 << endl;
        return 0;
    }

    pair<int, int> pre = parent[h-1][w-1];
    set<pair<int, int>> st;
    while(pre != make_pair(-2, -2)){
        st.insert(pre);
        int x = pre.first;
        int y = pre.second;
        pre = parent[y][x];
    }
    st.insert(make_pair(w-1, h-1));

    int ans = 0;
    rep(row, h) rep(col, w){
        if (s[row][col] == '#') continue;
        auto itr = st.find(make_pair(col, row));
        if (itr != st.end()) continue;
        ans++;
    }
    cout << ans << endl;
}