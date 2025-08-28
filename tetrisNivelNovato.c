// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.

// 🧩 Nível Novato: Fila de Peças Futuras

#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX 5 // Tamanho máximo da fila

// Definição dos tipos de peças
typedef enum { I, O, T, L } TipoPeca;

// Estrutura para representar uma peça
typedef struct {
    TipoPeca tipo;
    int id;
} Peca;

// Estrutura da fila circular   
typedef struct {
    Peca itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

int contador_id = 0;

// Inicializa a fila com valores padrão
void inicializaFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;      // Início e fim começam no mesmo ponto
    f->total = 0;
}

// Verifica se a fila está vazia
int filaVazia(Fila *f) {
    return f->total == 0;
}

// Verifica se a fila está cheia
int filaCheia(Fila *f) {
    return f->total == MAX;
}

// Gera uma nova peça aleatória
Peca gerarPeca() {
    return (Peca){ .tipo = rand() % 4, .id = contador_id++ };
}

// Insere uma peça na fila
int inserir(Fila *f, Peca p) {
    if (filaCheia(f)) return 0;
    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
    return 1;
}

// Remove uma peça da fila
int remover(Fila *f, Peca *removida) {
    if (filaVazia(f)) return 0;
    *removida = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
    return 1;
}

// Converte enum para caractere
char tipoParaChar(TipoPeca tipo) {
    const char nomes[] = { 'I', 'O', 'T', 'L' };
    return nomes[tipo];
}

// Mostra a fila
void mostrarFila(Fila *f) {
    printf("\nFila de peças:\n");
    if (filaVazia(f)) {
        printf("[Vazia]\n");
        return;
    }
    for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % MAX) {
        printf("[%c %d] ", tipoParaChar(f->itens[idx].tipo), f->itens[idx].id);
    }
    printf("\n");
}

// Mostra o menu
void mostrarMenu() {
    printf("\n****** Opções ******\n");
    printf("1 - Jogar peça\n");
    printf("2 - Inserir nova peça\n");
    printf("0 - Sair\n");
    printf("***********************\n");
    printf("\n=> Escolha: ");
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    Fila fila;
    int opcao;
    Peca p;

// Inicializa o gerador de números aleatórios
srand((unsigned int) time(NULL));

// Inicializa a fila
inicializaFila(&fila);

// Preenche a fila inicialmente
    for (int i = 0; i < MAX; i++) {
        inserir(&fila, gerarPeca());
    }

    do {
        mostrarFila(&fila);
        mostrarMenu();
        if (scanf("%d", &opcao) != 1) break;

        switch (opcao) {
            case 1:
                if (remover(&fila, &p))
                    printf("\n=> Peça jogada: [%c %d]\n", tipoParaChar(p.tipo), p.id);
                else
                    printf("--- Fila vazia.---\n");
                break;

            case 2:
                p = gerarPeca();
                if (inserir(&fila, p))
                    printf("\n=> Peça inserida: [%c %d]\n", tipoParaChar(p.tipo), p.id);
                else
                    printf("+++ Fila cheia. +++\n");
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}





    // 🧠 Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).


    // 🔄 Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha

