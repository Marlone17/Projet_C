#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LENGTH 25

  typedef struct {
    int id; 
    char name[MAX_LENGTH];
    int age; 
    char role[15]; 
  
  }Users; // Struct pour les colonnes des users

  typedef struct node {
    Users row; 
    struct node *left; 
    struct node *right; 

  }node; // Struc pour les noeuds

//Notions a revoir : Récursivié ! 

  node *insert_node(node* root, Users users1){
    if(root == NULL){
      node *new_node = (node*)malloc(sizeof(node)); 
      new_node->row = users1; 
      new_node->left = NULL; 
      new_node->right = NULL; 
      return new_node; 
    }
    if (users1.id < root->row.id) {
      root->left = insert_node(root->left, users1);
  } else {
      root->right = insert_node(root->right, users1);
  }
  return root;
  }
  void print_tree(node* root) { // fonction , récursive, à regarder Mawlone
    if (root == NULL) return;
    print_tree(root->left);  // parcours le sous-arbre gauche
    printf("ID: %d, Name: %s, Role: %s\n", root->row.id, root->row.name, root->row.role);
    print_tree(root->right); // parcours le sous-arbre droit
}

void save_data_csv(node* root, FILE* file) { // fonction récursive
  if (root == NULL){
  return;
  }
  // PARCOURS L'ARBRE ET VA ECRIRE CHAQUE DATA USER DANS LA TABLE
  save_data_csv(root->left, file);
  fprintf(file, "%d,%s,%d,%s\n", root->row.id, root->row.name, root->row.age, root->row.role);
  save_data_csv(root->right, file);
}

node* searchUser(node *root, int id){ // pour chercher les users 
  if (root == NULL){
    printf("rien n'a été trouveé ");
    return NULL; 
  }
  if(id == root->row.id){
    return root;  // des datas on été trouvé donc on les return
  }else if (id<root->row.id){
    return searchUser(root->left, id); //on va chercher a gauche
  }else{
    return searchUser(root->right, id); // on va chercher a droite
  }
}


//*************FONCTION A BIEN COMPRENDRE (REGARDER LE FICHIER delete .txt) ****************/
node* deleteUser(node* root, int id){
  
}

  int main(){
  node *root = NULL; // c'est pour initialisern, la racine de l'arbre a nulll (vick, pas oublier la struct)
  Users users1 = {1, "vick", 21,"member"} ; 
   Users users2 = {2, "marlone", 55,"student"}; 
   Users users3 = {3, "wilfried", 12,"client"}; 
   root = insert_node(root, users1);
   root = insert_node(root, users2);
   root = insert_node(root, users3);
  print_tree(root);

    //***************** */ pour faire de la persistance********************* */
    FILE *file = fopen("usersTable.csv", "w");
    if (file == NULL) {
        printf("Erreur lors de la création du fichier.\n");
        return 1;
    }
    // premiere ligne du fichier
    fprintf(file, "ID,Name,Age,Role\n");
        save_data_csv(root, file);
    fclose(file); //Pas oblier de fermer le fichier

    //*********************************fin de la persistance *********************************/

    int findById = 2; 
    node *userFound = searchUser(root, findById); 

    //**************************************************Recherche user */
    if(userFound != NULL){
      printf("user trouvé!");
      printf("\nUtilisateur trouvé : ID: %d, Nom: %s, Age: %d, Role: %s\n", userFound->row.id, userFound->row.name, userFound->row.age, userFound->row.role); 
    }else{
      printf("User non trouvé");

    }

    return 0;
  }