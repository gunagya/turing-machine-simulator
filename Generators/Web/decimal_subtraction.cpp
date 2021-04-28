/*-------------------------------------------
Generator for Decimal Subtraction on https://turingmachinesimulator.com/
Input format : A-B
eg - 2983-4434
-------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ofstream fout("decimal_subtraction.txt");

	int i, j;
	for (i=0; i<=9; i++)
        fout<<"P,"<<i<<",_\nP,"<<i<<",_,>,-\n";
    fout<<"P,-,_\nC,_,_,>,-\n";
    for (i=0; i<=9; i++)
        fout<<"C,"<<i<<",_\nC,_,"<<i<<",>,>\n";
    fout<<"C,_,_\nR,_,_,<,<\n";
    for (i=0; i<=9; i++)
        fout<<"R,_,"<<i<<"\nR,_,"<<i<<",<,-\n";
    for (i=0; i<=9; i++)
        for (j=0; j<=9; j++)
            fout<<"R,"<<i<<','<<j<<"\nA,"<<i<<','<<j<<",-,-\n";
	for (i=0; i<=9; i++)
    {
        for (j=i; j<=9; j++)
            fout<<"A,"<<j<<','<<i<<"\nA,"<<j-i<<",_,<,<\n";
        fout<<"A,"<<i<<",_\n"<<"A,"<<i<<",_,<,-\n";
    }
    for (i=0; i<=9; i++)
        for (j=i+1; j<=9; j++)
            fout<<"A,"<<i<<','<<j<<"\nB,"<<10+i-j<<",_,<,<\n";
    for (i=0; i<=9; i++)
        for (j=i; j<=9; j++)
            fout<<"B,"<<i<<','<<j<<"\nB,"<<9+i-j<<",_,<,<\n";
    fout<<"B,0,_\nB,9,_,<,-\n";
    for (i=0; i<=9; i++)
        for (j=i+1; j<=9; j++)
            fout<<"B,"<<j<<','<<i<<"\nA,"<<j-i-1<<",_,<,<\n";
    for (i=1; i<=9; i++)
        fout<<"B,"<<i<<",_\nA,"<<i-1<<",_,<,-\n";
    fout<<"A,_,_\nL,_,_,>,-\n";
    fout<<"L,0,_\nL,_,_,>,-\n";
    fout<<"L,_,_\nH,0,_,-,-\n";
    for (i=1; i<=9; i++)
        fout<<"L,"<<i<<",_\nH,"<<i<<",_,-,-\n";
}
