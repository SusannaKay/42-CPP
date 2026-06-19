La STL si basa su 3 elementi principali:
- container
- iteratori
- algoritmi

Container ed iteratori li abbiamo visti nel modulo precedente. Ora si tratta di saper mettere insieme tutto e fare le scelte giuste per ogni esercizio. 

Il vincolo fondamentale del modulo é: ogni tipologia di container va usata una sola volta in tutto il modulo. 

### algoritmi
La STL fornisce algoritmi generici come ad es
- find
- sort
- lower_bound
- binary_search
- merge
- copy
ecc.
Lavorano tutti sugli iteratori, non sui container.

### complessitá temporale

cioé come cresce il tempo richiesto per effettuare una operazione al crescere del numero degli elementi. Questo costo non é in termini di tempo ( perché quello vari da pc a pc ), ma si intende come scala l'algoritmo scelto. 

#### O-Notation 

Immaginandoci
100
1000
10000
elementi
quanto peggiora il costo?

O(1) - Costo costante

1 elemento -> 1 operazione
1000 elementi -> 1 operazione
100000 elementi -> 1 operazione

l'esempio migliore é cercare un elemento in un vector.
v[1] == v[50] perché la memoria é contigua. internamente succede qualcosa tipo base_address + index * sizeof(type) e vai diretto alla memoria.

O(n) - Costo lineare
l'esempio migliore é quello di cercare un elemento in una lista. Per trovare il valore, devi attraversare nodo per nodo fino ad arrivare alla posizione di memoria desiderata. Devi quindi compiere n operazioni
| Elementi | Operazioni |
| -------- | ---------- |
| 10       | 10         |
| 100      | 100        |
| 1000     | 1000       |

O(log n) - Ogni operazione dimezza il problema

Tipico di container tipo map o set ( come quando cerchiamo la parola in un dizionario ).
| Elementi  | Operazioni |
| --------- | ---------- |
| 8         | 3          |
| 1024      | 10         |
| 1 milione | ~20        |

O(nˆ2) - Costo quadratico
Un esempio é l'applicazione del bubble sort: Per ogni elemento, scorro tutti gli altri.

| Elementi | Operazioni |
| -------- | ---------- |
| 10       | 100        |
| 1000     | 1.000.000  |

Come si calcola il costo?
Si contano le operazioni elementari tipo:
- confronto
- assegnazione
- accessi memoria
- dereference
- incrementi

esempi:
- ciclo for le iterazioni sono n --> O(n)
- doppio loop - iterazioni n * n --> O(nˆ2)
- Binary search - iterazioni n/2 --> O(log n)

| Complessità | Significato        |
| ----------- | ------------------ |
| O(1)        | costante           |
| O(log n)    | cresce lentamente  |
| O(n)        | cresce linearmente |
| O(n log n)  | sorting efficiente |
| O(n²)       | cresce molto male  |

Tutto questo serve per scegliere il container giusto ed avere delle performance buone. Nello specifico di questo modulo dobbiamo tenere in considerazione alcune operazioni e capirne la complessitá, a titolo d'esempio:

| Operazione           | vector | list | map      |
| -------------------- | ------ | ---- | -------- |
| accesso random       | O(1)   | O(n) | O(log n) |
| inserimento in mezzo | O(n)   | O(1) | O(log n) |
| ricerca              | O(n)   | O(n) | O(log n) |

## ex00

Abbiamo un db in csv con data ed exchange rate. Un input di tipo data | valore ( deve poter accettare sia float che int ). Per ogni riga dobbiamo trovare il rate corretto, moltiplicare e stampare il risultato. Se la data non é nel db, dobbiamo trovare la data piú vicina precedente. 

Ci serve quindi un contenitore chiave - valore ordinato. Le opzioni sono std::map e std::multimap, tra queste map non ammette chiavi duplicate, quindi useremo questo contenitore.  

#### std::map

esempio di utilizzo

std::map<std::string, double> prices;
prices["2024-01-01"] = 42.0;

Costo ricerca: O(log n) con prices.find("data")e in piú abbiamo a disposizione la funzione .lower_bound() che cerca la prima chiave non minore di un certo valore. 

Quindi é un container buono per bitcoin exchange. 

Prima di proseguire controlliamo di quali container hanno bisogno gli altri esercizi visto che se usiamo map sull'ex00, non possiamo usarlo da nessun altra parte. 
----------------------------------------
ex01: 

l esercizio richiede di usare la reverse polish notation, in cui gli operatori seguono gli operandi. Il vantaggio di questa notation é che rimuove il bisogno di dare un ordine con le parentesi. Il concetto di stack é implicito in questo metodo, quindi useró questo container per l ex01

ex02:

in questo esercizio dobbiamo usare l algoritmo di Ford-johnson che si puo riassumere cosi:

1.crea coppie
2.ordina le coppie
3.costruisce una chain principale
4.inserisce gli elementi rimanenti con binary search
5.usa Jacobsthal per ottimizzare l’ordine degli inserimenti

