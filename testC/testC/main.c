#include <stdio.h>
#include <math.h>
#include <time.h>

#define M_PI 3.14159265358979323846

struct __pyx_opt_args_6Clogic_6Clogic_normal_distributionC;
struct __pyx_opt_args_6Clogic_6Clogic_F;
struct __pyx_opt_args_6Clogic_6Clogic_calculate;
struct __pyx_ctuple_float__and_float__and_float;
typedef struct __pyx_ctuple_float__and_float__and_float __pyx_ctuple_float__and_float__and_float;


struct __pyx_opt_args_6Clogic_6Clogic_normal_distributionC {
    int __pyx_n;
    float nx;
    float o;
};
struct __pyx_opt_args_6Clogic_6Clogic_F {
    int __pyx_n;
    int n;
};
struct __pyx_opt_args_6Clogic_6Clogic_calculate {
    int __pyx_n;
    int n;
};
struct __pyx_ctuple_float__and_float__and_float {
    float f0;
    float f1;
    float f2;
};


static float __pyx_f_6Clogic_6Clogic_normal_distributionC(float, struct __pyx_opt_args_6Clogic_6Clogic_normal_distributionC* __pyx_optional_args);
static float __pyx_f_6Clogic_6Clogic_F(float, struct __pyx_opt_args_6Clogic_6Clogic_F* __pyx_optional_args);
static __pyx_ctuple_float__and_float__and_float __pyx_f_6Clogic_6Clogic_calculate(float, float, float, float, int __pyx_skip_dispatch, struct __pyx_opt_args_6Clogic_6Clogic_calculate* __pyx_optional_args); 


static float __pyx_f_6Clogic_6Clogic_normal_distributionC(float __pyx_v_x, struct __pyx_opt_args_6Clogic_6Clogic_normal_distributionC* __pyx_optional_args) {
    float __pyx_v_nx = ((float)0.0);
    float __pyx_v_o = ((float)1.0);
    float __pyx_r;
    double __pyx_t_1;
    float __pyx_t_2;
    int __pyx_lineno = 0;
    const char* __pyx_filename = NULL;
    int __pyx_clineno = 0;
    if (__pyx_optional_args) {
        if (__pyx_optional_args->__pyx_n > 0) {
            __pyx_v_nx = __pyx_optional_args->nx;
            if (__pyx_optional_args->__pyx_n > 1) {
                __pyx_v_o = __pyx_optional_args->o;
            }
        }
    }

    __pyx_t_1 = (__pyx_v_o * sqrt((2.0 * M_PI)));
    __pyx_t_2 = (__pyx_v_x - __pyx_v_nx);
    __pyx_r = ((1.0 / __pyx_t_1) * exp((-0.5 * powf((__pyx_t_2 / __pyx_v_o), 2.0))));


    return __pyx_r;
}

static float __pyx_f_6Clogic_6Clogic_F(float __pyx_v_b, struct __pyx_opt_args_6Clogic_6Clogic_F* __pyx_optional_args) {
    int __pyx_v_n = ((int)0x2710);
    int __pyx_v_a;
    float __pyx_v_dx;
    float __pyx_v_sum;
    float __pyx_v_xi;
    int __pyx_v_i;
    float __pyx_r;
    float __pyx_t_1;
    int __pyx_t_2;
    int __pyx_t_3;
    int __pyx_t_4;
    int __pyx_lineno = 0;
    const char* __pyx_filename = NULL;
    int __pyx_clineno = 0;
    if (__pyx_optional_args) {
        if (__pyx_optional_args->__pyx_n > 0) {
            __pyx_v_n = __pyx_optional_args->n;
        }
    }

    __pyx_v_a = 0;
    __pyx_t_1 = (__pyx_v_b - __pyx_v_a);

    __pyx_v_dx = (__pyx_t_1 / ((float)__pyx_v_n));

    __pyx_v_sum = 0.0;


    __pyx_t_2 = __pyx_v_n;
    __pyx_t_3 = __pyx_t_2;
    for (__pyx_t_4 = 0; __pyx_t_4 < __pyx_t_3; __pyx_t_4 += 1) {
        __pyx_v_i = __pyx_t_4;


        __pyx_v_xi = (__pyx_v_a + (__pyx_v_i * __pyx_v_dx));

        __pyx_t_1 = __pyx_f_6Clogic_6Clogic_normal_distributionC(__pyx_v_xi, NULL);
        __pyx_v_sum = (__pyx_v_sum + (__pyx_t_1 * __pyx_v_dx));
    }

    __pyx_r = __pyx_v_sum;

    return __pyx_r;
}




