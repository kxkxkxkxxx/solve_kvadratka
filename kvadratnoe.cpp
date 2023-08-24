#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
//#include "solutions.h"
//#include "input_output.h"

enum iteration_variable {
    CONTINUE = -1,
    STOP = 0
};

enum n_roots {
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
};

int compare_b_with_c(double b, double c);

int compare_discriminant_with_zero(double discriminant);

int solver_equations(double a, double b, double c,
                     double* x_1, double* x_2, int n_scanf, int* n_roots);
void output_solver_equations(double x_1, double x_2, int n_roots);

int compare_variables(double var_1, double var_2);

/*int compare_c_(double c);
int compare_a(double a);
int compare_b(double b);
int compare_c(double c);
int compare_discriminant(double discriminant);*/

double input(double* a, double* b, double* c, int* n_scanf);

int clear_buffer();
int would_user_continue(int* iteration_variable);

int square_equation_solution(double a, double b, double c,
                                double* x_1, double* x_2, int* n_roots);

int linear_equation_solution(double b, double c,
                                double* x_1, int* n_roots);

//int output_square_solution(double x_1, double x_2, int n_roots);

//int output_linear_solution(double x_1, int n_roots);

int main()
{
    printf("квадратное уравнение в общем виде: a*x^2+b*x+c=0\n");

    double a = NAN, b = NAN, c = NAN, x_1 = NAN, x_2 = NAN;
    int iteration_variable = 0, n_roots = 0, n_scanf = 0;

    for(; iteration_variable < 1; ++iteration_variable)
    {
        input(&a, &b, &c, &n_scanf);

        solver_equations(a, b, c, &x_1, &x_2, n_scanf, &n_roots);
        output_solver_equations(x_1, x_2, n_roots);

        clear_buffer();

        would_user_continue(&iteration_variable);
        clear_buffer();
    }
    /*for(; iteration_variable < 1; ++iteration_variable)
    {
        printf("введите коэффициенты a,b,c:\n");
        int n_scanf = 0;                        //добавил в input()

        input( &a, &b, &c, &n_scanf);

        assert(n_scanf == 3); //добавил в solver_equation()

        if(compare_a(a)) // TODO move to solve function
        {
            square_equation_solution(a, b, c, &x_1, &x_2, &n_roots);
            output_square_solution(x_1, x_2, n_roots);

            clear_buffer();
        }
        else
        {
            linear_equation_solution( b, c, &x_1, &n_roots);
            output_linear_solution(x_1, n_roots);

            clear_buffer();
        }

        would_user_continue(&iteration_variable);
        clear_buffer();
    }  */

    return 0;
}

/*
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

    if(compare_discriminant(discriminant)) // triple comparasion
    {
        *x_1 = - b / (2 * a);
        *n_roots = 1;

        return *n_roots; //TODO return int
    }
    else if(discriminant > 0.0)
    {
        double square_root_discriminant = NAN;

        square_root_discriminant = sqrt(discriminant);
        *x_1 = (- b + square_root_discriminant) / (2 * a);
        *x_2 = (- b - square_root_discriminant) / (2 * a);
        *n_roots = 2;

        return *n_roots;
    }
    else
    {   *x_1 = *x_2 = NAN;
        *n_roots = 0;

        return *n_roots;
    }
}



int linear_equation_solution(double b, double c,
                                double* x_1, int* n_roots)
{
    if(compare_b(b) && compare_c(c))
    {
        *x_1 = ;
        *n_roots = 2; // TODO use enum for n roots

        return *n_roots;
    }
    else if(compare_b(b) && compare_c_(c)) // TODO naming
    {
        *x_1 = -1;
        *n_roots = 0;

        return *n_roots;
    }
    else
    {
        *x_1 = - c / b;
        *n_roots = 1;

        return *n_roots;
    }
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


double input(double* a, double* b, double* c, int* n_scanf)
{
    printf("введите коэффициенты a,b,c:\n");
    int n_scanf = 0;

    *n_scanf = scanf("%lf %lf %lf", &*a, &*b, &*c);

    if(*n_scanf != 3)
    {
        clear_buffer();
        printf("данные введены некорректно\n");

        would_user_continue(&iteration_variable);
        clear_buffer();
    }
    return *n_scanf;
}


int compare_a(double num1, num2)      // TODO
{
    int is_a_zero = 1;

    if(fabs(num1 - num2) < 0.000001) // TODO make constant
        is_a_zero = 1;
    else
        is_a_zero = 0;

    return is_a_zero;
}


int compare_b(double b)
{
    int is_b_zero = 1;

    if(fabs(b) < 0.000001)
        is_b_zero = 1;
    else
        is_b_zero = 0;

    return is_b_zero;
}


int compare_c(double c)
{
    int is_c_zero = 1;

    if(fabs(c) < 0.000001)
        is_c_zero = 1;
    else
        is_c_zero = 0;

    return is_c_zero;
}


int compare_c_(double c)
{
    int is_c_zero = 1;

    if(fabs(c) > 0.000001)
        is_c_zero = 1;
    else
        is_c_zero = 0;

    return is_c_zero;
}


int compare_discriminant(double discriminant)
{
    int is_d_zero = 1;

    if(fabs(discriminant) < 0.000001)
        is_d_zero = 1;
    else
        is_d_Zero = 0;

    return is_d_zero;
}


int output_square_solution(double x_1, double x_2, int n_roots)   // unite to one output function
{
    switch(n_roots)
    {
        case 0 : printf("действительных  корней уравнения нет\n");
                 break;
        case 1 : printf("уравнение имеет 1 корень : x_1 = %lf\n", x_1);
                 break;
        case 2 : printf("уравнение имеет 2 корня : x_1 = %lf, x_2 = %lf \n", x_1, x_2);
                 break;
                 default :
                    printf("что-то пошло не так...");
    }
    return 0;
}


int output_linear_solution(double x_1, int n_roots)
{
    switch(n_roots)
    {
        case 0 : printf("корней нет \n");
                 break;
        case 1 : printf("уравнение сводится к линейному и имеет 1 корень : x_1 = %lf\n", x_1);
                 break;
        case 2 : printf("уравнение имеет бесконечное колличество корней \n");
                 break;
                 default :
                    printf("что-то пошло не так...");
    }
    return 0;
}
*/

