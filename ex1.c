#include <stdio.h>
#include <stdlib.h>
int x[10], n, i, aux, flag;

int main() {
    for(i = 0; i<10; i++){
      printf("Digite: ");
      scanf("%d", &x[i]);
      }
  
      n = 1;
      flag = 1;
  
      while(n <=10 && flag == 1){
        flag = 0;
        for(i = 0; i<9; i++){
           if(x[i] < x[i+1]){
         
             flag = 1;
             aux = x[i];
             x[i] = x[i+1];
             x[i+1] = aux;    
        }
      }
        n = n +1;
    }
   for(i = 0; i<10; i++){
     printf("\nDados: %d", x[i]);
  }
}
