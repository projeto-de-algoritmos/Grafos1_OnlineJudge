// https://www.beecrowd.com.br/judge/pt/problems/view/1907?origem=1
#include <stdio.h>

#define N 1025
#define V '.'
#define I 'o'

char s[N][N];
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, -1, 1};

int valido(int i, int j, int n, int m)
{
    return i >= 0 && i < n &&
           j >= 0 && j < m &&
           s[i][j] == V;
}

void forca(int i, int j, int n, int m) // backtracking para realizar a pesquisa
{
    int k, i1, j1;
    s[i][j] = I;
    for (k = 0; k < 4; k++)
    {
        i1 = i + di[k], j1 = j + dj[k];
        if (valido(i1, j1, n, m))
            forca(i1, j1, n, m);
    }
}

int main(void)
{
    int n, m, i, j, a;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
        scanf("%s", s[i]);

    for (a = 0, i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            if (s[i][j] == V)
                a++, forca(i, j, n, m);
    }

    printf("%d\n", a);

    return 0;
}