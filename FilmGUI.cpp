#include "FilmGUI.h"
#include "service.h"
#include "validators.h"
#include "domain.h"
#include <QtWidgets/qlabel.h> // biblioteca pentru label
#include <QtWidgets/qpushbutton.h> // biblioteca pentru push button
#include <QtWidgets/qboxlayout.h> // biblioteca pentru box layout
#include <QtWidgets/qlineedit.h> // biblioteca pentru line edit
#include <QtWidgets/qformlayout.h> // biblioteca pentru perechi (forme de a introduce date)
#include <QtWidgets/qlistwidget.h> // biblioteca pentru liste
#include <QtWidgets/qcombobox.h> // biblioteca pentru combo box
#include <QtWidgets/qinputdialog.h> //biblioteca pentru fereastra de dialog
#include <QtWidgets/qtableview.h> //biblioteca pentru table view
#include <QApplication>
#include <QTimer>
#include <QEventLoop>
#include<qdebug.h>
using namespace std;


/*
Initializare GUI

	pre: true
	post: initializez GUI

*/
void FilmGUI::initGUI()
{

	setWindowTitle("Inchiriere filme"); //setez titlul ferestrei

	auto mainLy = new QVBoxLayout{}; // creez un vertical box layout
	setLayout(mainLy); // adaug layout-ul in panou

	auto formLy = new QFormLayout; // layout pentru perechi ( denumire - text field ), cuprinde si layout-urile: operatiiLy si cosLy
	formLy->addRow("Titlu: \n", txtTitlu);
	formLy->addRow("Gen: \n", txtGen);
	formLy->addRow("An aparitie: \n", txtAnAparitie);
	formLy->addRow("Actor principal: \n", txtActorPrincipal);

	auto operatiiLy = new QHBoxLayout{}; // layout pentru operatiile cu filme (adaugare, stergere, modificare)
	operatiiLy->addWidget(btnAdauga);
	operatiiLy->addWidget(btnModifica);
	operatiiLy->addWidget(btnSterge);
	operatiiLy->setSpacing(5); //adaug spatii intre butoane

	auto cosLy = new QHBoxLayout{}; // layout pentru operatiile cu cos (adauga in cos, goleste cos, genereaza cos)
	cosLy->addWidget(btnAdaugaCos);
	cosLy->addWidget(btnGolesteCos);
	cosLy->addWidget(btnGenereazaCos);
	cosLy->setSpacing(5); //adaug spatii intre butoane

	auto cosLy2 = new QHBoxLayout{}; // layout pentru operatiile cu cos (cos CRUD, cos READ ONLY)
	cosLy2->addWidget(btnVizualizeazaCosCRUD);
	cosLy2->addWidget(btnVizualizeazaCosReadOnly);
	cosLy2->setSpacing(5); //adaug spatii intre butoane

	auto labLy = new QHBoxLayout{}; // layout pentru: button genuri (LAB 10) si button tabel genuri (LAB 11)
	labLy->addWidget(btnGenuri);
	labLy->addWidget(btnTabelFilme);

	formLy->addItem(operatiiLy); // adaug operatiiLy la formLy
	formLy->addItem(cosLy); // adaug cosLy la formLy
	formLy->addItem(cosLy2); // adaug cosLy2 la formLy
	formLy->setSpacing(7); // adaug spatiu intre layout-uri
	//formLy->addItem(labLy); //adaug labLy la formly

	auto josLy1 = new QHBoxLayout{}; // layout care cuprinde alte operatii (vizualizare filme, cautare, filtrare, sortare)
	josLy1->addWidget(btnVizualizeazaFilme);
	josLy1->addWidget(btnCauta);
	josLy1->addWidget(btnFiltrare);
	
	josLy1->addWidget(sortCbox);

	// Optiunile din combo box
	sortCbox->addItem("Sortare dupa ...");
	sortCbox->addItem("titlu");
	sortCbox->addItem("actor principal");
	sortCbox->addItem("an aparitie + gen");
	sortCbox->setCurrentIndex(0); // setez index-ul de la combo box la primul element

	auto josLy2 = new QHBoxLayout{}; // layout care cuprinde alte operatii (raport, undo, exit)
	josLy2->addWidget(btnRaport);
	josLy2->addWidget(btnUndo);
	josLy2->addWidget(btnExit); // adaug Exit button la layout


	model = new MyListModel{serv.getAll()};
	listView->setModel(model);

	auto susLy = new QHBoxLayout{}; // layout care cuprinde: lstFilme, formLy
	susLy->addWidget(listView); 
	susLy->addItem(formLy);

	//adaug layout-urile la mainLy
	mainLy->addLayout(susLy); 
	mainLy->addLayout(labLy);
	mainLy->addLayout(josLy1); 
	mainLy->addLayout(josLy2); 


	//colorez butoanele
	btnAdauga->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnAdaugaCos->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnCauta->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnExit->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnFiltrare->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnGenuri->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnModifica->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnRaport->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnSterge->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnTabelFilme->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnUndo->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnVizualizeazaCosCRUD->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnVizualizeazaCosReadOnly->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnVizualizeazaFilme->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnGenereazaCos->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnGolesteCos->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");

	//colorez combo box-ul
	sortCbox->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");

	//colorez fereastra
	setStyleSheet("background-color: thistle;");

	//colorez lista
	listView->setStyleSheet("background-color: white; border: 1px solid #666666;");

	//colorez line edit-urile
	txtTitlu->setStyleSheet("background-color: white; border: 1px solid #666666;");
	txtGen->setStyleSheet("background-color: white; border: 1px solid #666666;");
	txtAnAparitie->setStyleSheet("background-color: white; border: 1px solid #666666;");
	txtActorPrincipal->setStyleSheet("background-color: white; border: 1px solid #666666;");

	//dimensiunea initiala a ferestrei
	resize(800, 450);
}


