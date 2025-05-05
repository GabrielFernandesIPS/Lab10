#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "input.h"
#include "map.h" 

void showMenu() {
    printf("\n--- Sistema de Votação ---\n");
    printf("1. Abrir nova votação\n");
    printf("2. Registar voto\n");
    printf("3. Fechar votação\n");
    printf("4. Listar candidatos (ordem alfabética)\n");
    printf("5. Apresentar vencedor\n");
    printf("6. Resultados por número de votos\n");
    printf("0. Sair\n");
    printf("\nOpção: ");
}

int main() {
    int menuOption;
    bool votingIsOpen = false; /* Votação aberta? */
    PtMap voting = mapCreate(); /* Contém candidatos e votos associados */
    
    if(voting == NULL) {
        printf("[ERRO] Não foi possível iniciar o programa. Não existe memória disponível.\n");
        return EXIT_FAILURE;
    }

    do {
        showMenu();
        readInteger(&menuOption);

        if (menuOption == 1) {
            if(votingIsOpen) {
                printf("[ERRO] Já existe uma votação em aberto.\n");
                continue;
            }

            // Abrir nova votação
            if (voting != NULL) {
                mapClear(voting); // apagar possível informação existente
            }
            
            // Solicitar nomes de candidatos a votos e inseri-los com 0 votos iniciais
            // String "vazia" termina introdução de candidatos
            printf("Registo de candidatos ->\n");
            char nome[100];
            do {
                printf("Nome (ENTER para terminar)?: ");
                readString(nome, 100);

                // TODO: adicionar candidato com zero (0) votos

            } while(strlen(nome) != 0);

            int size;
            mapSize(voting, &size);
            if(size == 0) {
                printf("[ERRO] Não é possível abrir uma votação sem candidatos.\n");
            } else {
                votingIsOpen = true;
                printf("[INFO] Nova votação iniciada com %d candidatos.\n", size);
            }

        } else if (menuOption == 2) {
            // Registar voto
            if (!votingIsOpen) {
                printf("[ERRO] A votação está encerrada. Não é possível registar mais votos.\n");
                continue;
            } else {
                char nome[100];
                printf("Nome do candidato: ");
                readString(nome, 100);

                // TODO: Registar voto (incrementar votação) ou mensagem de erro se candidato não existir
                
                printf("[VOTO REGISTADO]\n");
            }

        } else if (menuOption == 3) {
            // Fechar votação
            if (!votingIsOpen) {
                printf("[ERRO] A votação já está encerrada.\n");
            } else {
                votingIsOpen = false;
                printf("[INFO] Votação encerrada.\n");
            }

        } else if (menuOption == 4) {
            // Listar candidatos por ordem alfabética
            if (mapIsEmpty(voting)) {
                printf("[INFO] Nenhum candidato registado.\n");
            } else {

                // TODO: Listar candidatos ordenados alfabeticamente
                printf("Candidatos:\n");
            }

        } else if (menuOption == 5) {
            // Apresentar vencedor
            if (mapIsEmpty(voting)) {
                printf("[INFO] Nenhum candidato registado.\n");
            } else {

                // TODO: Encontrar e apresentar vencedor
                printf("Vencedor: ...\n");
            }

        } else if (menuOption == 6) {
            // Resultados por número de votos
            if (mapIsEmpty(voting)) {
                printf("[INFO] Nenhum candidato registado.\n");
            } else {

                // TODO: Listar candidatos por número de votos (descendente)
                printf("Resultados:\n");
            }

        } else if (menuOption == 0) {
            // Terminar programa
            printf("[PROGRAMA TERMINADO]\n");

        } else {
            printf("[ERRO] Opção inválida.\n");
        }

    } while (menuOption != 0);

    
    mapDestroy(&voting);

    return EXIT_SUCCESS;
}



