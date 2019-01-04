#ifndef CLASEUSUARIO_H_INCLUDED
#define CLASEUSUARIO_H_INCLUDED

class Usuario{
    private:
        char username[30];
        char nombre[30];
        char clave[30];
    public:
        //Usuario();
        /// Sets
        void setUsername(char*user){strcpy(username, user);}
        void setNombre(char*nombre){strcpy(this->nombre, nombre);}
        void setClave(char*clave){strcpy(this->clave, clave);}
        /// Gets
        char* getUsername(){return username;}
        char*getNombre(){return nombre;}
        char*getClave(){return clave;}
};

#endif // CLASEUSUARIO_H_INCLUDED