float normal_distribution(float x, float nx, float o) {
    return (1 / (o * sqrt(2 * M_PI))) * exp(-0.5 * pow(((x - nx) / o), 2));
}

float F(float b, int n) {
    int a = 0;
    float dx = (b - a) / (float)n;
    float sum = 0;

    float xi;
    for (int i = 0; i < n; i++) {
        xi = a + i * dx;
        struct __pyx_opt_args_6Clogic_6Clogic_normal_distributionC __pyx_args = { .__pyx_n = n, .nx = 0, .o = 1 };
        sum += __pyx_f_6Clogic_6Clogic_normal_distributionC(xi, &__pyx_args) * dx;
    }

    return sum;
}

static __pyx_ctuple_float__and_float__and_float __pyx_f_6Clogic_6Clogic_calculate(float __pyx_v_ei, float __pyx_v_es, float __pyx_v_nx, float __pyx_v_o, struct __pyx_opt_args_6Clogic_6Clogic_calculate* __pyx_optional_args) {
    int __pyx_v_n = ((int)0x2710);
    float __pyx_v_t2;
    float __pyx_v_t1;
    float __pyx_v_p_suitable_parts;
    float __pyx_v_p_incorrigible_marriage;
    float __pyx_v_p_fixable_marriage;
    __pyx_ctuple_float__and_float__and_float __pyx_r;
    float __pyx_t_1;
    struct __pyx_opt_args_6Clogic_6Clogic_F __pyx_t_2;
    float __pyx_t_3;
    __pyx_ctuple_float__and_float__and_float __pyx_t_4;
    int __pyx_lineno = 0;
    const char* __pyx_filename = NULL;
    int __pyx_clineno = 0;
    if (__pyx_optional_args) {
        if (__pyx_optional_args->__pyx_n > 0) {
            __pyx_v_n = __pyx_optional_args->n;
        }
    }

    __pyx_t_1 = (__pyx_v_es - __pyx_v_nx);
    __pyx_v_t2 = (__pyx_t_1 / __pyx_v_o);


    __pyx_t_1 = (__pyx_v_ei - __pyx_v_nx);
    __pyx_v_t1 = (__pyx_t_1 / __pyx_v_o);


    __pyx_t_2.__pyx_n = 1;
    __pyx_t_2.n = __pyx_v_n;
    __pyx_t_1 = __pyx_f_6Clogic_6Clogic_F(__pyx_v_t2, &__pyx_t_2); 
        __pyx_t_2.__pyx_n = 1;
    __pyx_t_2.n = __pyx_v_n;
    __pyx_t_3 = __pyx_f_6Clogic_6Clogic_F(__pyx_v_t1, &__pyx_t_2); 
        __pyx_v_p_suitable_parts = ((__pyx_t_1 - __pyx_t_3) * 100.0);


    __pyx_t_3 = (__pyx_v_ei - __pyx_v_nx);

    __pyx_v_t2 = (__pyx_t_3 / __pyx_v_o);


    __pyx_t_3 = ((__pyx_v_nx - (3.0 * __pyx_v_o)) - __pyx_v_nx);

    __pyx_v_t1 = (__pyx_t_3 / __pyx_v_o);


    __pyx_t_2.__pyx_n = 1;
    __pyx_t_2.n = __pyx_v_n;
    __pyx_t_3 = __pyx_f_6Clogic_6Clogic_F(__pyx_v_t2, &__pyx_t_2); 
        __pyx_t_2.__pyx_n = 1;
    __pyx_t_2.n = __pyx_v_n;
    __pyx_t_1 = __pyx_f_6Clogic_6Clogic_F(__pyx_v_t1, &__pyx_t_2); 
        __pyx_v_p_incorrigible_marriage = ((__pyx_t_3 - __pyx_t_1) * 100.0);


    __pyx_t_1 = ((__pyx_v_nx + (3.0 * __pyx_v_o)) - __pyx_v_nx);
    __pyx_v_t2 = (__pyx_t_1 / __pyx_v_o);


    __pyx_t_1 = (__pyx_v_es - __pyx_v_nx);
    __pyx_v_t1 = (__pyx_t_1 / __pyx_v_o);


    __pyx_t_2.__pyx_n = 1;
    __pyx_t_2.n = __pyx_v_n;
    __pyx_t_1 = __pyx_f_6Clogic_6Clogic_F(__pyx_v_t2, &__pyx_t_2); 
        __pyx_t_2.__pyx_n = 1;
    __pyx_t_2.n = __pyx_v_n;
    __pyx_t_3 = __pyx_f_6Clogic_6Clogic_F(__pyx_v_t1, &__pyx_t_2); 
        __pyx_v_p_fixable_marriage = ((__pyx_t_1 - __pyx_t_3) * 100.0);

    __pyx_t_4.f0 = __pyx_v_p_suitable_parts;
    __pyx_t_4.f1 = __pyx_v_p_incorrigible_marriage;
    __pyx_t_4.f2 = __pyx_v_p_fixable_marriage;
    __pyx_r = __pyx_t_4;


    return __pyx_r;
}


