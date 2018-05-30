#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    int seleccion;
    int ex, ex2, cam, tam;
    int x = 1;
    char arr1[50];
    char arr2[50];
    char arr3[50];
    
    while (x == 1) {
    	/*Menu de Inicio*/
        printf("¿Desea usted hacer?\n\t1) Cifrar\n\t2) Decifrar\n\t3) Salir\n");
        scanf("%d%*c", &seleccion);
        switch (seleccion) {

        	/*Cifrar*/
            case 1:

            	/*Texto a Cifrar*/
                printf("Escriba el texto que desea cifrar: \n");
                gets(arr1);
                tam = strlen(arr1);

                if (tam > 20) {
                	printf("Las especificaciones requieren que el mensaje sea de máximo 20 caracteres");
                	break;
                }

                cam = 0;
                while(cam < tam) {
                    arr1[cam] = toupper(arr1[cam]);
                    cam++;
                }
                
                /*Llave de Cifrado*/
                printf("Escriba la llave para cifrar: \n");
                gets(arr2);
                int perm = strlen(arr2);

                if (perm > 10) {
                	printf("Las especificaciones requieren que la llave sea de máximo 10 caracteres");
                	break;
                }
                
                cam = 0;
                while(cam < perm) {
                    arr2[cam] = toupper(arr2[cam]);
                    cam++;
                }

                ex = 0;
                ex2 = 0;
                while (ex < tam ) {
                	if (ex2 > perm) {
                		ex2 = 0;
                	}
                	if (arr1[ex] == 32) {
                		arr3[ex] = arr1[ex];
                		printf("\n");
                		ex++;
                		ex2++;
                	}else if (arr1[ex] >= 48 && arr1[ex] <= 57) {
                		arr3[ex] = abs(((arr2[ex2]-65) + (arr1[ex]-48)))%10;
	                    arr3[ex] = arr3[ex]+48;
	                    printf("\n%c + %c -> %c", arr1[ex], arr2[ex2], arr3[ex]);
	                    ex++;
	                    ex2++;
                	}else{
	                    arr3[ex] = abs(((arr2[ex2]-65) + (arr1[ex]-65)))%26;
	                    arr3[ex] = arr3[ex]+65;
	                    printf("\n%c + %c -> %c", arr1[ex], arr2[ex2], arr3[ex]);
	                    ex++;
	                    ex2++;
	                }
                }
                printf("\n");
                break;

            /*Descifrar*/
            case 2:

            	/*Texto a Descifrar*/
                printf("Escriba el texto cifrado: \n");
                gets(arr1);
                tam = strlen(arr1);

                if (tam > 20) {
                	printf("Las especificaciones requieren que el mensaje sea de máximo 20 caracteres");
                	break;
                }

                cam = 0;
                while(cam < tam) {
                    arr1[cam] = toupper(arr1[cam]);
                    cam++;
                }

                /*Llave de Descifrado*/
                printf("Escriba la llave para descifrar: \n");
                gets(arr2);
                
                perm = strlen(arr2);

                if (perm > 10) {
                	printf("Las especificaciones requieren que la llave sea de máximo 10 caracteres");
                	break;
                }
                
                cam = 0;
                while(cam < tam) {
                    arr2[cam] = toupper(arr2[cam]);
                    cam++;
                }

                ex = 0;
                ex2 = 0;
                while (ex < tam ) {
                	if (ex2 > perm) {
                		ex2 = 0;
                	}
                	if (arr1[ex] == 32) {
                		arr3[ex] = arr1[ex];
                		printf("\n");
                		ex++;
                		ex2++;
                	}else if (arr1[ex] >= 48 && arr1[ex] <= 57) {
                		arr3[ex] = abs(((arr1[ex]-48+10) - (arr2[ex2]-65)))%10;
	                    arr3[ex] = arr3[ex]+48;
	                    printf("\n%c + %c -> %c", arr1[ex], arr2[ex2], arr3[ex]);
	                    ex++;
	                    ex2++;
                	}else{
	                    arr3[ex] = abs(((arr1[ex]-65+26) - (arr2[ex2]-65)))%26;
	                    arr3[ex] = arr3[ex]+65;
	                    printf("\n%c + %c -> %c", arr1[ex], arr2[ex2], arr3[ex]);
	                    ex++;
	                    ex2++;
	                }
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


/*
if(perm2%2 == 0){
                    
    for( int i = 0; i < (perm2/2); i++){
        char temp = arr2[i];
        arr2[i] = arr2[perm2 - i - 1];
        arr2[perm2 - i - 1] = temp;
    }
}else{
    for( int i = 0; i < ((perm - 1) / 2); i++){
        char temp = arr2[i];
        arr2[i] = arr2[perm - i - 1];
        arr2[perm - i - 1] = temp;
    }
    
}
*/