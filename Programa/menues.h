#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

void menu_principal()
{
    cout << "    ________________________" << endl;
    cout << "   |                        |" << endl;
    cout << "   |     Menu principal     |" << endl;
    cout << "   |________________________|" << endl;
    cout << "   |                        |" << endl;
    cout << "   |   1) Libros            |" << endl;
    cout << "   |   2) Autores           |" << endl;
    cout << "   |   3) Generos           |" << endl;
    cout << "   |   4) Mis bibliotecas   |" << endl;
    cout << "   |   5) Reportes          |" << endl;
    cout << "   |   6) Configuracion     |" << endl;
    cout << "   |________________________|" << endl;
    cout << "   |                        |" << endl;
    cout << "   |   0) Salir             |" << endl;
    cout << "   |________________________|" << endl;
    cout << endl << "Ingrese opcion: ";
}

void menu_misLibros()
{
    cout << "    ________________________" << endl;
    cout << "   |                        |" << endl;
    cout << "   |      Menu Libros       |" << endl;
    cout << "   |________________________|" << endl;
    cout << "   |                        |" << endl;
    cout << "   |   1) Nuevo Libro       |" << endl;
    cout << "   |   2) Modificar Libro   |" << endl;
    cout << "   |   3) Terminar Libro    |" << endl;
    cout << "   |   4) Borrar Libro      |" << endl;
    cout << "   |   5) Mostrar Libros    |" << endl;
    cout << "   |________________________|" << endl;
    cout << "   |                        |" << endl;
    cout << "   |   0) Salir             |" << endl;
    cout << "   |________________________|" << endl;
    cout << endl << "Ingrese opcion: ";
}

void menu_autores()
{
    cout << "    ________________________" << endl;
    cout << "   |                        |" << endl;
    cout << "   |      Menu Autores      |" << endl;
    cout << "   |________________________|" << endl;
    cout << "   |                        |" << endl;
    cout << "   |   1) Nuevo Autor       |" << endl;
    cout << "   |   2) Modificar Autor   |" << endl;
    cout << "   |   3) Borrar Autor      |" << endl;
    cout << "   |   4) Mostrar Autores   |" << endl;
    cout << "   |________________________|" << endl;
    cout << "   |                        |" << endl;
    cout << "   |   0) Salir             |" << endl;
    cout << "   |________________________|" << endl;
    cout << endl << "Ingrese opcion: ";
}

void menu_generos()
{
    cout << "    ________________________" << endl;
    cout << "   |                        |" << endl;
    cout << "   |      Menu Genero       |" << endl;
    cout << "   |________________________|" << endl;
    cout << "   |                        |" << endl;
    cout << "   |   1) Nuevo Genero      |" << endl;
    cout << "   |   2) Modificar Genero  |" << endl;
    cout << "   |   3) Borrar Genero     |" << endl;
    cout << "   |   4) Mostrar Generos   |" << endl;
    cout << "   |________________________|" << endl;
    cout << "   |                        |" << endl;
    cout << "   |   0) Salir             |" << endl;
    cout << "   |________________________|" << endl;
    cout << endl << "Ingrese opcion: ";

}

void menu_otrasBibliotecas()
{
    cout << "    ____________________________" << endl;
    cout << "   |                            |" << endl;
    cout << "   |      Menu Bibliotecas      |" << endl;
    cout << "   |____________________________|" << endl;
    cout << "   |                            |" << endl;
    cout << "   |   1) Nueva Biblioteca      |" << endl;
    cout << "   |   2) Modificar Biblioteca  |" << endl;
    cout << "   |   3) Mostrar Bibliotecas   |" << endl;
    cout << "   |   4) Mostrar Mis Libros    |" << endl;
    cout << "   |   5) Borrar Biblioteca     |" << endl;
    cout << "   |   6) Guardar Libro         |" << endl;
    cout << "   |   7) Buscar Personas       |" << endl;
    cout << "   |____________________________|" << endl;
    cout << "   |                            |" << endl;
    cout << "   |   0) Salir                 |" << endl;
    cout << "   |____________________________|" << endl;
    cout << endl << "Ingrese opcion: ";
}

void menu_otrasBibliotecas2(char*nombre)
{

    cout << "       Biblioteca de " << nombre << endl;
    cout << "    __________________________________" << endl;
    cout << "   |                                  |" << endl;
    cout << "   |   1) Mostrar Libros              |" << endl;
    cout << "   |   2) Pedir Libro                 |" << endl;
    cout << "   |   3) Devolver Libro              |" << endl;
    cout << "   |__________________________________|" << endl;
    cout << "   |                                  |" << endl;
    cout << "   |   0) Salir                       |" << endl;
    cout << "   |__________________________________|" << endl;
    cout << endl << "Ingrese opcion: ";
}

void menu_reportes()
{
    cout << "    ____________________________" << endl;
    cout << "   |                            |" << endl;
    cout << "   |       Menu Reportes        |" << endl;
    cout << "   |____________________________|" << endl;
    cout << "   |                            |" << endl;
    cout << "   |   1) Libros a devolver     |" << endl;
    cout << "   |   2) Libros por terminar   |" << endl;
    cout << "   |   3) Libros terminados     |" << endl;
    cout << "   |____________________________|" << endl;
    cout << "   |                            |" << endl;
    cout << "   |   0) Salir                 |" << endl;
    cout << "   |____________________________|" << endl;
    cout << endl << "Ingrese opcion: ";
}

void menu_configuracion()
{
    cout << "    ____________________________" << endl;
    cout << "   |                            |" << endl;
    cout << "   |    Menu Configuracion      |" << endl;
    cout << "   |____________________________|" << endl;
    cout << "   |                            |" << endl;
    cout << "   |   1) Crear Backup          |" << endl;
    cout << "   |   2) Restaurar Backup      |" << endl;
    cout << "   |   3) Eliminar Archivos     |" << endl;
    cout << "   |____________________________|" << endl;
    cout << "   |                            |" << endl;
    cout << "   |   0) Salir                 |" << endl;
    cout << "   |____________________________|" << endl;
    cout << endl << "Ingrese opcion: ";
}

#endif // MENUES_H_INCLUDED
