#include <iostream>
#include <string.h>
#include <windows.h>


using namespace std;

class produs{
    int ziua, luna, anul;
    string nume, u_masura;
    double cantitate;
    double pret;
public:
    produs();
    produs(string, string, int, int, int, double, double);
    ~produs();
    void set(string, string, int, int, int, double, double);
    void set(produs&);
    void afisare(ostream &out);
    void citire(istream &in);
    friend istream& operator>>(istream &in, produs& z);  ///supraincarcare pe >>
	friend ostream& operator<<(ostream &out, produs& z); ///supraincarcare pe <<
	string getNume();
};

produs::produs(){
    this->ziua=0;
    this->luna = 0;
    this->anul = 0;
    this->cantitate = 0;
    this->pret = 0;
}

produs::produs(string nume, string u_masura, int ziua = 0, int luna = 0, int anul = 0, double cantitate = 0, double pret = 0){
    this->nume = nume;
    this->u_masura = u_masura;
    this->ziua=ziua;
    this->luna = luna;
    this->anul = anul;
    this->cantitate = cantitate;
    this->pret = pret;
}
produs::~produs(){
    this->ziua=0;
    this->luna = 0;
    this->anul = 0;
    this->cantitate = 0;
    this->pret = 0;
}

void produs::citire(istream &in) {
	cout << "Cititi numele produsului: ";
	in >> nume;
	cout<< "Cititi unitatea de masura a produsului: ";
	in >> u_masura;
	cout << "Cititi ziua in care produsul a ajuns in magazin: ";
	in >> ziua;
		cout << "Cititi luna in care produsul a ajuns in magazin: ";
	in >> luna;
		cout << "Cititi anul in care produsul a ajuns in magazin: ";
	in >> anul;

	cout << "Cititi cantitatea produsului: ";
	in >> cantitate;
	cout << "Cititi pretul pe unitate a produsului: ";
	in >> pret;
}
istream& operator>>(istream& in, produs& z) {
	z.citire(in);
	return in;
}
void produs::afisare(ostream &out) {
		out << "Nume produs: " << nume << "\nData in care a ajuns in magazin: " << ziua << "." << luna << "." << anul << "\nCantitate: " << cantitate << " " << u_masura << "\nPret/unitate: " << pret << "\n";
}
ostream& operator<<(ostream& out, produs& z) {
	z.afisare(out);
	return out;
}
void produs::set(string nume, string u_masura, int ziua, int luna, int anul, double cantitate, double pret){
    this->nume = nume;
    this->u_masura = u_masura;
    this->ziua=ziua;
    this->luna = luna;
    this->anul = anul;
    this->cantitate = cantitate;
    this->pret = pret;
}
void produs::set(produs& p){
    this->nume = p.nume;
    this->u_masura = p.u_masura;
    this->ziua = p.ziua;
    this->luna = p.luna;
    this->anul = p.anul;
    this->cantitate = p.cantitate;
    this->pret = p.pret;
}
string produs::getNume(){
    return nume;
}


class magazin{
    string nume;
    produs *v;
    int numar_produse;
public:
    magazin();
    magazin(string);
    ~magazin();
    void ad(produs);
    void del(string);
    void afisare(ostream &out);
    void citire(istream &in);
    friend istream& operator>>(istream &in, magazin& z);  ///supraincarcare pe >>
	friend ostream& operator<<(ostream &out, magazin& z); ///supraincarcare pe <<
	int getNP();
};

magazin::magazin(){
    numar_produse = 0;
}
magazin::magazin(string nume){
    this->nume = nume;
    numar_produse = 0;
}
void magazin::ad(produs s){
    produs *temp;
	temp = new produs[numar_produse];

	for(int i = 0; i <= numar_produse-1; i++)
		temp[i].set(v[i]);

	delete[] v;
	this->numar_produse = numar_produse + 1;
	this->v = new produs[numar_produse];

	if(numar_produse > 1)

		for(int i = 0; i<=numar_produse-2; i++){
			v[i].set(temp[i]);
		}
	v[numar_produse-1].set(s);
}

