//
//  Crud.cpp
//  dfgsdgf
//
//  Created by Diego Fernando Calderon Silva on 12/03/22.
//

#include <iostream>
#include <stdlib.h>
#include "Crud.h"
#include <string>
#include<fstream>
#include <cstdlib>
#include "json.h"
#include "value.h"
#include <string>
#include <fstream>
#include <cstdlib>




using namespace std;

Crud::Crud()
{
    //Constructor vacio por que se utilizan los getter y setter
}

//Ayudara crear de cero la base de datos. Si se llama nuevamente este metodo es por que se va a eliminar absolutamente todo para empezar de cero.
void Crud::crear(){
    //Fichero de salida
    Json::Reader reader;
    Json::Value root;
    Json::StyledStreamWriter writer;
    //std::string text = "{ \"first\": \"James\", \"last\": \"Bond\", \"nums\": [1, 12, 7] }";
    std::string text = "{\"ID\": \" \",\"Nombre\": \" \", \"Apellido\": \" \", \"Edad\": \" \", \"Email\": \" \"}";
    std::ofstream outFile;
    outFile.open("DatosPersonas.json");
    char rpt;
    int _id=0;
      
      // Parse JSON and print errors if needed
    if(!reader.parse(text, root)) {
        std::cout << reader.getFormattedErrorMessages();
        exit(1);
    }
        
        // Read and modify the json data
        //std::cout << "Tamaño del vector: " << root.size() << std::endl;
        //std::cout << "Contains nums " << root.isMember("nums") << std::endl;
          
    do{
        
        
        root["id"] = _id;
        fflush(stdin);
        cout<<"\nDigite su nombre: ";
        getline(cin,nombre);
        root["Nombre"] = nombre;
        
        cout<<"Digite su Apellido: ";
        getline(cin,apellido);
        root["Apellido"] = apellido;
        
        cout<<"Digite su E-mail: ";
        getline(cin,email);
        root["Email"] = email;
        
        cout<<"Digite su edad: ";
        cin >> edad;
        root["Edad"] = edad;
        
        writer.write(outFile, root);
        
        cout<<"\nDesea Agregar otro contacto ? \nYES: S \nNO:N\n ";
        cin>>rpt;
        
        _id ++;
    }while((rpt == 'S') || (rpt == 's'));
    // Write the output to a file
   // outFile.open("DatosPersonas.json");
   //writer.write(outFile, root);
    outFile.close();
    id = _id;
      
    
}

void Crud::agregar(){
    
    Json::Reader reader;
    Json::Value root;
    Json::StyledStreamWriter writer;
    //std::string text = "{ \"first\": \"James\", \"last\": \"Bond\", \"nums\": [1, 12, 7] }";
    std::string text = "{\"ID\": \" \",\"Nombre\": \" \", \"Apellido\": \" \", \"Edad\": \" \", \"Email\": \" \"}";
    std::ofstream outFile;
    outFile.open("DatosPersonas.json",ios::app);//abro el archivo en modo agregar
    char rpt;
    
      
      // Parse JSON and print errors if needed
    if(!reader.parse(text, root)) {
        std::cout << reader.getFormattedErrorMessages();
        exit(1);
    }
    
    do{
        root["id"] = id;
        fflush(stdin);
        cout<<"\nDigite su nombre: ";
        getline(cin,nombre);
        root["Nombre"] = nombre;
        
        cout<<"Digite su Apellido: ";
        getline(cin,apellido);
        root["Apellido"] = apellido;
        
        cout<<"Digite su E-mail: ";
        getline(cin,email);
        root["Email"] = email;
        
        cout<<"Digite su edad: ";
        cin >> edad;
        root["Edad"] = edad;
        
        writer.write(outFile, root);
        
        cout<<"\nDesea Agregar otro contacto ? \nYES: S \nNO:N\n ";
        cin>>rpt;
        
        id ++;
    }while((rpt == 'S') || (rpt == 's'));
    // Write the output to a file
   // outFile.open("DatosPersonas.json");
   //writer.write(outFile, root);
    outFile.close();
    
    
}

void Crud::modificar(){
    /*
    Json::Reader reader;
    Json::Value root;
    Json::StyledStreamWriter writer;
    //std::string text = "{ \"first\": \"James\", \"last\": \"Bond\", \"nums\": [1, 12, 7] }";
    std::ofstream aux;
    std::ifstream lectura;
    bool encontrado=false;
    int auxId=0;
    char auxNombre[50];
    
    aux.open("auxiliar.json",ios::out);//archivo de escritura
    lectura.open("DatosPersonas.json",ios::in);//archivo de lectura
    
    if(aux.is_open() && lectura.is_open()){

        cout<<"Ingresa el ID de la persona que deseas Modificar: ";
        cin>>auxId;//Se carga el dato en la variable auxiliar para comparar con lo guardado en el fichero
        std::cout << "Contains apellido " << root.isMember("Apellido") << endl;
        lectura>>apellido;
        lectura>>apellido;
        
        cout << "vamos a ver que  carga: " << apellido << endl;
        
    
    }
    */
}

void Crud::listar(){
    
    int con = 0;
    string texto;
    //Fichero de salida
    Json::Reader reader;
    Json::Value root;
    
    std::ifstream outFile;
    outFile.open("DatosPersonas.json");
    
    while(!outFile.eof()){ //mientras no sea el final de archivo
        getline(outFile,texto);
        cout<<texto<<endl;
        con = con+1;//contador auxiliar de numero de lineas en el archivo de datos
    }
    
    outFile.close();
    id=(con/7)-1;//se hace esta operacion para cargar al atributo id el valor
    
    cout << id <<endl;
}
