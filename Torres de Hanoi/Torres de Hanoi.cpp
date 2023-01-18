// Enunciado:
// Torres de Hanoi 
//
// Fecha de entrega:
// 16/1/23
//
// Participantes:
// 1- John Luis Del Rosario Sánchez - ID 1106940
// 2- Ashly Marisell Paula Ynoa - ID 1108023
// 3- Elián Matos Díaz - ID 1106901
// 4- Juan Daniel Ubiera Méndez - ID 1107248
// 5- Kelvin Arístides García Espinal - ID 1107646

#include <iostream>
#include <string>
using namespace std;

int contador = 0;

void hanoi(int dato, char origen, char destino, char aux) {
    contador++; //sumar 1 al contador por cada movimiento
    if (dato == 1) { //cuando se llegue al anillo 1
        cout << "Mover anillo 1 desde " << origen << " a " << destino << endl;
        return; //regresar a los valores de la recursion
    }
    hanoi(dato - 1, origen, aux, destino); //primera llamada recursiva
    cout << "Mover anillo " << dato << " desde " << origen << " a " << destino << endl;
    hanoi(dato - 1, aux, destino, origen); //segunda llamda recursiva
}

string ValidarNumero(string str)
{
    bool notNum = false;
    int i = 0;
    while ((str[i] != '\0') && notNum != true) //'\0' es el character que marca el final del string
    {
        if (isdigit(str[i]) == false)// compara cada caracter de la cadena para saber si es numerico
        {
            str = "";
            notNum = true;
            break;
        }
        i++;
    }
    return str; //devuelve un str igual si no se encontraron letras
}

int main() {
    string anillos;// string utilizado para la validacion numerica
    int anillosI;// int para asignar la validacion del dato insertado

    do {
        cout << "Ingrese el numero de anillos: ";
        cin >> anillos;
        if (ValidarNumero(anillos) != anillos) {
            cout << "Tipo de dato incorrecto, solo se permiten numeros, intente de nuevo" << endl;
            system("PAUSE");
            system("CLS");

            continue;
        }
        anillosI = stoi(anillos);// conversion de string a int del dato ya validado
        hanoi(anillosI, 'A', 'C', 'B');// metodo para iniciar el juego, A, B Y C son las respectivas torres
        cout << "Movimientos realizados: " << contador << endl;
        return 0;
    } while (true);
}