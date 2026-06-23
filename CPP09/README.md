# CPP09 - STL e container

La STL si basa su 3 elementi principali:

- container
- iteratori
- algoritmi

Container ed iteratori li abbiamo visti nel modulo precedente. Ora si tratta di mettere insieme tutto e fare le scelte giuste per ogni esercizio.

Il vincolo fondamentale del modulo è: ogni tipologia di container va usata una sola volta in tutto il modulo.

## Algoritmi STL

La STL fornisce algoritmi generici come ad es:

- `find`
- `sort`
- `lower_bound`
- `binary_search`
- `merge`
- `copy`
- `for_each`

Lavorano sugli iteratori, non direttamente sui container.

Esempio:

```cpp
std::sort(v.begin(), v.end());
```

`sort` non sa davvero cosa sia `v`. Lui riceve un inizio e una fine, cioè due iteratori, e lavora su quel range.

Questa è una dei concetti più importanti della STL:

container = dove stanno i dati
iteratori = come ci muoviamo sui dati
algoritmi = cosa facciamo sui dati

### Nota sugli iteratori

Non tutti gli iteratori sono uguali.

Alcuni container permettono accesso random, altri no.

Esempio:

- `vector` permette `v[i]`
- `deque` permette `d[i]`
- `list` non permette `l[i]`
- `map` si attraversa con iteratori, ma non ha accesso per indice

Questa cosa influenza gli algoritmi che possiamo usare.

Per esempio `std::sort` richiede random access iterator, quindi funziona con `vector` e `deque`, ma non con `list`.

## Complessità temporale

La complessità temporale indica come cresce il tempo richiesto per effettuare una operazione al crescere del numero degli elementi.

Il costo non è in termini di secondi reali, perché quelli variano da pc a pc, ma indica come scala l'algoritmo scelto.

### O-Notation

Immaginandoci:

- 100 elementi
- 1000 elementi
- 10000 elementi

quanto peggiora il costo?

### O(1) - costo costante

```text
1 elemento       -> 1 operazione
1000 elementi    -> 1 operazione
100000 elementi  -> 1 operazione
```

L'esempio migliore è accedere ad un elemento in un `vector` tramite indice.

```cpp
v[50]
```

Il costo non dipende da quanti elementi ci sono nel vector, perché la memoria è contigua. Internamente succede qualcosa tipo:

```text
base_address + index * sizeof(type)
```

e vai diretto alla posizione di memoria.

### O(n) - costo lineare

Il costo cresce insieme al numero di elementi.

Esempio: cercare un valore in una lista o in un vector non ordinato.

Per trovare il valore, devo guardare gli elementi uno alla volta, fino ad arrivare al nodo desiderato.

| Elementi | Operazioni |
| -------- | ---------- |
| 10       | 10         |
| 100      | 100        |
| 1000     | 1000       |

### O(log n) - ogni operazione dimezza il problema

Tipico di ricerche su dati ordinati, tipo binary search, oppure di container come `map` e `set`.

È un po' come cercare una parola nel dizionario: non parti dalla prima pagina, tagli il problema a metà ogni volta.

| Elementi  | Operazioni |
| --------- | ---------- |
| 8         | 3          |
| 1024      | 10         |
| 1 milione | circa 20   |

### O(n log n) - sorting efficiente

È la complessità tipica degli algoritmi di sorting efficienti, come `std::sort`.

Non è costante, non è lineare, ma cresce molto meglio di un doppio ciclo.

### O(n²) - costo quadratico

Un esempio classico è il bubble sort: per ogni elemento, scorro tutti gli altri.

| Elementi | Operazioni |
| -------- | ---------- |
| 10       | 100        |
| 1000     | 1.000.000  |


### Come si calcola il costo?

Si contano le operazioni elementari, tipo:

- confronti
- assegnazioni
- accessi memoria
- dereference
- incrementi

Esempi:

- ciclo `for` singolo su n elementi -> O(n)
- doppio loop -> O(n²)
- binary search -> O(log n)
- sorting efficiente -> O(n log n)

