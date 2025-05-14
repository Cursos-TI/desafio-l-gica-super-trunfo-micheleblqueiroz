#include <stdio.h>
#include <string.h>

int main() {
    // Definição das variáveis para duas cartas (cidades)
    char codigoA[10], codigoB[10];
    char nomeA[50], nomeB[50];
    int populacaoA, populacaoB;
    float areaA, areaB;
    float pibA, pibB;
    float idhA, idhB;
    
    // Cadastro da Carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o código da cidade: ");
    scanf("%s", codigoA);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeA);
    printf("Digite a população (milhares): ");
    scanf("%d", &populacaoA);
    printf("Digite a área (km²): ");
    scanf("%f", &areaA);
    printf("Digite o PIB (bilhões): ");
    scanf("%f", &pibA);
    printf("Digite o IDH (0-1): ");
    scanf("%f", &idhA);
    
    // Cadastro da Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o código da cidade: ");
    scanf("%s", codigoB);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeB);
    printf("Digite a população (milhares): ");
    scanf("%d", &populacaoB);
    printf("Digite a área (km²): ");
    scanf("%f", &areaB);
    printf("Digite o PIB (bilhões): ");
    scanf("%f", &pibB);
    printf("Digite o IDH (0-1): ");
    scanf("%f", &idhB);
    
    // Comparação de Cartas
    printf("\n=== Resultados da Comparação ===\n");
    int pontosA = 0, pontosB = 0;
    
    // Comparação de População
    if (populacaoA > populacaoB) {
        printf("%s tem maior população!\n", nomeA);
        pontosA++;
    } else if (populacaoB > populacaoA) {
        printf("%s tem maior população!\n", nomeB);
        pontosB++;
    } else {
        printf("Empate na população!\n");
    }
    
    // Comparação de Área
    if (areaA > areaB) {
        printf("%s tem maior área!\n", nomeA);
        pontosA++;
    } else if (areaB > areaA) {
        printf("%s tem maior área!\n", nomeB);
        pontosB++;
    } else {
        printf("Empate na área!\n");
    }
    
    // Comparação de PIB
    if (pibA > pibB) {
        printf("%s tem maior PIB!\n", nomeA);
        pontosA++;
    } else if (pibB > pibA) {
        printf("%s tem maior PIB!\n", nomeB);
        pontosB++;
    } else {
        printf("Empate no PIB!\n");
    }
    
    // Comparação de IDH
    if (idhA > idhB) {
        printf("%s tem maior IDH!\n", nomeA);
        pontosA++;
    } else if (idhB > idhA) {
        printf("%s tem maior IDH!\n", nomeB);
        pontosB++;
    } else {
        printf("Empate no IDH!\n");
    }
    
    // Exibição do Resultado Final
    printf("\n=== Resultado Final ===\n");
    printf("Pontos %s: %d\n", nomeA, pontosA);
    printf("Pontos %s: %d\n", nomeB, pontosB);
    
    if (pontosA > pontosB) {
        printf("A cidade vencedora é: %s!\n", nomeA);
    } else if (pontosB > pontosA) {
        printf("A cidade vencedora é: %s!\n", nomeB);
    } else {
        printf("Empate entre as cidades!\n");
    }
    
    return 0;
}

