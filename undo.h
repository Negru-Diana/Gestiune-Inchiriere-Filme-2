#pragma once
#include"domain.h"
#include"repo.h"
#include"repoFile.h"

class ActiuneUndo
{
private:

public:
	virtual void doUndo() = 0;
	virtual ~ActiuneUndo() = default;
};


class UndoAdauga :public ActiuneUndo
{
private:

	string titlu; // titlul filmului care a fost adaugat
	string gen; // genul filmului care a fost adaugat
	RepoFile& repo;

public:

	UndoAdauga(const string& titlu, const string& gen, RepoFile& repo) : titlu{ titlu }, gen{ gen }, repo{ repo } {}

	void doUndo() override // sterg filmul care a fost adaugat
	{
		repo.sterge(titlu, gen);
	}
};


class UndoSterge :public ActiuneUndo
{
private:

	Film film;
	RepoFile& repo;

public:

	UndoSterge(const Film& film, RepoFile& repo) : film{ film }, repo{ repo } {}

	void doUndo() override // adaug filmul care a fost sters
	{
		repo.store(film);
	}
};


class UndoModifica :public ActiuneUndo
{
private:

	string titlu; // titlul filmului care a fost modificat
	string gen; // genul filmului care a fost modificat
	Film film; // filmul inainte de a fi modificat
	RepoFile& repo;

public:

	UndoModifica(const string& titlu, const string& gen, const Film& film, RepoFile& repo) : titlu{ titlu }, gen{ gen }, film{ film }, repo{ repo } {}

	void doUndo() override // remodific la starea initiala filmul care a fost modificat
	{
		repo.modifica(titlu, gen, film);
	}
};