| Complessità | Significato        |
| ----------- | ------------------ |
| O(1)        | costante           |
| O(log n)    | cresce lentamente  |
| O(n)        | cresce linearmente |
| O(n log n)  | sorting efficiente |
| O(n²)       | cresce molto male  |

Tutto questo serve per scegliere il container giusto ed avere performance buone.

In questo modulo dobbiamo tenere in considerazione alcune operazioni e capirne la complessità.

| Operazione           | vector | deque | stack | map      |
| -------------------- | ------ | ----- | ----- | -------- |
| accesso random       | O(1)   | O(1)  | no    | no       |
| push_back            | O(1)*  | O(1)  | no    | no       |
| push_front           | O(n)   | O(1)  | no    | no       |
| top                  | no     | no    | O(1)  | no       |
| ricerca generica     | O(n)   | O(n)  | no    | O(log n) |
| inserimento ordinato | O(n)   | O(n)  | no    | O(log n) |

`vector` ha push_back ammortizzato O(1), cioè di solito è O(1), ma quando deve riallocare memoria può costare di più.

---

# Scelta dei container per il modulo

Prima di entrare nei singoli esercizi, conviene fare una panoramica.

## ex00

Abbiamo un database in CSV con:

```text
data,exchange_rate
```

Poi abbiamo un input nel formato:

```text
data | valore
```

Per ogni riga dobbiamo:

1. validare la data
2. validare il valore
3. trovare il rate corretto
4. moltiplicare valore * rate
5. stampare il risultato

Se la data non è presente nel database, dobbiamo usare la data precedente più vicina.

Ci serve quindi un contenitore:

- chiave -> valore
- ordinato
- con ricerca efficiente
- senza bisogno di chiavi duplicate

La scelta naturale è `std::map`.

## ex01

L'esercizio richiede di usare la Reverse Polish Notation.

In questa notazione gli operatori vengono dopo gli operandi.

Esempio:

```text
3 + 2
```

diventa:

```text
3 2 +
```

Il concetto di stack è implicito in questo metodo, perché ogni volta che trovo un operatore devo prendere gli ultimi due valori disponibili.

Quindi userò `std::stack` per l'ex01.

## ex02

In questo esercizio dobbiamo usare l'algoritmo Ford-Johnson / merge-insert sort.

L'algoritmo, semplificato, fa questo:

1. crea coppie
2. ordina internamente ogni coppia
3. ordina le coppie in base al valore più grande
4. costruisce una main chain
5. tiene da parte i valori pending
6. inserisce i pending nella main chain con binary search
7. usa Jacobsthal per ottimizzare l'ordine degli inserimenti

L'algoritmo deve essere applicato su due container diversi, così possiamo confrontare le performance.

Per questo esercizio ha senso usare:

- `std::vector`
- `std::deque`

Entrambi permettono accesso tramite indice e supportano `std::sort`, `lower_bound` e inserimenti nel range.

`vector` usa memoria contigua.

`deque` usa memoria a blocchi.

Quindi sono simili come interfaccia, ma diversi internamente: perfetto per confrontarli.

---

# Ex00 - Bitcoin Exchange

## Obiettivo

Abbiamo un database con date e rate del bitcoin.

Per ogni riga di input dobbiamo stampare:

```text
data => valore = valore * exchange_rate
```

Se la data esatta non c'è, bisogna usare la data precedente più vicina presente nel database.

## Perché std::map

`std::map` è un container associativo ordinato.

Esempio:

```cpp
std::map<std::string, double> prices;
prices["2024-01-01"] = 42.0;
```

Nel nostro caso:

```cpp
std::map<std::string, double> _data;
```

La chiave è la data in formato stringa `YYYY-MM-DD`.

Il valore è il rate.

Funziona bene perché il formato `YYYY-MM-DD` è confrontabile anche come stringa.

Esempio:

```text
2020-01-01 < 2021-01-01 < 2021-05-10
```

Quindi la map resta ordinata cronologicamente senza dover convertire le date in un tipo speciale.

## lower_bound

`lower_bound(key)` restituisce un iteratore al primo elemento con chiave non minore di `key`.

Tradotto:

