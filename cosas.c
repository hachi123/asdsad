#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_LINE_LENGTH 800



typedef struct {
	size_t id;
	char nombre[200];
	char desarrollador[200];
	char plataforma[200];
	char fecha[12];
	double puntaje;
	size_t resenias;
	
}

int ingreseMenu(void);
void documento(FILE *);
void actualizar(FILE *);
void añadir(FILE *);
void eliminar(FILE *);

int main(int argc, char *argv[])
{
	FILE * juegor;
	int menu;
	
	if((juegor=fopen("db.txt", "rb+"))==NULL)
	printf("no se puede abrir el archivo.\n");
	else{
		while ((menu=ingreseMenu()) !=5) {
			switch (menu){
				case 1:
				documento(juegor);
				break;
				case 2:
				actualizar(juegor);
				break;
				case 3:
				añadir(juegor);
				break;
				case 4:
				eliminar(juegor);
				break;
				
			}
		}
	}
	fclose(juegor);
	return 0;
}
/*ESTO ES ELDOCUMENTO YA CREADO ANTERIORMENTE*/
void documento(FILE *termina) /*almacena una lista con formato de todos
{								los datos en un archivo llamado doc.scv*/
	FILE *juegoh;/*establece que juegos es un apuntador a la estructura*/
	struct juego jugador;
	
	if((juegoh=fopen("doc.scv", "w"))==NULL)
	printf("el archivo no puede abrirse.\n");
	else{
		rewind(termina);/*coloca el apuntador del fichero al principio es equivalente
						a (void)fseek(stream, 0l,SEEK_SET) es el desplazamiento
						 del archivo*/
		fprintf(juegoh, "%%s%s%s%s%d\n","nombre", "desarrollador", "plataforma", "fecha", "puntaje");/*escribe datos de doc.scv*/
			
			while (!feof(termina)) { /*usa la funcion feof para determinar si el fin del archivo 
									esta definido para el archivo readptr*/
				fread(&jugador, sizeof(struct juego_t), 1, termina);/*lee el numero de bites del size.. al
																	archivo llamado por termina, entonces
																	los datos a a la estructura jugador de juego*/
																	feof determina el fin, yfread transfiere
				
				if(juego.nombre !="")
				fprintf(juegoh, "%s%s%s%s%d\n",juego.nombre, juego.desarrollador, juego.plataforma, juego.fecha, juego.puntaje);
				}
			}
			fclose(juegoh);
		}
		void actualizar(FILE*apunt)
		{
			int id;
			struct juego jugador;
			printf("ingrese un juego");
			fseek(apunt, (id - 1) * sizeof(struct juego),SEEK_SET);/*el apuntador va a el archivo referenciado por apunt
																		a la posicion apuntadotada por (id..)..desplazamiento
																		seek set indica que hay una relacion del apuntador con el
																		principio del archivo*/
			fread(&jugador, sizeof(struct juego), 1, apunt);
			
			if (juegos.id==0)
			printf("no hay informacion de la direccion de juego #%d.\n", id);
			
			else {
				printf("%d%s\n\n",juegos.id, juegos.nombre);
				fseek(apunt, (id-1)*sizeof(struct juego),SEEK_SET);
				fwrite(&jugador, sizeof(struct juego), 1, apunt);
			}
		}
		void eliminar(FILE*apunt)
		{
			struct juego jugador, sek={0, "", "", "", "",0};
			int id;
			
			printf("documento eliminado");
			scanf("%d", &id);
			fseek(apunt, (id - 1) * sizeof(struct juego),SEEK_SET);
			fread( &jugador, sizeof(struct juego), 1, apunt);
			
			if (juego.id == 0)
			printf("eljuego %d no existe.\n", id);
			else{
				fseek(apunt, (id - 1)* sizeof(struct juego),SEEK_SET);
				fwrite(&sek, sizeof(struct juego), 1, apunt);/*la estructura sek escriba al 
															archivo del apunt, regresa el tamaño
															en bites de la info en juego*/
			}
		}
		void añadir(FILE*apunt)
		{
			struct juego jugador;
			int id;
			printf("nuevo id del juego ");
			fseek(apunt, (id - 1)* sizeof(struct juego),SEEK_SET);
			fread(&jugador, sizeof(struct juego), 1, apunt);
			
			if (juego.id !=0)
			printf("el juego #%d ya cuenta con informacion.\n",juego.id);
			
			else{
				printf("agregar juego\n");
				fwrite(&jugador, sizeof(struct juego), 1, apunt);
			}
		}
		int ingreseMenu(void)
		{
			int menuChoice;
			
			printf("\n ingrese su eleccion\n"
			"1 -store a formatted text fili of acounts called\n"
			"	\"accounts.txt\" for printing\n"
			"2 - update an account\n"
			"3 -add a new account\n"
			"4 -delete an account\n"
			"5 -end program\n?");
			scanf("%d", &menuChoice);
			return menuChoice;
}
