import statistics
from subprocess import PIPE, Popen
import joblib
import optuna


n_parallel = 10
n_files = 100
n_trials = 100


# 各入力ごとのスコアを計算する
def calc_score_each(seed: int, x: float):
    p = Popen(f"./a.out {x}", shell=True, stdout=PIPE, stderr=PIPE)
    stdout, stderr = p.communicate()
    return float(stderr)


# 平均スコアを計算する
def calc_scores(x: float):
    scores = joblib.Parallel(n_jobs=n_parallel)(
        joblib.delayed(calc_score_each)(i, x) for i in range(n_files)
    )
    return scores


def objective(trial: optuna.trial.Trial):
    x = trial.suggest_float("x", -1, 1)
    scores = calc_scores(x)
    return statistics.mean(scores)


if __name__ == "__main__":
    Popen("g++ -O2 -std=c++17 objective.cpp", shell=True).wait()
    study = optuna.create_study(
        direction="maximize",
        storage="sqlite:///test.db",
        study_name="test",
        load_if_exists=True,
    )
    study.optimize(objective, n_trials=n_trials)