- se la data esiste, mi dà quella data
- se la data non esiste, mi dà la prima data successiva

Ma a noi serve la data precedente più vicina.

Quindi:

```cpp
it = map.lower_bound(date);
```

Poi:

- se `it` punta alla data esatta, ok
- se `it` punta ad una data successiva, torno indietro di uno
- se `it == begin()` e la data non coincide, significa che non ho una data precedente valida

Esempio:

```text
DB:
2020-01-01
2020-01-10
2020-01-20

Input:
2020-01-15
```

`lower_bound("2020-01-15")` restituisce `2020-01-20`.

Ma noi dobbiamo usare `2020-01-10`, quindi facciamo `--it`.

## Struttura del programma

- parse database
- salvataggio in `map<data, valore>`
- process input file
  - parse riga
  - validazione input
  - ricerca rate corretto
  - moltiplicazione
  - stampa

## Spiegazione funzioni

### main.cpp

Il main:

- valida il numero di argomenti
- apre il file input
- se l'apertura fallisce, esce
- crea l'oggetto `bitExchange`
- chiama la funzione che processa e stampa i risultati

Nel codice il controllo è:

```cpp
if (argc != 2)
```

Quindi il programma accetta un solo argomento: il file input.

Il database invece non viene passato da terminale, ma viene aperto internamente come:

```cpp
file.open("data.csv");
```

Quindi quando eseguo il programma devo essere nella cartella giusta, cioè dove `data.csv` è raggiungibile con quel path relativo.

### BitcoinExchange.cpp

Il costruttore chiama subito `parseDb()`.

`parseDb()`:

- apre `data.csv`
- legge e valida la prima riga/header
- legge il file riga per riga
- cerca il separatore `,`
- crea una substring per la data
- crea una substring per il valore
- converte il valore con `strtod`
- controlla che la conversione sia andata bene
- valida la data
- se tutto è ok, inserisce nella map

La map usata nel codice si chiama:

```cpp
std::map<std::string, double> prices;
```

Quindi il nome mentale è proprio: data -> prezzo/rate.

### strtod ed end pointer

In ex00 uso `strtod` per convertire il valore da stringa a double.

Il punto importante è l'`end pointer`:

```cpp
char *end;
value = strtod(valueStr.c_str(), &end);
```

Se `*end != '\0'`, vuol dire che la conversione non ha consumato tutta la stringa.

Esempio:

```text
42abc
```

`strtod` riesce a leggere `42`, ma si ferma su `a`.

Quindi non posso considerarlo un numero valido.

### errno ed ERANGE

Nel processing dell'input viene anche azzerato `errno` prima della conversione:

```cpp
errno = 0;
value = strtod(valueStr.c_str(), &end);
```

Poi viene controllato:

```cpp
errno != ERANGE
```

Questo serve per intercettare valori fuori range durante la conversione numerica.

In pratica:

- `*end != '\0'` -> la stringa contiene roba non numerica
- `errno == ERANGE` -> il numero è fuori range per la conversione
- `value < 0` -> numero negativo
- `value > 1000` -> numero troppo grande per il subject

La validazione della data controlla:

- formato `YYYY-MM-DD`
- lunghezza corretta
- `-` nelle posizioni giuste
- anno valido
- mese valido
- giorno valido
- anni bisestili, se gestiti

Nel codice la data viene spezzata così:

```cpp
year = strtol(date.substr(0, 4).c_str(), &end, 10);
month = strtol(date.substr(5, 2).c_str(), &end, 10);
day = strtol(date.substr(8, 2).c_str(), &end, 10);
```

Anche qui viene controllato `*end`, perché pure l'anno/mese/giorno devono essere numeri puliti.

Per i giorni del mese viene usato un array:

```cpp
int dayMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
```

Così posso controllare che, ad esempio, febbraio non abbia 31 giorni.

Nota da ricordare: la funzione `checkLeap()` è il punto in cui si decide se febbraio deve avere 28 o 29 giorni. Se una validazione sulle date bisestili si comporta in modo strano, quello è il primo posto da ricontrollare.

Nel programma la data resta stringa perché così è più semplice usarla come chiave nella map.

