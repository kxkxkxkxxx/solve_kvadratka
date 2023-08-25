#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
//#include "solutions.h"
//#include "input_output.h"

enum iteration_variable {
    CONTINUE = -1,
    STOP = 0
};

/*enum n_roots {
    INFINITY = 10000
};

enum discriminant_and_zero {
    LESS = -1,
    EQUAL = 0,
    GREATER = 1
};

enum is_variables_equal {
    YES = 1,
    NO = 0
};*/

int compare_b_with_c(double b, double c, int* compare_b_with_c_result);

int compare_discriminant_with_zero(double discriminant, int* discriminant_and_zero);

int solver_equations(double a, double b, double c, int n_scanf,double* x1, double* x2, int* nRoots);

void output_solver_equations(double x1, double x2, int nRoots);

int compare_variables(double var_1, double var_2);


double input(double* a, double* b, double* c, int* n_scanf, int* iterationVariable);

int clear_buffer();
int would_user_continue(int* iteration_variable);

int square_equation_solution(double a, double b, double c,
                             double* x_1, double* x_2, int* n_roots);

int linear_equation_solution(double b, double c,
                             double* x_1, int* n_roots);


int main()
{
    printf("квадратное уравнение в общем виде: a*x^2+b*x+c=0\n");

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int iterationVariable = 0, nRoots = 0, n_scanf = 0;
    int iteration_variable = 0;

    for(; iterationVariable < 1; ++iterationVariable)
    {
        input(&a, &b, &c, &n_scanf, &iterationVariable);

        solver_equations(a, b, c, n_scanf, &x1, &x2, &nRoots);
        output_solver_equations(x1, x2, nRoots);

        clear_buffer();

        would_user_continue(&iteration_variable);

        iterationVariable = iteration_variable;

        clear_buffer();
    }

    return 0;
}



int would_user_continue(int* iteration_variable)
{
    printf("желаете продолжить ?\n"
           "(введите 'y',чтобы продолжить)\n");

    if(getchar() == 'y')
       *iteration_variable = CONTINUE;
    else
       *iteration_variable = STOP;

    clear_buffer();
    return *iteration_variable;
}


int clear_buffer()
{
    while(getchar() != '\n')
        getchar();
    return 0;
}


double input(double* a, double* b, double* c, int* n_scanf, int* iterationVariable)
{
    printf("введите коэффициенты a,b,c:\n");

    *n_scanf = scanf("%lf %lf %lf", &*a, &*b, &*c);
    int iteration_variable = 0;
    if(*n_scanf != 3)
    {
        clear_buffer();
        printf("данные введены некорректно\n");

        would_user_continue(&iteration_variable);
        *iterationVariable = iteration_variable;
        clear_buffer();
    }
    return *n_scanf;
}



int solver_equations(double a,  double b, double c, int n_scanf, double* x1, double* x2, int* nRoots)
{
    assert(n_scanf == 3);

    int n_roots = 0;
    double x_1 = NAN, x_2 = NAN;

    if(compare_variables(0.0, a) == 1) //yes
    {
        square_equation_solution(a, b, c, &x_1, &x_2, &n_roots);

        *x1 = x_1;
        *x2 = x_2;

        *nRoots = n_roots;
    }

    else
    {
        linear_equation_solution( b, c, &x_1, &n_roots);

        *nRoots = n_roots;
        *x1 = x_1;
    }

    return *nRoots;
}



int compare_variables(double var_1, double var_2)
{
    int is_variables_equal = 0;
    const double compare_const = 0.000001;

    assert(fabs(var_1 - var_2) < compare_const);

    if(fabs(var_1 - var_2) < compare_const)
        is_variables_equal = 1; //yes

    else
        is_variables_equal = 0; //no

    return is_variables_equal;
}




void output_solver_equations(double x1, double x2, int nRoots)
{
    switch(nRoots)
    {
        case 0 : printf("действительных корней нет\n");
                 break;

        case 1 : printf("уравнение имеет 1 корень : x_1 = %lf\n", x1);
                 break;

        case 2 : printf("уравнение имеет 2 корня : x_1 = %lf, x_2 = %lf\n", x1, x2);
                 break;

        case 10000 :
                 printf("уравнение имеет бесконечное колличество решений \n");
                 break;

        case 999: printf("так быть не должно!!!\n");
                  break;

        default : printf("что-то пошло не так\n");
    }
return ;
}

int compare_discriminant_with_zero(double discriminant, int* discriminant_and_zero)
{

    if(compare_variables(0.0, discriminant) == 1) //yes
        *discriminant_and_zero = 0; //equal

    if(discriminant < 0)
        *discriminant_and_zero = -1; //less

    if(discriminant > 0)
        *discriminant_and_zero = 1; //greater

    return *discriminant_and_zero;
 }


int square_equation_solution(double a, double b, double c,
                             double* x_1, double* x_2, int* n_roots)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x_1 != NULL);
    assert(x_2 != NULL);
    assert(x_1 != x_2);

    double discriminant = NAN;
    discriminant = b * b - 4 * a * c;

    int discriminant_and_zero = 0;

    double square_root_discriminant = NAN;

    compare_discriminant_with_zero(discriminant, &discriminant_and_zero);

    switch(discriminant_and_zero)
    {
     case -1 : assert(discriminant_and_zero == -1);
               *n_roots = 0;
               *x_1 = *x_2 = NAN;
               break;

     case 0 :  assert(discriminant_and_zero == 0);
               *n_roots = 1;
               *x_1 = - b / (2 * a);
               break;

     case 1 :  assert(discriminant_and_zero == 1);
               *n_roots = 2;

               square_root_discriminant = sqrt(discriminant);
               *x_1 = - b + square_root_discriminant;
               *x_2 = - b - square_root_discriminant;
               break;

               default : *n_roots = 999;
    }
    return *n_roots;
}



int linear_equation_solution(double b, double c,
                             double* x_1, int* n_roots)
{
    int compare_b_with_c_result = 0;

    compare_b_with_c( b, c, &compare_b_with_c_result);

    switch(compare_b_with_c_result)
    {
        case - 1 : assert(compare_b_with_c_result == -1)
                   *x_1 = NAN;
                   *n_roots = 0;
                   break;

        case 0 : assert(compare_b_with_c_result == 0)
                 *x_1 = 12345;
                 *n_roots = 10000; //infinity
                 break;

        case 1 : assert(compare_b_with_c_result == 1)
                 *x_1 = - c / b;
                 *n_roots = 1;
                 break;

        default : *n_roots = 999;
    }
    return *n_roots;
}



int compare_b_with_c(double b, double c, int* compare_b_with_c_result)
{

    if(compare_variables( b, c) == 1)  //yes
        *compare_b_with_c_result = 0;//тогда у нас бессконечное колличество корней

    else if(compare_variables( 0.0, b) == 1 && compare_variables( 0.0, c) == 0)  //yes no
        *compare_b_with_c_result = - 1; //корней не будет

    else
        *compare_b_with_c_result = 1;   //1 корень

     return *compare_b_with_c_result;
}
