#include <stdio.h>
#include "enums.h"
#include "input_output.h"

int would_user_continue(int* iterationVariable)
{
    printf("желаете продолжить ?\n"
           "(введите 'y',чтобы продолжить)\n");

    if(getchar() == 'y')
       *iterationVariable = CONTINUE;
    else
       *iterationVariable = STOP;

    clear_buffer();
    return *iterationVariable;
}


int clear_buffer()
{
    while(getchar() != '\n')
        getchar();
    return 0;
}


int input(double* a, double* b, double* c, int* n_scanf)
{
    printf("введите коэффициенты a,b,c:\n");

    *n_scanf = scanf("%lf %lf %lf", &*a, &*b, &*c);

    if(*n_scanf != 3)
    {
        printf("данные введены некорректно\n");
        clear_buffer();
    }

    return *n_scanf;
}


void output_solver_equations(double x1, double x2, int nRoots)
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
}