Quando poi processiamo l'input:

- controlliamo l'header
- cerchiamo il divisore ` | `
- separiamo data e valore
- convertiamo il valore
- controlliamo errori tipo numero negativo o troppo grande
- cerchiamo il rate corretto con `lower_bound`
- stampiamo il risultato

Nel codice il limite del subject viene gestito così:

```cpp
if (value > 1000)
    std::cout << "Error: too large a number." << std::endl;
```

Quindi i valori validi sono positivi e non maggiori di 1000.

### Eccezioni custom

Nel `.hpp` ci sono varie eccezioni custom:

- `CouldNotOpen`
- `InvalidHeader`
- `InvalidLine`
- `InvalidYear`
- `InvalidMonth`
- `InvalidDay`
- `InvalidDate`

Servono per distinguere mentalmente i diversi punti in cui il parsing può fallire.

Nel processing dell'input però, quando fallisce la validazione della data, il programma stampa in modo uniforme:

```text
Error: bad input => data
```

Quindi le eccezioni sono dettagliate nel codice, ma l'output verso il subject resta semplice.

## Error handling ex00

Casi da gestire:

- file non apribile
- header sbagliato
- riga senza separatore corretto
- data malformata
- data impossibile
- valore non numerico
- valore negativo
- valore troppo grande
- overflow / underflow numerico durante `strtod`
- data precedente non disponibile nel database

---

# Ex01 - RPN

## Obiettivo

Lo scopo del programma è prendere in input una espressione matematica in Reverse Polish Notation e calcolarne il risultato.

La notazione che siamo abituati ad usare è la infix:

```text
3 + 2
```

La reverse polish invece scrive:

```text
3 2 +
```

Nel caso ad esempio di:

```text
(3 + 4) * 2
```

scriviamo:

```text
3 4 + 2 *
```

Il lato positivo è che elimina completamente l'uso delle parentesi per dare precedenza alle operazioni.

Altro esempio:

```text
3 + (4 * 2)
```

in RPN diventa:

```text
3 4 2 * +
```

Prima calcolo `4 * 2`, poi sommo `3`.

## Perché stack

Una calcolatrice RPN deve usare lo stack.

L'algoritmo ha sempre bisogno degli ultimi due valori disponibili.

Quando leggo un numero:

```text
push nello stack
```

Quando leggo un operatore:

```text
prendo top
prendo il secondo valore
calcolo
pusho il risultato
```

## Ordine degli operandi

Questo è importante per non sbagliarsi con sottrazione e divisione.

Per una espressione:

```text
8 3 -
```

nello stack avrei:

```text
3  <- top
8
```

Quindi:

```text
right = top = 3
left = second = 8
op = -
```

Il calcolo è:

```text
left op right
8 - 3
```

Non il contrario.

## std::stack<int>

`stack` è un container adapter.

Questo significa che non è un container completo come `vector` o `deque`, ma una interfaccia limitata costruita sopra un altro container.

Di default, internamente usa `std::deque`.

Operazioni disponibili:

- `push()` aggiunge in cima
- `pop()` rimuove la cima
- `top()` legge il valore in cima
- `size()` restituisce la dimensione
- `empty()` controlla se è vuoto

Complessità: O(1).

Non posso iterare liberamente su uno stack, perché l'idea è proprio limitarlo al comportamento LIFO:

```text
Last In, First Out
```

cioè l'ultimo che entra è il primo che esce.

## std::stringstream

`std::stringstream` serve per parsare la stringa separandola automaticamente sugli spazi.

Esempio:

```cpp
std::stringstream ss(args);
std::string token;

while (ss >> token)
{
    // token contiene un pezzo alla volta
}
```

Spazi multipli vengono ignorati automaticamente.

Quindi:

```text
"3   4      +"
```

viene letto come:

```text
"3"
"4"
"+"
```

## Condizioni

Alla fine lo stack deve avere necessariamente size `== 1`.

Se è vuoto, manca qualcosa.

Se contiene più elementi, significa che c'erano troppi numeri o pochi operatori.

I numeri originali accettati dal subject sono a singola cifra.