/*
Conexiune intre butoane si actiuni

	pre: true
	post: conecteaza butoanele cu actiunile pe care trebuie sa le execute apeland functiile corespondente din service si din validators

*/
void FilmGUI::initConnect()
{
	//Conexiune button Exit si actiune
	QObject::connect(btnExit, &QPushButton::clicked, [&]()
		{
			QMessageBox::information(nullptr, " ", "La revedere!"); //mesaj
			//close(); //inchid fereastra

			QApplication::closeAllWindows(); //pentru a inchide aplicatia
		});


	//Conexiune button Adauga si actiune
	QObject::connect(btnAdauga, &QPushButton::clicked, [&]()
		{
			auto qtxtTitlu = txtTitlu->text(); //iau titlul filmului din txtTitilu
			auto qtxtGen = txtGen->text(); //iau genul filmului din txtGen
			auto qtxtAnAparitie = txtAnAparitie->text(); //iau anul de aparitie al filmului din txtAnAparitie
			auto qtxtActorPrincipal = txtActorPrincipal->text(); //iau actorul principal al filmului din txtActorPrincipal

			//convertesc din qstring in StdString
			auto titlu = qtxtTitlu.toStdString(); 
			auto gen = qtxtGen.toStdString();
			auto actorPrincipal = qtxtActorPrincipal.toStdString();

			bool reusit = false;
			auto anAparitie = qtxtAnAparitie.toInt(&reusit); //convertesc din QString in int

			if (!reusit)
			{
				QMessageBox::information(nullptr, " ", "Anul apritiei trebuie sa fie un numar!");
				return;
			}

			int invalide = 0; //numar cate elemente sunt invalide
			FilmValidator val; //validator
			if (val.validareTitlu(titlu) == false)
			{
				QMessageBox::information(nullptr, " ", "Titlul este invalid!");
				invalide++;
			}

			if (val.validareGen(gen) == false)
			{
				QMessageBox::information(nullptr, " ", "Genul este invalid!");
				invalide++; 
			}

			if (val.validareAnAparitie(anAparitie) == false)
			{
				QMessageBox::information(nullptr, " ", "Anul aparitiei este invalid!");
				invalide++; 
			}

			if (val.validareActorPrincipal(actorPrincipal) == false)
			{
				QMessageBox::information(nullptr, " ", "Actorul principal este invalid!");
				invalide++; 
			}

			if (invalide == 0)
			{
				try
				{
					serv.add(titlu, gen, anAparitie, actorPrincipal);
					QMessageBox::information(nullptr, " ", "Film adaugat cu succes!");
					reloadList(serv.getAll());
					clearData();
				}
				catch (RepoException& e)
				{
					QMessageBox::information(nullptr, " ", QString::fromStdString(e.get_message()));
				}
			}
		});


	//Conexiune selectare un element din lstFilme si actiune
	/*QObject::connect(lstFilme, &QListWidget::itemClicked, [&](QListWidgetItem* currentItem)
		{
			if (currentItem) //verific daca exista un element selectat
			{
				QVariant filmData = currentItem->data(Qt::UserRole); //Obtin datele filmului
				auto filmAles = filmData.value<QString>();  //convertesc datele filmului in obiect de tip Film

				//Convertesc titlul si genul filmului din SQtring la string
				titluFilm = currentItem->text().toStdString();
				genFilm = filmAles.toStdString();
				
				vector<Film> filme = serv.getAll();
				for (auto const& f : filme)
				{
					if (f.get_titlu() == titluFilm && f.get_gen() == genFilm)
					{
						txtTitlu->setText(QString::fromStdString(f.get_titlu()));
						txtGen->setText(QString::fromStdString(f.get_gen()));
						txtAnAparitie->setText(QString::number(f.get_anAparitie()));
						txtActorPrincipal->setText(QString::fromStdString(f.get_actorPrincipal()));
					}
				}
			}
		});*/


	//Conexiune selectare un element din listView si actiune
	QObject::connect(listView->selectionModel(), &QItemSelectionModel::selectionChanged, [&] ()
		{
			auto selectedIndexes = listView->selectionModel()->selectedIndexes();
			if (!selectedIndexes.isEmpty()) //verific daca exista un element selectat
			{
				QModelIndex currentIndex = selectedIndexes.first();

				QVariant filmData = listView->model()->data(currentIndex, Qt::UserRole); //Obtin datele filmului
				auto filmAles = filmData.value<QString>();  //convertesc datele filmului in obiect de tip Film

				//Convertesc titlul si genul filmului din SQtring la string
				titluFilm = listView->model()->data(currentIndex, Qt::DisplayRole).toString().toStdString();
				genFilm = filmAles.toStdString();

				vector<Film> filme = serv.getAll();
				for (auto const& f : filme)
				{
					if (f.get_titlu() == titluFilm && f.get_gen() == genFilm)
					{
						txtTitlu->setText(QString::fromStdString(f.get_titlu()));
						txtGen->setText(QString::fromStdString(f.get_gen()));
						txtAnAparitie->setText(QString::number(f.get_anAparitie()));
						txtActorPrincipal->setText(QString::fromStdString(f.get_actorPrincipal()));
					}
				}

				listView->selectionModel()->clearSelection();
			}
		});



	//Conexiune button Modifica si actiune
	QObject::connect(btnModifica, &QPushButton::clicked, [&]() 
		{
			if (titluFilm == "" || genFilm == "")
			{
				QMessageBox::information(nullptr, " ", "Alegeti din lista ce film doriti sa modificati!");
				return;
			}

			auto qtxtTitlu = txtTitlu->text(); //iau titlul filmului din txtTitilu
			auto qtxtGen = txtGen->text(); //iau genul filmului din txtGen
			auto qtxtAnAparitie = txtAnAparitie->text(); //iau anul de aparitie al filmului din txtAnAparitie
			auto qtxtActorPrincipal = txtActorPrincipal->text(); //iau actorul principal al filmului din txtActorPrincipal

			//convertesc din qstring in StdString
			auto titlu = qtxtTitlu.toStdString();
			auto gen = qtxtGen.toStdString();
			auto actorPrincipal = qtxtActorPrincipal.toStdString();

			bool reusit = false;
			auto anAparitie = qtxtAnAparitie.toInt(&reusit); //convertesc din QString in int

			if (!reusit)
			{
				QMessageBox::information(nullptr, " ", "Anul apritiei trebuie sa fie un numar!");
				return;
			}

			int invalide = 0; //numar cate elemente sunt invalide
			FilmValidator val; //validator
			if (val.validareTitlu(titlu) == false)
			{
				QMessageBox::information(nullptr, " ", "Titlul este invalid!");
				invalide++;
			}

			if (val.validareGen(gen) == false)
			{
				QMessageBox::information(nullptr, " ", "Genul este invalid!");
				invalide++;
			}

			if (val.validareAnAparitie(anAparitie) == false)
			{
				QMessageBox::information(nullptr, " ", "Anul aparitiei este invalid!");
				invalide++;
			}

			if (val.validareActorPrincipal(actorPrincipal) == false)
			{
				QMessageBox::information(nullptr, " ", "Actorul principal este invalid!");
				invalide++;
			}

			if (invalide == 0)
			{
				try
				{
					Film filmModificat{ titlu,gen,anAparitie,actorPrincipal };
					serv.modifica(titluFilm, genFilm, filmModificat);
					QMessageBox::information(nullptr, " ", "Film modificat cu succes!");
					reloadList(serv.getAll());
					clearData();
					titluFilm = "";
					genFilm = "";
				}
				catch (RepoException& e)
				{
					QMessageBox::information(nullptr, " ", QString::fromStdString(e.get_message()));
				}
			}
		});


	//Conexiune button Sterge si actiune
	QObject::connect(btnSterge, &QPushButton::clicked, [&]() 
		{
			auto qtxtTitlu = txtTitlu->text(); //iau titlul filmului din txtTitilu 
			auto qtxtGen = txtGen->text(); //iau genul filmului din txtGen

			//convertesc din qstring in StdString
			auto titlu = qtxtTitlu.toStdString();
			auto gen = qtxtGen.toStdString();


			try
			{
				serv.sterge(titlu, gen);
				QMessageBox::information(nullptr, " ", "Film sters cu succes!"); 
				reloadList(serv.getAll());
				clearData(); 
			}
			catch (RepoException& e)
			{
				QMessageBox::information(nullptr, " ", QString::fromStdString(e.get_message()));
			}
		});


	//Conexiune button AdaugaCos si actiune
	QObject::connect(btnAdaugaCos, &QPushButton::clicked, [&]() 
		{
			auto qtxtTitlu = txtTitlu->text(); //iau titlul filmului din txtTitilu  
			auto qtxtGen = txtGen->text(); //iau genul filmului din txtGen 

			//convertesc din qstring in StdString 
			auto titlu = qtxtTitlu.toStdString(); 
			auto gen = qtxtGen.toStdString(); 


			try
			{
				serv.addCos(titlu, gen); 
				QMessageBox::information(nullptr, " ", "Film adaugat in cos!"); 
				reloadList(serv.getAll());
				clearData(); 
			}
			catch (RepoException& e) 
			{
				QMessageBox::information(nullptr, " ", QString::fromStdString(e.get_message())); 
			}
		});


	//Conexiune button VizualizeazaFilme si actiune
	QObject::connect(btnVizualizeazaFilme, &QPushButton::clicked, [&]()
		{
			reloadList(serv.getAll());
		});


	// Conexiune button Cauta si actiune
	QObject::connect(btnCauta, &QPushButton::clicked, [&]()  
		{
			auto qtxtTitlu = txtTitlu->text(); //iau titlul filmului din txtTitilu   

			//convertesc din qstring in StdString
			auto titlu = qtxtTitlu.toStdString(); 

			FilmValidator val; //validator 
			if (val.validareTitlu(titlu) == false) 
			{
				QMessageBox::information(nullptr, " ", "Titlul dupa care doriti sa cautati este invalid!"); 
				return;
			}

			try
			{
				vector<Film> filme = serv.cauta(titlu);
				reloadList(filme);
				clearData(); 
			}
			catch (RepoException& e)
			{
				QMessageBox::information(nullptr, " ", QString::fromStdString(e.get_message())); 
			}
			
		});


	// Conexiune button Filtrare si actiune
	QObject::connect(btnFiltrare, &QPushButton::clicked, [&]() 
		{
			int invalide = 0;
			auto qtxtTitlu = txtTitlu->text(); //iau titlul filmului din txtTitilu   

			//convertesc din qstring in StdString
			auto titlu = qtxtTitlu.toStdString();

			FilmValidator val; //validator 
			if (val.validareTitlu(titlu) == false)
			{
				invalide++;
			}
			else
			{
				try
				{
					vector<Film> filmeF = serv.filtrare(1, titlu);
					reloadList(filmeF); 
					clearData(); 
				}
				catch (RepoException& e) 
				{
					QMessageBox::information(nullptr, " ", QString::fromStdString(e.get_message())); 
				}
				return;
			}

			auto qtxtAnAparitie = txtAnAparitie->text(); //iau anul de aparitie al filmului din txtAnAparitie

			if (qtxtAnAparitie != "")
			{
				bool reusit = false; 
				auto anAparitie = qtxtAnAparitie.toStdString();

				bool reusit2 = false; 
				auto anAparitieINT = qtxtAnAparitie.toInt(&reusit2); //convertesc din QString in int 

				if (!reusit2) 
				{
					QMessageBox::information(nullptr, " ", "Anul apritiei trebuie sa fie un numar!"); 
					return;
				}

				if (val.validareAnAparitie(anAparitieINT) == false)
				{
					QMessageBox::information(nullptr, " ", "Anul aparitiei este invalid!"); 
					return;
				}
				 
				try
				{
					vector<Film> filme = serv.filtrare(2, anAparitie); 
					reloadList(filme); 
					clearData(); 
				}
				catch (RepoException& e) 
				{
					QMessageBox::information(nullptr, " ", QString::fromStdString(e.get_message())); 
				}
				return;
			}
			else
			{
				invalide++;
			}
			
			if (invalide > 1)
			{
				QMessageBox::information(nullptr, " ", "Pentru a filtra dupa titlu trebuie sa introduceti un titlu valid in campul destinat titlului, iar pentru a filtra dupa an trebuie sa introduceti un an valid in campul destinat anului de aparitie!");
			}
		});


	// Conexiune button Undo si actiune
	QObject::connect(btnUndo, &QPushButton::clicked, [&]() 
		{
			try
			{
				serv.Undo();
				QMessageBox::information(nullptr, " ", "Undo realizat cu succes!");
				reloadList(serv.getAll());
				clearData(); 
			}
			catch (RepoException& e) 
			{
				QMessageBox::information(nullptr, " ", QString::fromStdString(e.get_message())); 
			}
		});

	// Conexiune combo box sortare si actiune
	QObject::connect(sortCbox, QOverload<int>::of(&QComboBox::activated), [&](int index)  
		{
			if (index >= 1 && index <= 3)
			{
				try
				{
					vector<Film> filme = serv.sortare(index); 
					reloadList(filme); 
					clearData();
				}
				catch (RepoException& e) 
				{
					QMessageBox::information(nullptr, " ", QString::fromStdString(e.get_message())); 
				}
			}
		});


	// Conexiune button Undo si actiune
	QObject::connect(btnRaport, &QPushButton::clicked, [&]() 
		{
			RaportGUI* fereastraRaport = new RaportGUI(serv);
			fereastraRaport->show();
		});

	// Conexiune button VizualizeazaCosCRUD si actiune
	QObject::connect(btnVizualizeazaCosCRUD, &QPushButton::clicked, [&]()
		{
			CosCRUDGUI* fereastraCos = new CosCRUDGUI(serv);
			fereastraCos->show();
		});


	// Conexiune button btnVizualizeazaCosReadOnly si actiune
	QObject::connect(btnVizualizeazaCosReadOnly, &QPushButton::clicked, [&]() 
		{
			HistogramGUI* fereastraHGui = new HistogramGUI(serv);
			fereastraHGui->show();
			fereastraHGui->setFocus(); // Programmatically set focus to the widget
		});


	// Conexiune button Genuri si actiune
	QObject::connect(btnGenuri, &QPushButton::clicked, [&]() 
		{
			GenuriGUI* fereastraGenuri = new GenuriGUI(serv);
			fereastraGenuri->show();
		});

	// Conexiune button TabelFilme si actiune
	QObject::connect(btnTabelFilme, &QPushButton::clicked, [&]()
		{
			TabelFilmeGUI* fereastraTabelFilme = new TabelFilmeGUI(serv);
			fereastraTabelFilme->show();
		});

	//Conexiune button GolesteCos si actiune
	QObject::connect(btnGolesteCos, &QPushButton::clicked, [&]()
		{
			try
			{
				serv.delCos(); //golesc cosul
			}
			catch (RepoException&) {}
			
		});

	//Conexiune button GenereazaCos si actiune
	QObject::connect(btnGenereazaCos, &QPushButton::clicked, [&]()
		{
			//verific daca exista filme pentru a genera cosul
			vector<Film> listaFilme = serv.getAll();
			if (listaFilme.size() == 0)
			{
				QMessageBox::information(nullptr, " ", "Nu exista filme pentru a putea genera cosul!");
				return;
			}

			bool ok;

			//citesc numar de filme care trebuie generat cu ajutorul unei ferestre de dialog
			QString nr = QInputDialog::getText(this, "Numumar filme de generat", "Numar filme: ", QLineEdit::Normal, "", &ok);

			//daca s-a apasat butonul "OK" si s-a introdus un numar
			if (ok && !nr.isEmpty())
			{
				vector<Film> filme = serv.getAllCos();

				bool reusit = false;
				auto numar = nr.toInt(&reusit); //convertesc din QString in int

				if (!reusit)
				{
					QMessageBox::information(nullptr, " ", "Numarul de filme generate trebuie sa fie un numar!");
					return;
				}

				FilmValidator val; //validator 

				if (val.validareNumar(numar) == false)
				{
					QMessageBox::information(nullptr, " ", "Numarul este invalid!");
				}
				else
				{
					vector<Film> filme = serv.genereazaCos(numar);

					for (const auto& f : filme)
					{
						serv.addCos(f.get_titlu(), f.get_gen());
					}

					//loadCos(); //reincarc filmele din cos 
				}
			}

		});
}


