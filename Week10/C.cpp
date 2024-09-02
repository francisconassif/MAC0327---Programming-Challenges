/* LCA com Binary Lifting
 * é dada uma árvore com qv vértices enraizada no vértice 1
 * são dados também qq pares de vértices
 * para cada par, encontrar o menor ancestral comum
 *
 * Entrada:

6 3

1 2
1 3
2 4
2 5
3 6

4 5
4 6
6 3

 * Saída:

2
1
3

 */

#include<iostream>
#include<vector>
#include<array>

using namespace std;

// MAXP representa a quantidade de linhas da matriz de "pulos"
// deve ser pelo menos o teto do log do tamanho do maior "pulo" possível no problema
// MAXP >= log(10**9)
#define MAXP 32 

vector<vector<int>> bss; // bss[a] representa a lista de adjacência do vértice a
vector<array<int, MAXP>> ps; // matriz de "pulos": ps[a][j] representa o 2**j-ésimo ancestral do vértice a
vector<int> ls, rs; // ls[a] e rs[a] representam respectivamente o tempo inicial e final da DFS no vértice a
int c=0; // contador de tempos para a DFS

void dfs(int a, int p) {

	ps[a][0] = p; // incializa o primeiro ancestral de a como o pai na DFS
	ls[a] = c++;

	for(int b : bss[a])
		if(b != p)
			dfs(b, a);

	rs[a] = c++;

}

int main() {

	ios_base::sync_with_stdio(false);cin.tie(NULL);	

	int qv, qq; // quantidade de vértices e quantidade de consultas
	cin >> qv >> qq;

	// define o tamanho dos vetores
	bss.resize(qv);
	ps.resize(qv);
	ls.resize(qv);
	rs.resize(qv);

	// lê as arestas
	for(int i=1; i<qv; i++) {
		int a, b; cin >> a;
		a--;
		bss[a].push_back(i);
		bss[i].push_back(a);
	}

	// aplica a DFS partindo do vértice zero, fazendo com que a árvore seja enraizada nesse vértice
	// aqui, o zero no segundo argumento é muito importante, pois faz com que o ancestral da raiz seja ela mesma
	// isso garante que ficaremos na raiz em caso de "pulos" maiores que a altura da árvore
	dfs(0,0);

	// inicializa a matriz de "pulos"
	// cada linha da matriz é construída a partir das informações da linha anterior
	for(int j=0; j<MAXP-1; j++) {
		for(int i=0; i<qv; i++)
			ps[i][j+1] = ps[ps[i][j]][j];
	}

	// processa as consultas
	for(int i=0; i<qq; i++) {

		int a, b; cin >> a >> b;
		a--; b--;

		if(ls[a] <= ls[b] && rs[b] <= rs[a]) // a é ancestral de b
			cout << a + 1 << '\n';

		else if(ls[b] <= ls[a] && rs[a] <= rs[b]) // b é ancestral de a
			cout << b + 1 << '\n';

		else { // a e b não são ancestrais um do outro
			// usamos a matriz do binary lifting para buscar pelo último ancestral de a que não é um ancestral de b
			// durante a busca, representaremos esse ancestral pela variável u
			int u = a;
			for(int j=MAXP-1; j>=0; j--) { // para cada tamanho de "pulo" começando pelo maior (essa ordem é importante)
				int v = ps[u][j]; // v é o 2**j-ésimo ancestral de u
				if(ls[v] > ls[b] || rs[b] > rs[v]) // v não é ancestral de b, podemos continuar a busca em v
					u = v;
			}
			// ao final da busca, o menor ancestral comum de a e b é o ancestral direto (pai) de u
			cout << ps[u][0]+1 << '\n';
		}

	}

	return 0;	
}
