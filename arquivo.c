#include <stdio.h>

int arquivos(){
    char nome;
    int idade, totalAlunos;
    float altura;

    FILE *arquivo;
    arquivo = fopen ("arquivo/cadastros.txt", "a");

    while(
        fscanf(
            arquivo,
            "nome: %49s | idade: %d | altura: %f", nome, &idade, &altura) == 3

        ) {

            totalAlunos++;

            printf("\nAluno %d\n", totalAlunos);

            printf("nome: %s\n", nome);
            printf("idade: %d\n", idade);
            printf("altura: %.2f\n", altura);
        }

        fclose(arquivo);
    


}