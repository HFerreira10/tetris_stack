#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    char nome;
    int id; 
} Peca;

#define CAPACIDADE 5
Peca fila[CAPACIDADE];
int frente = 0; 
int traseira = -1;
int tamanho = 0;
int proximo_id = 1;

bool filaVazia() {
    return tamanho == 0;
}

bool filaCheia() {
    return tamanho == CAPACIDADE;
}

Peca gerarPeca() {
    Peca nova_peca;
    char tipos[] = {'I', 'O', 'T', 'L', 'S', 'Z', 'J'};
    int num_tipos = sizeof(tipos) / sizeof(tipos[0]);

    int indice_tipo = rand() % num_tipos;
    nova_peca.nome = tipos[indice_tipo];
    
    nova_peca.id = proximo_id++;
    
    return nova_peca;
}

void inserirPeca() {
    if (filaCheia()) {
        printf("\n **A T E N Ç Ã O:** A fila de peças está CHEIA! Não é possível adicionar mais peças.\n");
        return;
    }

    Peca nova_peca = gerarPeca();
    
    traseira = (traseira + 1) % CAPACIDADE; 
    fila[traseira] = nova_peca;
    tamanho++;

    printf("\n Peça '%c' (ID: %d) ADICIONADA ao final da fila.\n", nova_peca.nome, nova_peca.id);
}

void jogarPeca() {
    if (filaVazia()) {
        printf("\n **A T E N Ç Ã O:** A fila de peças está VAZIA! Não há peças para jogar.\n");
        return;
    }

    Peca peca_jogada = fila[frente];
    
    frente = (frente + 1) % CAPACIDADE;
    tamanho--;

    printf("\n▶ Peça '%c' (ID: %d) JOGADA (REMOVIDA) da frente da fila.\n", peca_jogada.nome, peca_jogada.id);
}

void exibirFila() {
    printf("\n--- Fila de Peças Futuras (Tamanho: %d/%d) ---\n", tamanho, CAPACIDADE);

    if (filaVazia()) {
        printf("A fila está VAZIA.\n");
        return;
    }

    printf("FRENTE -> ");

    int i = frente;
    for (int count = 0; count < tamanho; count++) {
        printf("| %c (ID: %d) |", fila[i].nome, fila[i].id);
        i = (i + 1) % CAPACIDADE;
    }
    
    printf(" <- TRASEIRA\n");
    printf("--------------------------------------------------\n");
}

void inicializarFila() {
    printf("🛠️ Inicializando a fila de peças com %d elementos...\n", CAPACIDADE);
    srand(time(NULL)); 
    for (int i = 0; i < CAPACIDADE; i++) {
        inserirPeca();
    }
    printf("\n");
}

int main() {
    inicializarFila();
    exibirFila();

    int escolha;

    do {
        printf("\n==================================\n");
        printf("--- Menu Tetris ---\n");
        printf("1. Jogar Peça \n");
        printf("2. Inserir nova peça \n");
        printf("3. Visualizar Fila\n");
        printf("0. Sair\n");
        printf("==================================\n");
        printf("Escolha uma opção: ");
        
        if (scanf("%d", &escolha) != 1) {            
            while (getchar() != '\n');
            escolha = -1;
        }
        
        switch (escolha) {
            case 1:
                jogarPeca();
                exibirFila();
                break;
            case 2:
                inserirPeca();
                exibirFila();
                break;
            case 3:
                exibirFila();
                break;
            case 0:
                printf("\n Saindo do programa.\n");
                break;
            default:
                printf("\n Opção inválida. Tente novamente.\n");
                break;
        }
    } while (escolha != 0);

    return 0;
}