# Exercícios de Estruturas de Dados

Este repositório contém meus exercícios da disciplina de **Estruturas de Dados**, implementados em **C**.  
Cada arquivo corresponde a um exercício prático com foco em lógica, organização e aplicação de algoritmos.

---

## 📌 Exercício 1 - Cadastro e Busca de Alunos

### Descrição
Programa em C que:
- Cadastra alunos com **nome** e **nota**;
- Permite **ordenar** as notas usando o algoritmo **Selection Sort**;
- Realiza **busca binária** para encontrar um aluno pela nota;
- Exibe a lista completa de alunos cadastrados;
- Possui um **menu interativo** para navegação.

### Estrutura do código
- `struct notasAlunos`: guarda o nome e a nota de cada aluno;
- `selectionSort()`: ordena as notas em ordem crescente;
- `buscaBinaria()`: procura por uma nota específica já ordenada;
- `main()`: controla o fluxo principal do programa.

---

## ▶️ Como compilar e executar

No terminal, use o **gcc** para compilar:

```bash
gcc Exercicio_1.c -o exercicio1
