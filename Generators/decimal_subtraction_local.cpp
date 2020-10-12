/*-------------------------------------------
Generator for Decimal Subtraction on local Turing Machine Simulator
Input format : A-B
eg - 2983-4434 
-------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream fout("decimal_subtraction_local.txt");

	int i, j;
	for (i=0; i<=9; i++)
        fout<<"P "<<i<<"_ P "<<i<<"_ >-\n";
    fout<<"P -_ C __ >-\n";
    for (i=0; i<=9; i++)
        fout<<"C "<<i<<"_ C _"<<i<<" >>\n";
    fout<<"C __ R __ <<\n";
    for (i=0; i<=9; i++)
        fout<<"R _"<<i<<" R _"<<i<<" <-\n";
    for (i=0; i<=9; i++)
        for (j=0; j<=9; j++)
            fout<<"R "<<i<<j<<" A "<<i<<j<<" --\n";
	for (i=0; i<=9; i++)
    {
        for (j=i; j<=9; j++)
            fout<<"A "<<j<<i<<" A "<<j-i<<"_ <<\n";
        fout<<"A "<<i<<"_ "<<"A "<<i<<"_ <-\n";
    }
    for (i=0; i<=9; i++)
        for (j=i+1; j<=9; j++)
            fout<<"A "<<i<<j<<" B "<<10+i-j<<"_ <<\n";
    for (i=0; i<=9; i++)
        for (j=i; j<=9; j++)
            fout<<"B "<<i<<j<<" B "<<9+i-j<<"_ <<\n";
    fout<<"B 0_ B 9_ <-\n";
    for (i=0; i<=9; i++)
        for (j=i+1; j<=9; j++)
            fout<<"B "<<j<<i<<" A "<<j-i-1<<"_ <<\n";
    for (i=1; i<=9; i++)
        fout<<"B "<<i<<"_ A "<<i-1<<"_ <-\n";
    fout<<"A __ L __ >-\n";
    fout<<"L 0_ L __ >-\n";
    fout<<"L __ H 0_ --\n";
    for (i=1; i<=9; i++)
        fout<<"L "<<i<<"_ H "<<i<<"_ --\n";
}
