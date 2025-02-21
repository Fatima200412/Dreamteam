#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//// funciones para el juego

///fun para inicializar tablero
    void iniciatab(char tablero[3][3] ){
     int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tablero[i][j] = ' ';

        }
    }
    }

///fun para mostrar tablero base de opciones

    void showtabInicial(char tablero[3][3]){

        int i, j, h, cont=1;

        for(i=0;i<3;i++){
                printf("\t");
            for(j=0;j<3;j++){
                    printf(" %d ", cont);
                if(j<2){
                    printf("|");
                }cont++;
                }

            printf("\n\t");
            for(h=0;h<7;h++){
                    if(i<2){
                        printf("-");
                    }

                if(h%2==1&&i<2&&h<5){
                    printf("-|");
                }
            }

            printf("\n");
        }
    }

///fun para mostrar tablero
void showtab(char tablero[3][3]){

        int i, j, h, cont=1;

        for(i=0;i<3;i++){
                printf("\t");
            for(j=0;j<3;j++){
                    printf(" %c ", tablero[i][j]);
                if(j<2){
                    printf("|");
                }cont++;
                }

            printf("\n\t");
            for(h=0;h<7;h++){
                    if(i<2){
                        printf("-");
                    }

                if(h%2==1&&i<2&&h<5){
                    printf("-|");
                }

            }

            printf("\n");
        }
    }

///fun verificar ganador
    int ver_ganador(char tablero[3][3]){
    int i,j;
 //para filas

    for (i=0;i<3; i++){

    if(tablero[i][0]==tablero[i][1]&&tablero[i][1]==tablero[i][2]&&tablero[i][0]!=' ')
        {
            return 1;

        }
    }

  // para las columnas
    for ( j=0; j < 3; j++){

    if(tablero[0][j]==tablero[1][j]&&tablero[1][j]==tablero[2][j]&&tablero[0][j]!=' ')
        {
            return 1;

        }
    }
 // para diagonales
    if(tablero[0][0]==tablero[1][1]&&tablero[1][1]==tablero[2][2]&& tablero[0][0]!=' '){
        return 1;
    }
    if (tablero[0][2]==tablero[1][1]&&tablero[1][1]==tablero[2][0]&&tablero[0][2]!=' '){
        return 1;
    }
      return 0;
    }

///tablero lleno
    int tablleno(char tablero[3][3]){
    for(int i=0;i<3;i++){
        for(int j =0; j<3; j++){
            if (tablero[i][j]==' '){
                return 0;
            }
        }
    }
            return 1;
    }

///Fun agregar opción
    void agregarOpcion(char tablero[3][3], int turno){

        int fila, columna, b=1, op;
        do {
                if (turno % 2 == 1) {
                    printf("\nJUGADOR 1 (X) \n");
                    printf("Elige un numero del 1 al 9, y que este en una casilla libre: ");
                    scanf("%d", &op);

            } else {
                    printf("\nJUGADOR 2 (O) \n");
                    printf("Elige un numero del 1 al 9, y que este en una casilla libre: ");
                    scanf("%d", &op);
            }
        switch(op){

                    case 1:
                        fila=0;
                        columna=0;
                        break;
                    case 2:
                        fila=0;
                        columna=1;
                        break;
                    case 3:
                        fila=0;
                        columna=2;
                        break;
                    case 4:
                        fila=1;
                        columna=0;
                        break;
                    case 5:
                        fila=1;
                        columna=1;
                        break;
                    case 6:
                        fila=1;
                        columna=2;
                        break;
                    case 7:
                        fila=2;
                        columna=0;
                        break;
                    case 8:
                        fila=2;
                        columna=1;
                        break;
                    case 9:
                        fila=2;
                        columna=2;
                        break;
                    }
                    if (tablero[fila][columna] == 'X' || tablero[fila][columna] == 'O') {
                        puts("ESTA CASILLA YA ESTA OCUPADA, SELECCIONA OTRA.\n");
                    }else{
                        b=2;
                    }
                }while (b!=2);

                if(turno % 2 == 1){
                    tablero[fila][columna] = 'X';
                }else{
                    tablero[fila][columna] = 'O';
                }
    }

int main() {

    int b=0;
    do{

    #ifdef _WIN32
        system("color f0");  // Cambia el color a verde sobre fondo negro (Windows)
    #else
        printf("\033[30;37m");  // Cambia el texto a verde (Linux/macOS)
    #endif


    printf(" BIENVENIDO! \n  ");
    printf(" # JUEGO DEL GATO # \n  ");

    char tablero[3][3];
    iniciatab(tablero);
    showtabInicial(tablero);
    int i, j, opc;


    int fila, columna, turno = 1;
        printf("INICIANDO PARTIDA \n\n");
        do {
            agregarOpcion(tablero, turno);

            showtab(tablero);

            if (ver_ganador(tablero)) {
                if (turno % 2 == 1) {
                    printf("\nX JUGADOR 1 GANA! X\n");
                } else {
                    printf("\nO JUGADOR 2 GANA! O\n");
                }

                break;
            }

            if (tablleno(tablero)) {
                printf("\n EMPATE! \n");
                break;
            }

            turno++;

        } while (1);

        #ifdef _WIN32
                system("color a0");  // Cambia el color a verde sobre fondo negro (Windows)
                #else
                printf("\033[30;32m");  // Cambia el texto a verde (Linux/macOS)
                #endif

    // Opciones extra

            printf("¿QUEREN LA REVANCHA? \n1.Si    2.No \nElige una opcion: ");
            scanf("%d", &opc);
            if(opc==2){
                b=2;
                printf("HASTA PRONTO");
            }


    }while(b!=2);

    return 0;
}
