\# Team_GLEM_C++
Lavoro di gruppo in cui analizzare e migliorare un progetto C++.
---
#### CONSEGNA:
1. Esaminare il progetto in allegato e riorganizzare il codice in modo più elegante e manutenibile.
2. Descrivere il funzionamento dell'applicativo (versione originale)
3. Effettuare refactoring del codice (utilizzo di interfacce e classi astratte ove necessario) e inserire gestione di eccezioni
4. Integrare il codice inserendo le seguenti migliorie funzionali:
     1. prevedere che ogni mezzo possa avere un equipaggio composto da 2 a 6 persone
     2. gestire tipi diversi di missioni:
        1. scorta (almeno 3 mezzi devono essere presenti)
        2. assalto (massimo 1 mezzo ogni 5 elementi di personale)
        3. estrazione (almeno 2 mezzi terrestri e 5 elementi di personale)
5. Descrivere la soluzione finale

La presentazione sarà oggetto di valutazione e sarà effettuata tramite meet.
Siete liberi di scegliere qualunque mezzo per la presentazione, saranno graditi sia elaborati scritti che grafici o diagrammi o anche una spiegazione direttamente del codice (nel qual caso opportunamente commentato), tutto quanto deve essere presentabile tramite call meet
Sarà oggetto di valutazione positiva per il superamento dei 10 punti qualunque aggiunta al progetto che non ne alteri la funzionalità ma che ne estenda le proprietà, tutto quanto naturalmente dovrà essere giustificato.

#### INTRODUZIONE
Per il seguente progetto, il nostro gruppo ha decido di adottare **Git** e **GitHub** come strumenti complementari di sviluppo.
* Git, in quanto definito sistema di version control, ci ha permesso di lavorare in parallelo e allo stesso tempo tener traccia dei cambiamenti che apportavamo al nostro progetto.
* GitHub, invece, attraverso la sua interfaccia grafica ci ha permesso di visualizzare lo stato del codice e dei branch in cui ognuno di noi lavorava quindi monitorare l'avanzamento delle task.
> https://github.com/matteosolivo/Team_GLEM_Cpp

#### STRUTTURA:

1. Template, GestoreRisorse.hpp, che accetta oggetti di tipo Risorsa e quindi anche le sue sottoclassi, nel nostro caso Personale e Mezzo.

2. Classe astratta Risorsa.hpp, che verrà estesa dalle classi Personale e Mezzo, che fornisce metodi che le classi figlie sono poi libere di ridefinire.

3. Personale e Mezzo estendono la classe astratta Risorsa, che ridefiniscono e aggiungono metodi al loro interno.

4. Caserma è un punto centrale, che incrocia sia metodi da usare sulle missioni, i mezzi e il personale, che la parte di salvataggio delle informazioni su tutti i componenti della caserma. Utilizza il pattern di singleton. 

5. Nella struttura del progetto sono state anche inserite le eccezioni, con un file .hpp e un file .cpp per gestire le eccezioni riguardo agli oggetti di tipo personale, gli oggetti di tipo mezzo, e le eccezioni che riguardano la gestione dei file.

6. Il file main utilizza un'istanza di Caserma, implementata con pattern di costruzione Singleton.

7. I file Missione.hpp e Missione.cpp permettono di definire l'oggetto di tipo Missione.

8. Il file Makefile facilita il processo di compilazione

#### SCELTE IMPLEMENTATIVE:
1. *Classe Astratta* tra personale e mezzo: Risorsa. --> **Motivazione**: eliminare codice duplicato, semplificare manutenzione e modifica.

2. *Refactoring Caserma*: gestore risorse come classe template. --> **Motivazione**: per gestire più tipi di oggetti che usano le stesse funzioni.

3. Creazione di un *makefile*. --> **Motivazione**: per facilitare il processo di compilazione.

4. Aggiunta *flag* per indicare se un membro di personale è un *pilota* o no. --> **Motivazione**: collegare l’informazione facilmente al singolo membro di personale.

5. Aggiunta di una *funzione controlloMissione*. --> **Motivazione**: per verificare in maniera completa il rispetto dei requisiti.

6. *Stampa su file*: aggiunta per stampare un resoconto. --> **Motivazione**: dare la possibilità di salvare un resoconto concreto dello stato della caserma.

7. Aggiunta di *eccezioni* su Missioni e Int. --> **Motivazione**: per gestire l’eventualità che si cerchi di usare personale o mezzo non disponibile o nel caso di inserimento di dato di tipo errato.

8. Utilizzo di *Singleton* per l'oggetto caserma. --> **Motivazione**: per fare in modo che sia presente solo un'istanza di caserma a cui si fa riferimento su tutto il codice
