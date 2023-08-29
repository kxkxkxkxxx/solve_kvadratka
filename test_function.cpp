#include <assert.h>
#include <math.h>
#include "enums.h"
#include "equations_solver.h"
#include <stdlib.h>
#include "test_function.h"
#include <stdio.h>

double data_for_test[nTests][nVariables];


int compare_results(double a, double b, double c,double n_scanf, double x1ref, double x2ref)
{
    int nRoots = 0, n_passed_tests = 0;
    double x1 = NAN, x2 = NAN;

    solver_equations(a, b, c, n_scanf, &x1, &x2, &nRoots);

    if(compare_variables(x1, x1ref) == 1 || compare_variables(x2, x2ref) == 1)
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

    test_data_reader();
            sum_of_passed_tests += compare_results(data_for_test[nRow][0], data_for_test[nRow][1],
                                            data_for_test[nRow][2], data_for_test[nRow][3],
                                            data_for_test[nRow][4], data_for_test[nRow][5]);
    }
    printf("колличество успешных тестов : %d/%d\n", sum_of_passed_tests, nTests);
    return 1;
}


int test_data_reader()
{
    FILE *test_data_file;

    test_data_file = fopen("testData.txt", "r");

    int nRow = 0;

    for(; nRow < nTests; ++nRow)
    {

            fscanf(test_data_file, "%lf%lf%lf%lf%lf%lf",&data_for_test[nRow][0], &data_for_test[nRow][1],
                                                      &data_for_test[nRow][2], &data_for_test[nRow][3],
                                                      &data_for_test[nRow][4], &data_for_test[nRow][5]);
    }
return 0;
}