void FilmGUI::reloadList(const vector<Film>& alll) 
{
	model->set(alll);
}


/*
Sterg datele din lineEdit

	pre: true
	post: sterg datele din lineEdit
*/
void FilmGUI::clearData()
{
	txtTitlu->clear();
	txtGen->clear();
	txtAnAparitie->clear();
	txtActorPrincipal->clear();
}



/*
Initializare RaportGUI

	pre: true
	post: initializez RaportGUI

*/
void RaportGUI::initRaportGUI()
{
	if (mp.size() == 0)
	{
		QMessageBox::information(nullptr, " ", "Nu exista raport de incarcat!");
		return;
	}

	setWindowTitle("Raport filme"); // Setez titlul ferestrei

	QVBoxLayout* mainLy = new QVBoxLayout{}; //creez un layout principal pentru raport
	setLayout(mainLy); //setez layout-ul

	tableRaport->setHorizontalHeaderLabels({ "Gen", "Numar filme" }); //capul de tabel

	int row = 0;

	//adaug elementele in tabel
	for (const auto& pair : mp)
	{
		tableRaport->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(pair.first)));
		tableRaport->setItem(row, 1, new QTableWidgetItem(QString::number(pair.second.getCount())));

		row++;
	}

	mainLy->addWidget(tableRaport);
	mainLy->addWidget(btnExitRaport);


	//Iterez prin tabel pentru a face celulele needitabile
	for (int row = 0; row < tableRaport->rowCount(); ++row) 
	{
		for (int col = 0; col < tableRaport->columnCount(); ++col) 
		{
			QTableWidgetItem* item = tableRaport->item(row, col);
			if (item) 
			{
				item->setFlags(item->flags() & ~Qt::ItemIsEditable);
			}
		}
	}


	//colorez butoanele
	btnExitRaport->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");

	//colorez fereastra
	setStyleSheet("background-color: thistle;");

	//colorez lista
	tableRaport->setStyleSheet("background-color: white; border: 1px solid #666666;");

	//dimensiunea initiala a ferestrei
	resize(270, 220);
}


