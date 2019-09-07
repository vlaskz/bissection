#include <math.h>
#include <stdio.h>
#define ARRAY_SIZE(arr)     (sizeof(arr) / sizeof((arr)[0]))


float function(float);

float getIter(float, float, float);

float signal(float);

void getData();

void iterate();

float a = 0, b = 0, x = 0, fa = 0, fb = 0, fx = 0, tol = 0;

float n_iter = 0;
void printMatrix(float[]);

int main() {
    getData();
    float matrix[(int)n_iter][7];
    for (int i = 0; i < n_iter; i++) {
        iterate();
        matrix[i][0] = a;
        matrix[i][1] = b;
        matrix[i][2] = x;
        matrix[i][3] = fa;
        matrix[i][4] = fb;
        matrix[i][5] = fx;
        matrix[i][6] = tol;

        printMatrix(matrix[i]);
        printf("\n");

    }
    return 0;
}

void printMatrix(float arr[]) {
    for(int i=0;i<6;i++){
        printf("\t %f",arr[i]);
    }
}

void iterate() {
    x = (a+b)/2;
    fa = function(a);
    fb = function(b);
    fx = function(x);
    if(signal(fa)==signal(fx)){
        a = x;
    }else{
        b=x;
    }

}


void getData() {
    printf("Bem vindo! A função é X²-3.\nVamos começar!\nInsira o limite inferior(A): ");
    scanf("%f", &a);
    printf("Ótimo! Agora insira o limite superior(B): ");
    scanf("%f", &b);
    printf("Excelente! Agora precisamos da Tolerância(TOL): ");
    scanf("%f", &tol);

    printf("Pronto! Vamos revisar: O intervalo é [%f , %f] com tolerância de %f", a, b, tol);
    n_iter = getIter(a, b, tol);
    printf("\nO número de iterações neste caso é de %i\n", (int) n_iter);
    printf("         A\t         B\t         X\t      f(A)\t      f(B)\t      f(X)\n");
}

float getIter(float l_inf, float l_sup, float tol) {
    return ceil((log(l_sup - l_inf) - log(tol)) / log(2));
}

float function(float x) {
    return pow(x, 2) - 3;
}

float signal(float number) {
    return (number / fabs(number));
}

