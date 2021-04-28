#include <math.h>
#include <stdio.h>
int main() {

FILE *fp;
fp = fopen("decimal_addition_local.txt", "w");
int i,j,k;
    fprintf(fp,"P +_ S __ >-\n",i, i);                          //P-S
for (i=0; i<10; i++)
{
    fprintf(fp,"P %d_ P %d_ >-\n",i, i);                        //P-P
}
for (i=0; i<10; i++)
{
    fprintf(fp,"S %d_ S _%d >>\n",i, i);                        //S-S
}
    fprintf(fp,"S __ R __ <<\n");                                 //S-R
for (i=0; i<10; i++)
{
    fprintf(fp,"R _%d R _%d <-\n",i,i);                           //R-R
}
for (i=0; i<10; i++)
{
    for (j=0; j<10; j++)
    {
        fprintf(fp,"R %d%d A %d%d --\n", i, j, i, j);             //R-A
    }
}
for (i=0; i<10; i++)
{
    for (j=0; j<10; j++)
    {
        if (i+j<10)
        {
            k=i+j;
            fprintf(fp,"A %d%d A %d_ <<\n", i, j, k);             //A-A
        }
        if (i+j>=10)
        {
            k=(i+j)-10;
            fprintf(fp,"A %d%d C %d_ <<\n", i, j, k);             //A-C
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
            fprintf(fp,"C %d%d A %d_ <<\n", i, j, k);             //C-A
        }
        if (i+j>=9)
        {
            k=(i+j+1)-10;
            fprintf(fp,"C %d%d C %d_ <<\n", i, j, k);             //C-C
        }
    }
}
for (i=0; i<10; i++)
{
    fprintf(fp,"A %d_ A %d_ <<\n", i, i);
}
for (i=0; i<10; i++)
{
    fprintf(fp,"A _%d A %d_ <<\n", i, i);
}
for (i=0; i<10; i++)
{
    if(i==9)
    {
        fprintf(fp,"C %d_ C 0_ <<\n", i);
    }
    else
    {
        k=i+1;
        fprintf(fp,"C %d_ A %d_ <<\n", i, k);
    }
}
for (i=0; i<10; i++)
{
    if(i==9)
    {
        fprintf(fp,"C _%d C 0_ <<\n", i);
    }
    else
    {
        k=i+1;
        fprintf(fp,"C _%d A %d_ <<\n", i, k);
    }
}
    fprintf(fp,"A __ H __ <<\n");
    fprintf(fp,"C __ A 1_ <<\n");
}
