#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function prototypes
void simpleCalculator();
void quadraticSolver();
void matrixAddition();
void scientificCalculator();
void displayMenu();

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice (1-5, 0 to exit): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: simpleCalculator(); break;
            case 2: quadraticSolver(); break;
            case 3: matrixAddition(); break;
            case 4: scientificCalculator(); break;
            case 0: printf("\nThank you for using the calculator!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
        
        if(choice != 0) {
            printf("\nPress Enter to continue...");
            getchar(); // Consume newline
            getchar(); // Wait for user input
            // REMOVED system("clear") - Now output stays on screen
        }
    } while(choice != 0);
    
    return 0;
}

void displayMenu() {
    printf("\n========== MULTI-UTILITY CALCULATOR ==========\n");
    printf("1. Simple Calculator (+, -, *, /, %%)\n");
    printf("2. Quadratic Equation Solver\n");
    printf("3. Matrix Addition\n");
    printf("4. Scientific Calculator\n");
    printf("0. Exit\n");
    printf("===============================================\n");
}

// ========== 1. SIMPLE CALCULATOR ==========
void simpleCalculator() {
    double num1, num2, result;
    char operator;
    
    printf("\n--- SIMPLE CALCULATOR ---\n");
    printf("Enter expression (e.g., 5 + 3): ");
    scanf("%lf %c %lf", &num1, &operator, &num2);
    
    switch(operator) {
        case '+': 
            result = num1 + num2;
            printf("\n✅ %.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-': 
            result = num1 - num2;
            printf("\n✅ %.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*': 
            result = num1 * num2;
            printf("\n✅ %.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            if(num2 != 0) {
                result = num1 / num2;
                printf("\n✅ %.2lf / %.2lf = %.2lf\n", num1, num2, result);
            } else {
                printf("\n❌ Error: Division by zero!\n");
            }
            break;
        case '%':
            if((int)num2 != 0) {
                result = (int)num1 % (int)num2;
                printf("\n✅ %.0lf %% %.0lf = %.0lf\n", num1, num2, result);
            } else {
                printf("\n❌ Error: Modulo by zero!\n");
            }
            break;
        default:
            printf("\n❌ Invalid operator!\n");
    }
}

// ========== 2. QUADRATIC EQUATION SOLVER ==========
void quadraticSolver() {
    double a, b, c, discriminant, root1, root2, realPart, imagPart;
    
    printf("\n--- QUADRATIC EQUATION SOLVER ---\n");
    printf("Enter coefficients a, b, c (ax^2 + bx + c = 0): ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    if(a == 0) {
        printf("\n❌ This is not a quadratic equation (a cannot be 0)\n");
        return;
    }
    
    discriminant = b*b - 4*a*c;
    
    printf("\n📐 Equation: %.2lfx² + %.2lfx + %.2lf = 0\n", a, b, c);
    
    if(discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2*a);
        root2 = (-b - sqrt(discriminant)) / (2*a);
        printf("✅ Two distinct real roots:\n");
        printf("   Root 1 = %.2lf\n", root1);
        printf("   Root 2 = %.2lf\n", root2);
    } else if(discriminant == 0) {
        root1 = -b / (2*a);
        printf("✅ One repeated real root:\n");
        printf("   Root = %.2lf\n", root1);
    } else {
        realPart = -b / (2*a);
        imagPart = sqrt(-discriminant) / (2*a);
        printf("✅ Two complex roots:\n");
        printf("   Root 1 = %.2lf + %.2lfi\n", realPart, imagPart);
        printf("   Root 2 = %.2lf - %.2lfi\n", realPart, imagPart);
    }
}

// ========== 3. MATRIX ADDITION ==========
void matrixAddition() {
    int rows, cols, i, j;
    
    printf("\n--- MATRIX ADDITION ---\n");
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    
    int matrix1[rows][cols], matrix2[rows][cols], sum[rows][cols];
    
    printf("\n📊 Enter elements of FIRST matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("  Matrix1[%d][%d] = ", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }
    
    printf("\n📊 Enter elements of SECOND matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("  Matrix2[%d][%d] = ", i+1, j+1);
            scanf("%d", &matrix2[i][j]);
        }
    }
    
    // Adding matrices
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    printf("\n✅ Resultant Matrix (Sum):\n");
    printf("   ");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%5d ", sum[i][j]);
        }
        printf("\n   ");
    }
    printf("\n");
}

// ========== 4. SCIENTIFIC CALCULATOR ==========
void scientificCalculator() {
    int choice;
    double num, result, base, exponent;
    
    printf("\n--- SCIENTIFIC CALCULATOR ---\n");
    printf("1. Sine (sin)\n");
    printf("2. Cosine (cos)\n");
    printf("3. Tangent (tan)\n");
    printf("4. Square Root (sqrt)\n");
    printf("5. Power (x^y)\n");
    printf("6. Log10 (base 10)\n");
    printf("7. Natural Log (ln)\n");
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter angle in degrees: ");
            scanf("%lf", &num);
            result = sin(num * M_PI / 180);
            printf("\n✅ sin(%.2lf°) = %.6lf\n", num, result);
            break;
            
        case 2:
            printf("Enter angle in degrees: ");
            scanf("%lf", &num);
            result = cos(num * M_PI / 180);
            printf("\n✅ cos(%.2lf°) = %.6lf\n", num, result);
            break;
            
        case 3:
            printf("Enter angle in degrees: ");
            scanf("%lf", &num);
            result = tan(num * M_PI / 180);
            printf("\n✅ tan(%.2lf°) = %.6lf\n", num, result);
            break;
            
        case 4:
            printf("Enter a number: ");
            scanf("%lf", &num);
            if(num >= 0) {
                result = sqrt(num);
                printf("\n✅ sqrt(%.2lf) = %.6lf\n", num, result);
            } else {
                printf("\n❌ Error: Cannot calculate square root of negative number!\n");
            }
            break;
            
        case 5:
            printf("Enter base: ");
            scanf("%lf", &base);
            printf("Enter exponent: ");
            scanf("%lf", &exponent);
            result = pow(base, exponent);
            printf("\n✅ %.2lf ^ %.2lf = %.6lf\n", base, exponent, result);
            break;
            
        case 6:
            printf("Enter a number: ");
            scanf("%lf", &num);
            if(num > 0) {
                result = log10(num);
                printf("\n✅ log10(%.2lf) = %.6lf\n", num, result);
            } else {
                printf("\n❌ Error: Log10 of non-positive number!\n");
            }
            break;
            
        case 7:
            printf("Enter a number: ");
            scanf("%lf", &num);
            if(num > 0) {
                result = log(num);
                printf("\n✅ ln(%.2lf) = %.6lf\n", num, result);
            } else {
                printf("\n❌ Error: Natural log of non-positive number!\n");
            }
            break;
            
        default:
            printf("\n❌ Invalid choice!\n");
    }
}
