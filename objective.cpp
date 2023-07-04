#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    random_device rnd;
    double x = 0;
    if (argc == 2) x = atof(argv[1]);
    double eps = rnd() % 1000 / 1000.0 - 0.5;
    cerr << - x * x + eps;
}