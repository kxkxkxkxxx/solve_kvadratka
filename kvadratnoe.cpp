#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include "enums.h"
//#define NDEBUG
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include "solutions.h"
#include "input_output.h"

/*enum {
    CONTINUE = - 1,
    STOP = 0,
    TWO_ROOTS, //= 2,
    ONE_ROOT, //= 1,
    NO_ROOTS, //= - 1000,
    ERROR_SITUATION, //= 999,
    INFINITY_OF_ROOTS, //= 1000,
    SKIP, //= - 999,
    LESS, //= -11,
    EQUAL, //= 10,
    GREATER //= 11
};*/

//int compare_b_with_c(double b, double c, int* compare_b_with_c_result);

/*int compare_discriminant_with_zero(double discriminant,
                                    int* discriminant_and_zero);

int solver_equations(double a, double b, double c,
                        int n_scanf,double* x1, double* x2, int* nRoots);*/

//void output_solver_equations(double x1, double x2, int nRoots);

//int compare_variables(double var_1, double var_2);


//int input(double* a, double* b, double* c, int* n_scanf);

//int clear_buffer();

//int would_user_continue(int* iterationVariable);

/*int square_equation_solution(double a, double b, double c,
                             double* x_1, double* x_2, int* n_roots);

int linear_equation_solution(double b, double c,
                             double* x_1, int* n_roots);*/


int main()
{
    printf("квадратное уравнение в общем виде: a*x^2+b*x+c=0\n");

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int iterationVariable = 0, nRoots = 0, n_scanf = 0;

    for(; iterationVariable < 1; ++iterationVariable)
    {
        input(&a, &b, &c, &n_scanf);

        solver_equations(a, b, c, n_scanf, &x1, &x2, &nRoots);
        output_solver_equations(x1, x2, nRoots);


        clear_buffer();

        would_user_continue(&iterationVariable);

        clear_buffer();
    }

    return 0;
}



/*int would_user_continue(int* iterationVariable)
{
    printf("желаете продолжить ?\n"
           "(введите 'y',чтобы продолжить)\n");

    if(getchar() == 'y')
       *iterationVariable = CONTINUE;
    else
       *iterationVariable = STOP;

    clear_buffer();
    return *iterationVariable;
}*/


/*int clear_buffer()
{
    while(getchar() != '\n')
        getchar();
    return 0;
}*/


/*int input(double* a, double* b, double* c, int* n_scanf)
{
    printf("введите коэффициенты a,b,c:\n");

    *n_scanf = scanf("%lf %lf %lf", &*a, &*b, &*c);

    if(*n_scanf != 3)
    {
        printf("данные введены некорректно\n");
        clear_buffer();
    }

    return *n_scanf;
}*/



/*int solver_equations(double a,  double b, double c,
                        int n_scanf, double* x1, double* x2, int* nRoots)
{
    int n_roots = 0;
    double x_1 = NAN, x_2 = NAN;

    if(n_scanf == 3)
    {
        if(compare_variables(0.0, a) == 0)
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
    }

    else
        *nRoots = SKIP;

    return *nRoots;
}*/



/*int compare_variables(double var_1, double var_2)
{
    int is_variables_equal = 0;
    const double compare_const = 0.000001;

    if(fabs(var_1 - var_2) < compare_const)
    {
        is_variables_equal = 1;
    }

    else
    {
        assert(is_variables_equal == 0);
        is_variables_equal = 0;
    }
    return is_variables_equal;
}    */




/*void output_solver_equations(double x1, double x2, int nRoots)
{
    switch(nRoots)
    {
        case NO_ROOTS :
            printf("действительных корней нет\n");
            break;

        case ONE_ROOT :
            printf("уравнение имеет 1 корень : x_1 = %lf\n", x1);
            break;

        case TWO_ROOTS :
            printf("уравнение имеет 2 корня : x_1 = %lf, x_2 = %lf\n", x1, x2);
            break;

        case INFINITY_OF_ROOTS :
            printf("уравнение имеет бесконечное колличество решений \n");
            break;

        case SKIP :
            break;

        case ERROR_SITUATION :
            printf("так быть не должно!!!\n");
            break;

        default :
            printf("что-то пошло не так\n");
    }
return ;
}*/


/*int compare_discriminant_with_zero(double discriminant,
                                    int* discriminant_and_zero)
{

    if(compare_variables(0.0, discriminant) == 1)
        *discriminant_and_zero = EQUAL;

    if(discriminant < 0)
        *discriminant_and_zero = LESS;

    if(discriminant > 0)
        *discriminant_and_zero = GREATER;

    return *discriminant_and_zero;
 } */


/*int square_equation_solution(double a, double b, double c,
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
     case LESS :
            assert(discriminant_and_zero == LESS);
            *n_roots = NO_ROOTS;
            *x_1 = *x_2 = NAN;
            break;

     case EQUAL :
            assert(discriminant_and_zero == EQUAL);
            *n_roots = ONE_ROOT;
            *x_1 = - b / (2 * a);
            break;


     case GREATER :
            assert(discriminant_and_zero == GREATER);
            *n_roots = TWO_ROOTS;

            square_root_discriminant = sqrt(discriminant);
            *x_1 = (- b + square_root_discriminant) / (2 * a);
            *x_2 = (- b - square_root_discriminant) / (2 * a);
            break;

     default :
                *n_roots = ERROR_SITUATION;

    }
    return *n_roots;
}           */



/*int linear_equation_solution(double b, double c,
                             double* x_1, int* n_roots)
{
    int compare_b_with_c_result = 0;

    compare_b_with_c( b, c, &compare_b_with_c_result);

    switch(compare_b_with_c_result)
    {
        case NO_ROOTS :
            (*x_1) = NAN;
            *n_roots = NO_ROOTS;
            break;

        case INFINITY_OF_ROOTS :
            (*x_1) = 12345.f;
            *n_roots = INFINITY_OF_ROOTS;
            break;

        case ONE_ROOT :
            (*x_1) = (- c) / b;

            if(compare_variables(0.0, *x_1) == 1)
                *x_1 = 0.0;

            *n_roots = ONE_ROOT;
            break;

        default : *n_roots = ERROR_SITUATION;
    }
    return *n_roots;
} */



/*int compare_b_with_c(double b, double c, int* compare_b_with_c_result)
{

    if(compare_variables( b, c) == 1 && compare_variables( 0.0, b) == 1)
        *compare_b_with_c_result = INFINITY_OF_ROOTS;

    else if(compare_variables( 0.0, b) == 1 && compare_variables( 0.0, c) == 0)
        *compare_b_with_c_result = NO_ROOTS;

    else
        *compare_b_with_c_result =  ONE_ROOT;

    return *compare_b_with_c_result;
}*/
