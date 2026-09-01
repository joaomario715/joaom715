
#include <stdio.h>

void boletim () {
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float nota5;
    float media;
    char nome[50];

    printf("\n========BOLETIM========\n");
    
    printf("Digite o nome do aluno: ");
    scanf("%s", nome);

    printf("Digite as notas do aluno:\n ");
    scanf("%f %f %f %f %f", &nota1, &nota2, &nota3, &nota4, &nota5);

    media = (nota1 + nota2 + nota3 + nota4 + nota5) / 5;

    printf("Nome do aluno: %s\n", nome);
    printf("As notas do aluno foram: %.1f | %.1f | %.1f | %.1f | %.1f \n", nota1, nota2, nota3, nota4, nota5);
    printf("A media do aluno é: %.1f\n ", media);

    if (media >= 7){
    printf("APROVADO");
    }
    else if (media >= 5 && media < 7){
        printf("RECUPERAÇÃO");
    }
    else {
        printf("REPROVADO");
    }

    
}
    

    



