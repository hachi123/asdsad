#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 800

const char *linetofield(char *l, int indx);
typedef struct {
	size_t id;
	char nombre[200];
	char desarrollador[200];
	char plataforma[200];
	/*time_t fecha; FIXME: strptime*/
	char fecha[12];
	double puntaje;
	size_t resenias;
}juego_t;

int main(int argc, char *argv[])
{
	FILE * juego;
	int menu;

	if((juego=fopen("db.text", "r+"))==NULL)
	printf("no se puede abrir el archivo.\n");
	else{
		while ((menu=ingreseMenu()) !=5) {
			switch (menu){
				case 1:
				textfile(juego);
				break;
				case 2:
				updateRecord(juego);
				break;
				case 3:
				newRecord(juego);
				break;
			}
		}
	}
	fclose(juego);
	return 0;
}
void textfile(FILE * juego_t)
{
	FILE *writeptr;
	struct juego_t ;

	if((writeptr=fopen("accounts.csv", "w"))==NULL)
	printf("el archivo no puede abrirse.\n");
	else{
		rewind(juego_t);/*genera un apuntador de posicion de archivo del programa*/
		fprintf(writeptr, "%s%s%s%s%d\n\n",&juego_t.nombre, &juego_t.desarrollador, &juego_t.plataforma, &juego_t.fecha, &juego_t.puntaje);

			while (!feof(juego_t)) {
				fread(&juego, sizeof(struct juego_t), 1, juego_t);

				if(juego.nombre !=0)
				fprintf(writeptr, "%s%s%s%s%d\n\n",juego.nombre, juego.desarrollador, juego.plataforma, juego.fecha, juego.puntaje);
				}
			}
			fclose(writeptr);
		}
		void updateRecord(FILE*juego)
		{
			struct juego_t nombre;
			fseek(juego, * sizeof(struct juego_t),SEEK_SET);
			fread(&juego, sizeof(struct juego_t), 1, juego);

			if (client.acctNum==0)
			printf("no hay informacion de la cuenta #%d.\n", account);

			else {
				printf("%s%s%s%s%d\n\n",juego.nombre, juego.desarrollador, juego.plataforma, juego.fecha, juego.puntaje);
				fseek(juego, sizeof(struct juego_t),SEEK_SET);
				fwrite(&juego, sizeof(struct juego_t), 1, juego);
			}
		}
		void deleteRecord(FILE*juego)
		{
			struct juego_t juego, Juego={0, ""};

			fseek(juego,  * sizeof(struct juego_t),SEEK_SET);
			fread( &juego, sizeof(struct juego_t), 1, juego);

			if (juego.nombre == 0)
			printf("el juego %d no existe.\n", nombre);
			else{
				fseek(juego, * sizeof(struct juego_t),SEEK_SET);
				fwrite(&Juego, sizeof(struct juego_t), 1, juego);
			}
		}
		void newRecord(FILE*juego)
		{
			struct juego_t nombre;

			fseek(juego, * sizeof(struct juego_t),SEEK_SET);
			fread(&juego, sizeof(struct juego_t), 1, juego);

			if (juego.nombre !=0)
			printf("el juego #%d ya contiene informacion.\n",juego.nombre);

			else{
				fseek(juego, * sizeof(struct juego_t), SEEK_SET);
				fwrite(&juego, sizeof(struct juego_t), 1, juego);
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
