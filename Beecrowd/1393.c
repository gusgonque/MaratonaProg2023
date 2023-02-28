#include <stdio.h>

int recursao(int x) {
    if(x <= 2)
        return x;
    else
        return recursao(x-1) + recursao(x-2);
}

int main() {
    int x;
    scanf("%d", &x);
    while (x != 0){
        printf("%d\n", recursao(x));
        scanf("%d", &x);
    }
    return 0;
}