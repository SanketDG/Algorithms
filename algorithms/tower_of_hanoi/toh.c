#include <stdio.h>

void toh(int n, char source, char dest, char temp)
{
    if(n > 0)
    {
        toh(n-1, source, temp, dest);
        printf("Move disk %d from %c to %c\n", n, source, dest);
        toh(n-1, temp, dest, source);
    }
}

int main(void)
{
    int n;
    char source = 'A', dest = 'C', temp = 'B';
    printf("Enter the no of disks: \n");
    scanf("%d", &n);
    toh(n, source, dest, temp);
}
