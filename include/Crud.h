//
//  Crud.h
//  dfgsdgf
//
//  Created by Diego Fernando Calderon Silva on 12/03/22.
//

#ifndef CRUD_H
#define CRUD_H
#include <string.h>
using namespace std;
class Crud
{
    public:
        Crud();
        void crear();
        void agregar();
        void modificar();
        void eliminar();
        void listar();

    protected:

    private://Atributos de la clase
        string nombre, apellido, email;
        int edad, id;

};

#endif // CRUD_H
