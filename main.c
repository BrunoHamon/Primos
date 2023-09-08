#include <stdio.h>
#include <sys/time.h>
#include <time.h>

//Função tempo
    void tempo(struct timeval inicio,clock_t start){
        struct timeval fim;
        clock_t end;
        double cpu_time_used;
        gettimeofday(&fim, 0);
        end = clock();


    long seg = fim.tv_sec - inicio.tv_sec;
        long mseg = fim.tv_usec - inicio.tv_usec;
        double tempo_total = seg + mseg * 1e-6;

        printf("Tempo gasto: %f segundos.\n", tempo_total);

        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Tempo gasto de CPU: %f segundos.\n", cpu_time_used);
    }

//Função principal
    int main() {
        //Declara variáveis
        struct timeval inicio;
        clock_t start;
        int resposta;
        int p = 1, n, np = 0, c = 0;

        //Determina qual função do código usar
        printf("Digite 1 para descobrir numeros primos ou 2 para testar se um numero é primo: ");
        scanf("%d", &resposta);


        switch (resposta) {

            case 1: //Função 1

                printf("Entre com o número de primos: ");
                scanf("%d", &n);

                start = clock();
                gettimeofday(&inicio, 0);

                //Repete até que o número, de números primos, desejado seja atingido
                while (np != n) {

                    for (int i = 1; i < p; i++) { //Verifica se é primo
                        if ((p % i) == 0) {
                            c++;
                        }
                    }

                    if (c == 1) { //Se for primo escreve o número
                        printf("%d\n", p);
                        np++;
                    }
                    p++;
                    c = 0;
                }
                break;
                //O número de repetições será igual ao número primo mais altos entre os escritos
                //Quanto maior o número mais tempo será necessário para verificar se é primo
                /*Não é possível equalizar a curva de crescimento dos números primos, mas é possível
                afirmar que está acima de linear na maioria dos casos*/
                //Para todos os casos a curva de crescimento de passos da função 1 está acima de linear

                //n = 100: Tempo gasto: 0.039639 segundos. //Tempo gasto de CPU: 0.039000 segundos.
                //n = 1000: Tempo gasto: 0.596409 segundos. Tempo gasto de CPU: 0.597000 segundos.
                //n = 10000 Tempo gasto: 48.707554 segundos. Tempo gasto de CPU: 48.708000 segundos.

            case 2: //Função 2

                printf("Entre com o número: ");
                scanf("%d", &p);

                start = clock();
                gettimeofday(&inicio, 0);

                for (int i = 1; i < p; i++) { //Testa se o número é primo
                    if ((p % i) == 0) {
                        c++;
                    }
                }
                //O número de repetições será igual ao número testado

                if (c == 1) { //Escreve a resposta correspondente
                    printf("Eh primo\n");
                } else {
                    printf("Nao eh primo\n");
                }

                break;
                //A velocidade da função 2 é n+k
                //Sendo n o número testado
                //E k o número de passos necessarios para escrever se o número é primo

                //n = 100: Tempo gasto: 0.001711 segundos. Tempo gasto de CPU: 0.003000  segundos.
                //n = 1000: Tempo gasto: 0.004261  segundos. Tempo gasto de CPU: 0.004000 segundos.
                //n = 10000: Tempo gasto: 0.004582  segundos. Tempo gasto de CPU: 0.005000 segundos.

            default:
                start = clock();
                gettimeofday(&inicio, 0);

                printf("Entrada invalida\n");
                break;
        }

        tempo(inicio,start);
        return 0;
    }