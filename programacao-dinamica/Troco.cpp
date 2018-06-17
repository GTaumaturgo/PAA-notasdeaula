//
// Created by gtaumaturgo on 31/05/18.
//

#include <bits/stdc++.h>
using namespace std;
int oo = 2e9; // infinito é um valor muito alto (2 x 10^9)

vector<long long> tabela(1000005);   // Se precisarmos resolver o problema
int quant_moedas;
vector<int> moedas(105);          // para mais que 100 moedas, precisaremos
                                      // aumentar o tamanho desse vetor.


// Nessa recorrência, queremos computar
// a menor quantidade de moedas para
// somarmos exatamente um certo troco,
// considerando apenas as moedas de entrada
// ou informar que é impossível somar
// exatamente aquela quantidade, retornando oo
int f(int troco){
    if(troco == 0){
        tabela[troco] = 0;
    }
    if(tabela[troco] != -1)    // se já computamos a resposta para esse subproblema,
        return tabela[troco];  // retorne a resposta que já computamos, se não a compute.

    int minimo = oo;

    for(int i = 1; i <= quant_moedas; i++){
        if(moedas[i] <= troco){
            minimo = min(minimo, 1 + f(troco - moedas[i]));
        }
    }
    tabela[troco] = minimo;
    return minimo;

}


int main(){
    // aqui marcamos na nossa tabela -1 em todos os valores,
    // de forma que -1 indica que aquele valor ainda não foi computado,
    // isto é, aquele subproblema ainda não foi resolvido
    for (int i = 0; i <= 1000000; ++i) {
        tabela[i] = -1;
    }

    int valor;
    cin >> quant_moedas >> valor;

    for (int i = 1; i <= quant_moedas; ++i) {
        int x;
        cin >> x;
        moedas[i] = x;
    }
    cout << f(valor) << endl;
}