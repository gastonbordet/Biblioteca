#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include "claseAutor.h"
#include "claseGenero.h"

int validarIdBiblioteca(int id){
    Biblioteca biblioteca;
    FILE *p = fopen("Bibliotecas.dat", "rb");
    if(p==NULL)return 0;
    while(fread(&biblioteca, sizeof biblioteca, 1, p)){
        if(biblioteca.getID()==id && biblioteca.getEstado()==true)return -1;
    }
    fclose(p);
    return 1;
}

bool validarBiblioteca(int id, Usuario user){
    Biblioteca biblioteca;
    FILE *p = fopen("Bibliotecas.dat", "rb");
    if(p==NULL)return false;

    while(fread(&biblioteca, sizeof biblioteca, 1, p)){
        //cout << "id biblioteca: " << biblioteca.getID() << " - id buscado: " << id << endl;
        //cout << "username: " << biblioteca.getDuenio().getUsername() << " - " << "username buscad: " << user.getUsername() << endl;
        if(biblioteca.getID() == id && strcmp(biblioteca.getDuenio().getUsername(), user.getUsername())==0 && biblioteca.getEstado() == true){
            fclose(p);
            //cout << "Biblioteca encontrada" << endl;
            return true;
        }
    }
    fclose(p);
    //cout << "Biblioteca no encontrada" << endl;
    return false;
}

int cantLibrosBiblioteca(int id){
    LibroPorBiblioteca libros;
    int cant = 0;
    FILE *p = fopen("LibrosPorBibliotecas.dat", "rb");
    if(p==NULL)return cant;
    while(fread(&libros, sizeof libros, 1, p)){
        if(libros.getIDBiblioteca() == id && libros.getEstado()==true){
            cant++;
        }
    }

    fclose(p);
    return cant;
}

bool validarEspacioBiblioteca(int id){
    Biblioteca biblioteca;
    FILE *p = fopen("Bibliotecas.dat", "rb");
    if(p==NULL)return true;
    int tam = 0;
    int cant = cantLibrosBiblioteca(id);
    while(fread(&biblioteca, sizeof biblioteca, 1, p)){
        if(biblioteca.getID() == id && biblioteca.getEstado() == true){
            tam = biblioteca.getTam();
        }
    }
    fclose(p);
    cout << "Biblioteca: " << id << " - Libros: " << cant << " - Tam: " << tam << endl;
    if(cant >= tam){
        return false;
    }
    return true;
}

bool validarUsuario(char*user){
    Usuario usuario;
    FILE *p = fopen("Usuarios.dat", "rb");
    if(p==NULL)return false;
    while(fread(&usuario, sizeof usuario, 1, p)){
        if(strcmp(usuario.getUsername(), user)==0){
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}

int validarIdLibro(char*id){
    Libro libro;
    FILE *p = fopen("Libros.dat", "rb");
    if(p==NULL)return 0; // 0 no hay archivo
    while(fread(&libro, sizeof libro, 1, p)){
        if(strcmp(libro.getID(), id)==0){
            fclose(p);
            return -1; // -1 repetido
        };
    }
    fclose(p);
    return 1; // 1 no existe
}

int biciesto(int anio){
    if(anio % 4 == 0)
    {
        if(anio % 100 == 0)
        {
            if(anio % 400 == 0)
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }
        else
        {
            return 29;
        }
    }
    else
    {
        return 28;
    }
}

bool fechaValida(Fecha fecha){
    int dias[12];
    dias[0] = 31;
    dias[1] = biciesto(fecha.getAnio());
    dias[2] = 31;
    dias[3] = 30;
    dias[4] = 31;
    dias[5] = 30;
    dias[6] = 31;
    dias[7] = 31;
    dias[8] = 30;
    dias[9] = 31;
    dias[10] = 30;
    dias[11] = 31;
    if(fecha.getDia() > 0 && fecha.getDia() <= dias[fecha.getMes()-1]){
        if(fecha.getMes() > 0 && fecha.getMes() < 13){
            if(fecha.getAnio() > 1800 && fecha.getAnio() < 2019){
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}

int autorValido(int id){
    Autor autor;
    FILE *p = fopen("Autores.dat", "rb");
    if(p==NULL)0;
    while(fread(&autor, sizeof autor, 1, p)){
        if(autor.getID()==id && autor.getEstado()==true){
            fclose(p);
            return -1;
        }
    }
    fclose(p);
    return 1;
}

int generoValido(int id){
    Genero genero;
    FILE *p = fopen("Generos.dat", "rb");
    if(p==NULL)return 0;
    while(fread(&genero, sizeof genero, 1, p)){
        if(genero.getID()==id && genero.getEstado()==true){
            fclose(p);
            return -1;
        }
    }
    fclose(p);
    return 1;
}

bool validarPassword(char*password, Usuario usuarioBuscado){
    FILE *p = fopen("Usuarios.dat", "rb");
    Usuario usuario;
    while(fread(&usuario, sizeof usuario, 1, p)){
        if(strcmp(usuario.getUsername(), usuarioBuscado.getUsername()) == 0){
            if(strcmp(usuario.getClave(), password) == 0){
                fclose(p);
                return true;
            }
            else{
                fclose(p);
                return false;
            }
        }
    }
    fclose(p);
    return false;

}

#endif // VALIDACIONES_H_INCLUDED