Lo stack però può contenere anche risultati parziali, non solo numeri originali.

Esempio:

```text
9 9 *
```

I numeri originali sono una cifra, ma il risultato nello stack è `81`.

## Error handling ex01

Casi da gestire:

- numero di argomenti sbagliato
- token sconosciuto, tipo `2 3 s +`
- numero con più cifre, se non ammesso dal subject
- operatore senza abbastanza operandi
- divisione per zero
- stack finale vuoto
- stack finale con più elementi

Nel main il programma accetta esattamente una stringa come argomento:

```cpp
if (argc == 2)
    RPN ss(argv[1]);
else
    std::cerr << "Invalid Input" << std::endl;
```

Quindi l'espressione va passata tra virgolette, tipo:

```bash
./RPN "3 4 + 2 *"
```

## Spiegazione funzioni

Il costruttore prende gli argomenti passati dal main come stringa e chiama subito:

```cpp
createStack(args);
```

Creiamo uno stream `ss` a partire da `args` e lo parsiamo buttando i token letti dentro una stringa temporanea.

Il ciclo:

```cpp
while (ss >> tmp)
```

continua finché lo stream non fallisce, cioè fino alla fine dell'argomento.

Il primo controllo è sulla lunghezza del token.

Da subject dobbiamo accettare solo:

- cifre a 1 digit
- operatori validi

Entrambi hanno lunghezza `== 1`.

Se non rientra in quel caso, lanciamo eccezione.

Poi:

- se è un numero, lo pusho nello stack
- se è un operatore, controllo che lo stack abbia almeno 2 elementi
- prendo `right`
- prendo `left`
- calcolo `left op right`
- pusho il risultato

Nel codice il riconoscimento del numero avviene con:

```cpp
if (isdigit(tmp[0]))
    _num.push(tmp[0] - '0');
```

`tmp[0] - '0'` serve per convertire il carattere numerico nel valore intero corrispondente.

Esempio:

```text
'7' - '0' = 7
```

Gli operatori validi sono controllati da `is_op()`:

```cpp
return (token == "+" || token == "-" || token == "/" || token == "*");
```

Quando trovo un operatore chiamo `solveOp()`.

`solveOp()`:

- controlla che lo stack abbia almeno due elementi
- salva il top in `num2`
- fa pop
- salva il nuovo top in `num1`
- fa pop
- calcola `calculate(num1, op, num2)`
- pusha il risultato

La funzione `calculate()` contiene lo switch sui quattro operatori.

La divisione per zero viene intercettata lì:

```cpp
if (num2 == 0)
    throw RPN::InvalidInput();
```

Alla fine controllo che lo stack abbia size `== 1` e stampo il risultato.

---

# Ex02 - PmergeMe

## Obiettivo

Dobbiamo creare un programma in grado di ordinare integer positivi usando l'algoritmo Ford-Johnson, chiamato anche merge-insert sort.

Se accade un errore, dobbiamo mostrarlo sullo standard error.

Da subject:

- usare almeno due container
- gestire almeno 3000 integer diversi
- implementare l'algoritmo per ogni container
- non usare direttamente una funzione generica per ordinare tutto l'input e basta

Output richiesto:

```text
Before: lista int non ordinati
After: lista int ordinati
Time to process a range of X elements with std::container1 : tempo
Time to process a range of X elements with std::container2 : tempo
```

Il formato del tempo lo scegliamo noi, ma la precisione deve permettere di vedere la differenza tra i due container usati.

I duplicati il subject dice che possiamo gestirli come vogliamo.

Nel mio caso li considero validi se il parsing li accetta, oppure posso decidere di rifiutarli: l'importante è essere coerenti.

## Vector e deque

Entrambi i container permettono accesso tramite indice e supportano `push_back()`.

### vector

`std::vector` usa memoria contigua.

Pro:

- accesso per indice molto veloce
- cache friendly
- ottimo per scorrere tanti elementi
- `std::sort` funziona bene

Contro:

- inserire in mezzo costa O(n)
- se finisce la capacità interna deve riallocare

### deque

`std::deque` usa memoria a blocchi.

