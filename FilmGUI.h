#pragma once
#include <QtWidgets/qwidget.h>
#include <QtWidgets/qlabel.h> // biblioteca pentru label
#include <QtWidgets/qpushbutton.h> // biblioteca pentru push button
#include <QtWidgets/qboxlayout.h> // biblioteca pentru box layout
#include <QtWidgets/qlineedit.h> // biblioteca pentru line edit
#include <QtWidgets/qformlayout.h> // biblioteca pentru perechi (forme de a introduce date)
#include <QtWidgets/qlistwidget.h> // biblioteca pentru liste
#include <QtWidgets/qcombobox.h> // biblioteca pentru combo box
#include <QtWidgets/qmessagebox.h> // biblioteca pentru message box
#include <QtWidgets/qtablewidget.h> // biblioteca pentru tabel
#include <qdebug.h> // biblioteca pentru qDebug
#include "service.h"
#include<qpainter.h>
#include<qrandom.h>
#include"MyListModel.h"
using namespace std;


class FilmGUI : public QWidget
{
public:

	FilmGUI(FilmService& serv) : serv { serv }
	{
		initGUI();
		//loadData();
		reloadList(serv.getAll());
		initConnect();

	}


private:

	FilmService& serv; //service filme

	vector<Film> filme = serv.getAll();
	MyListModel* model;

	QListView* listView = new QListView();

	QListWidget* lstFilme = new QListWidget; // creez o lista pentru filme
	QPushButton* btnExit = new QPushButton{ "  &Exit  " }; //button Exit
	QPushButton* btnAdauga = new QPushButton{ "  &Adauga  " }; //button Adauga film
	QLineEdit* txtTitlu = new QLineEdit; //line edit pentru titlu
	QLineEdit* txtGen = new QLineEdit; //line edit pentru gen
	QLineEdit* txtAnAparitie = new QLineEdit; //line edit pentru an aparitie
	QLineEdit* txtActorPrincipal = new QLineEdit; //line edit pentru actor principal
	QPushButton* btnModifica = new QPushButton{ "  &Modifica  " }; //button Modifica
	QPushButton* btnSterge = new QPushButton{ "  &Sterge  " }; //button Sterge
	QPushButton* btnAdaugaCos = new QPushButton{ "  &Adauga in cos  " }; //button Adauga in cos
	QPushButton* btnVizualizeazaCosCRUD = new QPushButton{ "  &Vizualizeaza cos " }; //button Vizualizeaza cos - CRUD
	QPushButton* btnVizualizeazaCosReadOnly = new QPushButton{ "  &Read Only Cos  " }; //button Vizualizeaza cos
	QPushButton* btnVizualizeazaFilme = new QPushButton{ "  &Vizualizeaza filme  " }; //button Vizualizeaza filme
	QPushButton* btnCauta = new QPushButton{ "  &Cauta  " }; //button Cauta
	QPushButton* btnFiltrare = new QPushButton{ "  &Filtrare (titlu/an)  " }; //button Filtrarea dupa titlu sau an
	QComboBox* sortCbox = new QComboBox{}; // creez un combo box pentru optiunea de sortare 
	QPushButton* btnRaport = new QPushButton{ "  &Raport  " }; //button Raport
	QPushButton* btnUndo = new QPushButton{ "  &Undo  " }; //button Undo
	QPushButton* btnGenuri = new QPushButton{ "  &Genuri filme  " }; //button Genuri filme - LAB 10
	QPushButton* btnTabelFilme = new QPushButton{ "  &Vizualizeaza filme in tabel  " }; //button vizualizare filme in tabel - LAB 11
	QPushButton* btnGolesteCos = new QPushButton{ " &Goleste cos " }; //button pentru golire cos - LAB 13
	QPushButton* btnGenereazaCos = new QPushButton{ " &Genereaza cos " }; //button pentru generare filme - LAB 13

	string titluFilm="";
	string genFilm="";

	//Incarc datele (filmele)
	void loadData(); 

	//Initializare GUI
	void initGUI();

	//Conexiune intre butoane si actiuni
	void initConnect();

	//Sterg datele din lineEdit
	void clearData();

	//Incarc lista de filme primita in lstFilme
	//void load(vector<Film>& filme);

	void reloadList(const vector<Film>& all);

	void handleTypeButtonClicked(const std::string& type);

};


//clasa pentru Raport
class RaportGUI : public QWidget
{
public:

	RaportGUI(FilmService& serv) : serv{ serv }
	{
		initRaportGUI();
		connectRaport();
	}

private:

	FilmService& serv; //service filme 

	map<string, DTOFilm> mp = serv.raport(); // raport genuri - numar filme

	QTableWidget* tableRaport = new QTableWidget{ static_cast<int>(mp.size()), 2 };  //tabel pentru raport
	QPushButton* btnExitRaport = new QPushButton{ "Exit" }; //button Exit


	//init RaportGUI
	void initRaportGUI();

	//Conexiune intre butoane si actiuni
	void connectRaport();
};


//clasa pentru Cos
//LAB 13 - CosCRUDGUI
//mosteneste clasa Observer pentru a putea actualiza fereastra de cos la fiecare operatie
class CosCRUDGUI : public QWidget, public Observer
{
public:

	CosCRUDGUI(FilmService& serv) : serv{ serv }
	{
		initCosGUI();
		loadCos();
		clearData();
		connectCos();
	}

private:

	FilmService& serv; //service filme 

