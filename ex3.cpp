#include <stdio.h>
#include <stdlib.h>
int vet[5], n, x, aux, cont;
int s[5];
int tam = sizeof(x) / sizeof(int);
int f[], i, j, eleito, pos, menor;
int qtde;
int p[10], i;
int l[10], i;
//-----------------------------------------------------
void entrada(int *vet, int n) {
  for (int i = 0; i < n; i++) {
    printf("Digite um numero: ");
    scanf("%d", &(*(vet + i)));
  }
}

void imprimir(int *vet, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", *(vet + 1));
  }
}

void insertion_sort(int *vet, int n) {
  int i, j, eleito;
  for (i = 1; i < 5; i++) {
    eleito = *(vet + i);
    j = i - 1;


    while (j >= 0 && *(vet + j) > eleito) {
      *(vet + j + 1) = *(vet + j);
      j = j - 1;
    }
    *(vet + j + 1) = eleito;
  }
}
//-------------------------------------------------
//heapsort-

int g[11];

void imprime() {
  int i;
  for (i = 1; i < 11; i++) {
    printf("%d", g[i]);
  }
}

void troca(int i, int j) {
  int aux;
  aux = g[i];
  g[i] = g[j];
  g[j] = aux;
}

void fila_prioridade(int i, int qtde) {
  int f_esq, f_dir, maio, aux;
  maio = i;
  if (2 * i * 1 <= qtde) {
    f_esq = 2 * i + 1;
    f_dir = 2 * i;
    if (g[f_esq] >= g[f_dir] && g[f_esq] > g[i]) {
      maio = 2 * i + 1;
    } else if (g[f_dir] > g[f_esq] && g[f_dir] > g[i]) {
      maio = 2*i;
    } else if (2 * i <= qtde) {
      f_dir = 2 * i;
    }
  }
  if (maio != i) {
    troca(i, maio);
    fila_prioridade(maio, qtde);
  }
}

void transforma_heap(int qtde) {
  int i, ultima_pos, aux;
  for (i = qtde; i >= 2; i--) {
    troca(1, i);
    ultima_pos = i - 1;
    fila_prioridade(1, ultima_pos);
  }
  }
//-----------------------------------------------

//merge

void intercala(int x[], int inicio, int fim, int meio) {

  int poslivre, inicio_Vetor1, inicio_Vetor2, i;
  int aux[10];
  inicio_Vetor1 = inicio;
  inicio_Vetor2 = meio + 1;
  poslivre = inicio;

  while (inicio_Vetor1 <= meio && inicio_Vetor2 <= fim) {
    if (p[inicio_Vetor1] <= p[inicio_Vetor2]) {
      aux[poslivre] = x[inicio_Vetor1];
      inicio_Vetor1 = inicio_Vetor1 + 1;
    } else {
      aux[poslivre] = p[inicio_Vetor2];
      inicio_Vetor2 = inicio_Vetor2 + 1;
    }
    poslivre++;
  }
  for (i = inicio_Vetor1; i <= meio; i++) {
    aux[poslivre] = p[i];
    poslivre++;
  }
  for (i = inicio_Vetor2; i <= fim; i++) {
    aux[poslivre] = p[i];
    poslivre++;
  }
  for (i = inicio; i <= fim; i++) {
    p[i] = aux[i];
  }
}


void merge(int x[], int inicio, int fim) {
  int meio;
  if (inicio < fim) {
    meio = (inicio + fim);
    merge(x, inicio, meio);
    merge(x, meio + 1, fim);
    intercala(x, inicio, fim, meio);
  }
}
//--------------------------------------------

void trocar(int *x, int i, int j) {
  int aux;
  aux = l[i];
  l[i] = l[j];
  l[j] = aux;
}
int particao(int *x, int p, int r) {
  int pivo, i, j;
  i = p - 1;
  j = r + 1;
  while (i < j) {
    do {
      j--;
    } while (l[j] > pivo);
    do {
      i++;
    } while (l[i] < pivo);
    if (i < j)
      trocar(x, i, j);
  }
  return j;
}

void quicksort(int *x, int p, int r) {
  int q;
  if (p < r) {
    q = particao(x, p, r);
    quicksort(x, p, r);
    quicksort(x, q + 1, r);
  }
}
//---------------------------------------
int main(void) {
  int opcao;

  printf("\n1 - Bubble sort");
  printf("\n2 - Insertion sort");
  printf("\n3 - Selection sort");
  printf("\n4 - Heap sort");
  printf("\n5 - Merge sort");
  printf("\n6 - Quick sort");
  printf(" - ");
  printf("\ndigite uma das opcoes: ");
  scanf("%d", &opcao);

  switch (opcao) {

  case 1:
    for(x=0; x<5; x++){
    printf("\ndigite um numero: ");
    scanf("%d", &vet[x]);
  }
  for(n=1; n<=5; n++){
    for(x = 0; x<=3; x++){
      if(vet[x] > vet[x+1]){
        aux = vet[x];
        vet[x] = vet[x+1];
        vet[x+1] = aux;
        cont +=1;
      }
    }
  }

  for(x=0; x<5; x++){
    printf("\nNumero: %d", vet[x]);
  }
  printf("\nNumero de comparações: %d", cont);
    break;
    
  case 2:

  entrada(s, tam);
  imprimir(s, tam);
  insertion_sort(s, tam);
  imprimir(s, tam);
    
    break;

  case 3:

  for (i = 0; i < 5; i++) {
    printf("digite o %d numero: ", i + 1);
    scanf("%d", &f[i]);
  }

  for (i = 0; i < 4; i++) {
    eleito = f[i];
    menor = f[i + 1];
    pos = j;
    for (j = i + 2; j < 5; j++) {
      if (f[j] < menor) {
        menor = f[j];
        pos = j;
      }
    }
    if (menor < eleito) {
      f[i] = f[pos];
      f[pos] = eleito;
    }
  }
  for (i = 0; i < 5; i++) {
    printf("%d", f[i]);
  } 
    break;

  case 4:

  for (i = 1; i <= 10; i++) {
    printf("digite o %d numero: ", i);
    scanf("%d", &g[i]);
  }
  qtde = 10;
  transforma_heap(qtde);
 // heapsort(qtde);
  imprime();
    break;

  case 5:

    for (i = 0; i < 10; i++) {
    printf("digite o %d numero: ", i + 1);
    scanf("%d", &p[i]);
  }
  merge(x, 0, 9);
  for (i = 0; i <= 10; i++) {
    printf("%d", p[i]);
  }
    break;

  case 6:

     for (i = 0; i <= 9; i++) {
    printf("digite o %d numero: ", i + 1);
    scanf("%d", &l[i]);
  }
  int tam = sizeof(x) / sizeof(int);
  imprimir(x, tam);
  quicksort(x, 0, tam - 1);
  imprimir(x, tam);
    break;
  
    }
  }
