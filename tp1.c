#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

int main () {
    
    struct racional r1, r2;
    struct racional somar, subtracaor, multr, divir;
    int i, max, n, fim;

    //com srand no 0, a sequencia de numeros sera sempre a mesma
    srand (0);

    //le um valor n tal que 0 < n < 100, garante o numero no intervalo
    //n sendo o numero de iteracoes
    fim = 1;
    do {
        scanf("%d", &n);
        if (n > 0 && n < 100)
            fim = 0;
    } while (fim); 

    //le um valor max tal que que 0 < max < 30, garante o numero no intervalo
    // max sendo o valor máximo assumido pelo racional
    fim = 1;
    do {
        scanf("%d", &max);
        if (max > 0 && max < 30)
            fim = 0;
    } while (fim);

    //loop que executa n iteraçoes
    for (i = 1; i <= n; i++) {
        printf("%d: ", i);

        r1 = sorteia_r(-max, max);
        r2 = sorteia_r(-max, max);

        imprime_r(r1); printf(" ");
        imprime_r(r2); printf(" ");

        //confere se r1 ou r2 sao invalidos
        if ((!valido_r(r1)) || (!valido_r(r2))) {
            printf("NUMERO INVALIDO\n");
            return 1;
        }

        //realiza as operaçoes
        somar = soma_r(r1, r2);
        subtracaor = subtrai_r(r1, r2);
        multr = multiplica_r(r1, r2);
        divir = divide_r(r1, r2);

        //confere se a divisao realizada acima eh valida
        if (!valido_r(divir)) {
            printf("DIVISAO INVALIDA"); printf ("\n");
            return 1;
        }

        imprime_r(somar); printf(" ");
        imprime_r(subtracaor); printf(" ");
        imprime_r(multr); printf(" ");
        imprime_r(divir);
        printf("\n");
    }  

    return (0) ;
}
