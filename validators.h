#pragma once
#include<string>
using namespace std;


class FilmValidator
{
private:

public:

	FilmValidator() = default;
	~FilmValidator() = default;

	//Validator pentru titlu
	bool validareTitlu(string titlu);

	//Validator pentru gen
	bool validareGen(string gen);

	//Validator pentru an aparitie
	bool validareAnAparitie(int anAparitie);

	//Validator pentru actor principal
	bool validareActorPrincipal(string actorPrincipal);

	//Validator pentru numarul de filme generate
	bool validareNumar(int numar);
};