Pro:

- accesso per indice comunque O(1)
- efficiente sia in push_front che push_back
- non deve riallocare tutto come vector

Contro:

- meno cache friendly del vector
- internamente è più complesso

Per questo ex sono una buona coppia da confrontare: hanno interfaccia simile, ma memoria diversa.

## Ford-Johnson / Merge-insert sort

L'idea generale è ridurre il numero di confronti.

Non è l'algoritmo più semplice del mondo, infatti il subject è famoso proprio per far impazzire.

Il flusso mentale è:

1. creo coppie
2. in ogni coppia metto prima il piccolo e poi il grande
3. ordino le coppie guardando i grandi
4. costruisco una main chain con i grandi ordinati
5. tengo i piccoli come pending
6. inserisco i pending nella main chain usando binary search
7. uso Jacobsthal per scegliere in quale ordine inserire i pending

## Esempio passo per passo

Input:

```text
8 3 7 1 9 2
```

### Step 1 - creo coppie

```text
(8,3)
(7,1)
(9,2)
```

Se i numeri sono dispari, l'ultimo rimane fuori e lo salvo in una variabile separata.

Nel codice questa variabile è `_left`.

### Step 2 - ordino internamente le coppie

Metto il minore in `first` e il maggiore in `second`.

```text
(3,8)
(1,7)
(2,9)
```

Per rappresentare le coppie uso:

```cpp
std::pair<int, int>
```

### Step 3 - ordino le coppie per valore grande

Ordino le coppie guardando `second`.

```text
(1,7)
(3,8)
(2,9)
```

A questo punto i secondi sono ordinati:

```text
7 8 9
```

### Step 4 - costruisco la main chain

La main chain parte con:

- il piccolo della prima coppia
- tutti i grandi delle coppie ordinate

Quindi:

```text
1 7 8 9
```

Perché inserisco subito il piccolo della prima coppia?

Perché se la prima coppia è `(1,7)`, so già che `1 < 7`, e dato che `7` è il primo dei grandi ordinati, `1` può stare all'inizio della main chain.

### Step 5 - creo i pending

I pending sono i piccoli delle altre coppie.

Nel nostro esempio:

```text
3 2
```

Il piccolo della prima coppia è già stato inserito nella main chain, quindi non va nei pending.

### Step 6 - inserisco i pending con lower_bound

Per ogni pending cerco la posizione corretta nella main chain.

Uso:

```cpp
it = std::lower_bound(mainchain.begin(), mainchain.end(), value);
mainchain.insert(it, value);
```

`lower_bound` funziona perché la main chain è già ordinata.

### Step 7 - inserisco lo straggler

Se l'input aveva un numero dispari di elementi, resta un numero spaiato.

Lo inserisco alla fine con lo stesso metodo:

```cpp
lower_bound + insert
```

## std::pair

`std::pair<int, int>` crea sostanzialmente una mini struct con due campi:

- `first`
- `second`

Esempio:

```cpp
std::pair<int, int> p(3, 8);
```

oppure:

```cpp
std::pair<int, int> p = std::make_pair(3, 8);
```

Accesso:

```cpp
p.first
p.second
```

Comparazione standard tra pair:

- prima confronta `first`
- se `first` è uguale, confronta `second`

Nel nostro caso però vogliamo ordinare le coppie in base a `second`, quindi serve una funzione di comparazione custom.

Esempio:

```cpp
static bool comparePair(const std::pair<int, int> &a,
                        const std::pair<int, int> &b)
{
    return (a.second < b.second);
}
```

## Jacobsthal

Jacobsthal viene usato sui pending per ridurre il numero di confronti prima dell'inserimento, cambiandone l'ordine.

L'idea non è ordinare i valori dei pending.

L'idea è ordinare gli indici dei pending secondo la sequenza di Jacobsthal.

La formula è:

```text
J(n) = J(n - 1) + 2 * J(n - 2)
```

con:

```text
J(0) = 0
J(1) = 1
```

Calcolando qualche valore:

