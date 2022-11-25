#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define pqueue(x) priority_queue<x,vector<x>,greater<x>>
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define rev(x) reverse(x);
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
using vpl=vector<pl>;
using vvpl=vector<vpl>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[9]={1,0,-1,0,1,1,-1,-1,0};
const ll dx[9]={0,-1,0,1,1,-1,1,-1,0};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
    ll n,m,a,b;cin >> n >> m >> a >> b;a--;
    vvl g(n+1);
    rep(i,m){
        ll l,r;cin >> l >>r;l--;
        if(l<=a)l=a;
        if(b<=r)r=b;
        g[l].pb(r);
        g[r].pb(l);
    }
    queue<ll> que;
    que.push(a);
    vl dist(n+1,-1);
    dist[a]=0;
    while(!que.empty()){
        ll v=que.front();que.pop();
        for(auto nv:g[v]){
            if(dist[nv]!=-1)continue;
            dist[nv]=dist[v]+1;
            que.push(nv);
        }
    }
    cout << dist[b] <<endl;
}