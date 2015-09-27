#include <stdio.h>

void toh(int n, char source, char temp, char dest)
{
    if(n > 0)
    {
        toh(n-1, source, dest, temp);
        printf("Move %c to %c\n", source, dest);
        toh(n-1, temp, source, dest);
    }
}

int main(void)
{
    int n;
    char source = 'A', dest = 'C', temp = 'B';
    printf("Enter the no of disks: \n");
    scanf("%d", &n);
    toh(n, source, temp, dest);
}
