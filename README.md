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
-  Stergere filme din cos
-  Generare cos cu filme aleatorii

### 3. Functionalitati suplimentare
-  Undo pentru ultima operatie efectuata
-  Exportarea cosului intr-un fisier HTML
-  Generarea unui raport despre genurile de filme

### 4. Interfete grafice multiple
-  **Fereastra principala**: centralizeaza toate actiunile
-  **Fereastra pentru cos**: permite gestionarea filmelor selectate
-  **Mod Read-Only**: ofera o vizualizare grafica a cosului, unde fiecare film este repezentat printr-o forma geometrica

## Tehnologii utilizate
- **Limbaj**: C++ (folosind STL pentru structuri de date si algoritmi)
- **Interfata Grafica**: Qt Framework
- **Stocare**: datele sunt salvate in fisiere text
- **Design Patterns**:
    -  **Observer**: actualizeaza automat interfata cosului la fiecare modificare
    -  **Layered Architecture**: separarea logicii aplicatiei

