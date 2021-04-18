/*
 * Primeiro laboratório de Computadores e Programação
 *
 * A ideia do laboratório é mostrar ao aluno outras formas de fazer as operações
 * que ele já está acostumado a fazer, mas de formas diferentes.
 * Criamos esse desafio com o objetivo de fazê-lo pensar em diferentes formas de se
 * atingir o mesmo resultado. Se possível, tentando pensar em qual seria mais
 * eficiente.
 *
 * O aluno deverá usar apenas um subset de operações de C para realizar o que
 * for pedido no enunciado.
 *
 * Todas as operações permitidas serão especificadas em cada questão.
 *
 * Forma de avaliação:
 *      - Quantas operações o aluno utlizou para realizar a tarefa (dentro da quantidade aceitável)
 *      - Explicação do código -- deverá ser o mais claro possível (como qualquer
 *          código), imaginando que qualquer pessoa sem conhecimento prévio da
 *          matéria consiga entender o que foi feito.
 *      - As resoluções com menos operações do que a do monitor terão bonificação.
 *
 * Assinatura:
 *      Aluno: Wesley Mota de Oliveira Gomes
 *      DRE: 117094621
 *      Aluno: XX
 *      DRE: XXx
 *      versão do GCC utilizada: gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0
 *
 */

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdio.h>
#include <stdint.h>


/* Número é par ou não
 *      Permitido:
 *          Operações: ~ & ^ | << >>
 *
 *      Número máximo de operações: 3
 *      Monitor: 2
 *
 *      Retorna 1 se x é par, retorna 0 caso contrário
 *
 *      Exemplo:
 *          ehPar(0) -> 1
 *          ehPar(2) -> 1
 *          ehPar(7) -> 0
 */
/*Caso o numero seja par, ele não tem o menor bit como 1, logo par & 1 = 0, logo !0 = 1
  Caso o numero seja impar, ele tem o menor bit como 1, então impar & 1 = 1, logo !1 = 0
  Retornando assim 1 caso par e 0 caso impar
 */
int32_t ehPar(int32_t x) {
    return !(x & 1);
}


/*
 * Módulo 8
 *      Permitido:
 *          Operações: ~ & ^ | ! << >>
 *
 *      Número máximo de operações: 3
 *      Monitor: 1
 *
 *      Retorna x % 8
 *
 *      Exemplo:
 *          mod8(1) -> 1
 *          mod8(7) -> 7
 *          mod8(10) -> 2
 */
/* o resto de um numero com 8 é, exatamente, os ultimos 3 bits da direita que o numero tiver, logo:
   Como 7 = 00000111, x&7 vai retornar exatamente o resto de x com 8
 */
int32_t mod8(int32_t x) {
    return x&7;
}

/* Negativo sem -
 *      Permitido:
 *          Operações: ~ & ^ | ! << >> +
 *
 *      Número máximo de operações: 5
 *      Monitor: 2
 *
 *      Retorna -x
 *
 *      Exemplo:
 *          negativo(1) -> -1
 *          negativo(42) -> -42
 */
/* Ao fazermos o complemento de x, vamos obter exatamente o numero -x-1
   Logo podemos simplesmente fazer ~x + 1 e vamos obter o negativo do numero x
 */
int32_t negativo(int32_t x) {
    return ~x + 1;
}

/* Implementação do & usando bitwise
 *      Permitido:
 *          Operações: ~ ^ | ! << >>
 *
 *      Número máximo de operações: 7
 *      Monitor: 4
 *
 *      Retorna x & y
 *
 *      Exemplo:
 *          bitwiseAnd(1, 2) -> 0
 *              01 & 10 -> 00
 *          bitwiseAnd(3, 11) -> 3
 *              11 & 1011 -> 0011
 */
/* Sabemos que o o complemento de | é & e que ~~numero = numero
   Logo ao fazermos ~(~x | ~y) = ~~x & ~~y = x & y
 */ 
int32_t bitwiseAnd(int32_t x, int32_t y) {
    return ~( ~x | ~y);
}

/* Igual sem ==
 *      Permitido:
 *          Operações: ~ & ^ | << >> !
 *
 *      Número máximo de operações: 3
 *      Monitor: 2
 *
 *      Retorna 1 se x == y, 0 caso contrário
 *
 *      Exemplo:
 *          ehIgual(10, 10) -> 1
 *          ehIgual(16, 8) -> 0
 */
/* Ao se fazer ou exclusivo (^), ^ vai se comparar bit a bit dos dois numeros:
   Se o bit de um dos numeros for 1 e o outro for 0, ^ vai retornar 1, caso os dois sejam 1 ou 0, ^ vai retornar 0.
   Logo se x=y, sabemos que x^y = 0, logo !(x^y) = 1.
   Se x!=y, sabemos que x^y vai ser algum numero qualquer diferente de 0, logo !(x^y) = 0.
   Então vai retor 1 caso x=y, e 0 caso x!=y
 */
