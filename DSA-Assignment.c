#include <stdio.h>
#include <string.h>

#define NAME_SIZE 50

// Define a structure for employee information
struct EmployeeStruct {
    char name[NAME_SIZE];
    int employeeID;
    float salary;
};

// Define a union for employee information
union EmployeeUnion {
    char name[NAME_SIZE];
    int employeeID;
    float salary;
};

int main() {
    // Create an instance of the structure
    struct EmployeeStruct empStruct;
    strcpy(empStruct.name, "Ayush Paliwal");
    empStruct.employeeID = 101;
    empStruct.salary = 175000.50;

    // Create an instance of the union
    union EmployeeUnion empUnion;
    
    // Initialize the union with the name
    strcpy(empUnion.name, "Salman Khan");
    printf("Union Employee Info after setting name:\n");
    printf("Name: %s\n", empUnion.name); // Should show "Bob Smith"
    
    // Now set the employee ID
    empUnion.employeeID = 102; // This will overwrite the name
    printf("Union Employee Info after setting employee ID:\n");
    printf("Name: %s\n", empUnion.name); // This will be garbage or empty
    printf("Employee ID: %d\n", empUnion.employeeID); // Should show 102
    
    // Now set the salary
    empUnion.salary = 50000.00; // This will overwrite the employee ID
    printf("Union Employee Info after setting salary:\n");
    printf("Name: %s\n", empUnion.name); // This will still be garbage or empty
    printf("Employee ID: %d\n", empUnion.employeeID); // This will be garbage or empty
    printf("Salary: %.2f\n", empUnion.salary); // Should show 50000.00

    // Display values stored in the structure
    printf("\nStructure Employee Info:\n");
    printf("Name: %s\n", empStruct.name);
    printf("Employee ID: %d\n", empStruct.employeeID);
    printf("Salary: %.2f\n", empStruct.salary);
    printf("Size of EmployeeStruct: %zu bytes\n\n", sizeof(empStruct));

    // Display the size of the union
    printf("Size of EmployeeUnion: %zu bytes\n\n", sizeof(empUnion));

    // Memory size occupied by each
    printf("Memory size occupied by EmployeeStruct: %zu bytes\n", sizeof(empStruct));
    printf("Memory size occupied by EmployeeUnion: %zu bytes\n", sizeof(empUnion));

    return 0;
}