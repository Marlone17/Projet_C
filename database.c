#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 25

typedef struct {
    int id;
    char name[MAX_LENGTH];
    int age;
    char role[15];
  }Employee;

  void insert(Employee *employees, int *count, int id, const char *name, int age, char *role) {
    employees[*count].id = id;
    strncpy(employees[*count].name, name, MAX_LENGTH);
    employees[*count].age = age;
    strncpy(employees[*count].role, role, 14);
    (*count)++;
    printf("Employee added\n");
    printf("New employeee: %d %s %d %s", employees[*count - 1].id, employees[*count - 1].name, employees[*count - 1].age, employees[*count - 1].role);
  }


  int main() {
    Employee employees[50];
    int count = 0;
    int id, age;
    char name[MAX_LENGTH];
    char role[14];

    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter role: ");
    scanf(" %14s", &role);
    insert(employees, &count, id, name, age, role);
    return 0;
  }