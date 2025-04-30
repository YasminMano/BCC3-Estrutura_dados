// Exercício 11
// Modifique a implementação da tabela hash com
// encadeamento exterior, para utilizar a função de hash que
// aplica o método da multiplicação descrito a seguir:
// h(k) = ⌊m × ((k × A) mod 1)⌋
// Considere A um número irracional.

// Código Fonte:

// int hash(int mat, int tam) {
//     return mat % tam; // MÃ©todo da divisÃ£o
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno *link;

struct Aluno {
  int matricula;
  float cr;
  link prox;
};

typedef struct Aluno *Hash;

void inicializar(Hash *tab, int m) {
  for (int i = 0; i < m; i++)
    tab[i] = NULL;
}

// Função hash usando o método da multiplicação
int hash(int k, int m) {
  double A = 0.110001; // aproximação simples do número de Liouville
  double val = k * A;
  double frac = val - (int)val; // parte fracionária
  return (int)(m * frac);
}

void inserir(Hash *tab, int m, int mat, float cr) {
  int h = hash(mat, m);
  link p = tab[h];
  link ant = NULL;
  while ((p != NULL) && (p->matricula != mat)) {
    ant = p;
    p = p->prox;
  }
  if (p != NULL)
    printf("Matrícula já cadastrada!\n");
  else {
    link novoNode = (link)malloc(sizeof(struct Aluno));
    novoNode->matricula = mat;
    novoNode->cr = cr;
    novoNode->prox = NULL;
    if (ant == NULL)
      tab[h] = novoNode;
    else
      ant->prox = novoNode;
  }
}

link buscar(Hash *tab, int m, int mat) {
  int h = hash(mat, m);
  link p = tab[h];
  while ((p != NULL) && (p->matricula != mat))
    p = p->prox;
  return p;
}

void remover(Hash *tab, int m, int mat) {
  int h = hash(mat, m);
  if (tab[h] == NULL)
    return;
  link p = tab[h];
  link ant = NULL;
  while ((p != NULL) && (p->matricula != mat)) {
    ant = p;
    p = p->prox;
  }
  if (p == NULL) {
    printf("Matrícula não cadastrada!\n");
    return;
  }
  if (ant == NULL)
    tab[h] = p->prox;
  else
    ant->prox = p->prox;
  printf("mat = %d , cr = %.1f foi removido!\n", p->matricula, p->cr);
  free(p);
}

void imprimir(Hash *tab, int m) {
  for (int i = 0; i < m; i++) {
    if (tab[i] != NULL) {
      link p = tab[i];
      printf("tab[%d]: ", i);
      while (p != NULL) {
        printf("mat = %d , cr = %.1f -> ", p->matricula, p->cr);
        p = p->prox;
      }
      printf("NULL\n");
    } else {
      printf("tab[%d]: NULL\n", i);
    }
  }
}

int main(void) {
  int n, m;
  printf("Digite o valor de m (tamanho da tabela hash): ");
  scanf("%d", &m);
  printf("Digite o valor de n (quantidade de matriculas): ");
  scanf("%d", &n);

  Hash tab[m];
  inicializar(tab, m);

  int mat;
  float cr;
  for (int i = 0; i < n; i++) {
    printf("Digite a matricula do aluno %d: ", i + 1);
    scanf("%d", &mat);
    printf("Digite o CR do aluno %d: ", i + 1);
    scanf("%f", &cr);
    inserir(tab, m, mat, cr);
  }

  imprimir(tab, m);

  char resposta;
  do {
    printf("Digite a matricula que deseja procurar: ");
    scanf("%d", &mat);
    link p = buscar(tab, m, mat);
    if (p == NULL)
      printf("Matrícula não encontrada!\n");
    else
      printf("Encontrou mat = %d , cr = %.1f\n", p->matricula, p->cr);
    printf("Quer procurar outra matrícula? (s/n) ");
    scanf(" %c", &resposta);
  } while ((resposta != 'N') && (resposta != 'n'));

  imprimir(tab, m);

  do {
    printf("Digite a matricula que deseja remover: ");
    scanf("%d", &mat);
    remover(tab, m, mat);
    imprimir(tab, m);
    printf("Quer remover outra matrícula? (s/n) ");
    scanf(" %c", &resposta);
  } while ((resposta != 'N') && (resposta != 'n'));

  return 0;
}
