#include "iostream"
#include <math.h>

double N, F, m, a;

void getValues(double *N, double *F, double *m, double *a);
void getY(double *N, double *T);
void gety(double *N, double t[]);
void count_y(double *N, double *F, double *m, double *a, double *T, double *t);
void count_Y (double *N, double *F, double *m, double *a, double *T, double *t);
void print_y (double *t, double *N);
void print_Y (double *T, double *N);
int main() {

    getValues(&N,&F, &m, &a);

    double T[(int)N];
    double t[(int)N];
    std::cout << "Co chcesz zrobic?\n\n";
    std::cout << "1 - transformata FNT\n";
    std::cout << "2 - transformata odwrotna\n\n";
    int choice;
    std::cin >> choice;


    switch(choice) {
        case 1:
            getY(&N, t);
            count_Y(&N, &F, &m, &a, T, t);
            print_Y(T, &N);
            break;
        case 2:
            getY(&N, T);
            count_y(&N, &F, &m, &a, T, t );
            print_y(t, &N);
            break;

    }




    //getY(&N, T);

        //std::cout << "\n" << N << "\n" << F << "\n" << m << "\n" << a << "\n" ;
//    for(int i = 0; i <N; i++) {
//        std::cout <<"\n" << t[i];
//    }
}

void getValues(double *N, double *F, double *m, double *a) {
    std::cout << "Podaj wartosc N: ";
    std::cin >> *N;

    std::cout << "\n Podaj wartosc F: ";
    std::cin >> *F;

    std::cout << "\n Podaj wartosc a: ";
    std::cin >> *a;

    *m = log2(*N);

}

void getY(double *N, double T[]) {

    for (int i = 0; i <*N; i++){
        std::cout << "Podaj " << i << " element: " ;
        std::cin >> T[i];
    }

}


void count_y (double *N, double *F, double *m, double *a, double *T, double *t){ //liczy odwrotną FNT

    for (int n = 0; n < *N; n++ ) {
        for (int k = 0; k < *N; k++){
            // t[n] = t[n] + T[k]*pow(*a,-n*k);
            t[n] = t[n] + pow(T[k]*(*a),k*n);

        }
        //t[n] = fmod(t[n], *F) * pow(2, -(*m));
        //t[n] = t[n] * (1 / *N);
        t[n] = fmod(t[n], *F);

    }

}
void count_Y (double *N, double *F, double *m, double *a, double *T, double *t) { //liczy transformatę fermata
    for (int k = 0; k < *N; k++) {
        for (int n = 0; n < *N; n++) {
            T[k] = T[k] + t[n] * pow(*a,k*n);
            T[k] = fmod(T[k], *F);
        }
    }
}

void print_y (double *t, double *N) {
    for (int i = 0; i <*N; i++) {
        std::cout << "Wartosc t[" << i << "]: " << t[i] << "\n";
    }

}

void print_Y (double *T, double *N) {
    for (int i = 0; i <*N; i++) {
        std::cout << "Wartosc T[" << i << "]: " << T[i] << "\n";
    }
}








