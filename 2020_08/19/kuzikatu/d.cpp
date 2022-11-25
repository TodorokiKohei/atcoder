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
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    vector<int> ans(n);
    rep(i,n){
        vector<int> dist(n, -1);
        queue<int> q;

        dist[i] = 0;
        q.push(i);
        while(!q.empty()){
            int v = q.front(); q.pop();
            ans[dist[v]]++;
            if (v+1 < n && dist[v+1] == -1){
                q.push(v+1);
                dist[v+1] = dist[v] + 1;
            }
            if (v-1 >= 0 && dist[v-1] == -1){
                q.push(v-1);
                dist[v-1] = dist[v] + 1;
            }
            if (v == x && dist[y] == -1){
                q.push(y);
                dist[y] = dist[v] + 1;
            }
            if (v == y && dist[x] == -1){
                q.push(x);
                dist[x] = dist[v] + 1;
            }
        }
    }
    for(int i = 1; i < n; i++){
        cout << ans[i] / 2 << endl;
    }
    return 0;
}