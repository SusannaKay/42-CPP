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
