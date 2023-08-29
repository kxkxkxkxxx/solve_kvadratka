#include <assert.h>
#include <math.h>
#include "enums.h"
#include "solutions.h"
#include <stdlib.h>
#include "massive_test.h"
#include <stdio.h>

double data_for_test[nTests][nVariables] = {{0, 0, 0,3 ,12345.f, NAN},
                                           {0, 0, 1, 3, NAN, NAN},
                                           {0, 3, -9, 3, 3, NAN},
                                           {1, 2, 3, 3, NAN, NAN}};


int kvadratka_test(double a, double b, double c,double n_scanf, double x1ref, double x2ref) // TODO naming
{
    int nRoots = 0;
    double x1 = NAN, x2 = NAN;                                          //compare_variables(x1, x1ref) == 0 || compare_variables(x2, x2ref) == 0

    solver_equations(a, b, c, n_scanf, &x1, &x2, &nRoots);
                                                                           //if(x1 != x1ref || x2 != x2ref)
    if(compare_variables(x1, x1ref) == 0 || compare_variables(x2, x2ref) == 0)  // TODO
    {
        printf("TEST FAILED :        x1 = %.6lf,x2 = %lf\n"
               "ожидаемые значения : x1 = %lf,x2 = %lf\n", x1, x2, x1ref, x2ref);
        return 0;  // TODO use true/false
    }
    else
    {
        printf("тест прошел успешно\n");
        return 1;
    }
}

int kvadratka_test_result()    // TODO naming
{
    int nRow = 0, n_passed_tests = 0;

    for(; nRow < nTests; ++nRow)
    {

            n_passed_tests += kvadratka_test(data_for_test[nRow][0], data_for_test[nRow][1],
                                            data_for_test[nRow][2], data_for_test[nRow][3],
                                            data_for_test[nRow][4], data_for_test[nRow][5]);
    }
    printf("колличество успешных тестов : %d/4\n", n_passed_tests);
    return 1;
}



