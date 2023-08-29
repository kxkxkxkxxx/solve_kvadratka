int compare_b_with_c(double b, double c, int* compare_b_with_c_result);

int compare_discriminant_with_zero(double discriminant,
                                    int* discriminant_and_zero);

int solver_equations(double a, double b, double c,
                        int n_scanf,double* x1, double* x2, int* nRoots);

int compare_variables(double var_1, double var_2);

int square_equation_solution(double a, double b, double c,
                             double* x_1, double* x_2, int* n_roots);

int linear_equation_solution(double b, double c,
                             double* x_1,double* x_2, int* n_roots);

