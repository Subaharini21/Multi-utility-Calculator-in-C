# Multi-utility-Calculator-System-in-C
Mini-Project in C with simple, matrix, quadratic and scientific calculators

#include <stdio.h>
#include <math.h>

//  Simple Calculator
void simpleCalculator() {
    int choice;
    float a, b, result;
    printf("\nSimple Calculator:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\nEnter your choice: ");
    scanf("%d", &choice);
    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    switch(choice) {
        case 1: result = a + b; printf("Result: %.2f\n", result); break;
        case 2: result = a - b; printf("Result: %.2f\n", result); break;
        case 3: result = a * b; printf("Result: %.2f\n", result); break;
        case 4: 
            if(b != 0)
                result = a / b;
            else {
                printf("Error: Division by zero.\n");
                return;
            }
            printf("Result: %.2f\n", result); 
            break;
        case 5: printf("Result: %d\n", (int)a % (int)b); break;
        default: printf("Invalid choice.\n");
    }
}

// Matrix Calculator
void matrixCalculator() {
    int a[10][10], b[10][10], c[10][10], r, col, i, j, k, choice;
    printf("\nMatrix Calculator:\n");
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &col);
    printf("Enter elements of first matrix:\n");
    for(i=0;i<r;i++)
        for(j=0;j<col;j++)
            scanf("%d", &a[i][j]);
    printf("Enter elements of second matrix:\n");
    for(i=0;i<r;i++)
        for(j=0;j<col;j++)
            scanf("%d", &b[i][j]);
    printf("1. Addition\n2. Subtraction\n3. Multiplication\nEnter your choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        for(i=0;i<r;i++)
            for(j=0;j<col;j++)
                c[i][j] = a[i][j] + b[i][j];
    } else if(choice == 2) {
        for(i=0;i<r;i++)
            for(j=0;j<col;j++)
                c[i][j] = a[i][j] - b[i][j];
    } else if(choice == 3) {
        for(i=0;i<r;i++)
            for(j=0;j<col;j++) {
                c[i][j] = 0;
                for(k=0;k<col;k++)
                    c[i][j] += a[i][k] * b[k][j];
            }
    } else {
        printf("Invalid choice.\n");
        return;
    }

    printf("Resultant matrix:\n");
    for(i=0;i<r;i++) {
        for(j=0;j<col;j++)
            printf("%d ", c[i][j]);
        printf("\n");
    }
}

//  Quadratic Equation Calculator
void quadraticCalculator() {
    float a, b, c, discriminant, root1, root2, realPart, imagPart;
    printf("\nQuadratic Equation Calculator:\n");
    printf("Enter coefficients a, b and c: ");
    scanf("%f %f %f", &a, &b, &c);
    discriminant = b*b - 4*a*c;
    if(discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2*a);
        root2 = (-b - sqrt(discriminant)) / (2*a);
        printf("Roots are real and distinct: %.2f and %.2f\n", root1, root2);
    } else if(discriminant == 0) {
        root1 = root2 = -b / (2*a);
        printf("Roots are real and equal: %.2f and %.2f\n", root1, root2);
    } else {
        realPart = -b / (2*a);
        imagPart = sqrt(-discriminant) / (2*a);
        printf("Roots are complex: %.2f + %.2fi and %.2f - %.2fi\n", realPart, imagPart, realPart, imagPart);
    }
}

// Scientific Calculator
void scientificCalculator() {
    int choice;
    double x, y, result;
    printf("\nScientific Calculator:\n");
    printf("1. sin(x)\n2. cos(x)\n3. tan(x)\n4. log(x)\n5. exp(x)\n6. power(x,y)\nEnter your choice: ");
    scanf("%d", &choice);
    if(choice == 6) {
        printf("Enter base (x) and exponent (y): ");
        scanf("%lf %lf", &x, &y);
    } else {
        printf("Enter value of x: ");
        scanf("%lf", &x);
    }
    switch(choice) {
        case 1: result = sin(x * M_PI / 180); printf("Result: %.4f\n", result); break;
        case 2: result = cos(x * M_PI / 180); printf("Result: %.4f\n", result); break;
        case 3: result = tan(x * M_PI / 180); printf("Result: %.4f\n", result); break;
        case 4: result = log(x); printf("Result: %.4f\n", result); break;
        case 5: result = exp(x); printf("Result: %.4f\n", result); break;
        case 6: result = pow(x, y); printf("Result: %.4f\n", result); break;
        default: printf("Invalid choice.\n");
    }
}

// Main function with menu
int main() {
    int choice;
    while(1) {
        printf("\n********* Calculator System *********\n");
        printf("1. Simple Calculator\n2. Matrix Calculator\n3. Quadratic Equation Calculator\n4. Scientific Calculator\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: simpleCalculator(); break;
            case 2: matrixCalculator(); break;
            case 3: quadraticCalculator(); break;
            case 4: scientificCalculator(); break;
            case 5: printf("Exiting Calculator System.\n"); return 0;
            default: printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