	QListWidget* lstCosFilme = new QListWidget; //creez o lista pentru filmele din cos
	QLineEdit* txtCosTitlu = new QLineEdit; //line edit pentru titlu
	QLineEdit* txtCosGen = new QLineEdit; //line edit pentru gen
	QLineEdit* txtCosAnAparitie = new QLineEdit; //line edit pentru an aparitie
	QLineEdit* txtCosActorPrincipal = new QLineEdit; //line edit pentru actor principal
	QPushButton* btnGolesteCos = new QPushButton{ "Goleste cos" }; //button pentru golire cos
	QPushButton* btnGenereazaCos = new QPushButton{ "Genereaza cos" }; //button pentru generare filme
	QLineEdit* txtNumarGenerare = new QLineEdit; //line edit pentru numarul de filme generate
	QPushButton* btnExportCos = new QPushButton{ "Export cos" }; //button pentru export cos
	QPushButton* btnExitCos = new QPushButton{ "Exit" }; //button pentru exit


	//init CosGUI
	void initCosGUI();

	//Conexiune intre butoane si actiuni
	void connectCos();

	//incarca filmele din cos
	void loadCos();

	//Sterg datele din lineEdit
	void clearData();


	void update() override
	{
		loadCos(); //reincarc filmele dupa operatie
	}

};


//clasa pentru genuri - LAB 10
class GenuriGUI : public QWidget
{
public:

	GenuriGUI(FilmService& serv) : serv{ serv }
	{
		initGenuriGUI();
		connectGenuri();
	}

private:

	FilmService& serv; //service filme 

	map<string, DTOFilm> mp = serv.raport(); // raport genuri - numar filme

	QListWidget* lstGenuriFilme = new QListWidget; //lista in care sa se incarce filmele de un anumit gen
	QPushButton* btnExitGenuri = new QPushButton{ "Exit" }; //button Exit

	//init GenuriGUI
	void initGenuriGUI(); 

	//incarca filme in lstGenuriFilme
	void loadFilmeGenuri(string gen);

	//Conexiune intre butoane si actiuni
	void connectGenuri();
};


//clasa pentru filme in tabel - LAB 11
class TabelFilmeGUI : public QWidget
{
public:

	TabelFilmeGUI(FilmService& serv) : serv{ serv }
	{
		initTabelFilmeGUI();
		connectTabelFilme();
	}

private:

	FilmService& serv; //service filme  

	vector<Film> filme = serv.getAll();

	QTableWidget* tableFilme = new QTableWidget{ static_cast<int>(filme.size()), 4 };  //tabel pentru filme
	QPushButton* btnExitTabelFilme = new QPushButton{ "Exit" }; //button Exit

	//init TabelFilmeGUI
	void initTabelFilmeGUI();

	// Conexiune intre butoane si actiuni
	void connectTabelFilme();


};


//LAB 13 - cosReadOnly
//mosteneste clasa Observer pentru a putea actualiza fereastra de cos la fiecare operatie
class HistogramGUI : public QWidget, public Observer
{
public:
	
	HistogramGUI(FilmService& serv) : serv{ serv } 
	{
		connectHistogram();
		saveInitialPositions(); //pentru a salva pozitiile figurilor geometrice
	}

private:

	FilmService& serv; //service filme
	std::vector<Film> filmeCos = serv.getAllCos(); // vector cu filmele din cos
	std::vector<QRect> obiectePoz; // pozitiile initiale ale obiectelor
	bool needsRepaint = false; // variabila pentru a stii daca trebuie actualizata fereastra sau nu


	void paintEvent(QPaintEvent* ev) override 
	{
		QPainter p{ this };

		for (int i = 0; i < filmeCos.size(); ++i) 
		{
			if (i % 3 == 0) // desenez un cerc
			{
				p.drawEllipse(obiectePoz[i]); // pozitia x, pozitia y, latimea dreptunghi, inaltime dreptunghi ==> incadrarea cercului
			}
			else if (i % 3 == 1) // desenez un dreptunghi
			{
				p.drawRect(obiectePoz[i]); // pozitia x, pozitia y, latimea dreptunghi, inaltime dreptunghi
			}
			else if (i % 3 == 2) // desenez un triunghi
			{
				QPolygon polygon; // creez un obiect pentru triunghi
				QRect rect = obiectePoz[i]; // iau datele despre triunghi din lista pozitiile obiectelor
				polygon << rect.topLeft() << rect.topRight() << rect.bottomLeft(); // definesc varfurile triunghiului
				p.drawPolygon(polygon);
			}
		}
	}

	void connectHistogram() // creez un Observer
	{
		serv.addObserver(this);
	}

	void saveInitialPositions() // salvez/actualizez pozitiile obiectelor
	{
		obiectePoz.clear();
		int i = 0;
		for (const auto& f : filmeCos) 
		{
			int x = QRandomGenerator::global()->bounded(width() - 100); // coordonata aleatooare x
			int y = QRandomGenerator::global()->bounded(height() - 100); // coordonata aleatooare y

			// creez un obiect QRect pentru a defini un dreptunghi
			QRect rect(x, y, (i % 3 == 1) ? 100 : 100, (i % 3 == 1) ? 50 : 100);
			
			// pentru i%3 == 1 avem dimensiunea triunghiului de 100 x 50
			// pentru i%3 != 1 avem dimensiunea de 100 x 100
			// cu acestea, fac difereta intre un dreptunghi ( 100 x 50 ) si un triunghi sau un cerc ( 100 x 100 )
			
			obiectePoz.push_back(rect); // adaug obiectul in lista cu coordonatele obiectelor

			++i;
		}
	}

	void update() override // actualizare
	{
		std::vector<Film> newFilmeCos = serv.getAllCos();

		if (newFilmeCos.size() != filmeCos.size()) // verific daca s-a schimbat numarul de filme din cos
		{
			filmeCos = newFilmeCos;
			saveInitialPositions(); // actualizez pozitiile obiectelor
			repaint(); // actualizez obiectele 
		}
	}
};