```text
J(2) = J(1) + 2 * J(0) = 1 + 2 * 0 = 1
J(3) = J(2) + 2 * J(1) = 1 + 2 * 1 = 3
J(4) = J(3) + 2 * J(2) = 3 + 2 * 1 = 5
J(5) = J(4) + 2 * J(3) = 5 + 2 * 3 = 11
```

Quindi la sequenza completa parte così:

```text
0 1 1 3 5 11 21 43 ...
```

Per il nostro uso pratico ignoriamo lo 0 e usiamo indici 1-based:

```text
1 3 5 11 21 43 ...
```

### Che sono questi numeri?

Sono limiti di gruppi.

Prendiamo:

```text
1 3 5 11
```

Significa:

```text
1
3 2
5 4
11 10 9 8 7 6
```

Cioè ogni gruppo viene inserito al contrario.

Quindi l'ordine finale degli indici diventa:

```text
1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, ...
```

Ovviamente se ho meno pending, mi fermo alla size reale.

Esempio: se ho 4 pending, l'ordine sarà:

```text
1, 3, 2, 4
```

Perché `5` sarebbe fuori range.

### Perché serve?

La parte matematica seria del Ford-Johnson dimostra che questo ordine riduce il numero di confronti necessari negli inserimenti binari.

Evito di approfondire troppo l'analisi matematica sennò finisco fra un paio di anni di capire questo esercizio, però il concetto utile per implementarlo è:

- creo la sequenza Jacobsthal
- genero gruppi di indici
- inserisco ogni gruppo al contrario
- uso quegli indici per scegliere quale pending inserire

## Funzione jacobVect / jacobDeq

Nel codice ho due versioni:

- `jacobVect`
- `jacobDeq`

Fanno la stessa cosa, ma una usa `std::vector<size_t>` e l'altra `std::deque<size_t>`.

Questo rispetta l'idea del subject: implementare il procedimento su entrambi i container.

Il procedimento è:

1. parto da `0` e `1`
2. genero la sequenza con la formula Jacobsthal
3. creo un vettore/deque finale di indici
4. per ogni intervallo Jacobsthal, pusho gli indici al contrario
5. ritorno l'ordine finale

Esempio concettuale:

```text
Jacobsthal: 1 3 5
Ordine:     1 3 2 5 4
```

Nel codice poi uso `id = jacob[i] - 1` perché i pending sono indicizzati da 0, mentre l'ordine Jacobsthal lo ragiono da 1.

## Ordine di chiamata delle funzioni

Flusso del programma:

```text
main
│
└── crea vector<int> input
    │
    ├── valida argomenti
    ├── stampa Before
    └── PmergeMe::process()
         │
         ├── processVector()
         │    │
         │    ├── sort delle coppie per second
         │    ├── build main chain vector
         │    ├── build pending vector
         │    ├── genera ordine Jacobsthal
         │    ├── inserisce pending con lower_bound
         │    └── inserisce _left se presente
         │
         └── processDeque()
              │
              ├── sort delle coppie per second
              ├── build main chain deque
              ├── build pending deque
              ├── genera ordine Jacobsthal
              ├── inserisce pending con lower_bound
              └── inserisce _left se presente
```

## Spiegazione del costruttore PmergeMe

Il costruttore riceve un `std::vector<int> input`.

Prima controlla se la size è dispari.

Se è dispari, salva l'ultimo elemento in `_left`.

```cpp
if (input.size() % 2 != 0)
    _left = input[input.size() - 1];
```

Poi scorre l'input a due a due:

```cpp
for (size_t i = 0; i + 1 < input.size(); i += 2)
```

Per ogni coppia:

- prende `a`
- prende `b`
- mette il minore in `first`
- mette il maggiore in `second`
- salva la coppia sia nel vector che nel deque

Quindi `_vect` e `_deq` contengono le stesse coppie, ma in container diversi.

## processVector

`processVector()` fa il sort usando `std::vector`.

Passaggi:

1. crea `mainchain`
2. crea `pending`
3. ordina `_vect` con `std::sort` e `comparePair`
4. chiama `mainVector(mainchain, pending)`
5. genera l'ordine Jacobsthal
6. inserisce i pending nella mainchain con `lower_bound`
7. inserisce `_left` se esiste
8. ritorna la mainchain ordinata

