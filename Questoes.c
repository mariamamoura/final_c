/* Questão 1
questão da soma mostrando elementos somados ; procurar
grupo de adição que deu a maior soma caso hajam resultados
iguais procurar a com a menor quantidade de sub-elementos
Ex: 1, 2, -5, -3, 1, 1, 1, -7
1 + 2 = 3 && 1 + 1 + 1 = 3
Nesse caso o retorno precisa ser [1, 2], por ter apenas
um elemento.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 2048

int main(void){
    FILE *fp = fopen("desafio_final.txt", "r");

    if(!fp){
        printf("Cheque o nome do arquivo e tente novamente.\n");
        return 0;
    }

    float line = 0, maior = 0;
    char *lineContent = (char *)malloc(BUFFER_SIZE * sizeof(char *));

    while (fgets(lineContent, BUFFER_SIZE, fp) != NULL){
        char *elemento = strtok(lineContent,"[ ,]\n");
        while(elemento != NULL){
            if(atof(elemento) > maior)
                maior = atof(elemento);

            printf(" %s", elemento);
            elemento = strtok(NULL,"[ ,]\n");
        }

        printf("\nMaior soma: %.2f\n", maior);
        maior = 0;
        line++;
    }

    free(lineContent);
    fclose(fp);
    return 0;
}

/*Questão 2
Dada uma string retorne todas a strings que saem da
combinação dessa string de entrada;*/

#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
  char t = *a;
  *a = *b;
  *b = t;
}

void permute(char *a, int i, int tam) {
   if (i == (tam-1)) printf("%s\n", a);
   else {
     // Show all the permutations with the first i-1 letters fixed and
     // swapping the i'th letter for each of the remaining ones.
     for (int j = i; j < tam; j++) {
       swap((a+i), (a+j));
       permute(a, i+1, tam);
       swap((a+i), (a+j));
     }
  }
}
int main() {
  char palavra[100];
  strcpy(palavra, "casa");
  permute(palavra, 0, strlen(palavra));
  return 0;
}

//segundo jeito

#include <stdio.h>

void combinacoes(char *arr, size_t tamanho, size_t index) {
    size_t i;
    if (index == tamanho) {
        /* array vazio, imprime o que está "para trás" */
        printf("%c", arr[0]);
        for (i = 1; i < tamanho ; i++){
            if (arr[i] != '\0')
                printf(" %c", arr[i]);}
        puts("");
        return;
    }
    for (i = index; i < tamanho; i++) {
        char tmp;
        /* mete cada um dos elementos ao principio */
        tmp = arr[i];
        arr[i] = arr[index];
        arr[index] = tmp;

        /* recursividade! */
        combinacoes(arr, tamanho, index + 1);

        /* repoe posicao inicial */
        tmp = arr[i];
        arr[i] = arr[index];
        arr[index] = tmp;
    }
}

int main(void) {
    char palavra[] = "casa";
    combinacoes(palavra, sizeof palavra / sizeof *palavra, 0);
    return 0;
}
