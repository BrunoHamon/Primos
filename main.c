#include <stdio.h>
#include <sys/time.h>
#include <time.h>

    void tempo(struct timeval inicio,clock_t start){
        struct timeval fim;
        clock_t end;
        double cpu_time_used;
        gettimeofday(&fim, 0);

        long seg = fim.tv_sec - inicio.tv_sec;
        long mseg = fim.tv_usec - inicio.tv_usec;
        double tempo_total = seg + mseg * 1e-6;

        printf("Tempo gasto: %f segundos.\n", tempo_total);

        end = clock();

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Tempo gasto de CPU: %f segundos.\n", cpu_time_used);
    }


    int main() {
        struct timeval inicio;
        clock_t start;
        int resposta;
        int p = 1, n, np = 0, c = 0, e = 1;


        printf("Digite 1 para descobrir numeros primos ou 2 para testar se um numero é primo:");
        scanf("%d", &resposta);

        switch (resposta) {
            case 1:

                printf("Entre com o número de primos: ");
                scanf("%d", &n);

                while (np != n) {
                    start = clock();
                    gettimeofday(&inicio, 0);
                    for (int i = 1; i < p; i++) {
                        if ((p % i) == 0) {
                            c++;
                        }
                    }
                    if (c == 1) {
                        printf("%d\n", p);
                        np++;
                    }
                    p++;
                    c = 0;
                }
                tempo(inicio,start);
                break;

            case 2:

                printf("Entre com o número: ");
                scanf("%d", &p);

                start = clock();
                gettimeofday(&inicio, 0);

                for (int i = 1; i < p; i++) {
                    if ((p % i) == 0) {
                        c++;
                    }
                }

                if (c == 1) {
                    printf("Eh primo\n");
                } else {
                    printf("Nao eh primo\n");
                }
                tempo(inicio,start);
                break;

            case 3:

                printf("Entre com o número de primos: ");
                scanf("%d", &n);

                while (np != n) {
                    start = clock();
                    gettimeofday(&inicio, 0);
                    for (int i = 1; i < p; i++) {
                        if ((p % i) == 0) {
                            c++;
                        }
                    }
                    if (c == 1) {
                        printf("%d\n", p);
                        np++;
                    }
                    p += e;
                    if (e % 5 == 0) {
                        e++;
                    }
                    c = 0;
                }
                tempo(inicio,start);
                break;

            default:
                printf("Entrada invalida");
                break;
        }

        return 0;
    }