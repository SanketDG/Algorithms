#include <stdio.h>

void represent(int r, int c, int count, int a[][c])
{
    int nz = r * c - count;
    int i, j, result[nz + 1][3], k;

    printf("Row\tColumn\tValue\n");

    result[0][0] = r;
    result[0][1] = c;
    result[0][2] = nz;
    k = 1;

    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(a[i][j] != 0) {
                result[k][0] = i;
                result[k][1] = j;
                result[k][2] = a[i][j];
                k++;
            }
        }
    }

    for(i = 0; i < nz + 1; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

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
}