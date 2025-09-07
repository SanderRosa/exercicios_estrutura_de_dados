#include <stdio.h>
#define MAX 100 // MÁXIMO DE CADASTROS POSSÍVEIS

// ------ STRUCT-DE-ALUNOS -------
struct notasAlunos {
    char nome[50];
    float nota1;
};
// ---------- ORDENAÇÃO ----------
void selectionSort(struct notasAlunos V[], int N) {
    int i, j, menor;
    struct notasAlunos troca;

    for (i = 0; i < N - 1; i++) {
        menor = i;
        for (j = i + 1; j < N; j++) {
            if (V[j].nota1 < V[menor].nota1)
                menor = j;
        }
        if (i != menor) {
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}
// ---------- BUSCA BINÁRIA ----------
int buscaBinaria(struct notasAlunos V[], int N, float elem) {
    int inicio = 0, final = N - 1, meio;
    while (inicio <= final) {
        meio = (inicio + final) / 2;
        if (elem < V[meio].nota1)
            final = meio - 1;
        else if (elem > V[meio].nota1)
            inicio = meio + 1;
        else
            return meio;
    }
    return -1;
}
int main() {
    char opcao;
    int i, qtd;
    struct notasAlunos alunos[MAX];
    printf("Quantos alunos deseja cadastrar (max %d)? ", MAX);
    scanf("%d", &qtd);
    for (i = 0; i < qtd; i++) {
        printf("\nNome do aluno %d: ", i + 1);
        scanf(" %[^\n]", alunos[i].nome);  // lê string com espaços
        printf("Nota: ");
        scanf("%f", &alunos[i].nota1);
    }
    // ---- Menu ----
    do {
        printf("\nMENU:\n a) Ordenar\n b) Buscar\n c) Mostrar notas\n d) Sair\nEscolha: ");
        scanf(" %c", &opcao);
        if (opcao == 'a') {
            selectionSort(alunos, qtd);
            printf("Notas ordenadas com sucesso!\n");
        }
        else if (opcao == 'b') {
            float busca;
            int pos;
            printf("Digite a nota para buscar: ");
            scanf("%f", &busca);
            pos = buscaBinaria(alunos, qtd, busca);
            if (pos != -1)
                printf("Nota %.1f encontrada: %s tirou essa nota (posicao %d)\n",
                       busca, alunos[pos].nome, pos);
            else
                printf("Nota %.1f nao encontrada!\n", busca);
        }
        else if (opcao == 'c') {
            printf("\nLista de alunos:\n");
            for (i = 0; i < qtd; i++) {
                printf("%s - %.1f\n", alunos[i].nome, alunos[i].nota1);
            }
        }
        else if (opcao == 'd') {
            printf("Saindo...\n");
        }
        else {
            printf("Opcao invalida!\n");
        }
    } while (opcao != 'd');
    return 0;
}
