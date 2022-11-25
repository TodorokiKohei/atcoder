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

int main(){
    int k, n;
    cin >> n >> k;
    VI p(n);
    rep(i,n) cin >> p[i];
    VI fi(n, -1);
    VI fnum(n);
    set<int> st;
    VI ans(n, -1);
    rep(i,n){
        int index = p[i]-1;
        auto itr = st.lower_bound(p[i]);
        if (itr == st.end()){
            st.insert(index);
            fi[index] = index;
            fnum[index] = 1;
        }else{
            int pre_index = *itr;
            st.erase(pre_index);
            st.insert(index);
            fi[index] = pre_index;
            fnum[index] = fnum[pre_index]+1;
        }
        int par_index = fi[index];
        if (fnum[index] == k){
            st.erase(index);
            int x = index;
            rep(j,k){
                ans[x] = i+1;
                x = fi[x];
            }
        }
    }
    rep(i,n) printf("%d\n", ans[i]);
    return 0;
}