/*
Conexiune intre butoane si actiuni

	pre: true
	post: conecteaza butoanele din RaportGUI cu actiunile pe care trebuie sa le execute

*/
void RaportGUI::connectRaport()
{
	//Conexiune button Exit si actiune
	QObject::connect(btnExitRaport, &QPushButton::clicked, [&]() 
		{
			close(); //inchide fereastra
		});
}



/*
Initializare CosGUI

	pre: true
	post: initializez CosGUI

*/
void CosCRUDGUI::initCosGUI()
{
	setWindowTitle("Cos filme"); //setez titlul ferestrei

	auto mainLy = new QVBoxLayout{}; //creez un layout principal pentru cos
	setLayout(mainLy); // adaug layout-ul

	auto formLy = new QFormLayout; // layout pentru perechi ( denumire - text field )
	formLy->addRow("Titlu: \n", txtCosTitlu);
	formLy->addRow("Gen: \n", txtCosGen);
	formLy->addRow("An aparitie: \n", txtCosAnAparitie);
	formLy->addRow("Actor principal: \n", txtCosActorPrincipal);

	txtCosTitlu->setReadOnly(true); 
	txtCosGen->setReadOnly(true);
	txtCosAnAparitie->setReadOnly(true);
	txtCosActorPrincipal->setReadOnly(true);


	auto susLy = new QHBoxLayout; //layout care cuprinde lstCosFilme si formLy
	susLy->addWidget(lstCosFilme);
	susLy->addLayout(formLy);

	auto btnSusLy = new QHBoxLayout; //layout care cuprinde: button generare cos si button export cos
	btnSusLy->addWidget(btnGenereazaCos);
	btnSusLy->addWidget(btnExportCos);

	auto btnJosLy = new QHBoxLayout; //layout care cuprinde: button goleste cos si button exit
	btnJosLy->addWidget(btnGolesteCos);
	btnJosLy->addWidget(btnExitCos);

	mainLy->addLayout(susLy);
	mainLy->addLayout(btnSusLy);
	mainLy->addLayout(btnJosLy);


	//colorez butoanele
	btnExitCos->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnExportCos->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnGenereazaCos->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	btnGolesteCos->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	
	//colorez fereastra
	setStyleSheet("background-color: thistle;");

	//colorez lista
	lstCosFilme->setStyleSheet("background-color: white; border: 1px solid #666666;");
	
	//colorez line edit-urile
	txtCosTitlu->setStyleSheet("background-color: white; border: 1px solid #666666;");
	txtCosGen->setStyleSheet("background-color: white; border: 1px solid #666666;");
	txtCosAnAparitie->setStyleSheet("background-color: white; border: 1px solid #666666;");
	txtCosActorPrincipal->setStyleSheet("background-color: white; border: 1px solid #666666;");

}