int32_t ehIgual(int32_t x, int32_t y) {
    return !(x ^y);
}

/* Limpa bit n
 *      Permitido:
 *          Operações: ~ & ^ | ! << >>
 *
 *      Número máximo de operações: 4
 *      Monitor: 3
 *
 *      Retorna o x com o bit n = 0,
 *      n pode variar entre 0 e 31, do LSB ao MSB
 *
 *      Exemplo:
 *          limpaBitN(3, 0) -> 2
 *          limpaBitN(3, 1) -> 1
 */
/* Ao fazermos 1<<n vamos ter um numero com todos os bits 0 menos o bit n, que vai ser 1.
   Fazendo ent�o ~(1<<n) vamos obter todos os bits 1 menos o bit n que vai ser 0.
   Ao fazermos x & ~(1<<n) Vamos retornar o x com o bit n zerado. 
 */
int32_t limpaBitN(int32_t x, int8_t n) {
    return x & ~(1<<n);
}

/*
 * Bit na posição p do inteiro x
 *      Permitido:
 *          Operações bitwise: << >> | & + -
 *
 *      Número máximo de operações: 6
 *      Monitor: 2
 *
 *      Retorna o valor do bit na posição p no inteiro x
 *      Valor de retorno pode ser apenas 0 ou 1
 *
 *      p será um valor entre 0 e 31
 *
 *      Exemplo:
 *          23 em binário: 0   0 ... 0 1 0 1 1 1
 *               posições: 31 30 ... 5 4 3 2 1 0
 *
 *          bitEmP(23, 31) -> 0
 *          bitEmP(23, 5) -> 0
 *          bitEmP(23, 4) -> 1
 *          bitEmP(23, 3) -> 0
 *          bitEmP(23, 2) -> 1
 *          bitEmP(23, 1) -> 1
 *          bitEmP(23, 0) -> 1
 *
 */
/* Ao fazermos (x & 1<<p) vamos ter todos os bits zerados e apenas o bit na posição p como 1 ou 0,
   ao fazer então ((x & 1<<p)>>p), trazer esse bit p para a primeira posição, sabendo assim se é 1 ou 0 
   No final fazemos ((x & 1<<p)>>p) & 1; para prevenir caso o resultado seja -1, pois quando o p for 31, ao se
   shiftar para direita vamos estender com numeros 1, gerando assim um numero negativo, o -1, logo fazemos -1 & 1 = 1. 
 */
int32_t bitEmP(int32_t x, uint8_t p) {
    return ((x & 1<<p)>>p) & 1;
}

/*
 * Byte na posição p do inteiro x
 *      Permitido:
 *          Operações: << >> | ! &
 *
 *      Número máximo de operações: 6
 *      Monitor: 3
 *
 *      Retorna o valor do bit na posição p no inteiro x
 *      Valor de retorno pode ser entre 0 e 0xFF
 *
 *      p será um valor entre 0 e 3
 *      0 retorna LSB
 *      3 retorna MSB
 *
 *      Exemplo:
 *          byteEmP(0x12345678, 0) -> 0x78
 *          byteEmP(0x12345678, 1) -> 0x56
 *          byteEmP(0x12345678, 2) -> 0x34
 *          byteEmP(0x12345678, 3) -> 0x12
 *
 */
 /*
    Eu muliplico p por 2^3, para encontrar o quanto que eu irei mover o x 
    e depois coloco na máscara dos dois dígitos
 */
int32_t byteEmP(int32_t x, uint8_t p) {

    return (x >> (p<< 3)) & 0xFF;
}
/*
 * Seta byte na posição p do inteiro x como y
 *      Permitido:
 *          Operações: << >> | ~ ! &
 *
 *      Número máximo de operações: 7
 *      Monitor: 5
 *
 *      Retorna x com o valor y no byte da posição p
 *
 *      p será um valor entre 0 e 3
 *      0 retorna LSB
 *      3 retorna MSB
 *
 *      Exemplo:
 *          setaByteEmP(0x12345678, 0xFF, 0) -> 0x123456FF
 *          setaByteEmP(0x12345678, 0xFF, 1) -> 0x1234FF78
 *          setaByteEmP(0x12345678, 0xFF, 2) -> 0x12FF5678
 *          setaByteEmP(0x12345678, 0xFF, 3) -> 0xFF345678
 *
 */
 /* A ideia � primeiro zerar o byte p do valor x, para depois preencher com o valor y:
    0xff << (p<<3) vai nos dar exatamente o byte p preenchido totalmente e o resto zerado.
    Ao fazermos ent�o ~(0xff << (p<<3)) vamos obter todos os bytes preenchidos menos o byte p que vai estar zerado.
	Dessa forma fazemos x & ~(0xff << (p<<3)), para obtermos ent�o x com o byte p zerado.
	Como sabemos que y << (p<<3) � todos os bytes zerados e o byte p sendo o valor y, ao fazermos ent�o:
	x & ~(0xff << (p<<3)) | y <<(p<<3) vamos obter x com o valor y no byte p.
  */
