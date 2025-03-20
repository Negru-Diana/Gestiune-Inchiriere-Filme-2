#include "inchiriere_filme.h"
#include <QtWidgets/QApplication>
#include "FilmGUI.h"
#include "teste.h"
#include "service.h"

using namespace std;

int main(int argc, char *argv[])
{
    //testAll();

    QApplication a(argc, argv);

    RepoFile rep{ "filme.txt" };  // repo pentru filme cu fisiere
    CosRepo repoC{ rep };  // repo pentru cos
    FilmService serv{ rep, repoC };

    FilmGUI gui{ serv };
    gui.show();
   
    return a.exec(); // DOAR cand ajunge aici apare fereastra si paraseste functia a.exec() DOAR cand sunt inchise toate ferestrele aplicatiei
}