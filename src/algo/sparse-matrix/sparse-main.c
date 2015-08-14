#include <stdio.h>
#include "sparse-matrix.h"

int main(void)
{
    int r, c, i, j, count;

    printf("Enter the no.of rows and columns\n");
    scanf("%d %d", &r, &c);

    int a[r][c];

    printf("Enter the elements\n");

    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    count = 0;

    for(i = 0; i < r; i++) {
        for(j = 0; j < r; j++) {
            if (a[i][j] == 0)
                count++;
        }
    }

    if(count > (2/3.0) * (r * c)) {
        printf("It is a sparse matrix\n");
        represent(r, c, count, a);
    }
    else {
        printf("It is not a sparse matrix\n");
    }

    return 0;
}