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

void change(string &s, vector<set<int>>& index, int i, char c){
    if (s[i] == c) return;
    int pre = s[i] - 'a';
    int to = c - 'a';
    index[pre].erase(i);
    index[to].insert(i);
    s[i] = c;
    return;
}

int calc(string &s, vector<set<int>>& index, int l, int r){
    int res = 0;
    rep(i, index.size()){
        if (index[i].size() == 0) continue;
        auto itr = index[i].lower_bound(l);
        if (itr == index[i].end()) continue;
        if (*itr <= r) res++;
    }
    return res;
}

int main(){
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<set<int>> index(26);
    rep(i,n){
        int j = s[i] - 'a';
        index[j].insert(i);
    }

    vector<int> ans;
    rep(k,q){
        int t;
        cin >> t;
        if (t == 1){
            int i;
            char c;
            cin >> i >> c;
            i--;
            change(s, index, i, c);
        }else{
            int l, r;
            cin >> l >> r;
            l--; r--;
            ans.push_back(calc(s, index, l, r));
        }
    }
    rep(i, ans.size()) cout << ans[i] << endl;
    return 0;
}