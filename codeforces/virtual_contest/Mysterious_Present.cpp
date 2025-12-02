// Peter decided to wish happy birthday to his friend from Australia and send him a card. To make his present more mysterious, he decided to make a chain. Chain here is such a sequence of envelopes A = {a1,  a2,  ...,  an}, where the width and the height of the i-th envelope is strictly higher than the width and the height of the (i  -  1)-th envelope respectively. Chain size is the number of envelopes in the chain.

// Peter wants to make the chain of the maximum size from the envelopes he has, the chain should be such, that he'll be able to put a card into it. The card fits into the chain if its width and height is lower than the width and the height of the smallest envelope in the chain respectively. It's forbidden to turn the card and the envelopes.

// Peter has very many envelopes and very little time, this hard task is entrusted to you.

// Input
// The first line contains integers n, w, h (1  ≤ n ≤ 5000, 1 ≤ w,  h  ≤ 106) — amount of envelopes Peter has, the card width and height respectively. Then there follow n lines, each of them contains two integer numbers wi and hi — width and height of the i-th envelope (1 ≤ wi,  hi ≤ 106).

// Output
// In the first line print the maximum chain size. In the second line print the numbers of the envelopes (separated by space), forming the required chain, starting with the number of the smallest envelope. Remember, please, that the card should fit into the smallest envelope. If the chain of maximum size is not unique, print any of the answers.

// If the card does not fit into any of the envelopes, print number 0 in the single line.





#include <bits/stdc++.h>
using namespace std;

struct Envelope {
    int w, h, idx;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cardW, cardH;
    cin >> n >> cardW >> cardH;

    vector<Envelope> env;
    for (int i = 0; i < n; i++) {
        int wi, hi;
        cin >> wi >> hi;
        if (wi > cardW && hi > cardH)
            env.push_back({wi, hi, i + 1}); 
    }

    if (env.empty()) {
        cout << 0;
        return 0;
    }

 
    sort(env.begin(), env.end(), [](Envelope a, Envelope b) {
        if (a.w == b.w) return a.h > b.h;
        return a.w < b.w;
    });

    int m = env.size();
    vector<int> dp(m, 1), parent(m, -1);

    int maxLen = 1, last = 0;

    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < i; ++j) {
            if (env[i].w > env[j].w && env[i].h > env[j].h && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            last = i;
        }
    }

    
    vector<int> chain;
    for (int i = last; i != -1; i = parent[i])
        chain.push_back(env[i].idx);

    reverse(chain.begin(), chain.end());

    cout << maxLen << "\n";
    for (int x : chain) cout << x << " ";
    cout << "\n";

    return 0;
}
