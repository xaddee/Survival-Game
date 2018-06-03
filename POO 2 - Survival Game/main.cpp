#include "Game.h"

/* pentru denumiri, variabilele sunt de forma: numele_variabilei, functiile de forma: numeleFunctiei, iar variabilele membre din clase au "_" inainte de nume (ex _numele_variabilei)
	agentii sunt facuti sa caute intai un item in jurul lor, apoi un agent, iar daca niciuna dintre cele doua nu este gasita, ei se muta la intamplare. daca sunt prea putini agenti ramasi 
	pur si simplu vor merge spre mijlocul mapei, ignorand itemele (aceast feature este adaugat pt ca jocul sa nu dureze prea multe runde)
*/


int main()
{
	Game game;

	game.start(20, 21, 10); //  20 reprzinta dimensiunea mapei (20x20), 21 este numarul de agenti iar 10 numarul de iteme

	system("pause");
	return 0;
}