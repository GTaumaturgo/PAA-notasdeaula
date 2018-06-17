// Created by gtaumaturgo on 31/05/18.

#include <bits/stdc++.h>
using namespace std;

int oo = 1000000000;

int tabela[105][105];           // Se precisarmos resolver o problema para mais que 10^2
vector<int> dimensao(105);
// matrizes precisamos aumentar o tamanho desse vetor.
int f(int l, int r){
    if(l+1 == r)
        return 0;
    if(tabela[l][r] != -1)
        return tabela[l][r];
    
    int resposta = oo;
    for(int i = l+1; i < r; i++){
        resposta = min(resposta, f(l,i) + f(i,r) + dimensao[l] * dimensao[i] * dimensao[r]);
    }
    tabela[l][r] = resposta;
    return resposta;
}

int main()
{
    // aqui marcamos na nossa tabela -1 em todos os valores,
    // de forma que -1 indica que aquele valor ainda não foi computado,
    // isto é, aquele subproblema ainda não foi resolvido
    for (int i = 0; i < 104; ++i)
        for (int j = 0; j < 104; ++j)
            tabela[i][j] = -1;

    int n;
    cin >> n;
    // temos que ler n+1 valores para multiplicar n matrizes.
    for(int i = 0; i < n+1; i++){
        cin >> dimensao[i];;
    }
    cout << f(0,n) << endl;
    cout << f(0,n-1) << endl;
    cout << f(1,n) << endl;
}