/*
Conexiune intre butoane si actiuni

	pre: true
	post: conecteaza butoanele din CosGUI cu actiunile pe care trebuie sa le execute

*/
void CosCRUDGUI::connectCos()
{
	serv.addObserver(this); //adaug un Observer pentru a putea actualiza cosul in timp real

	//Conexiune button Exit si actiune
	QObject::connect(btnExitCos, &QPushButton::clicked, [&]()
		{
			close(); //inchide fereastra
		});

	//Conexiune selectare un element din lstCosFilme si actiune
	QObject::connect(lstCosFilme, &QListWidget::itemDoubleClicked, [&](QListWidgetItem* currentItem)
		{
			if (currentItem) //verific daca exista un element selectat
			{
				QVariant filmData = currentItem->data(Qt::UserRole); //Obtin datele filmului
				auto filmAles = filmData.value<QString>();  //convertesc datele filmului in obiect de tip Film

				//Convertesc titlul si genul filmului din SQtring la string
				string titluFilm = currentItem->text().toStdString();
				string genFilm = filmAles.toStdString();

				vector<Film> filme = serv.getAll();
				for (auto const& f : filme)
				{
					if (f.get_titlu() == titluFilm && f.get_gen() == genFilm)
					{
						txtCosTitlu->setText(QString::fromStdString(f.get_titlu()));
						txtCosGen->setText(QString::fromStdString(f.get_gen()));
						txtCosAnAparitie->setText(QString::number(f.get_anAparitie()));
						txtCosActorPrincipal->setText(QString::fromStdString(f.get_actorPrincipal()));
					}
				}
			}
		});

	//Conexiune button GolesteCos si actiune
	QObject::connect(btnGolesteCos, &QPushButton::clicked, [&]()
		{
			try
			{
				serv.delCos(); //golesc cosul
			}
			catch (RepoException&) {}

			lstCosFilme->clear(); //golesc lstCosFilme
			clearData(); //sterg datele din line edit
		});

	//Conexiune button GenereazaCos si actiune
	QObject::connect(btnGenereazaCos, &QPushButton::clicked, [&]()
		{
			//verific daca exista filme pentru a genera cosul
			vector<Film> listaFilme = serv.getAll();
			if (listaFilme.size() == 0)
			{
				QMessageBox::information(nullptr, " ", "Nu exista filme pentru a putea genera cosul!");
				return;
			}

			bool ok;

			//citesc numar de filme care trebuie generat cu ajutorul unei ferestre de dialog
			QString nr = QInputDialog::getText(this, "Numumar filme de generat", "Numar filme: ", QLineEdit::Normal, "", &ok);

			//daca s-a apasat butonul "OK" si s-a introdus un numar
			if (ok && !nr.isEmpty()) 
			{
				vector<Film> filme = serv.getAllCos(); 

				bool reusit = false;
				auto numar = nr.toInt(&reusit); //convertesc din QString in int

				if (!reusit)
				{
					QMessageBox::information(nullptr, " ", "Numarul de filme generate trebuie sa fie un numar!");
					return;
				}

				FilmValidator val; //validator 

				if (val.validareNumar(numar) == false) 
				{
					QMessageBox::information(nullptr, " ", "Numarul este invalid!"); 
				}
				else
				{
					vector<Film> filme = serv.genereazaCos(numar); 

					for (const auto& f : filme) 
					{
						serv.addCos(f.get_titlu(), f.get_gen()); 
					}

					loadCos(); //reincarc filmele din cos 
				}
			}

		});

	//Conexiune button ExportCos si actiune
	QObject::connect(btnExportCos, &QPushButton::clicked, [&]()
		{ 
			bool ok; 

			//citesc numele fisierului de export cu ajutorul unei ferestre de dialog
			QString nume = QInputDialog::getText(this, "Nume fisier export", "Numele fisierului de export: ", QLineEdit::Normal, "", &ok); 
			
			//daca s-a apasat butonul "OK" si s-a introdus un nume de fisier
			if (ok && !nume.isEmpty()) 
			{ 
				vector<Film> filme = serv.getAllCos(); 
				string fisier = nume.toStdString(); 

				if (fisier.find(".html") == string::npos)
				{
					fisier += ".html";
				}

				serv.exportHTML(fisier, filme);

				QMessageBox::information(nullptr, " ", "Cosul a fost exportat cu succes!");
			}

		});
}