l algoritmo deve essere applicato su due container diversi e l idea é quella di confrontare le performance dei due container

l ordinamento e la creazione di coppie cosi come i confronti sono piu rapidi ed efficaci con container che permettono l accesso con indice. Quindi sicuramente uno dei container che usero' é std::vector. L'altra cosa che mi viene in mente é che visto che ad un certo punto costruisce una chain, quindi una sorta di lista con nodi, ma per un algo del genere probabilmente é poco efficiente per accesso casuale ( oltre al fatto che non prevede l accesso per indice ).  std::deque di contro é rapido con l accesso e si possono pushare elementi front e back in maniera efficace. 

----------------------------------------------

### Struttura del programma

- parse db
- salvataggio in map<data, valore>
- process input file
--parse riga
--validazione input
--ricerca rate corretto
--moltiplica
--stampa

### Spiegazione funzioni 

main.cpp:
validazione input -> n argc
apre file input -> se fallisce esce 
crea classe ( db hardcodato nei costruttori )
stampa output:
- validazione su ogni riga letta quindi per ogni entry faccio check e stampo di conseguenza 

BitcoinExchange.cpp:
Il costruttore chiama subito parseDB():
- apre data.csv
- lettura prima riga + validazione header
- loop lettura: 
-- posiziona l'indice prima del separatore ','
-- substringa data da indice 0 a pos
-- substringa value da pos + 1, a fine stringa
-- uso strtod passando pointer end --> value convertito da stringa a double
-- se ritorna un valore negativo o end é diverso da fine stringa vuol dire che ci sono simboli non ammessi in strtod e che quindi si é fermato prima.
-- validateDate()
- -- validazione formato data YYYY-MM-DD in termini di lunghezza e posizionamento "-"
- -- conversione dei dati in long esclusivamente per controllo validitá, nel programma manterremo la data in formato stringa perché sará piú semplice poi trovare la corrispondenza in map
-- se i controlli non escono con errore, creo il nodo in map con chiave data e valore value.
- chiudo il file.

A questo punto l'oggetto é creato ed include il db in formato map. Quindi chiamo dal main la funzione printRes passando il file di input.Il funzionamento é pressapoco lo stesso di parseDB:
- Il primo controllo é sull´header
- cerco il divisore che in questo caso é " | "
- mi creo le varie substringhe
- se strtod non esce con errore:
-- controllo data
--- mi creo un iteratore che punta al lower_bound di date: questa funzione ti restituisce l iteratore alla data se presente o a quella successiva piú vicina. Dato che a noi serve quella precedente piú vicina, se il valore é diverso dalla data cercata e se non restituisce un iteratore all inizio della mappa allora torniamo indietro di 1.
--- creo result e mando in stampa.
-- se validateDate fallisce esco con bad input
-- se non é positivo esco con not a positive number
- tutto ció che non ho gestito e non rientra nei casi precedenti é numero invalido

## Ex01

Lo scopo del programma é prendere in iput una espressione matematica in notazione Reverse polish. La notazione che siamo abituati ad usare é la infix ( 3 + 2 ). La reverse polish invece abbiamo (3 2 + ). Nel caso ad esempio di una moltiplicazione ( 3 + 2 ) * 2, viene scritta 3 4 + 2 *. Il lato positivo é che elimina completamente l'uso delle parentesi per dare la precedenza alle operazioni.
Altro esempio:

3 + (4 * 2)
3 4 2 * + 
Una calcolatrice RPN deve usare lo stack: l'algoritmo ha bisogno degli ultimi due valori disponibili. 

ordine con cui considerare gli operandi
right = top
left = second

8 3 - 
nello stack sarebbe

3
8

quindi 

right = 3
left = 8
op = -

quindi left op right ( in modo da non sbagliarsi con la sottrazione )

#### std::stack<int>

stack é un container adapter, internamente é un std::deque limitato. 
Operazioni disponibili:

push() - aggiunge a top
void pop() - rimuove top
top() - legge il valore in cima
size()
bool empty() - controlla se il container é vuoto

- complessitá 0(1)

#### Condizioni
stack.size() finale deve essere necessariamente == 1

rapporto numeri / operatori == 2:1

lo stack avrá anche risultati parziali, non solo numeri originali 

numeri originali a singola cifra

Error handling:

- token sconosciuto ( 2 3 s +)
- operatore senza operandi ( + )
- stack insufficiente ( 1 + )
- divisione per zero 
- stack finale con + elementi 


std::stringstream separa automaticamente gli spazi, crea uno stream con un cursore interno che si ferma al primo separatore quando lo inseriamo in una stringa. Spazi multipli vengono ignorati automaticamente

#### spiegazione funzioni:

Il costruttore prende gli argomenti passati dal main come stringa, creiamo uno stream ss a partire da args e lo parsiamo buttando i char letti dentro tmp. Il while ss >> tmp continua finché ss non fallisce, cioé a fine argomento. 

