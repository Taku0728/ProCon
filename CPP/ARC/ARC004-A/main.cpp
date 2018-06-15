#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int N(0);
    cin >> N;
    vector<vector<int>> v(0);
    for(int i(0); i < N; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        vector<int> vv = { a, b };
        v.emplace_back(vv);
    }
    double l(0);
    for (int i(0); i < N; ++i){
        for (int j(0); j < N; ++j){
            l = max(l, pow(pow(v[i][0] - v[j][0], 2) + pow(v[i][1] - v[j][1], 2), 0.5));
        }
    }
    printf("%f\n", l);
}