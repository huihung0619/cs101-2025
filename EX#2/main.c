#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];  
    int age;
    float salary;
} employee_t;

#define EMPLOYEE_COUNT 3
#define FILENAME "employee.bin"

void initialize_employees(employee_t employees[]) {
    strcpy(employees[0].name, "IU");
    employees[0].id = 1;
    employees[0].age = 20;
    employees[0].salary = 30000.0;

    strcpy(employees[1].name, "taylor");
    employees[1].id = 2;
    employees[1].age = 26;
    employees[1].salary = 36000.0;

    strcpy(employees[2].name, "swift");
    employees[2].id = 3;
    employees[2].age = 31;
    employees[2].salary = 90000.0;
}

void write_to_file(employee_t employees[]) {
    FILE *file = fopen(FILENAME, "wb");
    if (!file) {
        perror("�L�k�}���ɮ�");
        exit(1);
    }
    fwrite(employees, sizeof(employee_t), EMPLOYEE_COUNT, file);
    fclose(file);
}

void read_from_file() {
    employee_t employees[EMPLOYEE_COUNT];
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        perror("�L�k�}���ɮ�");
        exit(1);
    }
    fread(employees, sizeof(employee_t), EMPLOYEE_COUNT, file);
    fclose(file);

    printf("Ū�������u��ơG\n");
    for (int i = 0; i < EMPLOYEE_COUNT; i++) {
        printf("employee id = %d\n", employees[i].id);
        printf("employee name = %s\n", employees[i].name);
        printf("employee age = %d\n", employees[i].age);
        printf("employee salary = %.6f\n\n", employees[i].salary);
    }
}

int main() {
    employee_t employees[EMPLOYEE_COUNT];
    initialize_employees(employees);
    write_to_file(employees);
    read_from_file();
    return 0;
}

