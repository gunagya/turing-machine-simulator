/*-------------------------------------------
Generator for Decimal Division on local Turing Machine Simulator
Input format : A/B
eg - 2983/44
-------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i, j, k, l;
	ofstream fout("program.txt");

	fout<<"name: Decimal Divison\ninit: P\naccept: H\n\n";

	for (i=0; i<=9; i++)
        fout<<"P "<<i<<"___ P "<<i<<"___ >---\n";
    fout<<"P /___ C ____ >---\n";
    for (i=0; i<=9; i++)
        fout<<"C "<<i<<"___ C _"<<i<<"__ >>--\n";
    fout<<"C ____ R ____ <---\n";
    fout<<"R ____ R ____ <---\n";
    for (i=0; i<=9; i++)
        fout<<"R "<<i<<"___ X "<<i<<"___ ----\n";
    for (i=0; i<=9; i++)
        fout<<"X "<<i<<"___ X "<<i<<"___ <---\n";
    fout<<"X ____ Y #___ ----\n";
    for (i=0; i<=9; i++)
        for (j=0; j<=9; j++)
        {
            fout<<"Y "<<i<<j<<"__ Y "<<i<<j<<"__ >>--\n";
            for (k=0; k<=9; k++)
                fout<<"Y "<<i<<j<<k<<"_ Y "<<i<<j<<"__ >>>-\n";
        }
    fout<<"Y #___ Z #___ >---\n";
    for (i=0; i<=9; i++)
        fout<<"Z "<<i<<"___ Z"<<i<<" #___ <---\n";
    fout<<"Z ____ Z_ ____ <---\n";
    for (i=0; i<=9; i++)
        fout<<'Z'<<i<<" #___ A0 "<<i<<"___ -<--\n";
    fout<<"Z_ #___ H ____ <<<<\n";
    for (l=0; l<=9; l++)
    {
        for (i=0; i<=9; i++)
        {
            for (j=i; j<=9; j++)
                fout<<'A'<<l<<' '<<j<<i<<"__ A"<<l<<' '<<j<<i<<j-i<<"_ <<<-\n";
            fout<<'A'<<l<<' '<<i<<"___ "<<'A'<<l<<' '<<i<<'_'<<i<<"_ <<<-\n";
        }
        for (i=0; i<=9; i++)
            for (j=i+1; j<=9; j++)
                fout<<'A'<<l<<' '<<i<<j<<"__ B"<<l<<' '<<i<<j<<10+i-j<<"_ <<<-\n";
        for (i=0; i<=9; i++)
            for (j=i; j<=9; j++)
                fout<<'B'<<l<<' '<<i<<j<<"__ B"<<l<<' '<<i<<j<<9+i-j<<"_ <<<-\n";
        fout<<'B'<<l<<" 0___ B"<<l<<" 0_9_ <<<-\n";
        for (i=0; i<=9; i++)
            for (j=i+1; j<=9; j++)
                fout<<'B'<<l<<' '<<j<<i<<"__ A"<<l<<' '<<j<<i<<j-i-1<<"_ <<<-\n";
        for (i=1; i<=9; i++)
            fout<<'B'<<l<<' '<<i<<"___ A"<<l<<' '<<i<<"_"<<i-1<<"_ <<<-\n";
        for (i=0; i<=9; i++)
        {
            fout<<'A'<<l<<" _"<<i<<"__ Y _"<<i<<'_'<<l<<" >>>>\n";
            fout<<'B'<<l<<" _"<<i<<"__ Y _"<<i<<'_'<<l<<" >>>>\n";
        }
        fout<<'B'<<l<<" ____ Y ___"<<l<<" >>>>\n";
        fout<<'A'<<l<<" ____ L"<<l<<" ____ >>>-\n";
        for (i=0; i<=9; i++)
        {
            fout<<'L'<<l<<' '<<i<<"_0_ L"<<l<<" ____ >>>-\n";
            for (j=0; j<=9; j++)
            {
                fout<<'L'<<l<<' '<<i<<j<<"0_ L"<<l<<" _"<<j<<"__ >>>-\n";
                for (k=1; k<=9; k++)
                    fout<<'L'<<l<<' '<<i<<j<<k<<"_ T"<<l<<' '<<k<<j<<"__ >>>-\n";
            }
            for (j=1; j<=9; j++)
                fout<<'L'<<l<<' '<<i<<'_'<<j<<"_ T"<<l<<' '<<j<<"___ >>>-\n";
        }
        if (l<9)
            fout<<'L'<<l<<" #___ Z #__"<<l+1<<" >-->\n";
        for (i=0; i<=9; i++)
            for (j=0; j<=9; j++)
                for (k=0; k<=9; k++)
                    fout<<'T'<<l<<' '<<i<<j<<k<<"_ T"<<l<<' '<<k<<j<<"__ >>>-\n";
        fout<<'T'<<l<<" #___ A"<<l+1<<" #___ <<<-\n";
    }
}
