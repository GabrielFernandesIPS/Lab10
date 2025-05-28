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
                StringWrap s = stringWrapCreate(nome);
                if(strlen(s.text) != 0)
                    mapPut(voting, s, 0);

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
                StringWrap k = stringWrapCreate(nome);
                int v;
                // TODO: Registar voto (incrementar votação) ou mensagem de erro se candidato não existir
                if(mapContains(voting, k) == true){
                    mapGet(voting, k, &v);
                    mapPut(voting, k, v + 1);
                    printf("[VOTO REGISTADO]\n");
                } else{
                    printf("[ERRO:CANDIDATO %s NAO EXISTE]\n", k.text);
                }
                
                
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
                MapKey* mk = mapKeys(voting);
                int size;
                bool swapped = false;
                mapSize(voting, &size);
                for(int i = 0; i < size; i++){
                    swapped = false;
                    for(int j = 0; j < size - i - 1; j++){
                        if(mapKeyCompare(mk[j], mk[j + 1]) > 0){
                            MapKey temp = mk[j];
                            mk[j] = mk[j + 1];
                            mk[j + 1] = temp;
                            swapped = true; 
                        }
                    }
                    if(swapped == false){
                        break;
                    }
                }

                for(int i = 0; i < size; i++){
                    printf("%s\n", mk[i].text);
                }
            }

        } else if (menuOption == 5) {
            // Apresentar vencedor
            if (mapIsEmpty(voting)) {
                printf("[INFO] Nenhum candidato registado.\n");
            } else {

                // TODO: Encontrar e apresentar vencedor
                MapKey* mk = mapKeys(voting);

                int maxV, size, windex;

                mapGet(voting, mk[0], &maxV);
                mapSize(voting, &size);
                windex = 0;
                for(int i = 1; i < size; i++){
                    int v;
                    mapGet(voting, mk[i], &v);
                    if(maxV < v){
                        maxV = v;
                        windex = i;
                    }
                }


                printf("Vencedor: %s\n", mk[windex].text);
            }

        } else if (menuOption == 6) {
            // Resultados por número de votos
            if (mapIsEmpty(voting)) {
                printf("[INFO] Nenhum candidato registado.\n");
            } else {

                // TODO: Listar candidatos por número de votos (descendente)
                printf("Resultados:\n");
                MapValue* mv = mapValues(voting);
                MapKey* mk = mapKeys(voting);
                int size;
                bool swapped = false;
                mapSize(voting, &size);
                for(int i = 0; i < size; i++){
                    swapped = false;
                    for(int j = 0; j < size - i - 1; j++){
                        if(mv[j] < mv[j + 1]){
                            MapValue tempV = mv[j];
                            MapKey tempK = mk[j];

                            mk[j] = mk[j + 1]; //KEY
                            mv[j] = mv[j + 1]; //VALUE

                            mk[j + 1] = tempK; //KEY
                            mv[j + 1] = tempV; //VALUE
                            swapped = true; 
                        }
                    }
                    if(swapped == false){
                        break;
                    }
                }

                for(int i = 0; i < size; i++){
                    printf("Candidato: %s | Votos: %d\n", mk[i].text, mv[i]);
                }

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



