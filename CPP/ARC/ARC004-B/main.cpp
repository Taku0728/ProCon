#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int sum(0);
    int maxa(0);
    for (int i(0); i < N; ++i){
        int a;
        scanf("%d", &a);
        sum += a;
        maxa = max(a, maxa);
    }
    printf("%d\n%d\n", sum, max(0, 2 * maxa - sum));
}