int32_t setaByteEmP(int32_t x, int32_t y, uint8_t p) {
    return x & ~(0xff << (p<<3)) | y <<(p<<3);
}

/*
 * Minimo
 *      Permitido:
 *          Operações: << >> | ^ < > ~ ! & -
 *
 *      Número máximo de operações: 15
 *      Monitor: 5
 *
 *      Retorna o menor numero entre x e y
 *
 *      Exemplo:
 *          minimo(10, 15) -> 10
 *          minimo(-2, -1) -> -2
 *          minimo(-1, 2) -> -1
 *
 */
 /*
 Movo a subtração de x e y em 31, pois é inteiro 32, 
 Se (x-y) for menor que 0, então (x -y) >> 31 será 1. 
 Se (x-y) for maior ou igual a 0, então (x -y) >> 31 será 0.
 Portanto, se x> = y, obtemos o mínimo como y + (x-y) & 0, que é y.
 Se x <y, obtemos o mínimo de y + (x-y) & 1, que é x.
 */
int32_t minimo(int32_t x, int32_t y) {
    return y + ((x - y) & ((x - y) >>31));
}

/*
 * Negação lógica sem !
 *      Permitido:
 *          Operações: << >> | & + ~
 *
 *      Número máximo de operações: 15
 *      Monitor: 5
 *
 *      Retorna 1 se x == 0, retorna 0 caso contrário
 *
 *      Exemplo:
 *          negacaoLogica(0) -> 1
 *          negacaoLogica(37) -> 0
 *
 */
/* Primeiro, caso o x seja negativo, precisamos que ele seja transformado em um numero positivo, então fazemos x&-x
   Com a conta x&-x, se x for negativo ou positivo diferente de 0, vamos obter um numero positivo diferente de 0
   Caso o x seja 0, 0 & -0 = 0.
   Vamos então dividir as duas possibilidades, x!=0 e x==0:
   x!=0: ~(x & -x) + 1) = um numero negativo. Ao mover 31 posicoes a direita de um numero negativo de 31 bits, vamos obter o numero -1
	o numero -1 + 1 = 0, logo quando x!=0, vamos retornar 0
   x =0: ~(x & -x) + 1) = 0. Ao mover 31 posições a direita do numero 0, vamos obter novamente 0. 0+1 = 1, 
        logo quando x=0, vamos retornar 1.
 */
int32_t negacaoLogica(int32_t x) {
  return ((~(x & -x) + 1) >>31 )+ 1;
}

void teste(int32_t saida, int32_t esperado) {
    static uint8_t test_number = 0;
    test_number++;
    if(saida == esperado)
        printf(ANSI_COLOR_GREEN "PASSOU! Saída: %-10d\t Esperado: %-10d\n" ANSI_COLOR_RESET,
            saida, esperado);

    else
        printf(ANSI_COLOR_RED "%d: FALHOU! Saída: %-10d\t Esperado: %-10d\n" ANSI_COLOR_RESET,
            test_number, saida, esperado);
}