void calculate(float ei, float es, float nx, float o, float* p_suitable_parts, float* p_incorrigible_marriage, float* p_fixable_marriage, int n) {

    struct __pyx_opt_args_6Clogic_6Clogic_F __pyx_args = { .__pyx_n = n, .n = n };

    float t2 = (es - nx) / o;
    float t1 = (ei - nx) / o;
    *p_suitable_parts = (__pyx_f_6Clogic_6Clogic_F(t2, &__pyx_args) - __pyx_f_6Clogic_6Clogic_F(t1, &__pyx_args)) * 100;

    t2 = (ei - nx) / o;
    t1 = (nx - 3 * o - nx) / o;
    *p_incorrigible_marriage = (__pyx_f_6Clogic_6Clogic_F(t2, &__pyx_args) - __pyx_f_6Clogic_6Clogic_F(t1, &__pyx_args)) * 100;

    t2 = (nx + 3 * o - nx) / o;
    t1 = (es - nx) / o;
    *p_fixable_marriage = (__pyx_f_6Clogic_6Clogic_F(t2, &__pyx_args) - __pyx_f_6Clogic_6Clogic_F(t1, &__pyx_args)) * 100;
}

double test_normal_dist(int cycles) {
    clock_t start = clock();

    float p_suitable_parts, p_incorrigible_marriage, p_fixable_marriage;
    for (int i = 0; i < cycles; i++) {
        struct __pyx_opt_args_6Clogic_6Clogic_calculate __pyx_args = { .__pyx_n = 10000, .n = 10000 };
        __pyx_f_6Clogic_6Clogic_calculate(0.006f, 0.055f, 0.026f, 0.012f, &__pyx_args);
    }

    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time: %f seconds\n", duration);

    return duration;
}

int main() {
    int cycles = 1000;
    int countTests = 10;
    double sum = 0;

    for (int i = 0; i < countTests; i++) {
        sum += test_normal_dist(cycles);
    }
}