#include <stdio.h>

    int calculadora(){
    float num1;
    float num2;
    float resultado;
    char operador;
    int codigo;
    
    printf("\n========CALCULADORA========\n");

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);
    printf("Operador(+ - * /): ");
    scanf(" %c", &operador);
    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    switch(operador){
        case '+':
            resultado = num1 + num2;
            break;
        
        case '-':
            resultado = num1 - num2;
            break;
        
        case '*':
            resultado = num1 * num2;
            break;
        
        case '/': 
            if (num2 == 0){
                return 200;
            }
            resultado = num1 / num2;
            break;
            
            default:
                return 202;
                
    }
            
            printf("Resultado: %.2f\n", resultado);
                 
            return  0;
    }
    
    
        







