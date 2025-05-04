#ifndef DATABASE_H
#define DATABASE_H

#define MAX_LENGTH 25

typedef struct {
    int id;
    char name[MAX_LENGTH];
    int age;
    char role[15];
} Users;


typedef struct node {
    Users row;
    struct node *left;
    struct node *right;
} node;

node* insert_node(node* root, Users user);
node* init_database() {
    node* root = NULL;
    Users users1 = {1, "vick", 21, "member"};
    Users users2 = {2, "marlone", 55, "student"};
    Users users3 = {3, "wilfried", 12, "client"};

    root = insert_node(root, users1);
    root = insert_node(root, users2);
    root = insert_node(root, users3);

    return root;
}
node* init_database();
node* searchUser(node* root, int id);
node* deleteUser(node* root, int id);
node* modifierUser(node* root, int id, const char* nouveauNom, int nouvelAge, const char* nouveauRole);
void print_tree(node* root);

#endif