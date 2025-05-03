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
node* searchUser(node* root, int id);
node* deleteUser(node* root, int id);
node* modifierUser(node* root, int id, const char* nouveauNom, int nouvelAge, const char* nouveauRole);
void print_tree(node* root);

#endif