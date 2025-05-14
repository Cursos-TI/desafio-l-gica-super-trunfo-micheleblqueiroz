#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_CARTAS 3
#define MAX_NOME 30

typedef struct {
    char nome[MAX_NOME];
    int pib;          // Produto Interno Bruto (em trilhões de USD)
    int populacao;    // População (em milhões)
    int area;         // Área (em km²)
    int densidade;    // Densidade demográfica (hab/km²)
} Carta;

// Inicialização das cartas com dados de exemplo
Carta cartas[NUM_CARTAS] = {
    {"Brasil", 2055, 211, 8515770, 24},
    {"Alemanha", 3845, 83, 357022, 233},
    {"Japão", 4872, 125, 377975, 330}
};

// Limpa o buffer de entrada
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Exibe o menu principal
void exibir_menu_principal() {
    printf("\n=== Jogo de Comparação de Cartas ===\n");
    printf("1. Jogar\n");
    printf("2. Exibir todas as cartas\n");
    printf("3. Sair\n");
    printf("============================\n");
}

// Exibe o menu de atributos disponíveis
void exibir_menu_atributos() {
    printf("\nAtributos disponíveis:\n");
    printf("1. PIB\n");
    printf("2. População\n");
    printf("3. Área\n");
    printf("4. Densidade demográfica\n");
}

// Exibe o menu de cartas disponíveis
void exibir_menu_cartas() {
    printf("\nCartas disponíveis:\n");
    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("%d. %s\n", i + 1, cartas[i].nome);
    }
}

// Obtém uma escolha válida do usuário
int obter_escolha_valida(int max_opcoes, const char* mensagem, int carta_anterior) {
    int escolha;
    char input[100];
    do {
        printf("%s", mensagem);
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Erro de entrada! Tente novamente.\n");
            continue;
        }
        if (sscanf(input, "%d", &escolha) != 1) {
            printf("Entrada inválida! Digite um número.\n");
            continue;
        }
        if (escolha < 1 || escolha > max_opcoes) {
            printf("Escolha inválida! Escolha entre 1 e %d.\n", max_opcoes);
        } else if (carta_anterior != -1 && escolha - 1 == carta_anterior) {
            printf("Você não pode escolher a mesma carta! Tente novamente.\n");
        }
    } while (escolha < 1 || escolha > max_opcoes || (carta_anterior != -1 && escolha - 1 == carta_anterior));
    return escolha;
}

// Compara duas cartas com base em um atributo específico usando operador ternário
int comparar_atributo(Carta carta1, Carta carta2, int atributo) {
    int valor1, valor2;
    switch (atributo) {
        case 1: valor1 = carta1.pib; valor2 = carta2.pib; break;
        case 2: valor1 = carta1.populacao; valor2 = carta2.populacao; break;
        case 3: valor1 = carta1.area; valor2 = carta2.area; break;
        case 4: valor1 = carta1.densidade; valor2 = carta2.densidade; break;
        default: return 0;
    }
    return valor1 > valor2 ? 1 : (valor1 < valor2 ? -1 : 0);
}

// Obtém o nome do atributo para exibição
const char* obter_nome_atributo(int atributo) {
    return atributo == 1 ? "PIB" :
           atributo == 2 ? "População" :
           atributo == 3 ? "Área" :
           atributo == 4 ? "Densidade demográfica" : "Desconhecido";
}

// Exibe os detalhes de uma carta
void exibir_carta(Carta carta) {
    printf("Nome: %s\n", carta.nome);
    printf("PIB: %d trilhões USD\n", carta.pib);
    printf("População: %d milhões\n", carta.populacao);
    printf("Área: %d km²\n", carta.area);
    printf("Densidade: %d hab/km²\n", carta.densidade);
}

// Exibe todas as cartas
void exibir_todas_cartas() {
    printf("\n=== Todas as Cartas ===\n");
    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("\nCarta %d:\n", i + 1);
        exibir_carta(cartas[i]);
    }
    printf("=====================\n");
}

int main() {
    int carta1_idx, carta2_idx, atributo1, atributo2;
    int resultado1, resultado2;
    
    while (1) {
        exibir_menu_principal();
        int opcao = obter_escolha_valida(3, "Escolha uma opção (1-3): ", -1);
        
        if (opcao == 3) {
            printf("Obrigado por jogar! Até a próxima!\n");
            break;
        }
        
        if (opcao == 2) {
            exibir_todas_cartas();
            continue;
        }

        // Seleção das cartas
        exibir_menu_cartas();
        carta1_idx = obter_escolha_valida(NUM_CARTAS, "Escolha a primeira carta (1-3): ", -1) - 1;
        carta2_idx = obter_escolha_valida(NUM_CARTAS, "Escolha a segunda carta (1-3): ", carta1_idx) - 1;

        // Exibe as cartas escolhidas
        printf("\n=== Carta 1 ===\n");
        exibir_carta(cartas[carta1_idx]);
        printf("\n=== Carta 2 ===\n");
        exibir_carta(cartas[carta2_idx]);

        // Seleção dos atributos
        exibir_menu_atributos();
        atributo1 = obter_escolha_valida(4, "Escolha o primeiro atributo (1-4): ", -1);
        atributo2 = obter_escolha_valida(4, "Escolha o segundo atributo (1-4): ", -1);

        // Realiza as comparações
        resultado1 = comparar_atributo(cartas[carta1_idx], cartas[carta2_idx], atributo1);
        resultado2 = comparar_atributo(cartas[carta1_idx], cartas[carta2_idx], atributo2);

        // Exibe os resultados
        printf("\n=== Resultados da Comparação ===\n");
        printf("Atributo 1 (%s):\n", obter_nome_atributo(atributo1));
        printf("%s\n", resultado1 == 1 ? cartas[carta1_idx].nome : 
                       resultado1 == -1 ? cartas[carta2_idx].nome : "Empate");

        printf("Atributo 2 (%s):\n", obter_nome_atributo(atributo2));
        printf("%s\n", resultado2 == 1 ? cartas[carta1_idx].nome : 
                       resultado2 == -1 ? cartas[carta2_idx].nome : "Empate");

        // Determina o vencedor geral usando operador ternário
        printf("\n=== Resultado Final ===\n");
        const char* vencedor = (resultado1 == 1 && resultado2 == 1) ? cartas[carta1_idx].nome :
                              (resultado1 == -1 && resultado2 == -1) ? cartas[carta2_idx].nome :
                              "Nenhum (empate ou resultados mistos)";
        printf("Vencedor geral: %s\n", vencedor);
        printf("============================\n");
    }

    return 0;
}