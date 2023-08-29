#include <assert.h>
#include <math.h>
#include "enums.h"
#include "equations_solver.h"
#include <stdlib.h>
#include "test_function.h"
#include <stdio.h>

double data_for_test[nTests][nVariables] = {{0, 0, 0,3 ,NAN, NAN},
                                           {0, 0, 1, 3, NAN, NAN},
                                           {0, 3, -9, 3, 3, NAN},
                                           {1, 2, 3, 3, NAN, NAN}};


int compare_results(double a, double b, double c,double n_scanf, double x1ref, double x2ref) // TODO naming
{
    int nRoots = 0, n_passed_tests = 0;
    double x1 = NAN, x2 = NAN;                                          //compare_variables(x1, x1ref) == 0 || compare_variables(x2, x2ref) == 0

    solver_equations(a, b, c, n_scanf, &x1, &x2, &nRoots);
                                                                           //if(x1 != x1ref || x2 != x2ref)
    if(compare_variables(x1, x1ref) == 1 || compare_variables(x2, x2ref) == 1)  // TODO
    {
        printf("TEST FAILED :        x1 = %.6lf,x2 = %lf\n"
               "ожидаемые значения : x1 = %lf,x2 = %lf\n", x1, x2, x1ref, x2ref);

        n_passed_tests = 0;
    }
    else
    {
        printf("тест прошел успешно\n");

        n_passed_tests = 1;
    }

    return n_passed_tests;
}

int program_testing()
{
    int nRow = 0, sum_of_passed_tests = 0;

    for(; nRow < nTests; ++nRow)
    {

            sum_of_passed_tests += compare_results(data_for_test[nRow][0], data_for_test[nRow][1],
                                            data_for_test[nRow][2], data_for_test[nRow][3],
                                            data_for_test[nRow][4], data_for_test[nRow][5]);
    }
    printf("колличество успешных тестов : %d/4\n", sum_of_passed_tests);
    return 1;
}



