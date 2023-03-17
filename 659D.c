#include <stdio.h>

int main() {
    int x, cont = 0;

    scanf("%d",&x);

    int mat[x+1][2];
    char dir[x];

    scanf("%d %d", &mat[0][0], &mat[0][1]);
    for (int i = 1; i <= x; ++i) {
        scanf("%d %d", &mat[i][0], &mat[i][1]);
        if(mat[i][0]>mat[i-1][0]){
            dir[i-1] = 'd';
        } else if(mat[i][1]>mat[i-1][1]){
            dir[i-1] = 's';
        } else if(mat[i][0]<mat[i-1][0]){
            dir[i-1] = 'e';
        } else if(mat[i][1]<mat[i-1][1]){
            dir[i-1] = 'b';
        }
    } for (int i = 1; i < x; ++i) {
        switch (dir[i]) {
            case 'd':
                if(dir[i-1] == 'b')
                    cont ++;
                break;
            case 's':
                if(dir[i-1] == 'd')
                    cont ++;
                break;
            case 'e':
                if(dir[i-1] == 's')
                    cont ++;
                break;
            case 'b':
                if(dir[i-1] == 'e')
                    cont ++;
                break;
            default:
                break;
        }
    }
    printf("%d", cont);
    return 0;
}