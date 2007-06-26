/*
 * usuario/bajador.c
 *
 *  Minikernel. Versi�n 1.0
 *
 *  Fernando P�rez Costoya
 *
 */

/*
 * Programa de usuario que abre un sem�foro y lo baja.
 */

#include "servicios.h"

int main(){
	int id, desc;


	id=obtener_id_pr();
	printf("bajador (%d) comienza\n", id);

	if ((desc=abrir_sem("s1"))<0)
		printf("error creando s1. NO DEBE SALIR\n");

	printf("bajador (%d) baja sem�foro\n", id);

	/* Se debe bloquear */
	if (bajar(desc)<0)
		printf("error en bajar de semaforo. NO DEBE SALIR\n");

	/* desbloqueado por el subir */
	printf("bajador (%d) termina\n", id);

	/* cierre impl�cito de sem�foros */
	return 0;
}
