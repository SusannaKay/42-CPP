# 42-CPP: Guida di studio per i progetti

Questo repository contiene i progetti dei corsi 42 in C++. Il README è organizzato per modulo `CPP00`–`CPP07` e aiuta a capire i concetti principali trattati in ogni esercizio, prima di affrontare il codice.

---

## Come usare questo README

1. Leggi il modulo in ordine: i concetti sono progressivi.
2. Prima di aprire un esercizio, leggi la spiegazione dei temi chiave per comprendere i termini principali.
3. Usa il README come mappa: se non conosci un concetto, fermati e praticalo con esempi semplici.

---

## Struttura generale

- `CPP00/`: primi esempi di C++ con input/output e classi semplici.
- `CPP01/`: oggetti, gestione della memoria dinamica, riferimenti e composizione.
- `CPP02/`: classi con operatori, conversioni tra tipi e basi di geometria.
- `CPP03/`: ereditarietà, classi derivate e costruttori nelle gerarchie.
- `CPP04/`: polimorfismo, funzioni virtuali, distruttori virtuali e deep copy.
- `CPP05/`: eccezioni, classi astratte, astrazione e design OOP.
- `CPP06/`: conversioni di tipo, serializzazione e identificazione dinamica.
- `CPP07/`: template di funzione e classi template generiche.

---

## CPP00

### ex00: `megaphone.cpp`
Questo esercizio introduce i parametri della funzione `main`: `argc` è il numero di argomenti passati e `argv` è l'array di stringhe contenente questi argomenti.
Il programma deve leggere ciascun argomento, trasformare ogni carattere in maiuscolo e scrivere il risultato su standard output. L'idea è imparare a iterare sulle stringhe, a usare funzioni come `std::toupper` e a gestire il ciclo di elaborazione degli argomenti.

### ex01: `PhoneBook`, `Contact`
Qui si definiscono classi semplici: `Contact` memorizza informazioni di una persona e `PhoneBook` gestisce una collezione di contatti.
Il concetto di incapsulamento significa mantenere i dati privati e fornire metodi pubblici per leggere e aggiornare quelle informazioni.
L'esercizio usa un array statico di oggetti `Contact` con dimensione fissa, mostrando come organizzare una piccola applicazione a oggetti in C++.

---

## CPP01

### ex00: `Zombie` classica
In questo esercizio si definisce una classe `Zombie` con costruttore e distruttore.
Il costruttore viene chiamato quando l'oggetto nasce, il distruttore quando l'oggetto viene distrutto.
Si confrontano oggetti creati sullo stack (allocazione automatica, distruzione automatica quando si esce dal blocco) e oggetti creati sul heap con `new` (che richiedono `delete` per evitare perdite di memoria).

### ex01: `zombieHorde`
Qui si impara a creare un array dinamico di oggetti con `new[]` e a deallocarlo con `delete[]`.
L'esercizio mostra come la memoria dinamica permette di gestire un numero variabile di elementi, ma impone la responsabilità di liberarla correttamente.

### ex02
Questo esercizio è un passo intermedio che rafforza la gestione di oggetti, l'input/output e la logica di controllo.
L'obiettivo è consolidare la costruzione di oggetti, la loro manipolazione e l'uso di funzioni semplici per eseguire comportamenti legati al progetto.

### ex03: `HumanA`, `HumanB`, `Weapon`
Qui si studia la composizione: un `Human` possiede o usa un `Weapon`.
`HumanA` riceve il `Weapon` tramite riferimento, che significa che il `Human` lavora su un oggetto già esistente e non ne gestisce la vita.
`HumanB` riceve il `Weapon` tramite puntatore, che può essere nullo e richiede attenzione nel controllo.
Questo insegna la differenza tra riferimento e puntatore come membro di una classe e come la vita dell'oggetto associato influisce sul comportamento.

### ex05: `Harl`
L'esercizio mostra come associare livelli di log a comportamenti diversi.
Il codice organizza le varie frasi di `Harl` in metodi separati e sceglie quale metodo eseguire in base a una stringa di livello.
Questo esercizio insegna a costruire un piccolo dispatcher: una funzione che traduce un input in una chiamata a un metodo appropriato.

### ex06: `HarlFilter`
Qui si estende il meccanismo del precedente esercizio con un filtro che permette di eseguire solo certi messaggi.
Il codice può usare un array di puntatori a metodi o una struttura dati che associa i livelli di log alle azioni vere e proprie, rendendo il comportamento più modulare.