int main() {
    puts(ANSI_COLOR_BLUE "Primeiro lab - bits" ANSI_COLOR_RESET);
    puts("");

    puts("Teste: ehPar");
    teste(ehPar(2), 1);
    teste(ehPar(1), 0);
    teste(ehPar(3), 0);
    teste(ehPar(13), 0);
    teste(ehPar(100), 1);
    teste(ehPar(125), 0);
    teste(ehPar(1024), 1);
    teste(ehPar(2019), 0);
    teste(ehPar(2020), 1);
    teste(ehPar(-1), 0);
    teste(ehPar(-27), 0);
    teste(ehPar(-1073741825), 0);
    teste(ehPar(1073741824), 1);
    teste(ehPar(2147483647), 0);
    teste(ehPar(-2147483648), 1);
    teste(ehPar(0), 1);
    puts("");

    puts("Teste: mod8");
    teste(mod8(0), 0);
    teste(mod8(4), 4);
    teste(mod8(7), 7);
    teste(mod8(8), 0);
    teste(mod8(-1), 7);
    teste(mod8(-8), 0);
    teste(mod8(2147483647), 7);
    teste(mod8(-2147483648), 0);
    puts("");

    puts("Teste: negativo");
    teste(negativo(0), 0);
    teste(negativo(1), -1);
    teste(negativo(-1), 1);
    teste(negativo(2147483647), -2147483647);
    teste(negativo(-2147483647), 2147483647);
    teste(negativo(-2147483648), 2147483648);
    puts("");

    puts("Teste: bitwiseAnd");
    teste(bitwiseAnd(1, 3), 1);
    teste(bitwiseAnd(-1, 0), 0);
    teste(bitwiseAnd(-1, 0x7FFFFFFF), 0x7FFFFFFF);
    teste(bitwiseAnd(0b0100, 0b1100), 0b0100);
    puts("");

    puts("Teste: ehIgual");
    teste(ehIgual(1,1), 1);
    teste(ehIgual(1,0), 0);
    teste(ehIgual(0,1), 0);
    teste(ehIgual(-1,1), 0);
    teste(ehIgual(-1,-1), 1);
    teste(ehIgual(2147483647,-1), 0);
    teste(ehIgual(2147483647,-2147483647), 0);
    teste(ehIgual(2147483647,-2147483648), 0);
    teste(ehIgual(2147483647,-2147483648), 0);
    puts("");

    puts("Teste: limpaBitN");
    teste(limpaBitN(1,0), 0);
    teste(limpaBitN(0b1111,1), 0b1101);
    teste(limpaBitN(15,3), 7);
    teste(limpaBitN(-1,31), 2147483647);
    teste(limpaBitN(-1,0), -2);
    teste(limpaBitN(2147483647, 30), 1073741823);
    puts("");

    puts("Teste: bitEmP");
    teste(bitEmP(1, 0), 1);   //    b01 => retorna 1
    teste(bitEmP(1, 1), 0);   //    b01 => retorna 0
    teste(bitEmP(2, 0), 0);   //    b10 => retorna 0
    teste(bitEmP(2, 1), 1);   //    b10 => retorna 1
    teste(bitEmP(9, 2), 0);   //  b1001 => retorna 0
    teste(bitEmP(-4194305, 22), 0);
    teste(bitEmP(9, 3), 1);
    teste(bitEmP(16, 3), 0);
    teste(bitEmP(0x1 << 5, 4), 0);
    teste(bitEmP(0x1 << 31, 31), 1);
    teste(bitEmP(-1073741825, 30), 0);
    teste(bitEmP(-1073741825, 31), 1);
    puts("");

    puts("Teste: byteEmP");
    teste(byteEmP(0x766B, 1), 0x76);
    teste(byteEmP(0x766B, 0), 0x6B);
    teste(byteEmP(0x8420, 0), 0x20);
    teste(byteEmP(0x12345678, 3), 0x12);   // retorna 0x12
    teste(byteEmP(0x12345678, 2), 0x34);   // retorna 0x34
    teste(byteEmP(0x12345678, 1), 0x56);   // retorna 0x56
    teste(byteEmP(0x12345678, 0), 0x78);   // retorna 0x78
    teste(byteEmP(0x321, 1), 0x03);        // retorna 0x03
    teste(byteEmP(0x321, 0), 0x21);        // retorna 0x21
    puts("");

    puts("Teste: setaByteEmP");
    teste(setaByteEmP(0x00, 0xFF, 0), 0x000000FF);
    teste(setaByteEmP(0x00, 0xFF, 1), 0x0000FF00);
    teste(setaByteEmP(0x00, 0xFF, 2), 0x00FF0000);
    teste(setaByteEmP(0x00, 0xFF, 3), 0xFF000000);
    teste(setaByteEmP(0x01234567, 0x33, 2), 0x01334567);
    teste(setaByteEmP(0xdeadbeef, 0x00, 0), 0xdeadbe00);
    teste(setaByteEmP(0xdeadbeef, 0x00, 1), 0xdead00ef);
    puts("");

    puts("Teste: minimo");
    teste(minimo(0,1), 0);
    teste(minimo(0,10), 0);
    teste(minimo(1, 128), 1);
    teste(minimo(-1, 0), -1);
    teste(minimo(-1, -2), -2);
    teste(minimo(2147483647, 2147483646), 2147483646);
    teste(minimo(-2147483648, -2147483647), -2147483648);
    teste(minimo(-2147483648, -1), -2147483648);
    puts("");

    puts("Teste: negacaoLogica");
    teste(negacaoLogica(0), 1);
    teste(negacaoLogica(1), 0);
    teste(negacaoLogica(-1), 0);
    teste(negacaoLogica(64), 0);
    teste(negacaoLogica(-64), 0);
    teste(negacaoLogica(2147483647), 0);
    teste(negacaoLogica(-2147483648), 0);
    puts("");

}

