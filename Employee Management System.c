#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_employees 100

struct Employee
{
    char name[50];
    int id;
    char address[100];
    char phone[15];
    float yearlySalary;
};

struct Employee employees[max_employees];
int employeeCount = 0;

// Functions
void add_emp();
void rem_emp();
void show_epm();
void iv_emp();
void edit_emp();
void salary_calc();
void search_name();
void save_data_to_file();
void load_data_from_file();
int get_valid_int();
void get_string_input(char* str, int size);

int main()
{
    int choice;

    do
    {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Remove Employee\n");
        printf("3. Show All Employee Details\n");
        printf("4. Individual Employee Details\n");
        printf("5. Edit Employee Details\n");
        printf("6. Calculate Average Employee Salary\n");
        printf("7. Search Employee by Name\n");
        printf("8. Backup Data\n");
        printf("9. Load Data from Backup\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');  // Clearing the input buffer

        switch (choice)
        {
        case 1:
            add_emp();
            save_data_to_file();
            break;
        case 2:
            rem_emp();
            save_data_to_file();
            break;
        case 3:
            show_epm();
            break;
        case 4:
            iv_emp();
            break;
        case 5:
            edit_emp();
            save_data_to_file();
            break;
        case 6:
            salary_calc();
            break;
        case 7:
            search_name();
            break;
        case 8:
            save_data_to_file();
            printf("Data backed up successfully.\n");
            break;
        case 9:
            load_data_from_file();
            printf("Data loaded from backup successfully.\n");
            break;
        case 10:
            printf("Get An Heart Attack And Move On. Goodbye!\n");
            break;
        default:
            printf("Wrong Choice!\n");
        }
    }
    while (choice != 10);

    return 0;
}

void add_emp()
{
    if (employeeCount < max_employees)
    {
        struct Employee newEmployee;
        printf("Enter Employee Details:\n");
        printf("Name: ");
        get_string_input(newEmployee.name, sizeof(newEmployee.name));
        printf("ID: ");
        newEmployee.id = get_valid_int();
        printf("Address: ");
        get_string_input(newEmployee.address, sizeof(newEmployee.address));
        printf("Phone: ");
        get_string_input(newEmployee.phone, sizeof(newEmployee.phone));
        printf("Yearly Salary: ");
        scanf("%f", &newEmployee.yearlySalary);
        while(getchar() != '\n');  // Clearing the input buffer

        employees[employeeCount++] = newEmployee;

        printf("Employee added successfully!\n");
    }
    else
    {
        printf("Maximum number of employees reached!\n");
    }
}

void rem_emp()
{
    int idToRemove;
    printf("Enter Employee ID to remove: ");
    idToRemove = get_valid_int();

    int found = 0;
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == idToRemove)
        {
            found = 1;
            for (int j = i; j < employeeCount - 1; j++)
            {
                employees[j] = employees[j + 1];
            }
            employeeCount--;
            printf("Employee removed successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("Employee with ID %d not found!\n", idToRemove);
    }
}

void show_epm()
{
    if (employeeCount > 0)
    {
        printf("All Employee Details:\n");
        for (int i = 0; i < employeeCount; i++)
        {
            printf("Name: %s, ID: %d, Address: %s, Phone: %s, Yearly Salary: %.2f\n",
                   employees[i].name, employees[i].id, employees[i].address,
                   employees[i].phone, employees[i].yearlySalary);
        }
    }
    else
    {
        printf("No employees to display.\n");
    }
}

void iv_emp()
{
    int idToSearch;
    printf("Enter Employee ID to display details: ");
    idToSearch = get_valid_int();

    int found = 0;
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == idToSearch)
        {
            found = 1;
            printf("Employee Details:\n");
            printf("Name: %s, ID: %d, Address: %s, Phone: %s, Yearly Salary: %.2f\n",
                   employees[i].name, employees[i].id, employees[i].address,
                   employees[i].phone, employees[i].yearlySalary);
            break;
        }
    }

    if (!found)
    {
        printf("Employee with ID %d not found!\n", idToSearch);
    }
}

void edit_emp()
{
    int idToEdit;
    printf("Enter Employee ID to edit details: ");
    idToEdit = get_valid_int();

    int found = 0;
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == idToEdit)
        {
            found = 1;
            printf("Enter new details for Employee ID %d:\n", idToEdit);
            printf("Name: ");
            scanf("%s", employees[i].name);
            printf("Address: ");
            scanf("%s", employees[i].address);
            printf("Phone: ");
            scanf("%s", employees[i].phone);
            printf("Yearly Salary: ");
            scanf("%f", &employees[i].yearlySalary);
            printf("Employee details updated successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("Employee with ID %d not found!\n", idToEdit);
    }
}

void salary_calc()
{
    float totalSalary = 0;
    for (int i = 0; i < employeeCount; i++)
    {
        totalSalary += employees[i].yearlySalary;
    }
    float averageMonthlySalary = (employeeCount > 0) ? (totalSalary / employeeCount / 12) : 0;
    printf("Average Monthly Salary: %.2f\n", averageMonthlySalary);
}

void search_name()
{
    char nameToSearch[50];
    printf("Enter Employee Name to search: ");
    get_string_input(nameToSearch, sizeof(nameToSearch));

    int found = 0;
    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(employees[i].name, nameToSearch) == 0)
        {
            found = 1;
            printf("Employee found:\n");
            printf("Name: %s, ID: %d, Address: %s, Phone: %s, Yearly Salary: %.2f\n",
                   employees[i].name, employees[i].id, employees[i].address,
                   employees[i].phone, employees[i].yearlySalary);
            break;
        }
    }

    if (!found)
    {
        printf("Employee with Name %s not found!\n", nameToSearch);
    }
}

int get_valid_int()
{
    int num;
    char term;
    if(scanf("%d%c", &num, &term) != 2 || term != '\n')
    {
        while(fgetc(stdin) != '\n');
        printf("Invalid input, please enter a number: ");
        return get_valid_int();
    }
    else
    {
        return num;
    }
}

void save_data_to_file()
{
    FILE *file = fopen("employee_backup.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < employeeCount; i++)
    {
        fprintf(file, "Name: %s, ID: %d, Address: %s, Phone: %s, Yearly Salary: %.2f\n",
                employees[i].name, employees[i].id, employees[i].address,
                employees[i].phone, employees[i].yearlySalary);
    }

    fclose(file);
}

void load_data_from_file()
{
    FILE *file = fopen("employee_backup.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    employeeCount = 0;
    struct Employee tempEmployee;
    while (fscanf(file, "Name: %49[^,], ID: %d, Address: %99[^,], Phone: %14[^,], Yearly Salary: %f\n",
                  tempEmployee.name, &tempEmployee.id, tempEmployee.address,
                  tempEmployee.phone, &tempEmployee.yearlySalary) == 5)
    {
        if (employeeCount < max_employees)
        {
            employees[employeeCount++] = tempEmployee;
        }
        else
        {
            printf("Reached maximum employee limit while loading.\n");
            break;
        }
    }

    fclose(file);
}

void get_string_input(char* str, int size)
{
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = 0;
}
