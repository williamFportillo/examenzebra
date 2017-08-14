#include <iostream>
#include <fstream>
#include <math.h>
#include <list>
#include <vector>
#include "Evaluador.h"
using namespace std;

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 1 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Devuelve el atributo valor del objeto numero en la posicion del arreglo dado
int obtenerValor(Numero** arreglo, int pos)
{

    return arreglo[pos]->valor;
}

//Devuelve true si y solo si todas las letras de las cadenas de la lista son mayusculas
bool sonMayusculas(list<string> palabras)
{

   list<string>::iterator it=palabras.begin();
    while(it != palabras.end()){
        string pal=*it;
        for (int i = 0; i <pal.length() ; ++i) {
            if (pal[i]>='A' && pal[i]<='Z'){
                continue;
            }else{
                return false;
            }
        }
        it++;
    }
   return true;
}

//Devuelve un vector que contenga todos los valores del vector de parametro sin repetir ningun valor
vector<int> eliminarRepetidos(vector<int> vector_a)
{
    vector<int>respuesta;
    return respuesta;

}

//Guarda el contenido del objeto Pais que viene como parametro
void guardar(string nombre_archivo, Pais* pais)
{
}

//Devuelve un objeto Pais que contenga la informacion que se guardo anteriormente por la funcion guardar()
Pais* abrir(string nombre_archivo)
{
    return NULL;
}

//Devuelve el mayor entre a, b y c
template<typename T>
T obtenerMayor(T a, T b, T c)
{
    if(a>b && a>c){
        return a;
    }else if(b>c && b>a){
        return b;
    }
    return c;
}

///////////////////////////////////////////////////////////////////
///////////////////////////// PARTE 2 /////////////////////////////
///////////////////////////////////////////////////////////////////

//Realizar las siguientes clases dado el diagrama adjunto

//**JugadorDeFutbol**
//getTipo(): es virual pura
//getNombre(): devuelve el atributo valor

//**Atacante**
//Constructor: inicializa los atributos de clase dados los parametros
//getTipo(): devuelve "Atacante"
//getAnotaciones(): devuelve el atributo anotaciones
//operator+=(): suma el parametro al atributo anotaciones

//**Portero**
//Constructor: inicializa los atributos de clase dados los parametros
//getTipo(): devuelve "Portero"
//getAatjadas(): devuelve el atributo atajadas
//operator+=(): suma el parametro al atributo atajadas

class JugadorDeFutbol{
public:
    string nombre;
    virtual string getTipo()=0;
    virtual string getNombre(){
        return nombre;
    }
};
class Atacante:public JugadorDeFutbol{
public:
    int anotaciones;
    Atacante(string nombre,int anotaciones){
        this->nombre=nombre;
        this->anotaciones=anotaciones;
    }
    string getTipo(){
        return "Atacante";
    }
    int getAnotaciones(){
        return anotaciones;
    }
    void  operator+=(int anotaciones){
        this->anotaciones+=anotaciones;
    }
};
class Portero:public JugadorDeFutbol{
public:
    int atajadas;
    Portero(string nombre,int atajadas){
        this->nombre=nombre;
        this->atajadas=atajadas;
    }
    string getTipo(){
        return "Portero";
    }
    int getAtajadas(){
        return atajadas;
    }
    void  operator+=(int atajadas){
        this->atajadas+=atajadas;
    }
};

///////////////////////////////////////////////////////////////////
////////////////////////////// Main ///////////////////////////////
///////////////////////////////////////////////////////////////////

void evaluar();
void evaluar2();

int main ()
{
    //Funcion evaluadora parte 1
    cout<<"Evaluador parte 1"<<endl<<"================="<<endl;
    evaluar();


    //Evaluacion parte 2
    //Descomentar para evaluar
    cout<<"Evaluador parte 2"<<endl<<"================="<<endl;
    evaluar2();

    return 0;
}


///////////////////////////////////////////////////////////////////////
///////////////////////////// Evaluador 2 /////////////////////////////
///////////////////////////////////////////////////////////////////////

void evaluar()
{
    double nota = evaluarEscondido();

    cout<<"obtenerMayor():\t\t";
    if(obtenerMayor(10,30,20)==30
       && obtenerMayor('x','m','a')=='x'
       && obtenerMayor(25.6,53.2,100.2)==100.2
            )
    {
        nota+=4;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/20"<<endl<<endl;
}

void evaluar2()
{

    double nota = 0;


    cout<<"**Clase Atacante**"<<endl;
    Atacante atacante1("Lolo",10);
    Atacante atacante2("Lulu",20);
    Atacante atacante3("Rolo",30);
    cout<<"Test constructor, gets, sets:\t";
    if(atacante1.getNombre() =="Lolo"
       && atacante1.getAnotaciones() == 10
       && atacante2.getNombre() == "Lulu"
       && atacante2.getAnotaciones() == 20
       && atacante3.getNombre() == "Rolo"
       && atacante3.getAnotaciones() == 30
       )
    {
        nota+=1.5;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }
    JugadorDeFutbol* jugador = new Atacante("Ruru",10);
    cout<<"Test getTipo():\t\t\t";
    if(jugador->getTipo() == "Atacante")
    {
        nota+=1.5;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }
    cout<<"Test operator+=():\t\t";
    atacante1+=1;
    atacante2+=2;
    atacante3+=3;
    if(atacante1.getAnotaciones()==11
        && atacante2.getAnotaciones()==22
        && atacante3.getAnotaciones()==33
        )
    {
        nota+=1.5;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }
    cout<<"**Clase Portero**"<<endl;
    Portero portero1("Ruru",100);
    Portero portero2("Rora",200);
    Portero portero3("Lofo",300);
    cout<<"Test constructor, gets, sets:\t";
    if(portero1.getNombre() =="Ruru"
       && portero1.getAtajadas() == 100
       && portero2.getNombre() == "Rora"
       && portero2.getAtajadas() == 200
       && portero3.getNombre() == "Lofo"
       && portero3.getAtajadas() == 300
       )
    {
        nota+=1.5;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }
    JugadorDeFutbol* jugador_portero = new Portero("Pipo",100);
    cout<<"Test getTipo():\t\t\t";
    if(jugador_portero->getTipo() == "Portero")
    {
        nota+=1.5;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }
    cout<<"Test operator+=():\t\t";
    portero1+=10;
    portero2+=20;
    portero3+=30;
    if(portero1.getAtajadas()==110
        && portero2.getAtajadas()==220
        && portero3.getAtajadas()==330
        )
    {
        nota+=1.5;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/9"<<endl;
}