# Aplicatie pentru Gestionarea Inchirierilor de Filme

  Acest proiect este o aplicatie desktop dezvoltata in **C++**, dezvoltata cu **Qt Framework**, care permite administrarea unei colectii de filme si gestionarea unui sistem de inchirieri.


## Functionalitati principale:

### 1. Administrarea de filme
-  Adaugare, modificare si stergere filme
-  Cautare filme dupa titlu
-  Vizualizare filme in format tabelar sau lista
-  Filtrare filme dupa anul aparitiei sau titlu
-  Sortare filme dupa titlu, actor principal sau gen + an aparitie

### 2. Gestionarea inchirierilor
-  Adaugare filme in cosul de inchirieri
-  Stergere filme din cosul de inchirieri
-  Generare cos cu filme aleatorii

### 3. Functionalitati suplimentare
-  Undo pentru ultima operatie efectuata
-  Exportarea cosului de inchirieri intr-un fisier HTML
-  Generarea unui raport despre genurile de filme

### 4. Interfete grafice multiple
-  **Fereastra principala**: centralizeaza toate actiunile
-  **Fereastra pentru cos**: permite gestionarea filmelor selectate
-  **Mod Read-Only**: ofera o vizualizare grafica a cosului de inchirieri, unde fiecare film este reprezentat printr-o forma geometrica

## Obiective proiect
  Proiectul a fost realizat in **Anul I, Semestrul 2** de facultate, la cursul de **Programare Orientata Obiect**, avand ca obiective principale:
-  **Dezvoltarea competentelor practice in C++**:
    -  Utilizarea **STL** (Standard Template Library) pentru structuri de date si algoritmi
    -  Implementarea unui sistem CRUD
-  **Integrarea interfetei grafice cu Qt Framework**:
    -  Crearea de componente vizuale folosind QWidgets
-  **Implementarea Design Pattern-urilor**:
    -  **Observer Pattern**: asigurarea sincronizarii automate a interfetei cosului de inchirieri cu datele interne
    -  **Layered Architecture**: separarea logicii de business, stocarea datelor si interfata utilizator
-  **Gestionarea persistentei datelor**:
    -  Salvarea si incarcarea datelor in/din fisiere text
-  **Testare si Validare**
    -  Verificarea functionalitatilor prin testare unitara

