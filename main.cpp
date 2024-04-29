#include <iostream>

using namespace std;
///Memorarea listei
struct Nod{
    int numar; ///Memoram numarul
    Nod* next; ///Memoram legatura catre urmatorul nod
};

Nod* cap = NULL;

///Parcurgerea si afisarea elementelor din lista
void afisareLista(Nod* cap)
{
    while(cap != NULL)
    {
        cout<<cap -> numar<<" ";
        cap = cap -> next; ///Mutam elem curent la urmatoru elem din lista
    }
}

///Inserarea elementelor la inceputul listei
void inserareInceput(Nod* &cap, int valoare)
{
    //Creez noul nod si ii atribui valoarea din parametru
    Nod* elem = new Nod;
    elem -> numar = valoare;

    elem -> next = cap;
    cap = elem;
}

///Inserarea elementelor la sfarsitul listei
//Modificatorul de referință (&) este necesar aici deoarece dorim să putem
//modifica pointerul cap din interiorul funcției și să reflectăm aceste modificări și în afara funcției, în codul apelant.
void inserareFinal(Nod* &cap, int valoare)
{
    Nod* elem_final = new Nod;
    elem_final -> numar = valoare;
    elem_final -> next = NULL;

    if(cap == NULL) ///verific daca lista mea e vida
        cap = elem_final;
    else
    {
        ///parcurgem lista pana la final
        Nod *nod_curent = cap;
        while(nod_curent -> next != NULL)
            nod_curent = nod_curent->next;

        nod_curent -> next = elem_final;
    }
}

///Cautarea unui element dupa valoare intr-o lista
Nod* cautareValoare(Nod* cap, int valoare)
{
    while(cap != NULL &&cap -> numar != valoare)
        cap = cap -> next;
    if(cap != NULL && cap->numar == valoare)
    {
        cout<<"Am gasit nodul cu valoarea: "<<cap -> numar<<".\n";
    }
    else
        cout<<"Nu exista nodul cu valoarea: "<< valoare<<"!\n";
    return cap;
}

///Stergerea unui element din lista
void stergereElement(Nod* predecesor)
{
    Nod* victima = predecesor-> next;
    predecesor -> next = predecesor ->next->next;
    delete victima;
}

Nod* cautarePozitie(Nod* cap, int pozitie)
{
    int i = 0;
    while(cap != NULL && i<pozitie)
    {
        cap = cap -> next;
        i++;
    }
    if(i == pozitie)
        return cap;
    else
        return NULL;
}

void stergereElementPozitie(Nod* &cap, int pozitie)
{
    if(pozitie == 0)
    {
        Nod* victima = cap;
        cap = cap->next;
        delete victima;
    }
    else
    {
        Nod *predecesor = cautarePozitie(cap, pozitie -1);
        if(predecesor!= NULL)
            stergereElement(predecesor);
        else
            cout << "Nu exista nodul la pozitia specificata!\n";
    }
}

int main()
{
    inserareInceput(cap, 12);
    inserareInceput(cap, 23);
    inserareInceput(cap, 56);

    inserareFinal(cap, 125);

    cautareValoare(cap, 12);
    cautareValoare(cap, 122);

    afisareLista(cap);
    cout<<endl;

    stergereElementPozitie(cap, 0);

    stergereElementPozitie(cap, 1234);

    afisareLista(cap);
}
