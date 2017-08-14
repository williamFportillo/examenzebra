#include "Evaluador.h"

bool sonPaisesIguales(Pais* paisA, Pais* paisB)
{
    return paisA->nombre == paisB->nombre
           && paisA->capital == paisB->capital
           && paisA->habitantes == paisB->habitantes
           && paisA->superficie == paisB->superficie;
}

bool contiene(vector<int> contenedor, vector<int> contenido)
{
    for(int i=0;i<(int)contenido.size();i++)
    {
        bool existe = false;
        for(int j=0;j<(int)contenedor.size();j++)
        {
            if(contenido[i] == contenedor[j])
            {
                existe = true;
                break;
            }
        }
        if(!existe)
            return false;
    }
    return true;
}

double evaluarEscondido()
{
    double nota = 0;

    Numero* numeros1[3];
    numeros1[0] = new Numero(10);
    numeros1[1] = new Numero(20);
    numeros1[2] = new Numero(30);

    Numero* numeros2[2];
    numeros2[0] = new Numero(432);
    numeros2[1] = new Numero(5346);

    cout<<"obtenerValor():\t\t";
    if(obtenerValor(numeros1, 2)==30
       && obtenerValor(numeros1, 0)==10
       && obtenerValor(numeros2, 1)==5346
       && obtenerValor(numeros2, 0)==432
            )
    {
        nota+=4;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    list<string> son_mayusculas1;
    son_mayusculas1.push_back("HOLA");
    son_mayusculas1.push_back("MUNDO");
    son_mayusculas1.push_back("PROBANDO");
    son_mayusculas1.push_back("UNODOSTRES");

    list<string> son_mayusculas2;
    son_mayusculas2.push_back("ESTOY");
    son_mayusculas2.push_back("HACIEnDO");
    son_mayusculas2.push_back("PRUEBAS");

    list<string> son_mayusculas3;
    son_mayusculas3.push_back("UNO");
    son_mayusculas3.push_back("DOS");
    son_mayusculas3.push_back("TREs");

    cout<<"sonMayusculas():\t";
    if(sonMayusculas(son_mayusculas1)
       && !sonMayusculas(son_mayusculas2)
       && !sonMayusculas(son_mayusculas3)
            )
    {
        nota+=4;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    vector<int> repetidas1;
    repetidas1.push_back(10);
    repetidas1.push_back(10);
    repetidas1.push_back(30);
    repetidas1.push_back(20);
    repetidas1.push_back(20);

    vector<int> repetidas2;
    repetidas2.push_back(300);
    repetidas2.push_back(100);
    repetidas2.push_back(200);
    repetidas2.push_back(300);

    vector<int> repetidas3;
    repetidas3.push_back(1);
    repetidas3.push_back(2);
    repetidas3.push_back(3);
    repetidas3.push_back(2);
    repetidas3.push_back(4);
    repetidas3.push_back(4);

    cout<<"eliminarRepetidos():\t";

    vector<int> respuesta_repetidas1 = eliminarRepetidos(repetidas1);
    vector<int> respuesta_repetidas2 = eliminarRepetidos(repetidas2);
    vector<int> respuesta_repetidas3 = eliminarRepetidos(repetidas3);

    if(contiene(repetidas1, respuesta_repetidas1) && respuesta_repetidas1.size()==3
       && contiene(repetidas2, respuesta_repetidas2) && respuesta_repetidas2.size()==3
       && contiene(repetidas3, respuesta_repetidas3) && respuesta_repetidas3.size()==4
            )
    {
        nota+=4;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    Pais *pais1 = new Pais("Honduras", "Tegucigalpa", 8, 12);
    Pais *pais2 = new Pais("Francia", "Paris", 15, 24);
    Pais *pais3 = new Pais("Rusia", "Moscu", 25, 50);

    guardar("archivo1", pais1);
    guardar("archivo2", pais2);
    guardar("archivo3", pais3);

    Pais *pais_leido1 = abrir("archivo1");
    Pais *pais_leido2 = abrir("archivo2");
    Pais *pais_leido3 = abrir("archivo3");

    cout<<"guardar() y abrir():\t";
    if(pais_leido1 && sonPaisesIguales(pais1, pais_leido1)
       && pais_leido2 && sonPaisesIguales(pais2, pais_leido2)
       && pais_leido3 && sonPaisesIguales(pais3, pais_leido3)
            )
    {
        nota+=4;
        cout<<"Correcto"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }


    return nota;
}