Il primo controllo che facciamo é se la lunghezza del pezzo "letto" é uguale ad 1. Da subject dobbiamo accettare solo cifre a 1 digit e determinati operatori, la cui lunghezza é sempre == 1. Se non rientra in quel caso lancia l'eccezione. 

all'interno della condizione: pusho i numeri nello stack finché non trovo un operatore. Questo perché nella reverse notation di base quando incontro un op, eseguo l operazione sui 2 numeri precedenti. Il risultato di questa operazione viene pushata nello stack, e poi continuo a pushare numeri finché non trovo un altro operatore e cosí via. Una volta che ho finito il parsing dello stream controllo la lunghezza dello stack che deve essere di 1, e stampo, altrimenti lancio l eccezione. 

## Ex02

Dobbiamo creare un programma in grado di sortare integer positivi usando l algoritmo di ford johnson. 

Se occorre un errore, dobbiamo mostrarlo sullo standard error

Dobbiamo usare almeno due cointainers

Gestire almeno 3000 integer diversi 

Implementare l algoritmo per ogni contenitore evitando funzioni generiche

output:

Before : lista int non sortati
After : lista int sortati
Time to process a range of X elements with std::container1 : tempo in us
Time to process a range of X elements with std::container2 : tempo in us

Il formato del tempo impiegato per sortare lo scegliamo noi, ma la precisione ci deve permettere di vedere la differenza tra i due container usati 

I duplicati li possiamo gestire come ci pare

### Deque e Vector 
entrambi i container permettono l accesso tramite indice, supportano push_back()
Vector usa memoria contigua
Deque usa memoria a blocchi 

### Ford-Johnson 
Input:
8 3 7 1 9 2

Step 1 - si creano delle coppie, se i numeri forniti sono dispari, il rimanente sará salvato in una variabile a parte
        (8,3)
        (7,1)
        (9,2)
Dovendo creare delle coppie useremo std::pair<int, int>

Step 2 - ordiniamo internamente le coppie ( primo numero il min, secondo il max )
        (3,8)
        (1,7)
        (2,9)

Step 3 - ordinamento coppia per valori grandi 
        (1,7)
        (3,8)
        (2,9)

Step 4 - prendo i secondi della coppia ed il minimo assoluto e creo mainchain

1 7 8 9

step 5 - inserisco i pendenti minimi con lower bound
step 6 - inserisco il numero spaiato se disparo

### Jacobsthal

Jacobsthal viene usato sui pendenti per ridurre il numero di confronti prima dell inserimento, cambiandone l ordine di inserimento. L idea é ordinare gli indici dei pend secondo jacobsthal e non l ordine dei numeri dei pend. 

Questo algoritmo ha una sequenza tipica che ha formula 

J(n) = J(n - 1) + 2 * J(n - 2)

calcolando un paio di valori a titolo di esempio:

J(2) = J(2 - 1) + 2 * J(2 -2)
J(2) = 1 + 2 * 0 = 1

J(3) = J(3 - 1) + 2 * J(3 -1) = 3

Quindi la sequenza é:

1 3 5 11 21 43 ...

Che sono sti numeri?
Sono indici che delimitano dei gruppi. Prendiamo i primi elementi: 1 3 5 11

Tra 1 e 3 abbiamo n[2] e n[3]
Tra 3 e 5 abbiamo n[4] e n[5]
Tra 5 e 11 abbiamo n[6] n[7] n[8] n[9] n[10] n[11]
e cosí via.

Il Ford-Johnson poi li inserisce al contrario ovvero partendo dall'estremitá piu a destra a ritroso quindi 
1
3 2
5 4
11 10 9 8 7 6 

Evito di approfondire l analisi matematica sennó finisco fra un paio di anni di capire questo esercizio, ma il Ford-Johnson dimostra che inserendo partendo da quella sequenza.. si riduce il numero di confronti necessari.

### Ordine di chiamata delle funzioni 

1. pairing
2. sort delle coppie
3. main chain
4. pend
5. Jacobsthal decide l'ordine
6. inserimento dei pend secondo quell'ordine facendo
        it = lower_bound(n)
        main.insert(it, value);

### Error handling

- lettere
- numeri positivi
- overflow int

## Container pair

std::pair<int, int> crea sostanzialmente una struct Pair con dentro 2 int ( first e second )

Costruttore std::pair<int, int> p(n1, n2);
anche std::make_pair(n1, n2) ritorna un pair<int, int>

esempio di utilizzo: std::pair<int,int> p = std::make_pair(3, 8);

l'accesso é p.first, p.second

### comparazione:
tra coppie: prima usa la comparazione con first, se sono uguali, confronta i second
sennó specifichi quale elemento vuoi confrontare

main
│
└── process()
     │
     ├── processVector()
     │     │
     │     ├── sortVectorPairs() OK
     │     ├── buildVectorMain() OK
     │     ├── insertVectorPend()
     │     └── insertVectorStraggler()
     │
     └── processDeque()
           │
           ├── sortDequePairs() OK
           ├── buildDequeMain() OK
           ├── insertDequePend()
           └── insertDequeStraggler()