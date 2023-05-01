//Projeto de Algoritmos - Grafos 1 - Dupla 19
//Bruna Santos e Damarcones Porto

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define C 60
#define U -1

    int dfs_contador, pontes, dfs_menor[C], dfs_pai[C], dfs_num[C];
    vector<vector<int>> a;


void dfs(int u) {
    
    dfs_menor[u] = dfs_num[u] = dfs_contador++;

    for (int j = 0; j < (int)a[u].size(); j++) {
        
        int v = a[u][j];

        if (dfs_num[v] == U) {
            dfs_pai[v] = u;
            dfs(v);

            if (dfs_menor[v] > dfs_num[u])
                pontes++;
            dfs_menor[u] = min(dfs_menor[u], dfs_menor[v]);
        }
        
        else if (v != dfs_pai[u]) {
            dfs_menor[u] = min(dfs_menor[u], dfs_num[v]);
        }
    }
}


int main(void) {
    int c, p, x, y;

    while (cin >> c >> p) {       // Leitura
        
        memset(dfs_menor, U, sizeof dfs_menor);
        memset(dfs_pai, U, sizeof dfs_pai);
        memset(dfs_num, U, sizeof dfs_num);
        dfs_contador = pontes = 0;

        a.assign(c, vector<int>());

        while (p--) {
            cin >> x >> y;
            x--, y--;
            a[x].push_back(y), a[y].push_back(x);
        }

        dfs(0);

        cout << pontes << endl;     // Impressão

        a.clear();
    
    }
    return 0;
}