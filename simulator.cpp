/*-------------------------------------------
Turing Machine Simulator
The control program is read from program.txt
The instructions in program.txt are written as 5 space separated strings
eg - A 0 B 1 >
-------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

const int range=10;
const int no_of_tapes=1;

struct MachineState
{
    string state, read;
    MachineState()
    {
        read=string(no_of_tapes, ' ');
    }
    bool operator ==(const MachineState &rhs) const
    {
        return make_pair(state, read)==make_pair(rhs.state, rhs.read);
    }
};

struct NextStep
{
    string next_state, write, movement;
};

struct HashFunction
{
    size_t operator()(const MachineState &A) const
    {
        return  (hash<string>{}(A.state))^(hash<string>{}(A.read));
    }
};

class TuringMachine
{
    int head[no_of_tapes];
    string current_state, tape[no_of_tapes];
    unordered_map<MachineState, NextStep, HashFunction> program;

public:

    TuringMachine(vector<vector<string>> instructions, int tape_size=5000, char tape_init=' ', string initial_state="1")
    {
        for (auto step: instructions)
        {
            MachineState ms;
            NextStep ns;
            ms.state=step[0], ms.read=step[1];
            ns.next_state=step[2], ns.write=step[3], ns.movement=step[4];
            program[ms]=ns;
        }
        for (int i=0; i<no_of_tapes; i++)
            tape[i] = string(tape_size, tape_init);
        current_state = initial_state;
    }

    void input(string in)
    {
        for (int i=0; i<no_of_tapes; i++)
            head[i]=tape[i].size()/2;
        for (int i=0; i<in.size(); i++)
            tape[0][head[0]+i]=in[i];
    }

    void run ()
    {
        int steps=0;
        print(steps);
        while (current_state!="H")
        {
            MachineState ms;
            ms.state = current_state;
            for (int i=0; i<no_of_tapes; i++)
                ms.read[i] = tape[i][head[i]];
            if (program.find(ms)==program.end())
                break;
            NextStep ns = program[ms];
            current_state = ns.next_state;
            for (int i=0; i<no_of_tapes; i++)
            {
                tape[i][head[i]] = ns.write[i];
                switch(ns.movement[i])
                {
                    case '<': head[i]--; break;
                    case '>': head[i]++; break;
                }
            }
            print(++steps);
        }
        if (current_state=="H")
            cout<<"Accepted! Total number of steps: "<<steps<<".\n";
        else
            cout<<"Rejected.\n";
    }

    void print(int steps)
    {
        int i, j;
        cout<<"Step "<<steps<<":\n\n";
        for (j=0; j<no_of_tapes; j++)
        {
            cout<<" ";
            for (i=0; i<=2*range; i++)
                cout<<"----";
            cout<<"-\n | ";
            for (i=head[j]-range; i<=head[j]+range; i++)
                cout<<tape[j][i]<<" | ";
            cout<<"\n ";
            for (i=0; i<=2*range; i++)
                cout<<"----";
            cout<<"-\n   ";
            for (i=head[j]-range; i<head[j]; i++)
                cout<<"    ";
            cout<<"^\n";
        }
        cout<<'\n';
    }
};

int main()
{
    int i=0;
    vector<vector<string>> instructions;
    ifstream fin ("program.txt");
    vector<string> line(5);
    while (fin>>line[i])
    {
        i++;
        if (i==5)
        {
            instructions.push_back(line);
            i=0;
        }
    }
    TuringMachine tm(instructions, 5000, '0', "A");
    tm.input("");
    tm.run();
}
