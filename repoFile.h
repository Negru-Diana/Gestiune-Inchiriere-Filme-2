#pragma once
#include"repo.h"

// Repo pentru fisiere, clasa extinsa a clasei FilmRepo
class RepoFile : public FilmRepo
{
private:
	string fisier;

public:

	//constructor
	RepoFile(const string& file) : FilmRepo(), fisier{ file }
	{
		loadFile();
	}

	void setPath(const string& file)
	{
		this->fisier = file;
	}

	//Incarc filmele din fisier in lista de filme
	void loadFile();

	//Scriu filmele din lista de filme in fisier
	void writeFile();

	//Golesc fisierul
	void emptyFile();

	~RepoFile() = default;

};