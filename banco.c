#include <stdio.h>

int banco(){

    int opcao, meses, i, operacao = 0;
    float saldo = 1000, valor, rendimento, ganho, simulacao;

    do{
        printf("\n========BANCO========\n");
        printf("1 - Consultar Saldo\n");
        printf("2 - Depositar\n");
        printf("3 - Sacar\n");
        printf("4 - Rendimento mensal\n");
        printf("0 - SAIR\n");
        printf("Escolha uma das opções: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("Saldo: R$ %.2f", saldo);
                operacao++;
                break;
                
            case 2: 
                printf("Valor do depósito: R$ ");
                scanf("%f", &valor);
                saldo = saldo + valor;
                printf("Depósito realizado!\n");
                printf("Saldo atualizado: R$ %.2f", saldo);
                operacao ++;
                break;
            
            case 3: 
                printf("Valor do saque: R$ ");
                scanf("%f", &valor);
                saldo = saldo - valor;
                printf("Saque realizado!\n");
                printf("Saldo atualizado: R$ %.2f", saldo);
                operacao ++;
                break;
            
            case 4:
                printf("Valor para simulação de rendimento mensal: R$ ");
                scanf("%f", &simulacao);
                printf("Numero de meses: ");
                scanf("%d", &meses);
                printf("Rendimento mensal(%%): ");
                scanf ("%f", &rendimento);
                rendimento = rendimento / 100;

                printf("\n=====SIMULAÇÃO DE RENDIMENTO MENSAL=====\n");

                for (int i = 1; i <= meses; i++){
                   ganho = simulacao * rendimento;
                   simulacao = simulacao + ganho;
                
                    printf("\nMes %d", i);
                    printf("\nRendimento: R$ %.2f", ganho);
                    printf("\nSaldo final: R$ %.2f\n", simulacao);
                }
                    printf("\nSaldo total após o rendimento: %.2f", simulacao);
                    operacao ++;
                    break;

            case 0:
                printf("\nTotal de operações realizadas: %d\n", operacao);
                printf("Programa encerrado!\n");
                break;

                default:
                    printf("Opção inválida!");       
        }    
    }
     while (opcao != 0);

        return 0;
}