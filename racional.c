#include <stdio.h>
#include <stdlib.h> //include do aleat/rand
#include "racional.h"


/* retorna um número aleatório entre min e max. */
long aleat (long min, long max) {

    return min + rand() % (max - min + 1);

}

/* Máximo Divisor Comum entre a e b*/
long mdc (long a, long b) {
    if (b == 0)
      return a;
    
    return mdc(b, a % b);
}

/* Mínimo Múltiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b) {

    return (a *b) / mdc(a, b); 
}

/* Cria um número racional com o numerador e denominador indicados. */
struct racional cria_r (long numerador, long denominador) {
  
    struct racional r;

    r.num = numerador;
    r.den = denominador;

    return r;

}
/* Retorna 1 se o racional r for válido ou 0 se for inválido.
 * Um racional é inválido se seu denominador for zero */
int valido_r (struct racional r) {

    if(r.den != 0)
      return 1;
    return 0;
}
 
/* Recebe um número racional e o simplificar.
 * Se ambos numerador e denominador forem negativos, deve retornar um positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador.
 * Se r for inválido, devolve-o sem simplificar. */
struct racional simplifica_r (struct racional r) {

    int divisor;

    //caso r seja inválido
    if(valido_r(r) == 0)
      return r;

    //simplifica pelo mdc
    divisor = mdc(r.num, r.den);
    r.num /= divisor;
    r.den /= divisor;

    //ajuste de sinais
    if (r.den < 0) {
      r.num = r.num * (-1);
      r.den = r.den * (-1);
    }

    return r;
}

/* Retorna um número racional aleatório na forma simplificada.
 * Deve ser sorteado o numerador e depois o denominador.
 * o racional gerado pode ser válido ou inválido.
 * O numerador e o denominador devem ser inteiros entre min e max. */
struct racional sorteia_r (long min, long max) {

    struct racional r;

    r.num = aleat(min, max);
    r.den = aleat(min, max);

    return simplifica_r(r);
}

/* Imprime um racional r, respeitando estas regras:
   - o racional deve ser impresso na forma simplificada;
   - não imprima espaços em branco e não mude de linha;
   - a saída deve ter o formato "num/den", a menos dos casos abaixo:
     - se o racional for inválido, deve imprimir a mensagem "INVALIDO";
     - se o numerador for 0, deve imprimir somente "0";
     - se o denominador for 1, deve imprimir somente o numerador;
     - se o numerador e denominador forem iguais, deve imprimir somente "1";
     - se o racional for negativo, o sinal "-" deve vir antes do numerador;
     - se numerador e denominador forem negativos, o racional é positivo. */
void imprime_r (struct racional r) {

    //confere se r eh valido, se não for, imprime e retorna
    if(valido_r(r) == 0) {
      printf("INVALIDO");
      return;
    }
    //caso do numerador igual a zero, imprime apaenas zero
    if(r.num == 0)
      printf("0");
    
    //caso do denominador igual a um, imprime apenas o numerador
    else if(r.den == 1)
      printf("%ld", r.num);
    
    //caso em que o numerador e denominador sao iguais, imprime apenas um
    else if(r.num == r.den)
      printf("1");
    
    else 
    //imprime padrão
    printf("%ld/%ld", r.num, r.den);

    //como a questão do sinal foi resolvida na simplifica_r, nao foi colocado na impressao    
}

/* Retorna a soma dos racionais r1 e r2.
 * se r1 ou r2 for inválido, o resultado deve ser inválido */
struct racional soma_r (struct racional r1, struct racional r2) {

    struct racional r;

    //calcula o numerador pela formula a/b + c/d = (ad + cb)/(b*d)
    r.num = (r1.num * r2.den) + (r2.num * r1.den);
    r.den = r1.den * r2.den;
    
    //o caso de r1 ou r2 inválido é tratado na simplifica_r
    return simplifica_r(r);
  
}

/* Retorna a subtração dos racionais r1 e r2.
 * se r1 ou r2 for inválido, o resultado deve ser inválido */
struct racional subtrai_r (struct racional r1, struct racional r2) {

    struct racional r;

    //calcula o numerador pela formula a/b - c/d = (ad - cb)/(b*d)
    r.num = (r1.num * r2.den) - (r2.num * r1.den);
    r.den = r1.den * r2.den;

    //o caso de r1 ou r2 inválido é tratado na simplifica_r
    return simplifica_r(r);

}

/* Retorna a multiplicação dos racionais r1 e r2.
 * se r1 ou r2 for inválido, o resultado deve ser inválido */
struct racional multiplica_r (struct racional r1, struct racional r2) {

    struct racional r;

    r.num = r1.num * r2.num;
    r.den = r1.den * r2.den;
    
    return simplifica_r(r);
}

/* Retorna a divisão dos racionais r1 e r2.
 * se r1 ou r2 for inválido, o resultado deve ser inválido.
 * observe que a divisão com r1 e r2 válidos pode gerar um racional inválido */
struct racional divide_r (struct racional r1, struct racional r2) {

    struct racional r;

    //calcula a divisão usando a multiplição pelo inverso da r2
    r.num = r1.num * r2.den;
    r.den = r1.den *r2.num;

    return simplifica_r(r);
}