/*
Incarcare filmele din cos

	pre: true
	post: se incarca filmele din cos

*/
void CosCRUDGUI::loadCos()
{
	lstCosFilme->clear(); //golesc lstCosFilme
	vector<Film> filme = serv.getAllCos();


	for (const auto& f : filme)
	{
		// Creez un element de lista
		QListWidgetItem* item = new QListWidgetItem();

		//Setez textul vizualizat in lista pentru acest element
		item->setText(QString::fromStdString(f.get_titlu()));

		//Setez date suplimentare sub forma de sir de date
		QVariant filmData;
		filmData.setValue(QString::fromStdString(f.get_gen())); //Salvez intregul obiect Film in QVariant
		item->setData(Qt::UserRole, filmData); //Setez datele suplimentare pentru acest element

		//Adaug filmul in lista
		lstCosFilme->addItem(item);
	}
}


/*
Sterg datele din lineEdit

	pre: true
	post: sterg datele din lineEdit
*/
void CosCRUDGUI::clearData()
{
	txtCosTitlu->clear();
	txtCosGen->clear();
	txtCosAnAparitie->clear();
	txtCosActorPrincipal->clear();
}



/*
/Initializare GenuriGUI

	pre: true
	post: initializez GenuriGUI

*/
void GenuriGUI::initGenuriGUI() 
{
	//daca nu exista filme pentru care sa se incarce genurile
	if (mp.size() == 0)
	{
		QMessageBox::information(nullptr, " ", "Nu exista filme pentru a putea crea pagina cu genuri!");
		return;
	}

	setWindowTitle("Genuri filme"); //setez titlul ferestrei

	auto mainLy = new QHBoxLayout{}; //creez un layout principal pentru genuri 
	setLayout(mainLy); // adaug layout-ul 

	auto btnLy = new QVBoxLayout{}; //creez un layout pentru butoane genuri 

	//initializare butoane
	for (const auto& pair : mp)
	{
		//creare buton gen
		QPushButton* btn = new QPushButton(QString::fromStdString(pair.first));
		btnLy->addWidget(btn);

		//colorez butoanele
		btn->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");

		//conectare buton si actiune
		connect(btn, &QPushButton::clicked, [&]()
			{
				QString message = QString("Exista %1 filme care au genul %2.").arg(pair.second.getCount()).arg(QString::fromStdString(pair.first));
				QMessageBox::information(nullptr, " ", message);

				loadFilmeGenuri(pair.first); //incarc filmele in lstGenuriFilme

			});
	}

	auto dreaptaLy = new QVBoxLayout{}; //layout care cuprinde: lista cu genurile de filme si button exit
	dreaptaLy->addWidget(lstGenuriFilme);
	dreaptaLy->addWidget(btnExitGenuri);

	mainLy->addLayout(btnLy);
	mainLy->addLayout(dreaptaLy);
	

	//colorez butoanele
	btnExitGenuri->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");

	//colorez fereastra
	setStyleSheet("background-color: thistle;");

	//colorez lista
	lstGenuriFilme->setStyleSheet("background-color: white; border: 1px solid #666666;");

}


