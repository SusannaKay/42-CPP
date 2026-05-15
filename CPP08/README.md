CONTAINER:
sono strutture dati della STL (standarad template library), servono a memorizzare gruppi di elementi in modo generico.
Il container non sa che tipo di dato contiene, lo decide il template.

es.
std::vector<int>
std::list<std::string>
std::map<std::string, int>
ecc.

Gestisce memoria automaticamente,
offre funzioni standard ( es. insert, erase, size ecc )
usa gli iteratori (vedi sotto) per scorrere gli elementi

TIPI DI CONTAINER

Sequence container ( elementi in sequenza )
-- vector, list, deque
Associative containers ( elementi ordinati per chiave )
-- map, set, multimap
Adapter containers ( interfacce limitate sopra altri container )
-- stack, queue

VECTOR ->  std::vector<int>
é un array dinamico, memoria contigua. In pratica é come un array in C ma ridimensionabile.
-Memoria
quando finisce lo spazio, alloca un array piú grande, copia gli elementi, libera il vecchio array

LIST -> std::list<int>
lista doppiamente concatenata
[node]<->[node]<->[node]
ogni nodo contiene valore, puntatore al precedente, puntatore al successivo. 
Non essendo memoria NON é contigua l'accesso random é lento, mentre insert/erase sono veloci

DEQUE -> std::deque<int>
Sta per double ended queue. é una via di mezzo tra list e vector. Rispetto al vector fa molto bene push_back() e push_front().

MAP -> std::map<std::string, int>
fa associazione chiave -> valore. Le chiavi sono ordinate automaticamente per int. 
Es di utilizzo:
std::map<std::string, int> ages;
ages["Susanna"] = 42;
std::cout << ages["susanna"];
mi printa 42
se faccio ages["x"] ed x non esiste, mi crea l'elemento. Per controllare un elemento meglio usare ages.find("x")

SET
std::set<int>
é come map ma senza valore, contiene solo chiavi uniche

STACK
std::stack<int, std::deque<int> > ( usa un altro container sotto)
Last in first out, come una pila
push(), top(), pop()

QUEUE
first in first out, come una coda. 

Ogni container é ottimizzato per problemi diversi.

| Situazione                    | Container |
| ----------------------------- | --------- |
| array dinamico                | `vector`  |
| tante insert/remove nel mezzo | `list`    |
| chiave -> valore              | `map`     |
| valori unici                  | `set`     |
| pila                          | `stack`   |
| coda                          | `queue`   |


ITERATOR:
modo universale per attrvarsare un container a prescindere dal suo tipo.

In C se abbiamo un array possiamo usare un ciclo for per trovare un elemento perché:
-- esiste un indice
-- la memoria é contigua
-- l'array é fisso
con i container non possiamo farla questa cosa se non scrivendo un algoritmo diverso per ogni struttura dati.

es.

VECTOR
[1][2][3][4]

LIST
[node]<->[node]<->[node]

MAP
tree

container[i] funzionerebbe solo con VECTOR ma non con gli altri.

STL standardizza il movimento dentro i container:
I container forniscono begin() ed end(), mentre gli iteratori sanno fare ++it e *it. 

CONTAINER -> memorizza
ITERATOR -> naviga
ALGORITHM -> lavora sui dati

Cos'é iterator?

formalmente é un tipo. Piú precisamente é una classe che rappresenta la posizione dentro un container ( dentro ci sono overload degli operatori ). 
Qualcosa di molto simile ad un puntatore in C, con la differenza che il puntatore funziona solo con memoria normale, l'iterator funziona con vector, list, map, set anche se internamente sono diversi. 
é molto importante tenere a mente che ci sono delle funzioni dei container che invalidano i puntatori perché possono riallocare memoria ( es. push_back())

std::vector<int>::iterator it;
-- std::vector<int>::iterator  >> questo é il tipo.
-- it >> questo é il nome della variabile.
praticamente, in questo modo, sto dichiarando una variabile in grado di navigare dentro il vector<int>

Le funzioni begin() ed end() restituiscono un iterator

ex00:

Dobbiamo scrivere una funzione GENERICA che trovi un intero dentro un container di interi senza sapere che tipo di container sia. 
Quindi deve funzionare con vector<int>, list<int>, deque<int> ecc. Dobbiamo quindi usare un algoritmo generico:
1. Dobbiamo sapere qual é l'inizio (begin())
2. Dobbiamo sapere qual é la fine (end())
3. Scorriamo (++it)
4. Leggiamo (*it)

STL ha giá degli algoritmi pronti e std::find() fa esattamente questo: scorre da begin ad end finché non trova il valore. 
Come? si prende i parametri begin, end e value.
NB: non si prende il container, perché gli alggoritmi lavorano sugli iteratori, non sui container.

RETURN
Restituisce un iteratore all'elemento trovato. Visto che l'iteratore cambia in base al container, dobbiamo generalizzare il tipo di iterator
<typename T::iterator>
STL non lancia eccezioni quando non trova, fa return end() ( che non é l'ultimo elemento ma la posizione successiva all'ultimo elemento )