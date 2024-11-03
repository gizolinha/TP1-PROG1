#include <stdio.h>
#include <stdlib.h>
#include "racional.h"


int main () {

    struct racional r1, r2;
    struct racional somar, subtracaor, multiplir, divisaor;
    int i, max, n, fim;

    srand(0); 

    //le um valor n tal que 0 < n < 100, garante o numero dentro do intervalo
    fim = 1;
    do {
          scanf("%d", &n);
          if (n > 0 && n < 100)
              fim = 0;
    } while (fim);

    // le um valor max tal que 0 < max < 30, garante o numero dentro do intervalo
    fim = 1;
    do {
          scanf("%d", &max);
          if (max > 0 && max < 30)
              fim = 0;
    } while (fim);

    //loop que executa n interações, n fornecido pelo usuário
    for (i = 1; i <= n; i++) {
      printf("%d: ", i);

      r1 = sorteia_r(-max, max);
      r2 = sorteia_r(-max, max);

      imprime_r(r1); printf(" ");
      imprime_r(r2); printf(" ");

  //verifica se o numeros sorteados sao validos 
      if ((!valido_r(r1) || (!valido_r(r2)))) {
        printf("NUMERO INVALIDO\n");
        return 1;
      }

      //realiza as operações com os racionais
      somar = soma_r(r1, r2);
      subtracaor = subtrai_r(r1, r2);
      multiplir = multiplica_r(r1, r2);
      divisaor = divide_r(r1, r2);

      //verifica se a divisão é inválida
      if (!valido_r(divisaor)) {
          printf("DIVISAO INVALIDA"); printf ("\n");
          return 1;
      }

      //imprime as operações
      imprime_r(somar); printf(" ");
      imprime_r(subtracaor); printf(" ");
      imprime_r(multiplir); printf(" ");
      imprime_r(divisaor);
      printf("\n");
    }

  return (0);
}