/*
Incarcare filme in lstGenuriFilme care au genul = gen

	pre: gen - string
	post: se incarca filme in lstGenuriFilme care au genul = gen

*/
void GenuriGUI::loadFilmeGenuri(string gen)
{
	lstGenuriFilme->clear(); //golesc lstCosFilme

	vector<Film> filme = serv.getAll(); 

	for (const auto& f : filme)
	{
		if (f.get_gen() == gen)
		{
			// Creez un element de lista
			QListWidgetItem* item = new QListWidgetItem();

			//Setez textul vizualizat in lista pentru acest element
			item->setText(QString::fromStdString(f.get_titlu()));

			//Setez date suplimentare sub forma de sir de date
			QVariant filmData;
			filmData.setValue(QString::fromStdString(f.get_gen())); //Salvez intregul obiect Film in QVariant
			item->setData(Qt::UserRole, filmData); //Setez datele suplimentare pentru acest element

			//Adaug filmul in lista
			lstGenuriFilme->addItem(item);
		}
	}
}



/*
Conexiune intre butoane si actiuni

	pre: true
	post: conecteaza butoanele din GenuriGUI cu actiunile pe care trebuie sa le execute

*/
void GenuriGUI::connectGenuri()
{
	//Conexiune button Exit si actiune
	QObject::connect(btnExitGenuri, &QPushButton::clicked, [&]()
		{
			close(); //inchide fereastra
		});
}



