/*
    * Estrutura da árvore de busca binária.
*/
typedef struct binarytree btree;

/*
    * Inicializa uma árvore com valor NULL.
*/
void create_empty_binarytree(btree **root);

/*
    * Aloca espaço na memória.
    * Atribui valor ao item da estrutura.
    * Inicializa left e right com valor NULL.
    * Retorna o novo node.
*/
btree *create_newnode(int item);

/*
    * Procura a posição correta para o novo node.
    * Retorna a árvore com o node adicionado.
*/
btree *add_node_bt(btree *root, int item);

/*
    * Imprime os items da árvore em ordem crescente.
*/
void print_inorder(btree *node);

/*
    * Procura um item na árvore.
    * Retorna o número de comparações realizados para achar tal item.
*/
int b_search(btree *node, int item, int comparisons);

