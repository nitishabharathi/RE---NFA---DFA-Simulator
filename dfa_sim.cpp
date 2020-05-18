//#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#define MAX_DFA_STATES 10
#define MAX_INPUT_SIZE 10              //max value the input can take [1,2,....n]
using namespace std;

int main()  {
    int N, M, F, X, Y, A, state, symbol, i, j;
    char* p;
    int transitions[MAX_DFA_STATES][MAX_INPUT_SIZE];
    int finalStates[MAX_DFA_STATES]={0};
    char inputString[100];

    ifstream fin("DFA1.txt");
    fin >> N >> M >> F;
    cout<<M;
    for(i=0; i<F; i++)  {
        fin >> X;
        finalStates[X] = 1;
    }
    for(int i=0;i<MAX_DFA_STATES;i++){
        cout<<i<<" "<<finalStates[i]<<endl;
    }
    memset(transitions, -1, MAX_DFA_STATES * MAX_INPUT_SIZE * sizeof(int));

    while(!fin.eof())   {
        fin >> X >> A >> Y;
        transitions[X][A] = Y;      //X -> Start , A-> Input Symbol , Y ->End
    }
    fin.close();
    for(i=0; i<N; i++)
    {
        for(j=1; j<=M; j++)
        {
            if(transitions[i][j] < 0 || transitions[i][j] >= N)
            {
                cout<<endl<<"DFA not defined properly";
            }
        }
    }
    for(int i=0;i<MAX_DFA_STATES  ;i++){
        for(int j=0;j<MAX_INPUT_SIZE ;j++){
            if(transitions[i][j]!=-1){
                cout<<"State: "<<i<<" Symbol: "<<j<<" To_state: "<<transitions[i][j]<<"\n";
            }
        }
    }
    cout<<endl<<"Enter a string with space('.' to stop) : ";
    gets(inputString);
    while(inputString[0] !='.'){
        state = 0;
        p = strtok(inputString," ");
        while(p){
            symbol = atoi(p);
            if(symbol <= 0 || symbol > M)
            {
                cout<<endl<<"Invalid input symbol"<<symbol;
                return -1;
            }
            else
            {
                state = transitions[state][symbol];
                cout<<state;
            }
            p = strtok(NULL," ");
        }
        if(finalStates[state]==1)
            cout<<endl<<"String Accepted";
        else
            cout<<endl<<"String Rejected";
        cout<<endl<<"Enter a string with space('.' to stop) : ";
        gets(inputString);
    }
    return 0;
}
