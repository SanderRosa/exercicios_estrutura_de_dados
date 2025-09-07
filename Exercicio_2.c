#include <stdio.h>
#include <string.h>
#define MAX_ALUNOS 100

struct aluno {
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
};

float media(struct aluno al) {
    return (al.nota1 + al.nota2 + al.nota3) / 3;
}

// Ordena alunos por nome (ordem alfabética)
void ordenarPorNome(struct aluno lista[], int quantidade) {
    struct aluno temp;
    for(int i = 0; i < quantidade - 1; i++) {
        for(int j = i + 1; j < quantidade; j++) {
            if(strcmp(lista[i].nome, lista[j].nome) > 0) {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

// Busca binária por nome
int buscaBinaria(struct aluno lista[], int quantidade, char nome[]) {
    int esquerda = 0, direita = quantidade - 1;
    while(esquerda <= direita) {
        int meio = (esquerda + direita) / 2;
        int cmp = strcmp(nome, lista[meio].nome);
        if(cmp == 0) {
            return meio;
        } else if(cmp < 0) {
            direita = meio - 1;
        } else {
            esquerda = meio + 1;
        }
    }
    return -1;
}

int main(void) {
    struct aluno lista[MAX_ALUNOS];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n=== Sistema de Alunos ===\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos e medias\n");
        printf("3 - Listar alunos ordenados por media\n");
        printf("4 - Buscar aluno por nome (busca binaria)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch(opcao) {
            case 1:
                if(quantidade >= MAX_ALUNOS) {
                    printf("Limite de alunos atingido!\n");
                    break;
                }
                printf("Digite o nome do aluno: ");
                fgets(lista[quantidade].nome, 50, stdin);
                lista[quantidade].nome[strcspn(lista[quantidade].nome, "\n")] = '\0';

                printf("Digite a nota 1: ");
                scanf("%f", &lista[quantidade].nota1);
                printf("Digite a nota 2: ");
                scanf("%f", &lista[quantidade].nota2);
                printf("Digite a nota 3: ");
                scanf("%f", &lista[quantidade].nota3);
                getchar();
                quantidade++;
                printf("Aluno cadastrado com sucesso!\n");
                break;

            case 2:
                printf("\n=== Lista de Alunos ===\n");
                for(int i = 0; i < quantidade; i++) {
                    printf("Nome: %s - Media: %.2f\n", lista[i].nome, media(lista[i]));
                }
                break;

            case 3: {
                if(quantidade == 0) {
                    printf("Nenhum aluno cadastrado!\n");
                    break;
                }
                // Ordenar por média (decrescente)
                struct aluno temp;
                for(int i = 0; i < quantidade - 1; i++) {
                    for(int j = i + 1; j < quantidade; j++) {
                        if(media(lista[i]) < media(lista[j])) {
                            temp = lista[i];
                            lista[i] = lista[j];
                            lista[j] = temp;
                        }
                    }
                }
                printf("\n=== Alunos Ordenados por Media ===\n");
                for(int i = 0; i < quantidade; i++) {
                    printf("Nome: %s - Media: %.2f\n", lista[i].nome, media(lista[i]));
                }
                break;
            }

            case 4: {
                if(quantidade == 0) {
                    printf("Nenhum aluno cadastrado!\n");
                    break;
                }
                char nomeBusca[50];
                printf("Digite o nome do aluno: ");
                fgets(nomeBusca, 50, stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

                // Ordenar antes de fazer busca binária
                ordenarPorNome(lista, quantidade);

                int indice = buscaBinaria(lista, quantidade, nomeBusca);
                if(indice != -1) {
                    printf("Aluno encontrado: %s - Nota1: %.2f, Nota2: %.2f, Nota3: %.2f, Media: %.2f\n",
                           lista[indice].nome, lista[indice].nota1, lista[indice].nota2, lista[indice].nota3,
                           media(lista[indice]));
                } else {
                    printf("Aluno nao encontrado!\n");
                }
                break;
            }

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}
