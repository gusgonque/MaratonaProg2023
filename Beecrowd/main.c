#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    for(int i=0; i<y; ++i){
        printf("%d ", i+1);
        if ((i+1)%x == 0)
            printf("\n");
    }

    return 0;
}
