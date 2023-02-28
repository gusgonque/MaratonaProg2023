#include <stdio.h>
#include <stdlib.h>

int main(){

    int maior, x;
    scanf("%d", &maior);
    if (maior != 0){
        scanf("%d", &x);
        while (x != 0){
            maior = (maior>x?maior:x);
            scanf("%d", &x);
        }
        printf("%d",maior);
    }

    return 0;
}