int solver_equations(double a,  double b, double c,
                     double* x_1, double* x_2, int n_scanf, int* n_roots)
{
    assert(n_scanf == 3);

    if(compare_variables(0.0, a) == YES)
        square_equation_solution(a, b, c, &x_1, &x_2, &n_roots);
    else
        linear_equation_solution( b, c, &x_1, &n_roots);

    return *n_roots;
}




int compare_variables(double var_1, double var_2)
{
    int is_vaiables_equal = 0;
    const double compare_const = 0.000001;

    assert(fabs(var_1 - var_2) < compare_const);

    if(fabs(var_1 - var_2) < compare_const)
        is_variables_equal = YES;

    else
        is_variables_equal = NO;

    return is_variables_equal;
}




void output_solver_equations(double x_1, double x_2, int n_roots)
{
    switch(n_roots)
    {
        case 0 : printf("действительных корней нет\n");
                 break;

        case 1 : printf("уравнение имеет 1 корень : x_1 = %lf\n", x_1);
                 break;

        case 2 : printf("уравнение имеет 2 корня : x_1 = %lf, x_2 = %lf\n", x_1, x_2);
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

int compare_discriminant_with_zero(double discriminant)
{
    if(compare_values(0.0, discriminant) == YES)
       return discriminant_and_zero = EQUAL;

    if(discriminant < 0)
       return discriminant_and_zero = LESS;

    if(discriminant > 0)
        return discriminant_and_zero = GREATER;
 }


int square_equation_solution(double a, double b, double c,
                             double* x_1, double* x_2, int* n_roots, int* n_scanf)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x_1 != NULL);
    assert(x_2 != NULL);
    assert(x_1 != x_2);

    double discriminant = NAN;
    discriminant = b * b - 4 * a * c;

    compare_discriminant_with_zero(discriminant)

    switch(is_discriminant_zero)
    {
     case -1 : assert(is_discriminant_zero == -1);
               *n_roots = 0;
               *x_1 = *x_2 = NAN;
               break;

     case 0 :  assert(is_discriminant_zero == 0);
               *n_roots = 1;
               *x_1 = - b / (2 * a);
               break;

     case 1 :  assert(is_discriminant_zero == 1);
               *n_roots = 2;
               double square_root_discriminant = NAN;
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
    compare_b_with_c( b, c);

    switch(compare_b_with_c_result);
    {
        case - 1 : assert(compare_b_with_c_result == -1)
                   *x_1 = NAN;
                   *n_roots = 0;
                   break;

        case 0 : assert(compare_b_with_c_result == 0)
                 *x_1 = 12345;
                 *n_roots = INFINITY;
                 break;

        case 1 : assert(compare_b_with_c_result == 1)
                 *x_1 = - c / b;
                 *n_roots = 1;
                 break;

        default : *n_roots = 999;
    }
    return *n_roots;
}



int compare_b_with_c(double b, double c)
{                                             //возможно потом введу enum'ы
    int compare_b_with_c_result = 0;

    if(compare_variables( b, c) == YES)
        compare_b_with_c_result = 0;//тогда у нас бессконечное колличество корней

    else if(compare_variables( 0.0, b) == YES && compare_variables( 0.0, c) == NO)
      compare_b_with_c_result = - 1; //корней не будет

    else
      compare_b_with_c_result = 1;   //1 корень

     return compare_b_with__result;
}
