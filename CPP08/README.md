# CONTAINER:
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

## TIPI DI CONTAINER

Sequence container ( elementi in sequenza )
-- vector, list, deque
Associative containers ( elementi ordinati per chiave )
-- map, set, multimap
Adapter containers ( interfacce limitate sopra altri container )
-- stack, queue

### VECTOR ->  std::vector<int>
é un array dinamico, memoria contigua. In pratica é come un array in C ma ridimensionabile.
-Memoria
quando finisce lo spazio, alloca un array piú grande, copia gli elementi, libera il vecchio array

### LIST -> std::list<int>
lista doppiamente concatenata

[node]<->[node]<->[node]

ogni nodo contiene valore, puntatore al precedente, puntatore al successivo. 
Non essendo memoria NON é contigua l'accesso random é lento, mentre insert/erase sono veloci

### DEQUE -> std::deque<int>
Sta per double ended queue. é una via di mezzo tra list e vector. Rispetto al vector fa molto bene push_back() e push_front(). 
Ha accesso rapido tramite indice

[1 2 3] --> [4 5 6] -->[7 8]
puo'crescere avanti e dietro senza dover spostare tutto

### MAP -> std::map<std::string, int>
fa associazione chiave -> valore. Le chiavi sono ordinate automaticamente per int. 
Es di utilizzo:
std::map<std::string, int> ages;
ages["Susanna"] = 42;
std::cout << ages["susanna"];
mi printa 42
se faccio ages["x"] ed x non esiste, mi crea l'elemento. Per controllare un elemento meglio usare ages.find("x")

### SET
std::set<int>
é come map ma senza valore, contiene solo chiavi uniche

### STACK
std::stack é un container adapter, non é autonomo come vector o list, é una specie di wrapper sopra un altro container. 

Last In First Out : l'ultimo ad entrare é il primo ad uscire, tipo pila di piatti. 

con lo stack puoi fare principalmente 3 cose:
push - metti un elemento sopra lo stack
top - legge l'elemento in cima
pop - elimina l'elemento in cima

internamente usa deque, ma ne restringe l'interfaccia: quando scrivo std::stack<int> in realt'sto facendo piu o meno std::stack<int, std::deque<int>>. 

utile per:
- parsing 
- DFS ( depth-first search - algoritmo utilizzato per esplorare alberi e grafi ).
- gestione parentesi
- undo/redo
- call/stack
- recursion simulation 

es. su parentesi (((())))
ognu "(" fa push,  ogni ")" fa pop. Se alla fine lo stack é vuoto --> stringa valida

stack usa deque perché ha bisogno di push_back e pop_back e deque gestisce bene la crescita dinamica senza problemi di riallocazione che invece avrebbe il vector.



### QUEUE
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


## ITERATOR:
modo universale per attrvarsare un container a prescindere dal suo tipo.

In C se abbiamo un array possiamo usare un ciclo for per trovare un elemento perché:
-- esiste un indice
-- la memoria é contigua
-- l'array é fisso
con i container non possiamo farla questa cosa se non scrivendo un algoritmo diverso per ogni struttura dati.

es.

#### VECTOR
[1][2][3][4]

#### LIST
[node]<->[node]<->[node]

#### MAP
tree

container[i] funzionerebbe solo con VECTOR ma non con gli altri.

STL standardizza il movimento dentro i container:
I container forniscono begin() ed end(), mentre gli iteratori sanno fare ++it e *it. 

CONTAINER -> memorizza
ITERATOR -> naviga
ALGORITHM -> lavora sui dati

#### Cos'é iterator?

formalmente é un tipo. Piú precisamente é una classe che rappresenta la posizione dentro un container ( dentro ci sono overload degli operatori ). 
Qualcosa di molto simile ad un puntatore in C, con la differenza che il puntatore funziona solo con memoria normale, l'iterator funziona con vector, list, map, set anche se internamente sono diversi. 
é molto importante tenere a mente che ci sono delle funzioni dei container che invalidano i puntatori perché possono riallocare memoria ( es. push_back())

std::vector<int>::iterator it;
-- std::vector<int>::iterator  >> questo é il tipo.
-- it >> questo é il nome della variabile.
praticamente, in questo modo, sto dichiarando una variabile in grado di navigare dentro il vector<int>

Le funzioni begin() ed end() restituiscono un iterator

### ex00:

Dobbiamo scrivere una funzione GENERICA che trovi un intero dentro un container di interi senza sapere che tipo di container sia. 
Quindi deve funzionare con vector<int>, list<int>, deque<int> ecc. Dobbiamo quindi usare un algoritmo generico:
1. Dobbiamo sapere qual é l'inizio (begin())
2. Dobbiamo sapere qual é la fine (end())
3. Scorriamo (++it) - non it++ ( internamente quello che fa é creare una copia temporanea che poi incrementa - it spesso é una classe - questa cosa cosa in termini di memoria )
4. Leggiamo (*it)

STL ha giá degli algoritmi pronti e std::find() fa esattamente questo: scorre da begin ad end finché non trova il valore. 
Come? si prende i parametri begin, end e value.
NB: non si prende il container, perché gli alggoritmi lavorano sugli iteratori, non sui container.

RETURN
Restituisce un iteratore all'elemento trovato. Visto che l'iteratore cambia in base al container, dobbiamo generalizzare il tipo di iterator
<typename T::iterator>
STL non lancia eccezioni quando non trova, fa return end() ( che non é l'ultimo elemento ma la posizione successiva all'ultimo elemento )


### ex02

non essendo stack iterabile o fai pop() fino ad empty su uno stack copia dell'originale oppure usi il container al suo interno ( deque ).
Problema: deque é protetto all'interno di stack. Quindi puoi ereditarlo attraverso la classe MutantStack. Stack impedisce l interazione con deque non esponendo gli iteratori pubblici e nascondendo il container interno. 

idealmente stack é fatto cosí 

´´´

template <class T, class Container = std::deque<T>>
class stack
{
    protected:

        Container c;

    public:

        void push(const T& value)
        {
            c.push_back(value);
        }

        void pop()
        {
            c.pop_back();
        }

        T& top()
        {
            return c.back();
        }
};
´´´
typedef: serve a creare un alias di tipo: ovvero semplicemente un nome alternativo ad un tipo esistente. 
typename: si usa nei template quando il compilatore deve sapere che il nome generico che stai passando al template non é un valore ma un tipo. 
container_type: alias interno del tipo di contenitore usato in stack ( stack puo usare sia deque che vector che list )

quindi 

typedef typename std::stack<T>::container_type::iterator iterator;


di base significa: creami un alias di nome iterator che usa gli iteratori del tipo di container usato all interno di stack