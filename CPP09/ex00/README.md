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

### ex00

Abbiamo un db in csv con data ed exchange rate. un input di tipo data | valore ( deve poter accettare sia float che int ). Per ogni riga dobbiamo trovare il rate corretto, moltiplicare e stampare il risultato. Se la data non é nel db, dobbiamo trrovare la data piú vicina precedente. 

Ci serve quindi un contenitore chiave - valore ordinato. Le opzioni sono std::map e std::multimap, tra queste map non ammette chiavi duplicate, quindi useremo questo contenitore.  

#### std::map

esempio di utilizzo

std::map<std::string, double> prices;
prices["2024-01-01"] = 42.0;

Costo ricerca: O(log n) con prices.find("data")e in piú abbiamo a disposizione la funzione .lower_bound() che cerca la prima chiave non minore di un certo valore. 

Quindi é un container buono per bitcoin exchange. 
Prima di proseguire controlliamo di quali container hanno bisogno gli altri esercizi visto che se usiamo map sull'ex00, non possiamo usarlo da nessun altra parte. 

ex01: 