
#include <stdio.h>
#include "boletim.c"
#include "calculadora.c"
#include "banco.c"
#include "estacionamento.c"
int main () {
  int opcao;

  do{
  printf("\n========MENU========\n");
  printf("1 - boletim\n");
  printf("2 - calculadora\n");
  printf("3 - banco\n");
  printf("4 - estacionamento\n");
  printf("0 - SAIR\n");
  printf("Escolha a opção que deseja executar: ");
  scanf("%d", &opcao);

  switch(opcao){
    case 1:
      boletim();
      break;

    case 2:
      calculadora();
      break;

    case 3: 
      banco();
      break;
    
    case 4:
      estacionamento();
      break;
    
    case 0:
      printf("programa encerrado!");

  }
    
  } while (opcao != 0);

  return 0;
 
}