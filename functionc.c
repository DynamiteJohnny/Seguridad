//
//  main.c
//  One-time Pad
//
//  Created by Juan Suarez, Romel Martínez & Bruno Maglioni on 1/17/18.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    int seleccion;
    int x = 1;
    char arr1[50];
    char arr2[50];
    char arr3[50];
    
    while (x == 1) {
        printf("¿Desea usted hacer?\n\t1) Cifrar\n\t2) Decifrar\n\t3) Salir\n");
        scanf("%d%*c", &seleccion);
        switch (seleccion) {
            case 1:
                printf("Escriba el texto que desea cifrar: \n");
                gets(arr1);
                int tam = strlen(arr1);
                printf("Escriba la llave para cifrar: \n");
                gets(arr2);
                int cam = 0;
                while(cam < tam) {
                    arr2[cam] = toupper(arr2[cam]);
                    cam++;
                }
                int ex = 0;
                while (ex < tam ) {
                    arr3[ex] = ((arr2[ex]-65) + (arr1[ex]-97))%26;
                    arr3[ex] = arr3[ex]+65;
                    printf("\n%c + %c -> %c", arr1[ex], arr2[ex], arr3[ex]);
                    ex++;
                }
                printf("\n");
                break;
            case 2:
                printf("Escriba el texto cifrado: \n");
                gets(arr1);
                int cam3 = 0;
                while(cam3 < tam) {
                    arr2[cam3] = toupper(arr2[cam3]);
                    cam3++;
                }
                int tam2 = strlen(arr1);
                printf("Escriba la llave para cifrar: \n");
                gets(arr2);
                int cam2 = 0;
                while(cam2 < tam) {
                    arr2[cam2] = toupper(arr2[cam2]);
                    cam2++;
                }
                int ex2 = 0;
                while (ex2 < tam2) {
                    arr3[ex2] = ((arr1[ex2]-65 + 26) - (arr2[ex2] - 65))%26;
                    arr3[ex2] = arr3[ex2]+97;
                    printf("\n%c + %c -> %c", arr1[ex2], arr2[ex2], arr3[ex2]);
                    ex2++;
                }
                printf("\n");
                break;
            case 3:
                x = 0;
                break;
            default:
                break;
        }
    }
    return 0;
}
