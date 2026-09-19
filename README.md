# Projeto AV01 - Complexidade e Computabilidade de Algoritmos
Repositório da equipa para o desenvolvimento da Avaliação 01 da disciplina de Complexidade e Computabilidade de Algoritmos.

## Equipe
* [ClaraQrz](https://github.com/ClaraQrz) 
* [DanielaGOliveira](https://github.com/DanielaGOliveira)
* [Leandralimas](https://github.com/Leandralimas)
* [EduardaMFerreira](https://github.com/EduardaMFerreira) 
* [ThaisRainara](https://github.com/niquila?tab=followers)

---

## Sobre o Projeto
O objetivo deste software é implementar, testar e analisar a eficiência computacional de **5 funções principais** desenvolvidas em linguagem C (utilizando recursos do C99 como *[Variable Length Arrays](https://www.ibm.com/docs/en/xl-c-and-cpp-aix/16.1.0?topic=arrays-variable-length)* - VLA). Além da implementação em código, o projeto engloba o estudo teórico de complexidade linha a linha, expressão de complexidade total, notação **Big O** e cálculo de tempo estimado de execução.

---

## Funcionalidades do Sistema

O programa conta com um menu interativo onde o utilizador pode escolher qual função deseja testar, optando por preencher os dados **manualmente** ou **automaticamente (com valores randómicos gerados pelo sistema)**, exibindo a prévia do arranjo antes de rodar a operação:

1. **Contagem de Ocorrências Distintas:** Cruza um vetor de busca (k elementos) em um vetor principal (n = 50.000) somando o total de aparições.
2. **Análise de Pares em Matriz Triangular:** Percorre a diagonal principal e metade superior de uma matriz quadrada (n = 500) testando a condição de múltiplos de 5 com os seus opostos na metade inferior.
3. **Comparação de Matrizes Tridimensionais:** Soma integralmente dois arranjos tridimensionais (n = 300 \times 300 \times 300) e compara os resultados.
4. **Análise de Casos Assimétricos (Condicional):** Percorre um vetor (n = 50.000), somando diretamente os valores pares e calculando o fatorial dos valores ímpares no pior caso.
5. **Contagem em Vetor Ordenado (Busca Binária):** Utiliza uma função auxiliar de busca binária para verificar quantos elementos de um vetor desordenado (n = 10.000.000$) estão presentes num vetor ordenado.
