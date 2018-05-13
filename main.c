#include <stdio.h>
#include "tree.h"
#include "avl.h"


int main(){

    FILE* arquivo_dados=fopen("Dados.csv", "w"); //arquivo onde sera guardado o resultado
    fprintf(arquivo_dados, "%s\n", "Element_N, ABB, AVL"); //cabeçário

        btree *arvore_desbalanceada;
        avl_tree *arvore_avl;

    create_empty_binarytree(&arvore_desbalanceada);
    create_empty_avl_tree(&arvore_avl);

    printf("Defina a quantidade de elementos a serem inseridos:\n");

    int num_elements;
        scanf("%d", &num_elements);

    int aux, n_rand, N = 7;

    for(aux=0;aux<num_elements;aux++,n_rand+=N){

        n_rand=rand()%N; //aqui é definido um numero aleatorio entre 0 e o valor de rand
        arvore_desbalanceada=add_node_bt(arvore_desbalanceada, n_rand); //coloca os valores aleatorios na arvore de busca binaria
        arvore_avl=add_node_avl(arvore_avl, n_rand);//coloca os valores aleatorios na AVL
        fprintf(arquivo_dados,"%d, %d, %d\n", aux, b_search(arvore_desbalanceada, n_rand, 1), avlsearch(arvore_avl, n_rand, 1) ); //Anota os dados de quantia de elementos e comparações de cada estrutura no arquivo "dados"
    }
    fclose(arquivo_dados); //fecha o arquivo

    return 0;}
