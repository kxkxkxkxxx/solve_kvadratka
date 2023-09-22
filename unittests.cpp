#include "enums.h"
#include "equations_solver.h"
#include "unittests.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <TXLib.h>

int TestSqEq(const DO_SquareSolverTest test)      //объ€вить функцию
{
    double x1 = NAN, x2 = NAN;

    int n_passed_tests = 0;

    int nRoots = solver_equations(test.a, test.b, test.c, test.n_scanf, &x1, &x2, &nRoots);

    if(compare_variables(nRoots,test.nRoots_ref) != 1 || compare_variables(x1, test.x1_ref) != 1 ||
        compare_variables(x2, test.x2_ref) != 1)
    {
        printf("коэффициенты: a = %lf, b = %lf, c = %lf\n", test.a, test.b, test.c);
        printf("\tTEST FAILED :        x1 = %lf,x2 = %lf, nRoots = %d\n"
               "\tожидаемые значени€ : x1 = %lf,x2 = %lf, nRoots = %d\n", x1, x2, nRoots, test.x1_ref, test.x2_ref, test.nRoots_ref);

        n_passed_tests = 0;
    }
    else
    {
        printf("коэффициенты: a = %lf, b = %lf, c = %lf\n", test.a, test.b, test.c);
        printf("\tTEST COMPLETED\n");

        n_passed_tests = 1;
    }
    return n_passed_tests;
}

 int testAll()
 {
    DO_SquareSolverTest allData[] ={{.a = 1, .b = 0, .c = -4, .n_scanf = 3, .x1_ref = +2, .x2_ref = -2, .nRoots_ref = 2},
                                    {.a = 1, .b = -1, .c = 0, .n_scanf = 3, .x1_ref = 1, .x2_ref = 0, .nRoots_ref = 2}};

    size_t n_tests = sizeof(allData)/sizeof(allData[1]);
    size_t i = 0, n_passedtests = 0;

    printf("tests\n"
            "=============================================================================");

    for( i = 0; i < n_tests; ++i)
    {
        printf("\nTEST_%d\n", i+1);
        n_passedtests += TestSqEq(allData[i]);
    }

    printf("\n%u из %u успешно пройденных тестов\n"
            "=============================================================================\n", n_passedtests, n_tests);

    return 0;
}











