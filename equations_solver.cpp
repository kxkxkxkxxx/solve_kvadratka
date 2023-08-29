#include <assert.h>
#include <math.h>
#include "enums.h"
#include "equations_solver.h"
#include <stdlib.h>
#include <ctype.h>

int compare_b_with_c(double b, double c, int* compare_b_with_c_result)
{

    if(compare_variables( b, c) == 1 && compare_variables( 0.0, b) == 1)
        *compare_b_with_c_result = INFINITY_OF_ROOTS;

    else if(compare_variables( 0.0, b) == 1 && compare_variables( 0.0, c) == 0)
        *compare_b_with_c_result = NO_ROOTS;

    else
        *compare_b_with_c_result =  ONE_ROOT;

    return *compare_b_with_c_result;
}


int compare_discriminant_with_zero(double discriminant,
                                    int* discriminant_and_zero)
{

    if(compare_variables(0.0, discriminant) == 1)
        *discriminant_and_zero = EQUAL;

    if(discriminant < 0)
        *discriminant_and_zero = LESS;

    if(discriminant > 0)
        *discriminant_and_zero = GREATER;

    return *discriminant_and_zero;
 }


 int solver_equations(double a,  double b, double c,
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
            linear_equation_solution( b, c, &x_1, &x_2, &n_roots);

            *nRoots = n_roots;
            *x1 = x_1;
            *x2 = x_2;
        }
    }

    else
        *nRoots = SKIP;

    return *nRoots;
}


int compare_variables(double var_1, double var_2)
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
     case LESS :
            assert(discriminant_and_zero == LESS);

            *n_roots = NO_ROOTS;
            *x_1 = *x_2 = NAN;
            break;

     case EQUAL :
            assert(discriminant_and_zero == EQUAL);

            *n_roots = ONE_ROOT;
            *x_1 = - b / (2 * a);
            *x_2 = NAN;

            if(compare_variables(0.0, *x_1) == 1)
                *x_1 = 0.0;
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
}


int linear_equation_solution(double b, double c,
                             double* x_1,double* x_2, int* n_roots)
{
    int compare_b_with_c_result = 0;

    compare_b_with_c( b, c, &compare_b_with_c_result);

    switch(compare_b_with_c_result)
    {
        case NO_ROOTS :
            (*x_1) = NAN;
            (*x_2) = NAN;

            *n_roots = NO_ROOTS;
            break;

        case INFINITY_OF_ROOTS :
            (*x_1) = NAN;
            (*x_2) = NAN;

            *n_roots = INFINITY_OF_ROOTS;
            break;

        case ONE_ROOT :
            (*x_1) = (- c) / b;
            (*x_2) = NAN;

            if(compare_variables(0.0, *x_1) == 1)
                *x_1 = 0.0;

            *n_roots = ONE_ROOT;
            break;

        default : *n_roots = ERROR_SITUATION;
    }
    return *n_roots;
}
