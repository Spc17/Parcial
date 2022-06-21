#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validar_num(char* codigo)
{
    int i = 0, j;

    j = strlen(codigo);

    while (i < j) {
        if (isdigit(codigo[i]) != 0) {
            i++;
        } else {
            return 1;
        }
    }

    return 0;

}

int main(){
	char s[256], codigo[256];
	int validator, suma = 0, codigo_int;
	
	printf("Si desea ingresar codigo digite 01, de lo contrario 00\n");
	
	gets(s);
	
    while (strcmp(s, "01") == 0) {
        printf("Ingrese codigo de estudiante o 00 para terminar: \n");
        gets(codigo);
        validator = validar_num(codigo);
        printf("%d", validator);

        if (validator == 1) {
            printf("El valor ingresado no es un codigo de estudiante valido\n");
        }
        else if(strcmp(codigo, "00") == 0){
            return 0;
        }
        else {
            printf("El codigo de estudiante es valido\n");

            codigo_int = atoi(codigo);
            while (codigo_int > 0) {
                suma = suma + codigo_int % 10;
                codigo_int = codigo_int / 10;
            }
            printf("%d", suma);
            suma=0;
        }
    }
	
    return 0;
	
}