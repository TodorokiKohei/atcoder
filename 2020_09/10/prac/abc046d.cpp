#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    string s;
    cin >> s;
    int n = s.size();
    VI cnts;
    int cnt = 0;
    char c = 'g';
    for(int i = 1; i < n; i++){
        if (s[i] != c){
            cnts.push_back(cnt);
            c = c == 'g' ? 'p' : 'g';
            cnt = 0;
        }
        cnt++;
    }
    cnts.push_back(cnt);

    int score = 0, p_cnt = 1;
    if (s[0] == 'p') score = -1;
    rep(i, cnts.size()){
        if (i % 2 == 0){
            if (cnts[i] <= p_cnt){
                score += cnts[i];
                p_cnt -= cnts[i];
            }else{
                score += p_cnt;
                cnts[i] -= p_cnt;
                score += cnts[i] / 2;
                p_cnt = cnts[i] % 2;
            }
        }else{
            if (cnts[i] <= p_cnt){
                p_cnt -= cnts[i];
            }else{
                cnts[i] -= p_cnt;
                score -= (cnts[i]+1) / 2;
                p_cnt = cnts[i] % 2;
            }
        }
    }
    cout << score << endl;
    return 0;
}