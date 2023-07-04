#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void geraVetor(int *vetor,int vTam) {
  int x;
  for (int i = 0; i < vTam; i++) {
    x = rand() % INT_MAX;
    vetor[i] = x;
  }
}
int menorElemento(int *vetor, int n, int ini) {
  int idx_menor = ini;
  for (int i = ini + 1; i < n; i++) {
    if (vetor[i] < vetor[idx_menor]) {
      idx_menor = i;
    }
  }
  return idx_menor;
}
void selectionSort(int *vetor, int n) {
  int idx, aux;
  for (int i = 0; i < n - 1; i++) {
    idx = menorElemento(vetor, n, i);
    aux = vetor[i];
    vetor[i] = vetor[idx];
    vetor[idx] = aux;
  }
}
void insertion(int *vetor, int i) {
  int aux = vetor[i];
  for (int j = i - 1; j >= 0; j--) {
    if (vetor[j] < aux) {
      break;
    }
    vetor[j + 1] = vetor[j];
  }
}
void insertionSort(int *vetor, int n) {
  for (int i = 1; i < n; i++) {
    insertion(vetor, i);
  }
}
void merge(int *vetor, int p, int q, int r) {
  int i, j, k;
  int n1 = q - p + 1;
  int n2 = r - q;
  int *left, *right;

  left = (int *)malloc((n1 + 1) * sizeof(int));
  right = (int *)malloc((n1 + 1) * sizeof(int));

  for (i = 0; i < n1; i++) {
    left[i] = vetor[p + i];
  }
  for (j = 0; j < n2; j++) {
    right[j] = vetor[q + j + 1];
  }
  left[n1] = right[n2] = INT_MAX;
  i = j = 0;
  for (k = p; k <= r; k++) {
    if (left[i] <= right[j]) {
      vetor[k] = left[i];
      i++;
    } else {
      vetor[k] = right[j];
      j++;
    }
  }
  free(right);
  free(left);
}
void mergeSort(int *vetor, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        
        mergeSort(vetor, p, q);
        mergeSort(vetor, q + 1, r);
        
        merge(vetor, p, q, r);
    }
}
int particiona(int *vetor, int p, int r) {
    int pivo = vetor[r];
    int i = p - 1;
    
    for (int j = p; j <= r - 1; j++) {
        if (vetor[j] < pivo) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[r];
    vetor[r] = temp;
    return i + 1;
}
void quickSort(int *vetor, int p, int r) {
    if (p < r) {
        int q = particiona(vetor, p, r);
        
        quickSort(vetor, p, q - 1);
        quickSort(vetor, q + 1, r);
    }
}
//Utilizando o BubbleSort apenas para ordenar metade da lista O^O
void trocaLugar(int * a, int * b) {
  int aux = *a;
  *a = *b;
  *b = aux;
}
void bubbleSort(int vetor[], int inicio, int fim) {
    int i, j;
    int n = fim - inicio + 1;

    for (i = 0; i < n - 1; i++) {
        for (j = inicio; j < fim - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                trocaLugar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}
void ordenaMetade(int vetor[],int vTam) {
  int metade = vTam / 2;
  bubbleSort(vetor,0, metade);
}
//Criando uma função que faz uma cópia entre dois vetores, para fins de testes com diferentes vetores já ordenados, como exemplo um vetor ordenado pela metade...
void copiaVetor(int * vetor,int * vetor2, int vTam) {
  for (int i = 0; i < vTam; i++) {
    *(vetor2 + i) = *(vetor + i); 
  }
}
//Ordena o vetor de Tamanho vTam em Ordem Decrescente
void ordenarDecrescente(int vetor[], int vTam) {
    for (int i = 0; i < vTam - 1; i++) {
        for (int j = 0; j < vTam - i - 1; j++) {
            if (vetor[j] < vetor[j + 1]) {
                // Troca os elementos de posição
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}
//Ordena o vetor de Tamanho vTam em Ordem Crescente
void ordenarCrescente(int vetor[], int vTam) {
    for (int i = 0; i < vTam - 1; i++) {
        for (int j = 0; j < vTam - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos de posição
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}
// Quase ordena o vetor inteiro (Aproximadamente 75% do tamanho do vetor é ordenado...)
void quase_ordenar(int vetor[], int tamanho) {
    int fim_desordenado = tamanho * 0.25;  // Índice de fim da seção desordenada

    // Ordena a parte inicial do vetor (75% ordenado)
    for (int i = 0; i < fim_desordenado; i++) {
        for (int j = 0; j < fim_desordenado - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos de posição
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}
int main() {

  //Declaração dos Vetores...
  int vetor1kSelection[1000],vetor1kInsertion[1000],vetor1kMerge[1000],vetor1kQuick[1000];
  int vetorMeioOrdenado1kSelection[1000],vetorMeioOrdenado1kInsertion[1000],vetorMeioOrdenado1kMerge[1000],vetorMeioOrdenado1kQuick[1000];
  int vetorOrdenado75_1kSelection[1000],vetorOrdenado75_1kInsertion[1000],vetorOrdenado75_1kMerge[1000],vetorOrdenado75_1kQuick[1000];
  
  int vetor10kSelection[10000],vetor10kInsertion[10000],vetor10kMerge[10000],vetor10kQuick[10000];
  int vetorMeioOrdenado10kSelection[10000],vetorMeioOrdenado10kInsertion[10000],vetorMeioOrdenado10kMerge[10000],vetorMeioOrdenado10kQuick[10000];
  int vetorOrdenado75_10kSelection[10000],vetorOrdenado75_10kInsertion[10000],vetorOrdenado75_10kMerge[10000],vetorOrdenado75_10kQuick[10000];
  
  int vetor20kSelection[20000],vetor20kInsertion[20000],vetor20kMerge[20000],vetor20kQuick[20000];
  int vetorMeioOrdenado20kSelection[20000],vetorMeioOrdenado20kInsertion[20000],vetorMeioOrdenado20kMerge[20000],vetorMeioOrdenado20kQuick[20000];
  int vetorOrdenado75_20kSelection[20000],vetorOrdenado75_20kInsertion[20000],vetorOrdenado75_20kMerge[20000],vetorOrdenado75_20kQuick[20000];

  // Gerando Vetores de 1000 valores aleatórios, meio ordenados e 75% ordenados. E copiando eles para cada tipo de ordenação.
  geraVetor(vetor1kSelection,1000);
  copiaVetor(vetor1kSelection,vetor1kInsertion,1000);
  copiaVetor(vetor1kSelection,vetor1kMerge,1000);
  copiaVetor(vetor1kSelection,vetor1kQuick,1000);
  
  geraVetor(vetorMeioOrdenado1kSelection,1000);
  ordenaMetade(vetorMeioOrdenado1kSelection,1000);
  copiaVetor(vetorMeioOrdenado1kSelection,vetorMeioOrdenado1kInsertion,1000);
  copiaVetor(vetorMeioOrdenado1kSelection,vetorMeioOrdenado1kMerge,1000);
  copiaVetor(vetorMeioOrdenado1kSelection,vetorMeioOrdenado1kQuick,1000);
  
  geraVetor(vetorOrdenado75_1kSelection,1000);
  quase_ordenar(vetorOrdenado75_1kSelection,1000);
  copiaVetor(vetorOrdenado75_1kSelection,vetorOrdenado75_1kInsertion,1000);
  copiaVetor(vetorOrdenado75_1kSelection,vetorOrdenado75_1kMerge,1000);
  copiaVetor(vetorOrdenado75_1kSelection,vetorOrdenado75_1kQuick,1000);

  // Gerando Vetores de 10000 valores aleatórios, meio ordenados e 75% ordenados. E copiando eles para cada tipo de ordenação.
  geraVetor(vetor10kSelection,10000);
  copiaVetor(vetor10kSelection,vetor10kInsertion,10000);
  copiaVetor(vetor10kSelection,vetor10kMerge,10000);
  copiaVetor(vetor10kSelection,vetor10kQuick,10000);
  
  geraVetor(vetorMeioOrdenado10kSelection,10000);
  ordenaMetade(vetorMeioOrdenado10kSelection,10000);
  copiaVetor(vetorMeioOrdenado10kSelection,vetorMeioOrdenado10kInsertion,10000);
  copiaVetor(vetorMeioOrdenado10kSelection,vetorMeioOrdenado10kMerge,10000);
  copiaVetor(vetorMeioOrdenado10kSelection,vetorMeioOrdenado10kQuick,10000);
  
  geraVetor(vetorOrdenado75_10kSelection,10000);
  quase_ordenar(vetorOrdenado75_10kSelection,10000);
  copiaVetor(vetorOrdenado75_10kSelection,vetorOrdenado75_10kInsertion,10000);
  copiaVetor(vetorOrdenado75_10kSelection,vetorOrdenado75_10kMerge,10000);
  copiaVetor(vetorOrdenado75_10kSelection,vetorOrdenado75_10kQuick,10000);

  // Gerando Vetores de 20000 valores aleatórios, meio ordenados e 75% ordenados. E copiando eles para cada tipo de ordenação.
  geraVetor(vetor20kSelection,20000);
  copiaVetor(vetor20kSelection,vetor20kInsertion,20000);
  copiaVetor(vetor20kSelection,vetor20kMerge,20000);
  copiaVetor(vetor20kSelection,vetor20kQuick,20000);
  
  
  geraVetor(vetorMeioOrdenado20kSelection,20000);
  ordenaMetade(vetor20kSelection,20000);
  copiaVetor(vetorMeioOrdenado20kSelection,vetorMeioOrdenado20kInsertion,20000);
  copiaVetor(vetorMeioOrdenado20kSelection,vetorMeioOrdenado20kMerge,20000);
  copiaVetor(vetorMeioOrdenado20kSelection,vetorMeioOrdenado20kQuick,20000);
  
  geraVetor(vetorOrdenado75_20kSelection,20000);
  quase_ordenar(vetorOrdenado75_20kSelection,20000);
  copiaVetor(vetorOrdenado75_20kSelection,vetorOrdenado75_20kInsertion,20000);
  copiaVetor(vetorOrdenado75_20kSelection,vetorOrdenado75_20kMerge,20000);
  copiaVetor(vetorOrdenado75_20kSelection,vetorOrdenado75_20kQuick,20000);
  
  // Parte do Código que irá calcular o tempo de cada tipo diferente de ordenação : ) ...

  //Selection Sort ------- 1 mil Valores totalmente desordenados...
  clock_t start, end;
  double cpu_time_used;
  
  start = clock();
  selectionSort(vetor1kSelection,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores totalmente desordenados, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetor1kSelection[i]);
  //}
  
  //Selection Sort ------- 10 mil valores totalmente desordenados...
  start = clock();
  selectionSort(vetor10kSelection,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores totalmente desordenados, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
    //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetor10kSelection[i]);
  //}
  
  //Selection Sort ------- 20 mil valores totalmente desordenados...
  start = clock();
  selectionSort(vetor20kSelection,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores totalmente desordenados, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetor20kSelection[i]);
  //}
  
  //Insertion Sort ------- 1 mil valores totalmente desordenados...
  start = clock();
  insertionSort(vetor1kInsertion,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores totalmente desordenados, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetor1kInsertion[i]);
  //}
  
  //Insertion Sort ------- 10 mil valores totalmente desordenados...
  start = clock();
  insertionSort(vetor10kInsertion,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores totalmente desordenados, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetor10kInsertion[i]);
  //}
  
  //Insertion Sort ------- 20 mil valores totalmente desordenados...
  start = clock();
  insertionSort(vetor20kInsertion,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores totalmente desordenados, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetor20kInsertion[i]);
  //}
  
  //Merge Sort ------- 1 mil valores totalmente desordenados...
  start = clock();
  mergeSort(vetor1kMerge,0,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores totalmente desordenados, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetor1kMerge[i]);
  //}
  
  //Merge Sort ------- 10 mil valores totalmente desordenados...
  start = clock();
  mergeSort(vetor10kMerge,0,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores totalmente desordenados, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetor10kMerge[i]);
  //}
  
  //Merge Sort ------- 20 mil valores totalmente desordenados...
  start = clock();
  mergeSort(vetor20kMerge,0,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores totalmente desordenados, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetor20kMerge[i]);
  //}
  
  //Quick Sort ------- 1 mil valores totalmente desordenados...
  start = clock();
  quickSort(vetor1kQuick,0,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores totalmente desordenados, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetor1kQuick[i]);
  //}
  
  //Quick Sort ------- 10 mil valores totalmente desordenados...
  start = clock();
  quickSort(vetor10kQuick,0,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores totalmente desordenados, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetor10kQuick[i]);
  //}
  
  //Quick Sort ------- 20 mil valores totalmente desordenados...
  start = clock();
  quickSort(vetor20kQuick,0,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores totalmente desordenados, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetor20kQuick[i]);
  //}
  
  // Selection Sort ------- 1 mil valores com o vetor já meio ordenado...
  start = clock();
  selectionSort(vetorMeioOrdenado1kSelection,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores meio ordenados, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetorMeioOrdenado1kSelection[i]);
  //}
  
  //Selection Sort ------- 10 mil valores com o vetor já meio ordenado...
  start = clock();
  selectionSort(vetorMeioOrdenado10kSelection,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores meio ordenados, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetorMeioOrdenado10kSelection[i]);
  //}
  
  //Selection Sort ------- 20 mil valores com o vetor já meio ordenado...
  start = clock();
  selectionSort(vetorMeioOrdenado20kSelection,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores meio ordenados, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetorMeioOrdenado20kSelection[i]);
  //}
  
  //Insertion Sort ------- 1 mil valores com o vetor já meio ordenado...
  start = clock();
  insertionSort(vetorMeioOrdenado1kInsertion,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores meio ordenados, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetor1kInsertion[i]);
  //}
  
  //Insertion Sort ------- 10 mil valores com o vetor já meio ordenado...
  start = clock();
  insertionSort(vetorMeioOrdenado10kInsertion,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores meio ordenados, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetor10kInsertion[i]);
  //}
  
  //Insertion Sort ------- 20 mil valores com o vetor já meio ordenado...
  start = clock();
  insertionSort(vetorMeioOrdenado20kInsertion,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores meio ordenados, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetor20kInsertion[i]);
  //}
  
  //Merge Sort ------- 1 mil valores com o vetor já meio ordenado...
  start = clock();
  mergeSort(vetorMeioOrdenado1kMerge,0,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores meio ordenados, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetorMeioOrdenado1kMerge[i]);
  //}
  
  //Merge Sort ------- 10 mil valores com o vetor já meio ordenado...
  start = clock();
  mergeSort(vetorMeioOrdenado10kMerge,0,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores meio ordenados, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetorMeioOrdenado10kMerge[i]);
  //}
  
  //Merge Sort ------- 20 mil valores com o vetor já meio ordenado...
  start = clock();
  mergeSort(vetorMeioOrdenado20kMerge,0,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores meio ordenados, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetorMeioOrdenado20kMerge[i]);
  //}
  
  //Quick Sort ------- 1 mil valores com o vetor já meio ordenado...
  start = clock();
  quickSort(vetorMeioOrdenado1kQuick,0,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores meio ordenados, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetorMeioOrdenado1kQuick[i]);
  //}
  
  //Quick Sort ------- 10 mil valores com o vetor já meio ordenado...
  start = clock();
  quickSort(vetorMeioOrdenado10kQuick,0,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores meio ordenados, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetorMeioOrdenado10kQuick[i]);
  //}
  
  //Quick Sort ------- 20 mil valores com o vetor já meio ordenado...
  start = clock();
  quickSort(vetorMeioOrdenado20kQuick,0,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores meio ordenados, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetorMeioOrdenado20kQuick[i]);
  //}
  
  //Selection Sort ------- 1 mil valores com o vetor 75% ordenado...
  start = clock();
  selectionSort(vetorOrdenado75_1kSelection,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores com o vetor 75 por cento ordenado, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetorOrdenado75_1kSelection[i]);
  //}
  
  //Selection Sort ------- 10 mil valores com o vetor 75% ordenado...
  start = clock();
  selectionSort(vetorOrdenado75_10kSelection,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores com o vetor 75 por cento ordenado, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetorOrdenado75_10kSelection[i]);
  //}
  
  //Selection Sort ------- 20 mil valores com o vetor 75% ordenado...
  start = clock();
  selectionSort(vetorOrdenado75_20kSelection,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores com o vetor 75 por cento ordenado, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetorOrdenado75_20kSelection[i]);
  //}
  
  //Insertion Sort ------- 1 mil valores com o vetor 75% ordenado...
  start = clock();
  insertionSort(vetorOrdenado75_1kInsertion,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores com o vetor 75 por cento ordenado, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetorOrdenado75_1kInsertion[i]);
  //}
  
  //Insertion Sort ------- 10 mil valores com o vetor 75% ordenado...
  start = clock();
  insertionSort(vetorOrdenado75_10kInsertion,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores com o vetor 75 por cento ordenado, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetorOrdenado75_10kInsertion[i]);
  //}
  
  //Insertion Sort ------- 20 mil valores com o vetor 75% ordenado...
  start = clock();
  insertionSort(vetorOrdenado75_20kInsertion,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores com o vetor 75 por cento ordenado, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetorOrdenado75_20kInsertion[i]);
  //}
  
  //Merge Sort ------- 1 mil valores com o vetor 75% ordenado...
  start = clock();
  mergeSort(vetorOrdenado75_1kMerge,0,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores com o vetor 75 por cento ordenado, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetorOrdenado75_1kMerge[i]);
  //}
  
  //Merge Sort ------- 10 mil valores com o vetor 75% ordenado...
  start = clock();
  mergeSort(vetorOrdenado75_10kMerge,0,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores com o vetor 75 por cento ordenado, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetorOrdenado75_10kMerge[i]);
  //}
  
  //Merge Sort ------- 20 mil valores com o vetor 75% ordenado...
  start = clock();
  mergeSort(vetorOrdenado75_20kMerge,0,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores com o vetor 75 por cento ordenado, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetorOrdenado75_20kMerge[i]);
  //}
  
  //Quick Sort ------- 1 mil valores com o vetor 75% ordenado...
  start = clock();
  quickSort(vetorOrdenado75_1kQuick,0,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores com o vetor 75 por cento ordenado, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetorOrdenado75_1kQuick[i]);
  //}
  
  //Quick Sort ------- 10 mil valores com o vetor 75% ordenado...
  start = clock();
  quickSort(vetorOrdenado75_10kQuick,0,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores com o vetor 75 por cento ordenado, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetorOrdenado75_10kQuick[i]);
  //}
  
  //Quick Sort ------- 20 mil valores com o vetor 75% ordenado...
  start = clock();
  quickSort(vetorOrdenado75_20kQuick,0,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores com o vetor 75 por cento ordenado, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetorOrdenado75_20kQuick[i]);
  //}
  
  //Para vetores já ordenados, basta chamaar novamente os vetores utilizados anteriormente...
  //Pois eles já estão ordenados de forma crescente...
  
  //Selection Sort ------- 1 mil valores com o vetor já ordenado...
  start = clock();
  selectionSort(vetor1kSelection,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores com o vetor já ordenado, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetor1kSelection[i]);
  //}
  
  //Selection Sort ------- 10 mil valores com o vetor já ordenado...
  start = clock();
  selectionSort(vetor10kSelection,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores com o vetor já ordenado, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetor10kSelection[i]);
  //}
  
  //Selection Sort ------- 20 mil valores com o vetor já ordenado...
  start = clock();
  selectionSort(vetor20kSelection,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores com o vetor já ordenado, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetor20kSelection[i]);
  //}
  
  //Insertion Sort ------- 1 mil valores com o vetor já ordenado...
  start = clock();
  insertionSort(vetor1kInsertion,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores com o vetor já ordenado, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetor1kInsertion[i]);
  //}
  
  //Insertion Sort ------- 10 mil valores com o vetor já ordenado...
  start = clock();
  insertionSort(vetor10kInsertion,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores com o vetor já ordenado, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetor10kInsertion[i]);
  //}
  
  //Insertion Sort ------- 20 mil valores com o vetor já ordenado...
  start = clock();
  insertionSort(vetor20kInsertion,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores com o vetor já ordenado, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetor20kInsertion[i]);
  //}
  
  //Merge Sort ------- 1 mil valores com o vetor já ordenado...
  start = clock();
  mergeSort(vetor1kMerge,0,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores com o vetor já ordenado, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetor1kMerge[i]);
  //}

  //Merge Sort ------- 10 mil valores com o vetor já ordenado...
  start = clock();
  mergeSort(vetor10kMerge,0,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores com o vetor já ordenado, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetor10kMerge[i]);
  //}
  
  //Merge Sort ------- 20 mil valores com o vetor já ordenado...
  start = clock();
  mergeSort(vetor20kMerge,0,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores com o vetor já ordenado, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetor20kMerge[i]);
  //}
  
  //Quick Sort ------- 1 mil valores com o vetor já ordenado...
  start = clock();
  quickSort(vetor1kQuick,0,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores com o vetor já ordenado, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetor1kQuick[i]);
  //}
  
  //Quick Sort ------- 10 mil valores com o vetor já ordenado...
  start = clock();
  quickSort(vetor10kQuick,0,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores com o vetor já ordenado, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetor10kQuick[i]);
  //}
  
  //Quick Sort ------- 20 mil valores com o vetor já ordenado...
  start = clock();
  quickSort(vetor20kQuick,0,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores com o vetor já ordenado, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetor20kQuick[i]);
  //}
  
  //Testando os algoritmos para ordenar vetores que estão em Ordem Decrescente...
  //Ordenando os vetores em Ordem Decrescente:
  ordenarDecrescente(vetor1kSelection,1000);
  ordenarDecrescente(vetor10kSelection,10000);
  ordenarDecrescente(vetor20kSelection,20000);
  ordenarDecrescente(vetor1kInsertion,1000);
  ordenarDecrescente(vetor10kInsertion,10000);
  ordenarDecrescente(vetor20kInsertion,20000);
  ordenarDecrescente(vetor1kMerge,1000);
  ordenarDecrescente(vetor10kMerge,10000);
  ordenarDecrescente(vetor20kMerge,20000);
  ordenarDecrescente(vetor1kQuick,1000);
  ordenarDecrescente(vetor10kQuick,10000);
  ordenarDecrescente(vetor20kQuick,20000);
  
  //Refazendo as ordenções, agora, com os vetores organizados de forma decrescente...
  
  //Selection Sort ------- 1 mil valores com o vetor ordenado de forma decrescente...
  start = clock();
  selectionSort(vetor1kSelection,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores com o vetor ordenado de forma decrescente, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetor1kSelection[i]);
  //}
  
  //Selection Sort ------- 10 mil valores com o vetor ordenado de forma decrescente...
  start = clock();
  selectionSort(vetor10kSelection,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores com o vetor ordenado de forma decrescente, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetor10kSelection[i]);
  //}
  
  //Selection Sort ------- 20 mil valores com o vetor ordenado de forma decrescente...
  start = clock();
  selectionSort(vetor20kSelection,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores com o vetor ordenado de forma decrescente, o Selection Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetor20kSelection[i]);
  //}
  
  //Insertion Sort ------- 1 mil valores com o vetor ordenado de forma decrescente...
  start = clock();
  insertionSort(vetor1kInsertion,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores com o vetor ordenado de forma decrescente, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetor1kInsertion[i]);
  //}
  
  //Insertion Sort ------- 10 mil valores com o vetor ordenado de forma decrescente...
  start = clock();
  insertionSort(vetor10kInsertion,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores com o vetor ordenado de forma decrescente, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetor10kInsertion[i]);
  //}
  
  //Insertion Sort ------- 20 mil valores com o vetor ordenado de forma decrescente...
  start = clock();
  insertionSort(vetor20kInsertion,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores com o vetor ordenado de forma decrescente, o Insertion Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetor20kInsertion[i]);
  //}
  
  //Merge Sort ------- 1 mil valores com o vetor ordenado de forma decrescente...
  start = clock();
  mergeSort(vetor1kMerge,0,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores com o vetor ordenado de forma decrescente, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetor1kMerge[i]);
  //}

  //Merge Sort ------- 10 mil valores com o vetor ordenado de forma decrescente...
  start = clock();
  mergeSort(vetor10kMerge,0,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores com o vetor ordenado de forma decrescente, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetor10kMerge[i]);
  //}
  
  //Merge Sort ------- 20 mil valores com o vetor ordenado de forma decrescente...
  start = clock();
  mergeSort(vetor20kMerge,0,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores com o vetor ordenado de forma decrescente, o Merge Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetor20kMerge[i]);
  //}
  
  //Quick Sort ------- 1 mil valores com o vetor ordenado de forma decrescente...
  start = clock();
  quickSort(vetor1kQuick,0,1000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 1 mil valores com o vetor ordenado de forma decrescente, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 1000; i++) {
    //printf("%i \n",vetor1kQuick[i]);
  //}
  
  //Quick Sort ------- 10 mil valores com o vetor ordenado de forma decrescente...
  start = clock();
  quickSort(vetor10kQuick,0,10000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 10 mil valores com o vetor ordenado de forma decrescente, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 10000; i++) {
    //printf("%i \n",vetor10kQuick[i]);
  //}
  
  //Quick Sort ------- 20 mil valores com o vetor ordenado de forma decrescente...
  start = clock();
  quickSort(vetor20kQuick,0,20000);
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("Para vetores de 20 mil valores com o vetor ordenado de forma decrescente, o Quick Sort teve tempo de: %f segundos.\n",cpu_time_used);
  //for (int i = 0; i < 20000; i++) {
    //printf("%i \n",vetor20kQuick[i]);
  //}
}