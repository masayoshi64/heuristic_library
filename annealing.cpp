#include "header.hpp"

State simulated_annealing(State state) {
    Timer timer;
    double max_time = 800;
    double start_temp = 3000; // 一回の遷移で動きうるスコア幅の最大値程度
    double end_temp = 1; // 一回の遷移で動きうるスコア幅の最小値程度
    double time = timer.lap();
    while (time < max_time) {
        time = timer.lap();
        double temp = start_temp + (end_temp - start_temp) * time / max_time;
        double score = state.score;
        double new_score = state.get_new_score();
        double prob = exp((new_score - score) / temp);
        if (prob > (double) xor64(10000000) / 10000000) {
            state.step();
        }
    }
    return state;
}

State hill_climbing(State state){
    Timer timer;
    double max_time = 800;
    while (timer.lap() < max_time) {
        double score = state.score;
        double new_score = state.get_new_score();
        if (new_score > score) {
            state.step();
        }
    }
    return state;
}