---

## CPP02

### ex00/ex01/ex02: `Fixed`
Questo gruppo introduce una classe `Fixed` che rappresenta un numero in formato fixed-point.
Un numero fixed-point usa un intero interno per rappresentare il valore reale con un numero fisso di bit frazionari.
I costruttori permettono di creare l'oggetto da un valore intero o da un valore float, convertendo correttamente la parte frazionaria.
Il copy constructor e l'operator= gestiscono la copia dell'oggetto; la regola dei tre dice che se la classe gestisce risorse, è necessario definire costruttore di copia, operatore di assegnazione e distruttore.
I metodi `toFloat` e `toInt` convertono il valore interno nel tipo richiesto, mentre l'operatore `<<` permette di stampare l'oggetto in modo leggibile.
L'uso di `const` indica che una funzione non modifica l'oggetto e garantisce che i parametri non vengano alterati.

### ex03: `Point` e `bsp`
Qui si lavora con una classe `Point` che memorizza coordinate costanti `x` e `y`.
L'esercizio richiede di verificare se un punto è all'interno di un triangolo: si usa la geometria analitica, spesso con il calcolo dell'area o dei vettori e dei prodotti vettoriali.
Le funzioni free sono funzioni non associate a una classe, utili per operazioni geometriche, mentre i metodi sono funzioni che appartengono a un oggetto.

---

## CPP03

### ex00: `ClapTrap`
Si definisce una classe `ClapTrap` con attributi come punti vita, energia e danno.
I metodi implementano comportamenti come attaccare, subire danno e ripararsi.
Questo esercizio mostra come incapsulare dati e comportamento in una classe e come chiamare metodi per modificare lo stato dell'oggetto.

### ex01: estendere `ClapTrap`
L'estensione aggiunge nuovi metodi o logiche al comportamento della stessa classe.
Serve a comprendere come gestire la complessità aggiuntiva senza cambiare l'interfaccia di base.

### ex02: `FragTrap`
Questa lezione introduce l'ereditarietà: una classe derivata estende una classe base.
`FragTrap` eredita metodi e attributi da `ClapTrap`, può utilizzare i costruttori della base e aggiungere funzionalità proprie.
L'ereditarietà permette di riutilizzare codice e specializzare comportamenti.

### ex03: `DiamondTrap`
Qui si affronta l'ereditarietà multipla in C++.
Una classe derivata come `DiamondTrap` eredita da più classi base, che a loro volta derivano da una classe comune, creando ambiguità sui membri condivisi.
La risoluzione di questa ambiguità e l'inizializzazione corretta dei costruttori è il punto centrale.
L'override di metodi significa fornire una nuova implementazione in una classe derivata per un metodo già definito nella base.

---

## CPP04

### ex00: `Animal`, `Dog`, `Cat`, `WrongAnimal`, `WrongCat`
Il polimorfismo è la capacità di usare un puntatore o riferimento alla classe base per lavorare con oggetti di classi derivate.
Se un metodo è `virtual`, la chiamata a quel metodo su un puntatore di tipo base invoca l'implementazione della classe derivata reale.
Se non si usa `virtual`, viene chiamata la versione della classe base e il comportamento può essere sbagliato.
Un distruttore virtuale è necessario quando si distrugge un oggetto derivato tramite un puntatore alla base, altrimenti il distruttore della classe derivata non viene eseguito.

### ex01: `Brain` e deep copy
Questo esercizio mostra come gestire risorse dinamiche interne a un oggetto.
Se un oggetto contiene un puntatore a memoria allocata, una copia superficiale copia solo l'indirizzo, causando aliasing.
La deep copy invece alloca nuova memoria e copia i dati reali, così i due oggetti sono indipendenti.
Il copy constructor e l'operator= devono essere scritti in modo da effettuare questa copia profonda.

### ex02: array di animali e deep copy
Si costruisce un array di puntatori a `Animal` e si memorizzano oggetti di classi derivate come `Cat` e `Dog`.
Questo esercizio mostra come creare e distruggere oggetti derivati tramite puntatori alla base, sfruttando il polimorfismo e i distruttori virtuali.
È importante liberare correttamente ogni oggetto per evitare perdite di memoria.

---

## CPP05

