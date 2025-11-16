#include "utils/menu_controller.h"
#include <stdio.h>
#include <stdlib.h> 
#include "menus/menus.h"

/*
	Participantes do Grupo
	---------------------------------------
	# - Keven Xavier Campos
	# - Elton Reami
	# - Luana Alves Camilo
	# - Maisa Gomes Beatto
	# - Kauan De Freitas Neves
	# - Maria Eduarda Chaves Vieira
	---------------------------------------
*/

int main() {

	/*
	* Vamos começar o programa registrando os menus
	* Todo menu tem um metodo de registro, esse metodo serve para incluir o menu no controlador de menus (menu_controller)
	* Esse menu_controller é o responsável por gerenciar a navegação e a exposição dos menus
	*/
	RegisterMainMenu();
	RegisterProcessingMenu();
	RegisterParticipantsMenu();
	RegisterHistoryMenu();

	/*
	* Chamamos o "InvokeMenu" com -1 para iniciar o menu principal
	* O metodo "InvokeMenu" é um metodo do menu_controller.
	*/
    InvokeMenu(-1);
    return 0;
}
