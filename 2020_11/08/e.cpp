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

int main(){
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<P> L(n);
    VVI BX(h), BY(w);
    rep(i,n){
        int a, b;
        cin >> a >> b;
        a--; b--;
        L[i] = P(a, b);
    }
    rep(i,m){
        int c, d;
        cin >> c >> d;
        c--; d--;
        BX[c].push_back(d);
        BY[d].push_back(c);
    }
    rep(i, h) sort(all(BX[i]));
    rep(i, w) sort(all(BY[i]));
    VVL mpRL(h+1, VL(w+1)), mpUD(h+1, VL(w+1));
    rep(i,n){
        P l = L[i];
        int x = l.second, y = l.first;

        auto itrR = lower_bound(all(BX[y]), x);
        mpRL[y][x] += 1;
        if (itrR == BX[y].end()){
            mpRL[y][w] += -1;
        }else{
            mpRL[y][*itrR] += -1;
        }
        mpRL[y][x+1] += -1;
        if (itrR == BX[y].begin()){
            mpRL[y][0] += 1;
        }else{
            itrR--;
            mpRL[y][*itrR+1] += 1;
        }
        
        

        auto itrD = lower_bound(all(BY[x]), y);
        mpUD[y][x] += 1;
        if (itrD == BY[x].end()){
            mpUD[h][x] += -1;
        }else{
            mpUD[*itrD][x] += -1;
        }
        mpUD[y+1][x] += -1;
        if (itrD == BY[x].begin()){
            mpUD[0][x] += 1;
        }else{
            itrD--;
            mpUD[*itrD+1][x] += 1;       
        }
    }
    rep(i,h) rep(j,w){
        mpRL[i][j+1] += mpRL[i][j];
        mpUD[i+1][j] += mpUD[i][j];
    } 
    int ans = 0;
    rep(i,h) rep(j,w){
        if (mpRL[i][j] > 0 || mpUD[i][j] > 0) ans++;
    }
    view(ans);
    return 0;
}