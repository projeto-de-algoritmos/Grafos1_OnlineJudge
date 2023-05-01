//Projeto de Algoritmos - Grafos 1 - Dupla 19
//Bruna Santos e Damarcones Porto

#include <stdio.h>

#define N 105       // N = numero de pontos na cidade

int g[N][N], v[N];

void dfs(int i, int c, int n) {       // Função de busca em profundidade
    int j;
    for (v[i] = c, j = 0; j < n; j++)
        if (!v[j] && g[i][j])
            dfs(j, c, n);
}


int main(void) {
    
    int teste;      // Número de casos de teste
    int m, n, x, y, k, i, j, c;

    
    scanf("%d", &teste);

    for (k = 1; k <= teste; k++) {
        
        scanf("%d\n%d", &n, &m);        // n = pontos principais, m = nº de estradas concluídas

        for (i = 0; i < n; i++)
            for (v[i] = 0, j = 0; j < n; j++)
                g[i][j] = 0;

        for (i = 0; i < m; i++) {
            
            scanf("%d %d", &x, &y);
            x--, y--, g[x][y] = g[y][x] = 1;
        }

        for (i = 0, c = 0; i < n; i++)
            if (!v[i])
                dfs(i, ++c, n);

        if (c - 1)
            printf("Caso #%d: ainda falta(m) %d estrada(s)\n", k, c - 1);
        
        else
            printf("Caso #%d: a promessa foi cumprida!\n", k);
    }

    return 0;
}