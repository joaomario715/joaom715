#include <stdio.h>

int estacionamento()
{

    int opcao;
    int tipo;
    int horas;
    int vagas;
    int carros;
    int motos;
    int confirmacao;
    int encontrado;
    int consulta;

    char placa[20];
    char placaArquivo[20];
    char tipoArquivo[20];

    float valor;
    float faturamento;

    FILE *arquivo;
    FILE *temporario;

    do
    {

        printf("\n===== ESTACIONAMENTO SENAI =====\n");
        printf("1 - Registrar entrada\n");
        printf("2 - Registrar saida\n");
        printf("3 - Consultar situacao\n");
        printf("4 - Exibir faturamento\n");
        printf("5 - Consultar veiculos estacionados\n");
        printf("6 - Consultar historico\n");
        printf("7 - Encerrar sistema\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:

            vagas = 0;

            arquivo = fopen("arquivos/veiculos.txt", "r");

            if (arquivo != NULL)
            {

                while (fscanf(arquivo, "%s %s %d",
                              placaArquivo,
                              tipoArquivo,
                              &horas) == 3)
                {
                    vagas++;
                }

                fclose(arquivo);
            }

            if (vagas >= 20)
            {
                printf("\nESTACIONAMENTO LOTADO.\n");
                break;
            }

            printf("\n===== REGISTRAR ENTRADA =====\n");

            printf("Placa: ");
            scanf("%s", placa);

            printf("Tipo de veiculo:\n");
            printf("1 - Carro\n");
            printf("2 - Moto\n");
            scanf("%d", &tipo);

            if (tipo != 1 && tipo != 2)
            {
                printf("Tipo invalido.\n");
                break;
            }

            printf("Quantidade de horas previstas: ");
            scanf("%d", &horas);

            if (horas <= 0)
            {
                printf("Horas invalidas.\n");
                break;
            }

            arquivo = fopen("arquivos/veiculos.txt", "a");

            if (arquivo == NULL)
            {
                printf("Erro ao abrir arquivo.\n");
                break;
            }

            if (tipo == 1)
                fprintf(arquivo, "%s carro %d\n", placa, horas);
            else
                fprintf(arquivo, "%s moto %d\n", placa, horas);

            fclose(arquivo);

            arquivo = fopen("arquivos/historico.txt", "a");

            if (arquivo != NULL)
            {

                if (tipo == 1)
                    fprintf(arquivo, "ENTRADA - %s - Carro\n", placa);
                else
                    fprintf(arquivo, "ENTRADA - %s - Moto\n", placa);

                fclose(arquivo);
            }

            printf("Entrada registrada!\n");

            break;

        case 2:

            printf("\n===== REGISTRAR SAIDA =====\n");

            printf("Placa: ");
            scanf("%s", placa);

            arquivo = fopen("arquivos/veiculos.txt", "r");

            if (arquivo == NULL)
            {
                printf("Nenhum veiculo estacionado.\n");
                break;
            }

            encontrado = 0;

            while (fscanf(arquivo, "%s %s %d",
                          placaArquivo,
                          tipoArquivo,
                          &horas) == 3)
            {

                int i = 0;
                int igual = 1;

                while (placa[i] != '\0' ||
                       placaArquivo[i] != '\0')
                {

                    if (placa[i] != placaArquivo[i])
                    {
                        igual = 0;
                        break;
                    }

                    i++;
                }

                if (igual == 1)
                {
                    encontrado = 1;
                    break;
                }
            }

            fclose(arquivo);

            if (encontrado == 0)
            {
                printf("Veiculo nao encontrado.\n");
                break;
            }

            printf("Horas que ficou estacionado: ");
            scanf("%d", &horas);

            if (horas <= 0)
            {
                printf("Horas invalidas.\n");
                break;
            }

            if (tipoArquivo[0] == 'c')
                valor = 8 + (horas - 1) * 5;
            else
                valor = 5 + (horas - 1) * 3;

            printf("Valor a pagar: R$ %.2f\n", valor);

            arquivo = fopen("arquivos/veiculos.txt", "r");
            temporario = fopen("arquivos/temporario.txt", "w");

            if (arquivo == NULL || temporario == NULL)
            {
                printf("Erro ao abrir arquivo.\n");

                if (arquivo != NULL)
                    fclose(arquivo);

                if (temporario != NULL)
                    fclose(temporario);

                break;
            }

            while (fscanf(arquivo, "%s %s %d",
                          placaArquivo,
                          tipoArquivo,
                          &horas) == 3)
            {

                int i = 0;
                int igual = 1;

                while (placa[i] != '\0' ||
                       placaArquivo[i] != '\0')
                {

                    if (placa[i] != placaArquivo[i])
                    {
                        igual = 0;
                        break;
                    }

                    i++;
                }

                if (igual == 0)
                {
                    fprintf(temporario, "%s %s %d\n",
                            placaArquivo,
                            tipoArquivo,
                            horas);
                }
            }

            fclose(arquivo);
            fclose(temporario);

            remove("veiculos.txt");
            rename("temporario.txt", "veiculos.txt");

            arquivo = fopen("arquivos/historico.txt", "a");

            if (arquivo != NULL)
            {

                fprintf(arquivo,
                        "SAIDA - %s - %s - R$ %.2f\n",
                        placa,
                        tipoArquivo,
                        valor);

                fclose(arquivo);
            }

            arquivo = fopen("arquivos/caixa.txt", "a");

            if (arquivo != NULL)
            {

                fprintf(arquivo, "%.2f\n", valor);

                fclose(arquivo);
            }

            printf("Saida registrada!\n");

            break;

        case 3:

            printf("\n===== CONSULTAR SITUACAO =====\n");
            printf("1 - Situacao do estacionamento\n");
            printf("2 - Busca por placa\n");
            printf("Escolha: ");
            scanf("%d", &consulta);

            if (consulta == 1)
            {

                vagas = 0;
                carros = 0;
                motos = 0;

                arquivo = fopen("arquivos/veiculos.txt", "r");

                if (arquivo == NULL)
                {
                    printf("Nenhum veiculo estacionado.\n");
                    break;
                }

                while (fscanf(arquivo, "%s %s %d",
                              placaArquivo,
                              tipoArquivo,
                              &horas) == 3)
                {

                    vagas++;

                    if (tipoArquivo[0] == 'c')
                        carros++;
                    else
                        motos++;
                }

                fclose(arquivo);

                printf("\n===== SITUACAO =====\n");
                printf("Vagas totais: 20\n");
                printf("Vagas ocupadas: %d\n", vagas);
                printf("Vagas disponiveis: %d\n", 20 - vagas);
                printf("Carros: %d\n", carros);
                printf("Motos: %d\n", motos);
                printf("Taxa de ocupacao: %.0f%%\n",
                       vagas * 100.0 / 20);
            }

            else if (consulta == 2)
            {

                printf("\n===== BUSCA POR PLACA =====\n");
                printf("Digite a placa: ");
                scanf("%s", placa);

                arquivo = fopen("arquivos/veiculos.txt", "r");

                if (arquivo == NULL)
                {
                    printf("Nenhum veiculo encontrado.\n");
                    break;
                }

                encontrado = 0;

                while (fscanf(arquivo, "%s %s %d",
                              placaArquivo,
                              tipoArquivo,
                              &horas) == 3)
                {

                    int i = 0;
                    int igual = 1;

                    while (placa[i] != '\0' ||
                           placaArquivo[i] != '\0')
                    {

                        if (placa[i] != placaArquivo[i])
                        {
                            igual = 0;
                            break;
                        }

                        i++;
                    }

                    if (igual == 1)
                    {

                        encontrado = 1;

                        printf("\nVEICULO ENCONTRADO\n");
                        printf("Placa: %s\n", placaArquivo);

                        if (tipoArquivo[0] == 'c')
                            printf("Tipo: Carro\n");
                        else
                            printf("Tipo: Moto\n");

                        printf("Horas previstas: %d\n", horas);

                        break;
                    }
                }

                fclose(arquivo);

                if (encontrado == 0)
                    printf("VEICULO NAO ENCONTRADO.\n");
            }

            else
            {
                printf("Opcao invalida.\n");
            }

            break;

        case 4:

            faturamento = 0;

            arquivo = fopen("arquivos/caixa.txt", "r");

            if (arquivo == NULL)
            {
                printf("Faturamento total: R$ 0.00\n");
                break;
            }

            while (fscanf(arquivo, "%f", &valor) == 1)
                faturamento += valor;

            fclose(arquivo);

            printf("\n===== CAIXA =====\n");
            printf("Faturamento total: R$ %.2f\n",
                   faturamento);

            break;

        case 5:

            arquivo = fopen("arquivos/veiculos.txt", "r");

            if (arquivo == NULL)
            {
                printf("Nenhum veiculo estacionado.\n");
                break;
            }

            printf("\n===== VEICULOS ESTACIONADOS =====\n");

            while (fscanf(arquivo, "%s %s %d",
                          placaArquivo,
                          tipoArquivo,
                          &horas) == 3)
            {

                printf("Placa: %s\n", placaArquivo);

                if (tipoArquivo[0] == 'c')
                    printf("Tipo: Carro\n");
                else
                    printf("Tipo: Moto\n");

                printf("Horas: %d\n\n", horas);
            }

            fclose(arquivo);

            break;

        case 6:

            arquivo = fopen("arquivos/historico.txt", "r");

            if (arquivo == NULL)
            {
                printf("Nenhum historico encontrado.\n");
                break;
            }

            printf("\n===== HISTORICO =====\n");

            while (fscanf(arquivo, " %[^\n]",
                          placaArquivo) == 1)
            {

                printf("%s\n", placaArquivo);
            }

            fclose(arquivo);

            break;

        case 7:

            printf("\nDeseja realmente encerrar?\n");
            printf("1 - Sim\n");
            printf("2 - Nao\n");
            scanf("%d", &confirmacao);

            if (confirmacao == 1)
            {
                printf("Sistema encerrado!\n");
            }
            else
            {
                opcao = 0;
            }

            break;

        default:

            printf("Opcao invalida!\n");
        }

    } while (opcao != 7);

    return 0;
}