//
// Created by gtaumaturgo on 31/05/18.
//

#include <bits/stdc++.h>
using namespace std;

vector<long long> tabela(1000005);   // Se precisarmos resolver o problema
vector<int> valor(1000005);          // para mais que 10^6 moedas, precisaremos
                                     // aumentar o tamanho desse vetor.


// Nessa recorrência, o problema que queremos
// resolver computar o maior valor possível
// que podemos obter pegando moedas, considerando
// apenas as moedas que vem antes de um certo índice
// e respeitando a regra de não pegar duas adjacentes.
long long f(int indice){
    if(indice < 1)
        return 0;
    if(tabela[indice] != -1)    // se já computamos a resposta para esse subproblema,
        return tabela[indice];  // retorne a resposta que já computamos, se não a compute.

    tabela[indice] = max(f(indice-1), valor[indice] + f(indice-2));
    return tabela[indice];
}


int main(){
    // aqui marcamos na nossa tabela -1 em todos os valores,
    // de forma que -1 indica que aquele valor ainda não foi computado,
    // isto é, aquele subproblema ainda não foi resolvido
    for (int i = 0; i <= 1000000; ++i)
        tabela[i] = -1;
    

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> valor[i];
    

    cout << f(n) << endl;
}