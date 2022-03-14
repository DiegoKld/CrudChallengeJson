//
//  main.cpp
//  dfgsdgf
// ubicacion de los archivos de salida /Users/ingdiegocalde/Library/Developer/Xcode/DerivedData/dfgsdgf-ddazzuiqwyricvfwnbtrrnnpgkxi/Build/Products/Debug
//  Created by Diego Fernando Calderon Silva on 12/03/22.
//

#include <iostream>
#include <stdlib.h>
#include "Crud.h"
#include "Crud.h"
#include "json.h"
#include "value.h"
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(){
    int op;
    Crud crud;

    salto:
    cout << "[:]Menu principal\n" << endl;
    cout << "[1]Crear DataBase" << endl;
    cout << "[2]Agregar personas al DataBase" << endl;
    cout << "[3]Modificar nombre de persona" << endl;
    cout << "[4]Eliminar persona" << endl;
    cout << "[5]Listar \n" << endl;
    cout << "[6]Salir \n" << endl;
    cout << "Ingresa la opcion: ";
    cin >> op;

    switch(op){
        case 1:{
            crud.crear();
            goto salto;
        }
        case 2:{
            crud.listar();
            crud.agregar();
            goto salto;
            
        }
        case 3:{
            crud.listar();
            crud.modificar();
            goto salto;
            
        }
        case 4:{
            crud.listar();
            //crud.eliminar();
            goto salto;
            
        }
        case 5:{
            crud.listar();
            goto salto;
            break;
        }
        case 6:
            exit(0);
       
    
    return 0;
    }

}
