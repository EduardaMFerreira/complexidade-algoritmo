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

/* --- Protótipos da Função 3 (Comparação de Matrizes Tridimensionais) --- */
int ***alocarMatriz3D(int n);
void liberarMatriz3D(int ***M, int n);
void preencherManual3D(int ***M, int n, const char *nome);
void preencherAleatorio3D(int ***M, int n, int limiteInferior, int limiteSuperior);
void exibirMatriz3D(int ***M, int n, const char *nome);
int compararMatrizes3D(int ***A, int ***B, int n);

/* --- Protótipos da Função 4 (Análise de Casos Assimétricos / Fatorial) --- */
int *alocarVetor(int n);
void liberarVetor(int *V);
void preencherVetorManual(int *V, int n, const char *nome);
void preencherVetorAleatorio(int *V, int n, int limiteInferior, int limiteSuperior);
void exibirVetor(int *V, int n, const char *nome);
long long fatorial(int x);
long long processarVetor(int *V, int n);

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

/* Aloca uma matriz n x n x n dinamicamente (heap), evitando
   estourar a pilha para valores grandes de n. */
int ***alocarMatriz3D(int n)
{
  int ***M = (int ***)malloc(n * sizeof(int **));
  for (int i = 0; i < n; i++)
  {
    M[i] = (int **)malloc(n * sizeof(int *));
    for (int j = 0; j < n; j++)
    {
      M[i][j] = (int *)malloc(n * sizeof(int));
    }
  }
  return M;
}

void liberarMatriz3D(int ***M, int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      free(M[i][j]);
    }
    free(M[i]);
  }
  free(M);
}

/* Preenchimento manual: usuário digita cada elemento.
   Recomendado apenas para n pequeno. */
void preencherManual3D(int ***M, int n, const char *nome)
{
  printf("\nPreenchimento manual da matriz %s (%d x %d x %d):\n", nome, n, n, n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        printf("%s[%d][%d][%d] = ", nome, i, j, k);
        scanf("%d", &M[i][j][k]);
      }
    }
  }
}

/* Preenchimento aleatório dentro de um intervalo [limiteInferior, limiteSuperior]. */
void preencherAleatorio3D(int ***M, int n, int limiteInferior, int limiteSuperior)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        M[i][j][k] = limiteInferior + rand() % (limiteSuperior - limiteInferior + 1);
      }
    }
  }
}

/* Exibe a matriz. Só é chamada quando n é pequeno (ver main),
   pois para n grande (ex.: 300) a impressão seria inviável. */
void exibirMatriz3D(int ***M, int n, const char *nome)
{
  printf("\nMatriz %s:\n", nome);
  for (int i = 0; i < n; i++)
  {
    printf("Camada %d:\n", i);
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        printf("%4d ", M[i][j][k]);
      }
      printf("\n");
    }
  }
}

/* Núcleo da Função 3: percorre A e B num único laço triplo,
   acumulando as somas, e compara ao final. Complexidade O(n^3). */
int compararMatrizes3D(int ***A, int ***B, int n)
{
  long long somaA = 0;
  long long somaB = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      for (int k = 0; k < n; k++)
      {
        somaA += A[i][j][k];
        somaB += B[i][j][k];
      }
    }
  }

  printf("\nSoma de A = %lld\n", somaA);
  printf("Soma de B = %lld\n", somaB);

  if (somaA >= somaB)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

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

/* Aloca um vetor de tamanho n dinamicamente. */
int *alocarVetor(int n)
{
  return (int *)malloc(n * sizeof(int));
}

void liberarVetor(int *V)
{
  free(V);
}

void preencherVetorManual(int *V, int n, const char *nome)
{
  printf("\nPreenchimento manual do vetor %s (%d elementos):\n", nome, n);
  for (int i = 0; i < n; i++)
  {
    printf("%s[%d] = ", nome, i);
    scanf("%d", &V[i]);
  }
}

void preencherVetorAleatorio(int *V, int n, int limiteInferior, int limiteSuperior)
{
  for (int i = 0; i < n; i++)
  {
    V[i] = limiteInferior + rand() % (limiteSuperior - limiteInferior + 1);
  }
}

void exibirVetor(int *V, int n, const char *nome)
{
  printf("\nVetor %s:\n", nome);
  for (int i = 0; i < n; i++)
  {
    printf("%d ", V[i]);
  }
  printf("\n");
}

/* Calcula o fatorial de x. Usado quando o elemento do vetor é ímpar. */
long long fatorial(int x)
{
  long long resultado = 1;
  for (int i = 2; i <= x; i++)
  {
    resultado *= i;
  }
  return resultado;
}

/* Núcleo da Função 4: percorre V, somando o valor se for par
   ou o fatorial do valor se for ímpar. Complexidade: pior caso
   O(n^2), quando todos os elementos são ímpares. */
long long processarVetor(int *V, int n)
{
  long long somatorio = 0;

  for (int i = 0; i < n; i++)
  {
    if (V[i] % 2 == 0)
    {
      somatorio += V[i];
    }
    else
    {
      somatorio += fatorial(V[i]);
    }
  }

  return somatorio;
}
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

int main()
{
  int opcao;
  srand((unsigned int)time(NULL));

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
    {
      printf("\nFuncao 3 selecionada.\n");

      int n;
      printf("Digite o valor de n (dimensao das matrizes n x n x n): ");
      scanf("%d", &n);

      int ***A = alocarMatriz3D(n);
      int ***B = alocarMatriz3D(n);

      int modo;
      printf("Preenchimento (1 = Manual, 2 = Aleatorio): ");
      scanf("%d", &modo);

      if (modo == 1)
      {
        preencherManual3D(A, n, "A");
        preencherManual3D(B, n, "B");
      }
      else
      {
        preencherAleatorio3D(A, n, 0, 100);
        preencherAleatorio3D(B, n, 0, 100);
      }

      /* Exibir só faz sentido para matrizes pequenas */
      if (n <= 6)
      {
        exibirMatriz3D(A, n, "A");
        exibirMatriz3D(B, n, "B");
      }

      int resultado = compararMatrizes3D(A, B, n);
      printf("\nResultado: %d (%s)\n", resultado,
             resultado == 1 ? "soma(A) >= soma(B)" : "soma(A) < soma(B)");

      liberarMatriz3D(A, n);
      liberarMatriz3D(B, n);
      break;
    }

    case 4:
{
  printf("\nFuncao 4 selecionada.\n");

  int n;
  printf("Digite o valor de n (tamanho do vetor): ");
  scanf("%d", &n);

  int *V = alocarVetor(n);

  int modo;
  printf("Preenchimento (1 = Manual, 2 = Aleatorio): ");
  scanf("%d", &modo);

  if (modo == 1)
  {
    preencherVetorManual(V, n, "V");
  }
  else
  {
    preencherVetorAleatorio(V, n, 0, 20);
  }

  if (n <= 30)
  {
    exibirVetor(V, n, "V");
  }

  long long resultado = processarVetor(V, n);
  printf("\nResultado (somatorio): %lld\n", resultado);

  liberarVetor(V);
  break;
}

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