#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LENGTH 25

  typedef struct {
    int id; 
    char name[MAX_LENGTH];
    int age; 
    char role[15]; 
  
  }Users;

  typedef struct node {
    Users row; 
    struct node *left; 
    struct node *right; 

  }node;


  node *insert_node(node* root, Users users1){
    if(root == NULL){
      node *new_node = (node*)malloc(sizeof(node)); 
      new_node->row = users1; 
      new_node->left = NULL; 
      new_node->right = NULL; 
      return new_node; 
    }
    if(users1.id< root->)

  }

  // int test(int *num){
  //   printf("numéro recuperer de base : %d", *num);
  //   *num = 2; 
  //   printf("num modifier = %d", *num);

  // }

  

  int main(){
  node *root = NULL; // c'est pour initialisern, la racine de l'arbre a nulll (vick, pas oublier la struct)
  Users users1 = {1, "vick", 21,"member"} ; 
  root = insert_node(root, users1);
  printf("Root: %d, %s\n", root->row.id, root->row.name); // Affiche le p
  //  printf("id : %d , prénom: %s, age: %d; roles:%s", users1.id, users1.name, users1.age, users1.role); 
    return 0;
  }