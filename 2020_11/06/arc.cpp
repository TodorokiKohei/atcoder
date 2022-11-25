#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int inf = 1 << 30;
const ll INF = 1LL << 60;

struct Edge{
    int cost, to, id;
    Edge(int cost, int to, int id): cost(cost), to(to), id(id){}
};

struct Node{
    int id, cost;
    Edge e;
    Node(int id, int cost, Edge e): id(id), cost(cost), e(e){}

    bool operator>(const Node n) const{
        if (cost == n.cost) return id > n.id;
        else return cost > n.cost;
    }
};

vector<vector<Edge>> g;
vector<int> cnts;

void dijkstra(int i, int n){
    VL dist(n, INF), visited(n);
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[i] = 0;
    pq.push(Node(i, 0, Edge(-1, -1, -1)));
    while(!pq.empty()){
        Node n = pq.top(); pq.pop();
        int v = n.id, cost = n.cost;
        if (dist[v] < cost || visited[v]){
            cnts[n.e.id]--;
        }

        visited[v] = 1;
        for(Edge e: g[v]){
            int d = e.to;
            if (visited[d]) continue;
            if (dist[d] > dist[v] + e.cost){
                dist[d] = dist[v] + e.cost;
                pq.push(Node(d, dist[d], e));
                cnts[e.id]++;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    g.resize(n);
    cnts.resize(m);
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back(Edge(c, b, i));
        g[b].push_back(Edge(c, a, i));
    }
    rep(i,n) dijkstra(i, n);

    int ans = 0;
    rep(i,m) if (cnts[i] == 0) ans++;
    cout << ans << endl;
    return 0;
}