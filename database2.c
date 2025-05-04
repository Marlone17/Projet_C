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
      node *new_node = (node*)malloc(sizeof(node));  //on alloue de la mémoire ici, pas oublier de le free() !!
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


//*****************************************Fonction pour Update */
void modifierUser(node* root, int id, const char* nouveauNom, int nouvelAge, const char* nouveauRole) {
    node* user = searchUser(root, id);
    if (user == NULL) {
        printf("Aucun utilisateur avec l'ID %d trouvé pour modification.\n", id);
        return;
    }

    // pour mettre à jour les champs du userz trouvé
snprintf(user->row.name, MAX_LENGTH, "%s", nouveauNom);  // Snprintf pour que la chaine se termoine tjrs par \0
user->row.age = nouvelAge;
snprintf(user->row.role, sizeof(user->row.role), "%s", nouveauRole);
}






//fonction pour trouver le plus petit d'un sous arbre donée !!important a bien comprendre aussi
node* trouver_min(node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

//*************FONCTION A BIEN COMPRENDRE (REGARDER LE FICHIER delete .txt) ****************/
node* deleteUser(node* root, int id){
 if (root == NULL) return NULL;

    if (id < root->row.id) {
        root->left = deleteUser(root->left, id);
    } else if (id > root->row.id) {
        root->right = deleteUser(root->right, id);
    } else {
        // premier cas (regarder le ficher .txt que j'ai rajouter pour comprendre les différents cas)
        if (root->left == NULL && root->right == NULL) {
            free(root); // pour libierer la mémore qu'on a allouer
            return NULL;
        }
        // deuxieme cas a droite 
        else if (root->left == NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        }
        // deuxieme cas a gauche
        else if (root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        // troisieme cas 
        else {
            node* min_droite = trouver_min(root->right);
            root->row = min_droite->row;
            root->right = deleteUser(root->right, min_droite->row.id);
        }
    }
    return root;
  
  
}

  