#include "header.hpp"

State chokudai_search(State initial_state, int max_turn){
    vector<priority_queue<State>> beam(max_turn+1);
    beam[0].push(initial_state);
    int chokudai_width = 1;
    while(time_check()){
        rep(t, max_turn){
            rep(i, chokudai_width){
                if(beam[t].empty()) break;
                State state = beam[t].top();
                beam[t].pop();
                for(auto next_state: state.next_states()){
                    beam[t+1].push(next_state);
                }
            }
        }
    }
    State best_state = beam[max_turn].top();
    return best_state;
}

State greedy_search(State initial_state, int max_turn){
    State state = initial_state;
    rep(t, max_turn){
        auto next_states = state.next_states();
        state = *max_element(all(next_states));
    }
    return state;
}

State beam_search(State initial_state, int max_turn, int beam_width){
    vector<State> beam;
    beam.push_back(initial_state);
    rep(t, max_turn){
        vector<State> next_beam;
        int size = beam.size();
        rep(i, min(beam_width, size)){
            State state = beam[i];
            for(auto next_state: state.next_states()){
                next_beam.push_back(next_state);
            }
        }
        sort(rall(next_beam));
        beam = next_beam;
    }
    State best_state = beam[0];
    return best_state;
}