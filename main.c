/* ========================================================
   INSTITUIÇÃO: UNIPÊ – Centro Universitário de João Pessoa
   PROFESSOR: Carlos Herriot Fernandes Da Silva Junior
   DISCIPLINA: Computabilidade e Complexidade de Algoritmos
   REFERENTE: Código-Fonte Principal

   EQUIPE:
   1. Ana Clara de Queiroz Andrade
   2. Daniela Gomes de Oliveira
   3. Leandra Lima de Sousa
   4. Maria Eduarda de Moura Ferreira
   5. Thaís Rainara Marques de Morais

   ======================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



/* ========================================================
   SEÇÃO 1: PROTÓTIPOS DAS FUNÇÕES
   ========================================================

   RESPONSABILIDADE:
   Nesta seção devem ser declarados os protótipos de todas
   as funções implementadas no programa.

   O protótipo informa ao programa:
   - nome da função;
   - tipo de retorno;
   - parâmetros recebidos.

   Cada integrante deve adicionar aqui o protótipo da
   função pela qual ficou responsável, incluindo eventuais
   funções auxiliares necessárias para sua implementação.

   ======================================================== */




/* ========================================================
   SEÇÃO 2: IMPLEMENTAÇÃO DAS FUNÇÕES
   ========================================================

   RESPONSABILIDADE:
   Nesta seção serão implementadas as 5 funções solicitadas
   no projeto.

   Cada integrante deve implementar a função pela qual ficou
   responsável e, caso necessário, criar as funções auxiliares
   utilizadas exclusivamente por sua função.

   IMPORTANTE:
   - Seguir exatamente a descrição da questão;
   - Realizar a entrada dos dados necessária;
   - Permitir preenchimento manual ou aleatório, conforme
     solicitado pelo professor;
   - Exibir os vetores/matrizes utilizados;
   - Exibir o resultado da operação.

   ======================================================== */


/* --------------------------------------------------------
   FUNÇÃO 1: Contagem de Ocorrências Distintas

   RESPONSABILIDADE:
   Implementar a Função 1, que recebe um vetor principal
   de tamanho n e um vetor de k elementos a serem buscados.
   Para cada elemento buscado, deve contar suas ocorrências
   no vetor principal e retornar a soma dessas ocorrências.

   ======================================================== */

// Implementação da Função 1 aqui


/* --------------------------------------------------------
   FUNÇÃO 2: Análise de Pares em Matriz Triangular

   RESPONSABILIDADE:
   Implementar a Função 2, analisando a diagonal principal
   e os elementos da metade superior da matriz, comparando
   cada elemento com seu oposto A[j][i].

   O contador deve ser incrementado quando a soma dos dois
   elementos for múltipla de 5.

   ======================================================== */

// Implementação da Função 2 aqui


/* --------------------------------------------------------
   FUNÇÃO 3: Comparação de Matrizes Tridimensionais

   RESPONSABILIDADE:
   Implementar a Função 3, percorrendo completamente os
   arranjos tridimensionais A e B, calculando suas somas
   e comparando os resultados.

   Deve retornar 1 se a soma de A for maior ou igual à
   soma de B e 0 caso contrário.

   ======================================================== */

// Implementação da Função 3 aqui


/* --------------------------------------------------------
   FUNÇÃO 4: Análise de Casos Assimétricos no Condicional

   RESPONSABILIDADE:
   Implementar a função processar_vetor.

   Para cada elemento:
   - Se for PAR, somar diretamente ao acumulador;
   - Se for ÍMPAR, calcular seu fatorial e somar o
     resultado ao acumulador.

   Ao final, retornar o somatório.

   ======================================================== */

// Implementação da Função 4 aqui


/* --------------------------------------------------------
   FUNÇÃO AUXILIAR: Busca Binária

   RESPONSABILIDADE:
   Implementar a busca binária em um vetor ordenado.

   A função deve retornar:
   - 1 se o elemento for encontrado;
   - 0 caso contrário.

   Essa função será utilizada pela Função 5.

   ======================================================== */

// Implementação da Busca Binária aqui


/* --------------------------------------------------------
   FUNÇÃO 5: Contagem de Elementos Presentes em Vetor Ordenado

   RESPONSABILIDADE:
   Implementar a Função 5 utilizando a busca binária.

   Para cada elemento do vetor A, deve realizar uma busca
   no vetor B e contar quantos elementos de A estão presentes
   em B.

   Ao final, retornar o total encontrado.

   ======================================================== */

// Implementação da Função 5 aqui





/* ========================================================
   SEÇÃO 3: FUNÇÃO PRINCIPAL (MAIN) E MENU DO PROGRAMA
   ========================================================

   RESPONSABILIDADE:
   Esta seção será responsável pela execução do programa.

   O main deverá:
   - Exibir o menu principal;
   - Permitir que o usuário escolha uma das 5 funções;
   - Solicitar os dados necessários para a função escolhida;
   - Perguntar se os dados serão preenchidos manualmente
     ou de forma aleatória, conforme as regras do trabalho;
   - Chamar a função correspondente;
   - Exibir o resultado;
   - Permitir que o usuário retorne ao menu;
   - Encerrar o programa quando a opção de saída for escolhida.

   A integração das funções das 5 integrantes será realizada
   nesta seção.

   ======================================================== */

int main() {
    int opcao;

    do
    {
        printf("\n========================================\n");
        printf("       MENU - AVALIACAO 01\n");
        printf("========================================\n");
        printf("1. Contagem de Ocorrencias Distintas\n");
        printf("2. Analise de Pares em Matriz Triangular\n");
        printf("3. Comparacao de Matrizes Tridimensionais\n");
        printf("4. Analise de Casos Assimétricos no Condicional\n");
        printf("5. Contagem de Elementos em Vetor Ordenado\n");
        printf("0. Sair\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("\nFuncao 1 selecionada.\n");
                break;

            case 2:
                printf("\nFuncao 2 selecionada.\n");
                break;

            case 3:
                printf("\nFuncao 3 selecionada.\n");
                break;

            case 4:
                printf("\nFuncao 4 selecionada.\n");
                break;

            case 5:
                printf("\nFuncao 5 selecionada.\n");
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}