## mainVector

`mainVector()` costruisce mainchain e pending.

Fa:

```cpp
mainchain.push_back(_vect[0].first);
```

cioè inserisce il piccolo della prima coppia.

Poi inserisce tutti i grandi:

```cpp
for (...) mainchain.push_back(_vect[i].second);
```

Poi inserisce nei pending tutti i piccoli tranne quello della prima coppia:

```cpp
for (size_t i = 1; i < _vect.size(); i++)
    pending.push_back(_vect[i].first);
```

## processDeque

`processDeque()` è uguale come logica a `processVector()`, ma usa `std::deque`.

La duplicazione serve perché il subject vuole confrontare due container diversi.

## Timing

Per misurare il tempo uso `clock()`.

Il pattern è:

```cpp
start = clock();
// lavoro
elapsed = clock() - start;
```

Poi converto in microsecondi:

```cpp
(static_cast<double>(elapsed) / CLOCKS_PER_SEC) * 1000000.0
```

Questo permette di stampare tempi piccoli in modo più leggibile.

Su input piccoli la differenza può essere rumorosa o quasi invisibile.

Su input grandi, tipo 3000 numeri, la differenza tra container si vede meglio.

## Error handling ex02

Casi da gestire:

- meno di due numeri in input
- lettere o simboli
- numeri negativi
- overflow di `int`
- stringhe tipo `12abc`
- input vuoto

Nel main uso `strtol` perché mi permette di controllare anche dove si ferma la conversione.

```cpp
char *end;
long num = std::strtol(argv[i], &end, 10);
```

Se `*end != '\0'`, significa che la stringa non era un numero pulito.

Esempio:

```text
42abc
```

`strtol` converte `42`, ma si ferma su `a`.

Quindi devo considerarlo errore.

Controllo anche:

```cpp
num < 0 || num > INT_MAX
```

per accettare solo integer positivi nel range di `int`.

## Nota importante sul Ford-Johnson

Il Ford-Johnson completo è più raffinato della versione intuitiva "crea coppie + inserisci pending".

La parte importante per questo modulo è dimostrare di aver capito:

- divisione in coppie
- ordinamento interno delle coppie
- main chain
- pending
- inserimento binario
- ordine Jacobsthal
- confronto tra due container
- misurazione dei tempi

Quindi se il codice produce un output ordinato, gestisce gli errori e mostra chiaramente le differenze tra container, l'esercizio è concettualmente centrato.

---

# Checklist finale modulo

## Concetti da sapere spiegare

- cos'è la STL
- cosa sono container, iteratori e algoritmi
- perché gli algoritmi lavorano su iteratori
- complessità O(1), O(n), O(log n), O(n log n), O(n²)
- perché `map` è adatta per ex00
- come funziona `lower_bound` su map
- perché `stack` è adatto per RPN
- differenza tra notazione infix e RPN
- ordine corretto degli operandi in RPN
- perché vector e deque sono adatti a ex02
- differenza tra memoria contigua e memoria a blocchi
- cos'è una pair
- cos'è la main chain
- cosa sono i pending
- a cosa serve Jacobsthal
- come misurare il tempo di esecuzione

## Errori tipici da evitare

- usare lo stesso container in più esercizi quando il subject lo vieta
- pensare che `lower_bound` dia sempre la data precedente: dà la successiva non minore
- invertire left/right in RPN
- dimenticare il controllo divisione per zero
- usare `std::sort` direttamente sull'input finale in ex02 e basta
- dimenticare lo straggler quando gli elementi sono dispari
- usare indici Jacobsthal 1-based direttamente su container 0-based
- fidarsi di `strtol` senza controllare `end`
- stampare tempi con precisione troppo bassa

## Mini riassunto mentale

```text
ex00 -> map
perché devo cercare una data ordinata e recuperare il valore associato

ex01 -> stack
perché RPN lavora sempre sugli ultimi due valori disponibili

ex02 -> vector + deque
perché devo confrontare due container indicizzabili applicando Ford-Johnson
```
