# Aplicatie pentru Gestionarea Inchirierilor de Filme

  Acest proiect este o aplicatie desktop dezvoltata in **C++**, dezvoltata cu **Qt Framework**, care permite administrarea unei colectii de filme si gestionarea unui sistem de cos pentru inchirieri. Aplicatia ofera un set complet de instrumente pentru organizarea eficienta a filmelor, de la operatii CRUD pana la generarea de rapoarte si exportul datelor.


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
-  Generarea cosului cu filme aleatorii
-  Vizualizare cos in doua moduri: CRUD si Read-Only

### 3. Functionalitati avansate
-  Undo pentru ultima operatie efectuata
-  Generarea de rapoarte despre genurile de filme si distributia acestora

### 4. Interfete grafice multiple
-  **Fereastra principala**: centralizeaza toate actiunile
-  **Fereastra pentru cos**: vizualizeaza si gestioneaza filmele selectate
-  **Mod Read-Only**: afiseaza cosul ca o histograma dinamica cu forme geometrice

## Tehnologii si structura
- **Limbaj**: C++ (folosind STL pentru structuri de date si algoritmi)
- **Interfata Grafica**: Qt Framework
- **Stocare**: datele sunt salvate in fisiere text
- **Design Patterns**:
    -  **Observer**: actualizeaza automat interfata cosului la fiecare modificare
    -  **Layered Architecture**: separarea logicii de business, date si interfata

