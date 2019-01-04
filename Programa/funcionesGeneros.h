#ifndef FUNCIONESGENEROS_H_INCLUDED
#define FUNCIONESGENEROS_H_INCLUDED

#include "claseGenero.h"
#include "validaciones.h"
Genero crearGenero(){
    cin.ignore();
    Genero genero;

    /// ID
    cout << "Ingrese ID del genero: ";
    int id;
    cin >> id;
    while(generoValido(id)<0){
        cout << "El ID ya existe. Ingrese uno nuevamente: ";
        cin >> id;
    }
    genero.setID(id);
    system("cls");

    /// Nombre
    cout << "ingrese nombre del genero: ";
    char nombre[30];
    cin.ignore();
    cin.getline(nombre, 30);
    genero.setNombre(nombre);

    return genero;
}

bool grabarGenero(){
    Genero genero = crearGenero();
    FILE *p = fopen("Generos.dat", "ab");
    if(p==NULL) return false;
    fwrite(&genero, sizeof genero, 1, p);
    fclose(p);
    return true;
}

void mostrarGenero(Genero genero){

    cout << "_____________________________________" << endl;
    cout << endl;
    cout << "ID: " << genero.getID() << endl;
    cout << "Genero Favorito: " << genero.getNombre() << endl;
    cout << "_____________________________________" << endl;
}

bool mostrarGeneros(){
    Genero genero;
    FILE *p = fopen("Generos.dat", "rb");
    if(p==NULL)return false;
    cout << "               Generos               " << endl;
    while(fread(&genero, sizeof genero, 1, p)){
        if(genero.getEstado()==true)

            mostrarGenero(genero);
    }
    fclose(p);
    system("pause");
    return true;
}

char* buscarGenero(int id){
    Genero genero;
    FILE *p = fopen("Generos.dat", "rb");
    if(p==NULL)return " ";
    while(fread(&genero, sizeof genero, 1, p)){
        if(genero.getID()==id && genero.getEstado()==true){
            fclose(p);
            return genero.getNombre();
        }
    }
    fclose(p);
    return " ";
}


int posicionGenero(int id){
    Genero genero;
    FILE *p = fopen("Generos.dat", "rb");
    int pos = 0;
    if(p==NULL)return -1;
    while(fread(&genero, sizeof genero, 1, p)){
        if(genero.getID()==id){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

bool modificarGenero(){
    Genero genero;
    int id;
    cout << "Ingrese ID de Genero: ";
    cin >> id;
    int pos = posicionGenero(id);
    if(pos == -1){
        cout << "El genero no existe o fue dado de baja." << endl;
        system("pause");
        return false;
    }
    FILE *p = fopen("Generos.dat", "rb+");
    fseek(p, sizeof genero * pos, 0);
    fread(&genero, sizeof genero, 1, p);

    char nombre[30];
    cin.ignore();
    cout << "Ingrese nuevo nombre: ";
    cin.getline(nombre, 30);

    genero.setNombre(nombre);

    fseek(p, sizeof genero * pos, 0);
    fwrite(&genero, sizeof genero, 1, p);
    fclose(p);
    return true;
}

bool eliminarGenero(){
    Genero genero;
    int id;
    cout << "Ingrese ID de Genero: ";
    cin >> id;
    int pos = posicionGenero(id);
    if(pos == -1){
        cout << "El Genero no existe o fue dado de baja." << endl;
        system("pause");
        return false;
    }

    FILE *p = fopen("Generos.dat", "rb+");
    fseek(p, sizeof genero * pos, 0);
    fread(&genero, sizeof genero, 1, p);

    genero.setEstado(false);

    fseek(p, sizeof genero * pos, 0);
    fwrite(&genero, sizeof genero, 1, p);
    fclose(p);
    return true;

}


#endif // FUNCIONESGENEROS_H_INCLUDED
