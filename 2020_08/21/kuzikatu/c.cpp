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
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i]--;

    vector<int> town;
    set<int> st;
    town.push_back(0);
    st.insert(0);
    int i = 0;
    while(true){
        k--;
        if (k == 0){
            cout << a[i]+1 << endl;
            return 0;
        }
        if (st.find(a[i]) == st.end()){
            town.push_back(a[i]);
            st.insert(a[i]);
            i = a[i];
            continue;
        }else{
            vector<int> loop;
            rep(j,town.size()){
                if (a[i] == town[j]) {
                    for(int k = j; k < town.size(); k++) loop.push_back(town[k]);
                    break;
                }
            }
            k %= loop.size();
            cout << loop[k] + 1 << endl;
            return 0;
        }
    }
    return 0;
}