#include <stdio.h>

int main() {
    char Estado, Estado1, CodCidade[10], CodCidade1[10], nome[50], nome1[50];
    int populacao, populacao1, PT, PT1;
    float Area, Area1, PIB, PIB1;

    printf("Bem-vindo ao menu inicial do jogo SuperTrunfo - Estados \n");
    printf("1. Jogar\n");
    printf("2. Sair\n");
    printf("Escolha uma opção: ");
    int options;
    scanf("%d", &options);

    switch (options) {
        case 1:
            printf("Iniciando o Jogo...\n");

            // Cadastro da primeira carta
            printf("Registro da Primeira Carta:\n");
            printf("Estado (A-H): ");
            scanf(" %c", &Estado);
            printf("Código da Cidade (01 a 04): ");
            scanf("%s", CodCidade);
            printf("Nome da cidade: ");
            scanf("%s", nome);
            printf("População: ");
            scanf("%d", &populacao);
            printf("Área (km²): ");
            scanf("%f", &Area);
            printf("PIB: ");
            scanf("%f", &PIB);
            printf("Pontos Turísticos: ");
            scanf("%d", &PT);

            // Cadastro da segunda carta
            printf("\nRegistro da Segunda Carta:\n");
            printf("Estado (A-H): ");
            scanf(" %c", &Estado1);
            printf("Código da Cidade (01 a 04): ");
            scanf("%s", CodCidade1);
            printf("Nome da cidade: ");
            scanf("%s", nome1);
            printf("População: ");
            scanf("%d", &populacao1);
            printf("Área (km²): ");
            scanf("%f", &Area1);
            printf("PIB: ");
            scanf("%f", &PIB1);
            printf("Pontos Turísticos: ");
            scanf("%d", &PT1);

            float DensiPop = populacao / Area;
            float PIBperC = PIB / populacao;
            float DensiPop1 = populacao1 / Area1;
            float PIBperC1 = PIB1 / populacao1;

            int atributo1, atributo2;

            // Escolha do primeiro atributo
            printf("\nEscolha o PRIMEIRO atributo para a comparação:\n");
            printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capita\n");
            scanf("%d", &atributo1);

            // Menu dinâmico
            printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");

            switch (atributo1) {
                case 1:
                    printf("2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capita\n");
                    scanf("%d", &atributo2);
                    if (atributo2 == 1) atributo2 = 0;
                    break;
                case 2:
                    printf("1. População\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capita\n");
                    scanf("%d", &atributo2);
                    if (atributo2 == 2) atributo2 = 0;
                    break;
                case 3:
                    printf("1. População\n2. Área\n4. Pontos Turísticos\n5. Densidade Populacional\n6. PIB per Capita\n");
                    scanf("%d", &atributo2);
                    if (atributo2 == 3) atributo2 = 0;
                    break;
                case 4:
                    printf("1. População\n2. Área\n3. PIB\n5. Densidade Populacional\n6. PIB per Capita\n");
                    scanf("%d", &atributo2);
                    if (atributo2 == 4) atributo2 = 0;
                    break;
                case 5:
                    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n6. PIB per Capita\n");
                    scanf("%d", &atributo2);
                    if (atributo2 == 5) atributo2 = 0;
                    break;
                case 6:
                    printf("1. População\n2. Área\n3. PIB\n4. Pontos Turísticos\n5. Densidade Populacional\n");
                    scanf("%d", &atributo2);
                    if (atributo2 == 6) atributo2 = 0;
                    break;
                default:
                    atributo2 = 0;
            }

            if (atributo2 == 0) {
                printf("Erro: você escolheu o mesmo atributo duas vezes ou uma opção inválida!\n");
                return 1;
            }

            float valor1_c1 = 0, valor2_c1 = 0, valor1_c2 = 0, valor2_c2 = 0;

            // Atribuição dos valores de acordo com atributos escolhidos
            switch (atributo1) {
                case 1: valor1_c1 = populacao; valor1_c2 = populacao1; break;
                case 2: valor1_c1 = Area; valor1_c2 = Area1; break;
                case 3: valor1_c1 = PIB; valor1_c2 = PIB1; break;
                case 4: valor1_c1 = PT; valor1_c2 = PT1; break;
                case 5: valor1_c1 = DensiPop; valor1_c2 = DensiPop1; break;
                case 6: valor1_c1 = PIBperC; valor1_c2 = PIBperC1; break;
            }
            switch (atributo2) {
                case 1: valor2_c1 = populacao; valor2_c2 = populacao1; break;
                case 2: valor2_c1 = Area; valor2_c2 = Area1; break;
                case 3: valor2_c1 = PIB; valor2_c2 = PIB1; break;
                case 4: valor2_c1 = PT; valor2_c2 = PT1; break;
                case 5: valor2_c1 = DensiPop; valor2_c2 = DensiPop1; break;
                case 6: valor2_c1 = PIBperC; valor2_c2 = PIBperC1; break;
            }

            int pontos1 = 0, pontos2 = 0;

            // Comparação com regras (densidade = menor vence)
            if (atributo1 == 5) {
                if (valor1_c1 < valor1_c2) pontos1++;
                else if (valor1_c2 < valor1_c1) pontos2++;
            } else {
                if (valor1_c1 > valor1_c2) pontos1++;
                else if (valor1_c2 > valor1_c1) pontos2++;
            }

            if (atributo2 == 5) {
                if (valor2_c1 < valor2_c2) pontos1++;
                else if (valor2_c2 < valor2_c1) pontos2++;
            } else {
                if (valor2_c1 > valor2_c2) pontos1++;
                else if (valor2_c2 > valor2_c1) pontos2++;
            }

            float soma1 = valor1_c1 + valor2_c1;
            float soma2 = valor1_c2 + valor2_c2;

            // Exibição do Resultado
            printf("\n==== Resultado ====\n");
            printf("Cidade 1: %s\n", nome);
            printf("Cidade 2: %s\n", nome1);
            printf("Atributo 1 (Código %d): %.2f vs %.2f\n", atributo1, valor1_c1, valor1_c2);
            printf("Atributo 2 (Código %d): %.2f vs %.2f\n", atributo2, valor2_c1, valor2_c2);
            printf("Soma dos atributos: %.2f vs %.2f\n", soma1, soma2);

            if (soma1 > soma2)
                printf("Vencedora: %s\n", nome);
            else if (soma2 > soma1)
                printf("Vencedora: %s\n", nome1);
            else
                printf("Empate!\n");

            break;

        case 2:
            printf("Saindo do Programa...\n");
            break;

        default:
            printf("Opção inválida.\n");
            break;
    }

    return 0;
}
