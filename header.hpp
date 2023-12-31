#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep_(i, a_, b_, a, b, ...) for (ll i = (a), max_i = (b); i < max_i; i++)
#define rep(i, ...) rep_(i, __VA_ARGS__, __VA_ARGS__, 0, __VA_ARGS__)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

struct Timer {
    clock_t start_time;
    Timer() {
        start_time = clock();
    }
    void reset() {
        start_time = clock();
    }
    int lap() {
        // return x ms.
        return (clock() - start_time) * 1000 / CLOCKS_PER_SEC;
    }
};

long long xor64(long long range) {
    static uint64_t x = 88172645463325252ULL;
    x ^= x << 13;
    x ^= x >> 7;
    return (x ^= x << 17) % range;
}

bool time_check() {
    static Timer timer;
    if (timer.lap() > 1800)
        return false;
    return true;
}

struct State{
    // for annealing
    double score;
    double get_new_score(){}  
    void step(){} // 実際の更新

    // for beam search
    vector<State> get_next_states(){}  
    bool operator<(const State &rhs) const {
        return score < rhs.score;
    }
};