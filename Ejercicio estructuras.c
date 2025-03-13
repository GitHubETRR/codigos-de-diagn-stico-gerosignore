#include <stdio.h>
#include <stdbool.h>
#define MAX_CHAR 50
#define MAX_PERS 20

typedef struct{
    char Nombre[MAX_CHAR];
    char Apellido[MAX_CHAR];
    float Altura;
    float Peso;
} Registro_t;

void Registrar(Registro_t Lista_Personas[], int i);
int RegistrarOtro();
void Mostrar(Registro_t Lista_Personas[], int i);

int main(){
    Registro_t Lista_Personas[MAX_PERS];
    int repetir = 1;
    int i;
    for (i=0; (i<MAX_PERS)&& repetir; i++){
        Registrar(Lista_Personas, i);
        repetir = RegistrarOtro();
    }

    Mostrar(Lista_Personas, i);
    getchar();
    getchar();
}

void Registrar(Registro_t Lista_Personas[], int i){
        printf("\nPorfavor, registrese, persona numero %d \n", i+1);
        printf("Ingrese su nombre:\n");
        scanf("%s", Lista_Personas[i].Nombre);
        printf("Ingrese su apellido:\n");
        scanf("%s", Lista_Personas[i].Apellido);
        printf("Ingrese su altura(en metros):\n");
        scanf("%f",&Lista_Personas[i].Altura);
        printf("Ingrese su peso(en kg):\n");
        scanf("%f",&Lista_Personas[i].Peso);
}

int RegistrarOtro(){
    int repetir;
    printf("¿Desea registrar otra persona?\n 0(no)- 1(si)\n");
    scanf("%d",&repetir);
    return repetir == 1;
}

void Mostrar(Registro_t Lista_Personas[], int i){
    for(int j=0; j<i; j++){
        #define DELGADO 18.5
        #define NORMAL 24.9
        #define SOBREPESO 29.9
        #define OBD_1 34.9
        #define OBD_2 39.9
        float IMC;
        IMC=Lista_Personas[j].Peso/(Lista_Personas[j].Altura*Lista_Personas[j].Altura);
        printf("PERSONA NUMERO %d:\n", j+1);
        printf("Nombre: %s\n", Lista_Personas[j].Nombre);
        printf("Apellido: %s\n", Lista_Personas[j].Apellido);
        printf("Altura: %f\n", Lista_Personas[j].Altura);
        printf("Peso: %f\n", Lista_Personas[j].Peso);
        printf("IMC: %f\n", IMC);
        if(IMC<DELGADO)printf("PESO BAJO\n\n");
        else{
            if(IMC<NORMAL)printf("PESO NORMAL\n\n");
            else{
                if(IMC<SOBREPESO)printf("SOBREPESO\n\n");
                else{
                    if(IMC<OBD_1)printf("OBESIDAD 1\n\n");
                    else{
                        if(IMC<OBD_2)printf("OBESIDAD 2\n\n");
                        else printf("OBESIDAD 3\n\n");
                    }
                }
            }
        }
    }
}