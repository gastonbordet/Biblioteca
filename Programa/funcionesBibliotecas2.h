#ifndef FUNCIONESBIBLIOTECAS2_H_INCLUDED
#define FUNCIONESBIBLIOTECAS2_H_INCLUDED

#include "validaciones.h"

bool pedirLibro(Usuario pide, Usuario presta){
    Prestado prestamo;
    FILE *p = fopen("Prestados.dat", "ab");
    if(p==NULL)return false;

    cin.ignore();

    /// ID LIBRO
    char IDLibro[30];
    cout << "Ingrese ID libro que quiere pedir: ";
    cin.getline(IDLibro, 30);
    // Validacion libro existe
    if(validarIdLibro(IDLibro) != -1){
        cout << "Ese ID no existe o es invalido. " << endl;
        system("pause");
        return false;
    }
    prestamo.setIDLibro(IDLibro);

    /// ID BIBLIOTECA ORIGEN
    int origen;
    cout << "Ingrese ID biblioteca origen: ";
    cin >> origen;
    if(!(validarBiblioteca(origen, presta))){
        cout << "Ese ID no existe o no pertenece al usuario. " << endl;
        system("pause");
        return false;
    }
    prestamo.setIDBibliotecaOrigen(origen);

    /// ID BIBLIOTECA DESTINO
    int destino;
    cout << "Ingrese ID biblioteca destino: ";
    cin >> destino;
    if(!(validarBiblioteca(destino, pide))){
        cout << "Ese ID no existe o no pertenece al usuario. " << endl;
        system("pause");
        return false;
    }
    if(validarEspacioBiblioteca(destino)==false){
        cout << "No hay espacio en la biblioteca." << endl;
        system("pause");
        return false;
    }
    prestamo.setIDBibliotecaDestino(destino);

    prestamo.setDevuelto(false);

    fwrite(&prestamo, sizeof prestamo, 1, p);
    fclose(p);
    return true;
}


bool devolverLibro(){
    char libro[30];

    cin.ignore();
    cout << "Ingrese ID libro que quiere devolver: ";
    cin.getline(libro, 30);
    if(validarIdLibro(libro) != -1){
        cout << "Ese ID no existe o es invalido. " << endl;
        system("pause");
        return false;
    }

    int origen;
    cout << "Ingrese ID biblioteca origen: ";
    cin >> origen;
    if(validarIdBiblioteca(origen)!=-1){
        cout << "Ese ID no existe o es invalida. " << endl;
        system("pause");
        return false;
    }


    int destino;
    cout << "Ingrese ID biblioteca destino: ";
    cin >> destino;
    if(validarIdBiblioteca(destino)!=-1){
        cout << "Ese ID no existe o es invalida. " << endl;
        system("pause");
        return false;
    }

    FILE *p = fopen("Prestados.dat", "rb+");
    if(p==NULL){
        cout << "Error. " << endl;
        system("pause");
        return false;
    }
    Prestado pres;
    int pos = 0;
    bool encontrado = false;
    while(fread(&pres, sizeof pres, 1, p)){
        if(strcmp(pres.getIDLibro(), libro) == 0 && pres.getIDBibliotecaOrigen() == origen && pres.getIDBibliotecaDestino() == destino && pres.getDevuelto() == false){
            encontrado = true;
            pres.setDevuelto(true);
            break;
        }
        pos++;
    }
    if(!(encontrado)){
        cout << "No se encontro ese prestamo" << endl;
        fclose(p);
        //return false;
    }
    fseek(p, sizeof pres * pos, 0);
    fwrite(&pres, sizeof pres, 1, p);
    fclose(p);
    //return true;
}

#endif // FUNCIONESBIBLIOTECAS2_H_INCLUDED
