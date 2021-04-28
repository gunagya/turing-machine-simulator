#include <math.h>
#include <stdio.h>
void main() {

int i,j,k;
    printf("Init : P\n");
    printf("Accept : H\n");
    printf("P, +, _\nS, _, _, >, -\n",i, i);                          //P-S
for (i=0; i<10; i++)
{
    printf("P, %d, _\nP, %d, _, >, -\n",i, i);                        //P-P
}
for (i=0; i<10; i++)
{
    printf("S, %d, _\nS, _, %d, >, >\n",i, i);                        //S-S
}
    printf("S, _, _\nR, _, _, <, <\n");                                 //S-R
for (i=0; i<10; i++)
{
    printf("R, _, %d\nR, _, %d, <, -\n",i,i);                           //R-R
}
for (i=0; i<10; i++)
{
    for (j=0; j<10; j++)
    {
        printf("R, %d, %d\nA, %d, %d, -, -\n", i, j, i, j);             //R-A
    }
}
for (i=0; i<10; i++)
{
    for (j=0; j<10; j++)
    {
        if (i+j<10)
        {
            k=i+j;
            printf("A, %d, %d\nA, %d, _, <, <\n", i, j, k);             //A-A
        }
        if (i+j>=10)
        {
            k=(i+j)-10;
            printf("A, %d, %d\nC, %d, _, <, <\n", i, j, k);             //A-C
        }
    }
}
for (i=0; i<10; i++)
{
    for (j=0; j<10; j++)
    {
        if (i+j<9)
        {
            k=i+j+1;
            printf("C, %d, %d\nA, %d, _, <, <\n", i, j, k);             //C-A
        }
        if (i+j>=9)
        {
            k=(i+j+1)-10;
            printf("C, %d, %d\nC, %d, _, <, <\n", i, j, k);             //C-C
        }
    }
}
for (i=0; i<10; i++)
{
    printf("A, %d, _\nA, %d, _, <, <\n", i, i);
}
for (i=0; i<10; i++)
{
    printf("A, _, %d\nA, %d, _, <, <\n", i, i);
}
for (i=0; i<10; i++)
{
    if(i==9)
    {
        printf("C, %d, _\nC, 0, _, <, <\n", i);
    }
    else
    {
        k=i+1;
        printf("C, %d, _\nA, %d, _, <, <\n", i, k);
    }
}
for (i=0; i<10; i++)
{
    if(i==9)
    {
        printf("C, _, %d\nC, 0, _, <, <\n", i);
    }
    else
    {
        k=i+1;
        printf("C, _, %d\nA, %d, _, <, <\n", i, k);
    }
}
    printf("A, _, _\nH, _, _, <, <\n");
    printf("C, _, _\nA, 1, _, <, <\n");
}
