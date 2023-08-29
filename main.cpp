#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include "enums.h"
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include "solutions.h"
#include "input_output.h"
#include "massive_test.h"

int main()
{
    printf("квадратное уравнение в общем виде: a*x^2+b*x+c=0\n");

    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int iterationVariable = 0, nRoots = 0, n_scanf = 0;

    kvadratka_test_result();   // TODO conditional compilation #ifdef/#ifndef

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
