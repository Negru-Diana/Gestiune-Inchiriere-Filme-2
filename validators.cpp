#include "validators.h"

/*
Validator pentru titlu

	pre: titlu - string
	post: returneaza true daca titlu nu este un string null
		  returneaza false daca titlul este un string null

*/
bool FilmValidator::validareTitlu(string titlu)
{
	if (titlu == "")
	{
		return false;
	}

	return true;
}

/*
Validator pentru gen

	pre: gen - string
	post: returneaza true daca gen nu este un string null
		  returneaza false daca gen este un string null

*/
bool FilmValidator::validareGen(string gen)
{
	if (gen == "")
	{
		return false;
	}

	return true;
}

/*
Validator pentru an aparitie

	pre: anAparitie - int
	post: returneaza true daca anAparitie > 0
		  returneaza false daca anAparitie <= 0

*/
bool FilmValidator::validareAnAparitie(int anAparitie)
{
	if (anAparitie<=0)
	{
		return false;
	}

	return true;
}

/*
Validator pentru actor principal

	pre: actorPrincipal - string
	post: returneaza true daca actorPrincipal nu este un string null
		  returneaza false daca actorPrincipal este un string null

*/
bool FilmValidator::validareActorPrincipal(string actorPrincipal)
{
	if (actorPrincipal == "")
	{
		return false;
	}

	return true;
}


/*
Validator pentru numarul de filme generate

	pre: numar - int
	post: returneaza true daca numar > 0
		  returneaza false daca numar <= 0

*/
bool FilmValidator::validareNumar(int numar)
{
	if (numar <= 0)
	{
		return false;
	}

	return true;
}