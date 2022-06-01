#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char **argv) {
    //Inicializando o clock
    clock_t begin = clock();
    //Linha necessária para a randomização
    srand(time(NULL));
    int n;
    n = atoi(argv[1]);
    //Alocação da matriz e dos vetores
    int *x = malloc(n * sizeof(int));
    int *b = malloc(n * sizeof(int));
    int *matrix = (int *)malloc(n * n * sizeof(int));
    int i, j;
    //Preenchimento da matriz e do vetor x de números aleatórios
    for (i = 0; i < n; i++) {
        x[i] = rand();
        for (j = 0; j < n; j++) {
            matrix[i * n + j] = rand();
        }
    }
    //Produto Matriz Vetor
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            b[i] = b[i] + matrix[i * n + j] * x[j];
        }
    }
    //Encerramento do clock
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //Printando o tempo de execução e a dimensão da matriz e dos vetores
    printf("%f\n", time_spent);
    printf("%d\n", n);
    
    //Alocação dos pontos em um arquivo excel
    FILE *fptr;
    fptr = fopen("pontos_em_C.csv", "a");
    if(fptr == NULL) {
      printf("Error!");   
      exit(1);             
    }

    fprintf(fptr,"%d", n);
    fprintf(fptr,",%f\n", time_spent);
    fclose(fptr);
    
    exit(0);
}