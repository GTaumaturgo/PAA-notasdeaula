//
// Created by gtaumaturgo on 31/05/18.
//

#include <bits/stdc++.h>
using namespace std;

long long tabela[55];  // teremos que aumentar a tabela
                        // se quisermos calcular fibonacci
                        // para valores maiores que 50, mas
                        // a função cresce muito rápido, então
                        // valores um pouco maiores que isso já
                        // nao cabem em inteiros de 64 bits.

// Nessa recorrência, o problema que queremos
// resolver é calcular fibonacci para um certo n
long long f(int n){
    if(n == 0)
        return tabela[n] = 0;
    if(n == 1)
        return tabela[n] = 1;

    if(tabela[n] != -1)    // se já computamos a resposta para esse subproblema,
        return tabela[n];  // retorne a resposta que já computamos, se não a compute.

    tabela[n] = f(n-1) + f(n-2);
    return tabela[n];
}


int main(){
    // aqui marcamos na nossa tabela -1 em todos os valores,
    // de forma que -1 indica que aquele valor ainda não foi computado,
    // isto é, aquele subproblema ainda não foi resolvido
    for (int i = 0; i <= 50; ++i) {
        tabela[i] = -1;
    }

    int n;
    cin >> n;
    cout << f(n) << endl;
}