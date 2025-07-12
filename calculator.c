#include <stdio.h>
#include <math.h>

// Simple Calculator
void simple_calculator() {
    double a, b;
    char op;
    printf("Enter expression (e.g., 4 + 5): ");
    scanf("%lf %c %lf", &a, &op, &b);
    switch(op) {
        case '+': printf("Result: %.2lf\n", a + b); break;
        case '-': printf("Result: %.2lf\n", a - b); break;
        case '*': printf("Result: %.2lf\n", a * b); break;
        case '/': 
            if(b != 0) printf("Result: %.2lf\n", a / b);
            else printf("Error: Division by zero.\n");
            break;
        case '%':
            printf("Result: %d\n", (int)a % (int)b);
            break;
        default: printf("Invalid operator.\n");
    }
}

// Quadratic Equation Solver
void quadratic_solver() {
    double a, b, c, discriminant, root1, root2;
    printf("Enter coefficients a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    discriminant = b*b - 4*a*c;
    if(discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2*a);
        root2 = (-b - sqrt(discriminant)) / (2*a);
        printf("Roots are real: %.2lf and %.2lf\n", root1, root2);
    } else if(discriminant == 0) {
        root1 = -b / (2*a);
        printf("Roots are equal: %.2lf\n", root1);
    } else {
        printf("Roots are imaginary.\n");
    }
}

// Matrix Addition
void matrix_addition() {
    int r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int a[r][c], b[r][c], sum[r][c];

    printf("Enter elements of first matrix:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d", &b[i][j]);

    printf("Sum of matrices:\n");
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

// Scientific Calculator
void scientific_calculator() {
    int choice;
    double value, value2;
    printf("1. sin\n2. cos\n3. tan\n4. sqrt\n5. power\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter value in degrees: ");
            scanf("%lf", &value);
            printf("sin(%.2lf) = %.2lf\n", value, sin(value * M_PI / 180));
            break;
        case 2:
            printf("Enter value in degrees: ");
            scanf("%lf", &value);
            printf("cos(%.2lf) = %.2lf\n", value, cos(value * M_PI / 180));
            break;
        case 3:
            printf("Enter value in degrees: ");
            scanf("%lf", &value);
            printf("tan(%.2lf) = %.2lf\n", value, tan(value * M_PI / 180));
            break;
        case 4:
            printf("Enter value: ");
            scanf("%lf", &value);
            if(value >= 0)
                printf("sqrt(%.2lf) = %.2lf\n", value, sqrt(value));
            else
                printf("Error: Negative value.\n");
            break;
        case 5:
            printf("Enter base and exponent: ");
            scanf("%lf %lf", &value, &value2);
            printf("%.2lf ^ %.2lf = %.2lf\n", value, value2, pow(value, value2));
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// Main Menu
int main() {
    int choice;
    do {
        printf("\n==== Multi Utility Calculator ====\n");
        printf("1. Simple Calculator\n");
        printf("2. Quadratic Equation Solver\n");
        printf("3. Matrix Addition\n");
        printf("4. Scientific Calculator\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: simple_calculator(); break;
            case 2: quadratic_solver(); break;
            case 3: matrix_addition(); break;
            case 4: scientific_calculator(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while(choice != 5);

    return 0;
}