magazin::~magazin(){
    delete[] v;
    numar_produse = 0;
    nume = ' ';
}


void magazin::afisare(ostream &out) {
        out << "Magazin:\n";
        for(int i=0; i<numar_produse; i++)
            out << v[i];
}
ostream& operator<<(ostream& out, magazin& z) {
	z.afisare(out);
	return out;
}

void magazin::citire(istream &in) {
    cout<<"Cate produse vreti sa cititi? \n";
	in >> numar_produse;
	v = new produs[numar_produse];
	for(int i=0; i<numar_produse; i++)
        cin>>v[i];
}
istream& operator>>(istream& in, magazin& z) {
	z.citire(in);
	return in;
}

/*
void magazin::del(string nume) {
		if(numar_produse > 0){
			bool ok = 1;
			produs *temp;
			temp = new produs[numar_produse- 1];

			for(int i = 0; i < numar_produse - 1; i++){
				if(strcmp(nume, v[i].getNume()) != 0)
					ok = 0;
				if(ok)
					temp[i].set(v[i]);
				if(!ok)
					temp[i].set(v[i+1]);
			}
			if(strcmp(nume, v[numar_produse-1].getNume())!=0)
				ok = 0;
			if(ok == 0){
				delete[] v;
				this->numar_produse--;
				v = new produs[numar_produse];
				for(int i = 0; i < numar_produse; i++)
					v[i].set(temp[i]);

				delete[] temp;
				cout << "Produsul a fost sters din magazin!\n";
			}
			else
				cout << "Produsul nu exista!\n";
		}
		else
			cout << "Nu exista produse in magazin!!\n";
}
*/

int magazin::getNP(){
    return numar_produse;
    }




void menu_output()
{
	cout << "\n Alecu Florin Gabriel - Grupa 211 - BONUS \n";
	cout << "\n\t MENIU:";
	cout << "\n===========================================\n";
	cout << "\n";
	cout << "1. Adauga magazin nou cu produse comercializate.\n";
	cout << "2. Afisaza toate magazinele cu produsele comercializate.\n";
	cout << "3. Afisaza toate produsele primite la o anumita data si magazinul de care apartin.\n";
	cout << "4. Sterge un produs din magazin\n";
	cout << "5. Modifica un produs din magazin.\n";
	cout << "6. Afisaza magazinul cu cele mai multe produse.\n";
	cout << "0. Iesire.\n";
}

void menu()
{
	int option;///optiunea aleasa din meniu
	option = 0;

	magazin mg[10];
	int numar=-1;

	do
	{
		menu_output();

		cout << "\nIntroduceti numarul actiunii: ";
		cin >> option;

		if (option == 1){
            numar++;
            cin>>mg[numar];
		}
		if (option == 2){
            if (numar>=0)
            for(int i = 0; i<=numar; i++)
                cout << mg[i] << endl;
            else
                cout<<"Nu exista magazine!\n";
		}
		if (option == 3){
            bool ok = 0;

		}
		if (option == 6){
            if(numar>=0){
            int maxim=0, ind;
            for(int i=0; i<=numar;i++){
                if (maxim<mg[i].getNP()){
                    maxim = mg[i].getNP();
                    ind = i;
                }
            }
            cout<<mg[ind];
            }
            else
                cout<<"Nu exista magazine\n";

		}

		if (option == 0)
		{
			cout << "\nEXIT!\n";
		}
		if (option < 0 || option>6)
		{
			cout << "\nSelectie invalida\n";
		}
		cout << "\n";
		system("pause"); ///Pauza - Press any key to continue...
		system("cls");   ///Sterge continutul curent al consolei
	} while (option != 0);
}
int main()
{
    menu();


    return 0;
}