//init TabelFilmeGUI
void TabelFilmeGUI::initTabelFilmeGUI()
{
	if (filme.size() == 0)
	{
		QMessageBox::information(nullptr, " ", "Nu exista filme de incarcat!");
		return;
	}

	setWindowTitle("Filme"); // Setez titlul ferestrei 

	QVBoxLayout* mainLy = new QVBoxLayout{}; //creez un layout principal pentru raport
	setLayout(mainLy); //setez layout-ul

	tableFilme->setHorizontalHeaderLabels({ "Titlu", "Gen", "An aparitie", "Actor principal"}); //capul de tabel

	int row = 0;

	//adaug elementele in tabel
	for (const auto& f : filme)
	{
		tableFilme->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(f.get_titlu())));
		tableFilme->setItem(row, 1, new QTableWidgetItem(QString::fromStdString(f.get_gen())));
		tableFilme->setItem(row, 2, new QTableWidgetItem(QString::number(f.get_anAparitie())));
		tableFilme->setItem(row, 3, new QTableWidgetItem(QString::fromStdString(f.get_actorPrincipal())));

		row++;
	}

	mainLy->addWidget(tableFilme);
	mainLy->addWidget(btnExitTabelFilme);

	//Iterez prin tabel pentru a face celulele needitabile
	for (int row = 0; row < tableFilme->rowCount(); ++row)
	{
		for (int col = 0; col < tableFilme->columnCount(); ++col)
		{
			QTableWidgetItem* item = tableFilme->item(row, col);
			if (item)
			{
				item->setFlags(item->flags() & ~Qt::ItemIsEditable);
			}
		}
	}

	//colorez butoanele
	btnExitTabelFilme->setStyleSheet("background-color: mediumorchid; color: black; border: 1px solid #666666;");
	
	//colorez fereastra
	setStyleSheet("background-color: thistle;");

	//colorez lista
	tableFilme->setStyleSheet("background-color: white; border: 1px solid #666666;");

	//dimensiunea initiala a ferestrei
	resize(470, 300);

}


/*
Conexiune intre butoane si actiuni

	pre: true
	post: conecteaza butoanele din TabelFilmeGUI cu actiunile pe care trebuie sa le execute

*/
void TabelFilmeGUI::connectTabelFilme()
{
	//Conexiune button Exit si actiune
	QObject::connect(btnExitTabelFilme, &QPushButton::clicked, [&]()
		{
			close(); //inchide fereastra
		});
}
