#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>

using namespace std;

const string SVNOMBRE_COMPLETO = "Santos Misael Villarreal Vásconez";
const int CEDULA = 1753415999;

struct svCoordenada 
{
    int svCap;
    string svGeo;
    string svArsenal;
    svCoordenada* izq;
    svCoordenada* der;
};

void svInsertarCoordenada(svCoordenada*& arbol, int cap, string geo, string arsenal) 
{
    if (arbol == nullptr) {
        arbol = new svCoordenada;
        arbol->svCap = cap;
        arbol->svGeo = geo;
        arbol->svArsenal = arsenal;
        arbol->izq = nullptr;
        arbol->der = nullptr;
    }
    else if (cap < arbol->svCap) {
        svInsertarCoordenada(arbol->izq, cap, geo, arsenal);
    }
    else if (cap > arbol->svCap) {
        svInsertarCoordenada(arbol->der, cap, geo, arsenal);
    }
    else {
        if (geo.compare(arbol->svGeo) < 0) {
            svInsertarCoordenada(arbol->izq, cap, geo, arsenal);
        }
        else if (geo.compare(arbol->svGeo) > 0) {
            svInsertarCoordenada(arbol->der, cap, geo, arsenal);
        }
        else {
            if (arsenal.compare(arbol->svArsenal) < 0) {
                svInsertarCoordenada(arbol->izq, cap, geo, arsenal);
            }
            else if (arsenal.compare(arbol->svArsenal) > 0) {
                svInsertarCoordenada(arbol->der, cap, geo, arsenal);
            }
        }
    }
}

void svMostrarCoordenadas(svCoordenada* arbol) 
{
    if (arbol == nullptr) {
        return;
    }

    svMostrarCoordenadas(arbol->izq);

    cout << arbol->svCap << ", " << arbol->svGeo << ", " << arbol->svArsenal << endl;

    svMostrarCoordenadas(arbol->der);
}

void getCoordenadas() 
{
    string str;
    fstream f;
    cout << "[+]Leyendo coordenadas ... " << endl;
    f.open("Coord.txt", ios_base::in); // este debe estar a la altura de tu  programa xxxxx.exe
    if ( f.is_open() ) 
    while( !f.eof() )
     {
     getline( f, str );
     cout << str;
          }
    else
          cout << "Error de abrir el archivo de coordenadas" << endl;
    f.close();
}
int main(){
    string nombreArchivo = "src/datos.txt";
    svLeerArchivoCoordenadas(nombreArchivo);
    return 0;
}