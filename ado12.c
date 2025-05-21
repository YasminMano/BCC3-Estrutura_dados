#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno *link;

struct Aluno {
  int matricula;
  float cr;
};

typedef struct Aluno *Hash;

// Constante de ouro (sqrt(5)-1)/2
#define C 0.6180339887

void inicializar(Hash *tab, int m) {
  for (int i = 0; i < m; i++)
    tab[i] = NULL;
}

// Função h'(x) = x % m
int hash_primaria(int x, int m) { return x % m; }

// Função h''(x) = floor(m * ((x * c) - floor(x * c)))
int hash_secundaria(int x, int m) {
  double temp = x * C;
  return (int)(m * (temp - floor(temp)));
}

// Dispersão dupla: h(x, k) = (h'(x) + k * h''(x)) % m
int hash(int x, int m, int k) {
  return (hash_primaria(x, m) + k * hash_secundaria(x, m)) % m;
}

int buscar(Hash *tab, int m, int mat, int *achou) {
  *achou = 0;
  int endereco = -1;
  int posicao_livre = -1;
  int k = 0;

  while (k < m) {
    endereco = hash(mat, m, k);
    if (tab[endereco] != NULL && tab[endereco]->matricula == mat) {
      *achou = 1;
      return endereco;
    } else if (tab[endereco] == NULL) {
      if (posicao_livre == -1)
        posicao_livre = endereco;
    }
    k++;
  }

  return posicao_livre;
}

void inserir(Hash *tab, int m, int mat, float cr) {
  int achou;
  int endereco = buscar(tab, m, mat, &achou);

  if (!achou) {
    if (endereco != -1) {
      tab[endereco] = (link)malloc(sizeof(struct Aluno));
      tab[endereco]->matricula = mat;
      tab[endereco]->cr = cr;
    } else {
      printf("A tabela está cheia. Inserção não realizada.\n");
    }
  } else {
    printf("Matrícula já existente. Inserção inválida.\n");
  }
}

void remover(Hash *tab, int m, int mat) {
  int achou;
  int endereco = buscar(tab, m, mat, &achou);
  if (achou) {
    free(tab[endereco]);
    tab[endereco] = NULL;
  } else {
    printf("Matrícula não encontrada. Remoção não realizada.\n");
  }
}

void imprimir(Hash *tab, int m) {
  for (int i = 0; i < m; i++) {
    if (tab[i] != NULL)
      printf("tab[%d]:\tmat:%d\tcr:%.2f\n", i, tab[i]->matricula, tab[i]->cr);
    else
      printf("tab[%d]:\n", i);
  }
}

int main(void) {
  int m, n;
  printf("Digite o valor de m (tamanho da tabela hash, primo): ");
  scanf("%d", &m);
  printf("Digite o valor de n (quantidade de matrículas): ");
  scanf("%d", &n);

  Hash tab[m];
  inicializar(tab, m);
  imprimir(tab, m);

  for (int i = 0; i < n; i++) {
    int mat;
    float cr;
    printf("Digite a matrícula do aluno %d: ", i + 1);
    scanf("%d", &mat);
    printf("Digite o CR do aluno %d: ", i + 1);
    scanf("%f", &cr);
    inserir(tab, m, mat, cr);
    imprimir(tab, m);
  }

  char resposta;
  do {
    int mat;
    printf("Digite a matrícula que deseja procurar: ");
    scanf("%d", &mat);
    int achou;
    int endereco = buscar(tab, m, mat, &achou);
    if (achou)
      printf("Encontrou mat = %d, cr = %.1f\n", tab[endereco]->matricula,
             tab[endereco]->cr);
    else
      printf("Matrícula não encontrada.\n");
    printf("Quer procurar outra matrícula? (s/n): ");
    scanf(" %c", &resposta);
  } while (resposta != 'n' && resposta != 'N');

  do {
    int mat;
    printf("Digite a matrícula que deseja remover: ");
    scanf("%d", &mat);
    remover(tab, m, mat);
    imprimir(tab, m);
    printf("Quer remover outra matrícula? (s/n): ");
    scanf(" %c", &resposta);
  } while (resposta != 'n' && resposta != 'N');

  return 0;
}
