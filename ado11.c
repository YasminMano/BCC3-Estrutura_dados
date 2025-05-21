#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno *link;

struct Aluno {
    int matricula;
    float cr;
    link prox;
};

typedef struct Aluno *Hash;

// Inicializa a tabela hash com NULL
void inicializar(Hash *tab, int m) {
    for (int i = 0; i < m; i++)
        tab[i] = NULL;
}

// Método da dobra com repetição até valor < tam
int metodo_dobra(int mat, int tam) {
    char str[20];
    int valor = mat;

    while (valor >= tam) {
        sprintf(str, "%d", valor);
        int len = strlen(str);
        int soma = 0;

        for (int i = 0; i < len / 2; i++) {
            int dig_esq = str[i] - '0';
            int dig_dir = str[len - 1 - i] - '0';
            soma += dig_esq + dig_dir;
        }

        if (len % 2 != 0) {
            soma += str[len / 2] - '0';
        }

        valor = soma;
    }

    return valor;
}

// Função de hash usa o método da dobra
int hash(int mat, int tam) {
    return metodo_dobra(mat, tam);
}

// Insere um aluno na tabela
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

// Busca um aluno
link buscar(Hash *tab, int m, int mat) {
    int h = hash(mat, m);
    link p = tab[h];
    while ((p != NULL) && (p->matricula != mat))
        p = p->prox;
    return p;
}

// Remove um aluno
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

// Imprime a tabela
void imprimir(Hash *tab, int m) {
    for (int i = 0; i < m; i++) {
        printf("tab[%d]: ", i);
        link p = tab[i];
        while (p != NULL) {
            printf("mat = %d , cr = %.1f -> ", p->matricula, p->cr);
            p = p->prox;
        }
        printf("NULL\n");
    }
}

// Função principal
int main(void) {
    int n, m;
    printf("Digite o valor de m (tamanho da tabela hash): ");
    scanf("%d", &m);
    printf("Digite o valor de n (quantidade de matrículas): ");
    scanf("%d", &n);

    Hash tab[m];
    inicializar(tab, m);

    int mat;
    float cr;
    for (int i = 0; i < n; i++) {
        printf("Digite a matrícula do aluno %d: ", i + 1);
        scanf("%d", &mat);
        printf("Digite o CR do aluno %d: ", i + 1);
        scanf("%f", &cr);
        inserir(tab, m, mat, cr);
    }

    imprimir(tab, m);

    char resposta;
    do {
        printf("Digite a matrícula que deseja procurar: ");
        scanf("%d", &mat);
        link p = buscar(tab, m, mat);
        if (p == NULL)
            printf("Matrícula não encontrada!\n");
        else
            printf("Encontrou mat = %d , cr = %.1f\n", p->matricula, p->cr);

        printf("Quer procurar outra matrícula? (s/n) ");
        scanf(" %c", &resposta);
    } while (resposta != 'n' && resposta != 'N');

    imprimir(tab, m);

    do {
        printf("Digite a matrícula que deseja remover: ");
        scanf("%d", &mat);
        remover(tab, m, mat);
        imprimir(tab, m);
        printf("Quer remover outra matrícula? (s/n) ");
        scanf(" %c", &resposta);
    } while (resposta != 'n' && resposta != 'N');

    return 0;
}
