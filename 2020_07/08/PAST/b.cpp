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

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> score(m ,n);
    vector<vector<int>> userSolved(n);

    rep(i, q){
        int ope, curUser, curQues;
        cin >> ope;
        if (ope == 1){
            cin >> curUser;
            curUser--;
            int sum = 0;
            for(int uq: userSolved[curUser]){
                sum += score[uq];
            }
            cout << sum << endl;
        }else{
            cin >> curUser >> curQues;
            curUser--; curQues--;
            userSolved[curUser].push_back(curQues);
            if (score[curQues] > 0) score[curQues]--;
        }   
    }
}