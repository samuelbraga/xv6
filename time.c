#include "types.h"
#include "user.h"
#include "date.h"

int
main (int argc, char *argv[])
{
    //Inicia obtendo o acumulado até o disparo do time;
    int inicio = uptime();

    //exec(prog, params);
    int processo = fork();
    if (processo < 0)
    {
        printf(2, "Processo Invalido\n");
        exit();
    }

    //wait(prog);
    if (processo > 0)
        wait();

    if (processo == 0)
    {
        if (exec(argv[1], argv + 1) < 0)
        {
            printf(2, "Erro de execucao\n");
            exit();
        }
    }

    //Obtém o acumulado ao término da execução do programa
    int final = uptime();
    int segundos = (final - inicio)/100;
    int milissecundos = (final - inicio)%100;

    //Imprime os dados demandados
    printf(1, "%s ", argv[1]);
    printf(1, "demorou %d.", segundos);
    
    if (milissecundos < 10)
        printf(1, "0");
   
    printf(1, "%d segundos\n", milissecundos);
    exit();
}