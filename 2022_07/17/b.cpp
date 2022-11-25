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

const int inf = 1 << 29;
const ll INF = 1LL << 60;

bool sortPairs(const pair<int, int> &x, const pair<int, int> &y){
    if (x.first > y.first) return true;
    else if (x.first == y.first && x.second < y.second) return true;
    else return false;
}

int main(){
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<pair<int, int>> av(n), bv(n), abv(n);
    vector<int> ans;
    set<int> st;
    rep(i,n){
        int a;
        cin >> a;
        av[i] = make_pair(a, i);
    }
    rep(i,n){
        int b;
        cin >> b;
        bv[i] = make_pair(b, i);
    }
    rep(i,n){
        abv[i] = make_pair(av[i].first + bv[i].first, i);
    }
    sort(av.begin(), av.end(), sortPairs);
    sort(bv.begin(), bv.end(), sortPairs);
    sort(abv.begin(), abv.end(), sortPairs);
    int cnt = 0;
    rep(i,n){
        if (cnt == x) break;
        st.insert(av[i].second);
        ans.push_back(av[i].second);
        cnt++;
    }
    cnt = 0;
    rep(i,n){
        if (cnt == y) break;
        if (st.find(bv[i].second) != st.end()) continue;
        st.insert(bv[i].second);
        ans.push_back(bv[i].second);
        cnt++;
    }
    cnt = 0;
    rep(i,n){
        if (cnt == z) break;
        if (st.find(abv[i].second) != st.end()) continue;
        st.insert(abv[i].second);
        ans.push_back(abv[i].second);
        cnt++;
    }
    sort(all(ans));
    rep(i, sz(ans)) cout << ans[i]+1 << endl;
    return 0;
}