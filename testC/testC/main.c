#include <stdio.h>
#include <math.h>
#include <time.h>

#define M_PI 3.14159265358979323846

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
        sum += normal_distribution(xi, 0, 1) * dx;
    }

    return sum;
}

void calculate(float ei, float es, float nx, float o, float* p_suitable_parts, float* p_incorrigible_marriage, float* p_fixable_marriage, int n) {
    float t2 = (es - nx) / o;
    float t1 = (ei - nx) / o;
    *p_suitable_parts = (F(t2, n) - F(t1, n)) * 100;

    t2 = (ei - nx) / o;
    t1 = (nx - 3 * o - nx) / o;
    *p_incorrigible_marriage = (F(t2, n) - F(t1, n)) * 100;

    t2 = (nx + 3 * o - nx) / o;
    t1 = (es - nx) / o;
    *p_fixable_marriage = (F(t2, n) - F(t1, n)) * 100;
}

double test_normal_dist(int cycles) {
    clock_t start = clock();

    float p_suitable_parts, p_incorrigible_marriage, p_fixable_marriage;
    for (int i = 0; i < cycles; i++) {
        calculate(0.006f, 0.055f, 0.026f, 0.012f, &p_suitable_parts, &p_incorrigible_marriage, &p_fixable_marriage, 10000);
    }

    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time: %f seconds\n", duration);
}

int main() {
    int cycles = 1000;
    int countTests = 10;
    double sum = 0;

    for (int i = 0; i < countTests; i++) {
        sum += test_normal_dist(cycles);
    }
}