### ex00: `Bureaucrat`
Questa classe rappresenta un burocrate con un grado.
Il progetto richiede che alcuni valori di grado siano invalidi: in questi casi si lancia un'eccezione.
Le eccezioni in C++ sono oggetti che segnalano errori e possono essere catturate con `try`/`catch`.
I metodi `incrementGrade` e `decrementGrade` cambiano il grado e devono controllare i limiti, lanciando eccezioni se si supera il range consentito.

### ex01: `Form`
`Form` è un documento che richiede una firma e un’esecuzione con gradi minimi.
La relazione con `Bureaucrat` mostra come una classe può operare su un'altra e verificare i permessi richiesti.
Quando un burocrate firma o esegue un modulo, si verifica che il suo grado sia sufficiente e in caso contrario viene lanciata un'eccezione.

### ex02: `AForm` e form specifici
`AForm` è una classe astratta base che dichiara metodi virtuali puri come `execute`.
Le classi derivate, come `ShrubberyCreationForm`, `RobotomyRequestForm` e `PresidentialPardonForm`, implementano i comportamenti specifici.
Questo introduce il concetto di classe astratta: una classe che non può essere istanziata direttamente ma definisce l'interfaccia comune.

### ex03: `Intern`
L'`Intern` è un esempio di pattern factory semplice.
Riceve una stringa che indica il tipo di modulo da creare e restituisce l'oggetto corrispondente.
Se il tipo non è riconosciuto, viene lanciata un'eccezione, mostrando come gestire errori in fase di creazione.

---

## CPP06

### ex00: `ScalarConverter`
Questo esercizio converte una stringa in diversi tipi primitivi: `char`, `int`, `float` e `double`.
Deve gestire casi speciali come `nan`, `+inf`, `-inf`, e situazioni in cui la conversione non è possibile.
Si tratta di parsing del testo e di formattare l'output correttamente per ciascun tipo.

### ex01: `serializer`
Il codice usa `reinterpret_cast` per trattare un puntatore come un valore intero grezzo.
Questo mostra la rappresentazione in memoria di un puntatore e i limiti dei cast a basso livello.
Il punto principale è capire che si sta interpretando la memoria, non effettuando una conversione di alto livello.

### ex02: `Base`, `A`, `B`, `C`
Si definisce una classe base con metodi virtuali e tre classi derivate.
L'obiettivo è identificare a runtime il tipo reale di un oggetto puntato tramite un puntatore o riferimento alla base, usando `dynamic_cast`.
Questo è il concetto di RTTI (Run-Time Type Information) e permette di verificare il tipo effettivo dell'oggetto durante l'esecuzione.

---

## CPP07

### ex00: `Function.hpp`
Questo esercizio introduce i template di funzione.
Un template di funzione permette di scrivere una singola definizione che funziona con più tipi diversi, sostituendo `T` con il tipo richiesto dal chiamante.
La funzione diventa generica e riutilizzabile senza duplicare il codice per ogni tipo.

### ex01: `iter.hpp`
`iter` è una funzione template che applica un'operazione a ciascun elemento di un array.
Accetta un array generico e una funzione, dimostrando come i template possono lavorare con diversi tipi e puntatori a funzione.

### ex02: `Array.hpp`, `Array.tpp`
Qui si crea una classe template container generica simile a un array standard.
La classe gestisce la memoria dinamica per il contenuto, fornisce l'accesso tramite `operator[]` e deve gestire la copia e l'assegnazione in modo corretto.
La regola dei cinque si applica anche ai template: costruttore, distruttore, copy constructor, operator= e move assignment se necessario.
Un'eccezione personalizzata per indice fuori limite mostra come controllare gli accessi invalidi.

---

## Suggerimenti di studio

- Ripassa la sintassi base del C++: classi, costruttori, distruttori, puntatori e riferimenti.
- Studia le regole di gestione della memoria: stack vs heap, `new/delete`, copia profonda.
- Comprendi il polimorfismo e la differenza tra funzioni virtuali e non virtuali.
- Approfondisci `const` in C++: metodi const, parametri const, riferimenti const.
- Prima di ogni modulo, prova a scrivere piccoli esempi isolati per evitare di confondere i concetti.

---

## Note pratiche

- Ogni sotto-cartella `CPP##/ex##` contiene un `Makefile` per compilare l'esercizio.
- Se il codice non compila subito, inizia dal README di questo modulo e confronta con esempi semplici.
- Non è necessario completare tutti gli esercizi in un solo passaggio: è preferibile consolidare prima i concetti base.
