/*
Arbori binari

[a] Metode de reprezentare
[b] Metode de parcurgere

================

Aplicatii ale arborilor binari :
1. Arbori binari de cautare

Idee : Arborele este inzestrat cu informatii atasate nodurilor
           Informatiile din noduri sunt astfel depuse incat operatiile
           de consultare a structurii sa fie extrem de eficiente

Organizarea prespune respectarea urmatoarelor reguli

- informatia atasata unui nod este mai mare decat toate informatiile
  descendetilor sai pe subarbore stang
- informatia atasata unui nod este mai mica decat toate informatiile
  descendetilor sai pe subarbore drept

 OBS :
 Structura de arbore binar de cautare se implementeaza in mod firesc
 pe arbori binari binari cu alocare dinamica

Aplicatie :
Fie n numar natural nenul si (a)n un sir de n numere reale distincte
Se cere sa se construiasca un arbore binar de cautare in care
informatiile atasate nodurilor sa fie valorile sirului (a)n.
Arborele construit sa se parcurga dupa cele 3 metode.

exemplu :

n=5
235 55 889 31 67

                     [235]
                     /      \
                    *         *
                 [55]        [889]
                  /  \
                 *    *
             [31]   [67]

RSD(1): 235,55,31,67,889
SRD(1): 31,55,67,235,889
SDR(1): 31,67,55,889,235

class node{
                 public :
                 double my_info;
                 class node *my_left;
                 class node *my_right;
                 }

Algoritm :
Pornim initial cu arbore singleton contruit cu informatia primului termen
din sir.
Pentru fiecare nou termen din sir parcurgem arborele curent construit
pentru a gasi locul de creare a noului nod.

node *make_some_tree(node *this_one,double new_one)
{

//  testul de incetare a autoapelurilor => momentul de contruire

if (this_one.my_info<new_one)
                {
                return make_some_tree(this_one.my_right,new_one);
                }
if (this_one.my_info>new_one)
                {
                return make_some_tree(this_one.my_left,new_one);
                }
}

int RSD(node *this_one)
{
if (this_one!=NULL) {
                            cout<<this_one.my_info<<" ";
                            RSD(this_one.my_left);
                            RSD(this_one.my_right);
                                  }
}


/*
- make  ========
- find
- delete
- update
- echilibre
*/
#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("input.dat");

int n;

class node
{
    public :
    double my_info;
    class node *my_left;
    class node *my_right;
};

node *prim;

int read_data()
{
    fin>>n;
    fin>>prim->my_info;
}

node *new_nr;

node *make_some_tree(node *this_one,double new_one)
{
    new_nr->my_info=new_one;
    if(this_one->my_info<new_one)
    {
        if(this_one->my_right==NULL)
            this_one->my_right=new_nr;
        else
            return make_some_tree(this_one->my_right,new_one);
    }
    if(this_one->my_info>new_one)
    {
        if(this_one->my_left==NULL)
            this_one->my_left=new_nr;
        else
            return make_some_tree(this_one->my_left,new_one);
    }
}

int RSD(node *this_one)
{
    if (this_one!=NULL)
    {
        cout<<this_one->my_info<<" ";
        RSD(this_one->my_left);
        RSD(this_one->my_right);
    }
}

int SRD(node *this_one)
{
    if (this_one!=NULL)
    {
        SRD(this_one.my_left);
        cout<<this_one.my_info<<" ";
        SRD(this_one.my_right);
    }
}

int SDR(node *this_one)
{
    if (this_one!=NULL)
    {
        SDR(this_one.my_left);
        SDR(this_one.my_right);
        cout<<this_one.my_info<<" ";
    }
}

int main()
{
    read_data();
    double nr;
    for(int i=2;i<=n;i++)
    {
        fin>>nr;
        make_some_tree(prim, nr);
    }
    RSD(prim);
    cout<<endl;
    SRD(&prim);
    cout<<endl;
    SDR(&prim);
}
