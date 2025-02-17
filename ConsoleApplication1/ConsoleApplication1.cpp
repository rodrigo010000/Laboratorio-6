// ConsoleApplication1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;

// Clase base Vehiculo
class Vehiculo {
private:
    string marca;
    string modelo;
    double precio;

public:
    // Constructor
    Vehiculo(string m, string mod, double p) : marca(m), modelo(mod), precio(p) {}

    // Métodos getters y setters
    string getMarca() { return marca; }
    void setMarca(string m) { marca = m; }

    string getModelo() { return modelo; }
    void setModelo(string mod) { modelo = mod; }

    double getPrecio() { return precio; }
    void setPrecio(double p) { precio = p; }

    // Método mostrarInfo
    virtual void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Precio: $" << precio << endl;
    }
};

// Clase derivada Automovil
class Automovil : public Vehiculo {
private:
    int numPuertas;

public:
    // Constructor
    Automovil(string m, string mod, double p, int puertas)
        : Vehiculo(m, mod, p), numPuertas(puertas) {
    }

    // Métodos getters y setters
    int getNumPuertas() { return numPuertas; }
    void setNumPuertas(int puertas) { numPuertas = puertas; }

    // Sobrescribir el método mostrarInfo
    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << "Numero de puertas: " << numPuertas << endl;
    }
};

// Clase derivada Motocicleta
class Motocicleta : public Vehiculo {
private:
    int cilindrada;

public:
    // Constructor
    Motocicleta(string m, string mod, double p, int c)
        : Vehiculo(m, mod, p), cilindrada(c) {
    }

    // Métodos getters y setters
    int getCilindrada() { return cilindrada; }
    void setCilindrada(int c) { cilindrada = c; }

    // Sobrescribir el método mostrarInfo
    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << "Cilindrada: " << cilindrada << " cc" << endl;
    }
};

// Clase derivada Camioneta
class Camioneta : public Vehiculo {
private:
    int capacidadCarga;

public:
    // Constructor
    Camioneta(string m, string mod, double p, int carga)
        : Vehiculo(m, mod, p), capacidadCarga(carga) {
    }

    // Métodos getters y setters
    int getCapacidadCarga() { return capacidadCarga; }
    void setCapacidadCarga(int carga) { capacidadCarga = carga; }

    // Sobrescribir el método mostrarInfo
    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        cout << "Capacidad de carga: " << capacidadCarga << " kg" << endl;
    }
};

// Clase Cliente
class Cliente {
private:
    string nombre;
    int edad;

public:
    // Constructor
    Cliente(string n, int e) : nombre(n), edad(e) {}

    // Métodos getters y setters
    string getNombre() { return nombre; }
    void setNombre(string n) { nombre = n; }

    int getEdad() { return edad; }
    void setEdad(int e) { edad = e; }

    // Método comprarVehiculo
    void comprarVehiculo(Vehiculo* v) {
        cout << nombre << " ha comprado el siguiente vehiculo:" << endl;
        v->mostrarInfo();
        cout << endl;
    }
};

int main() {
    // Crear vehículos
    Automovil auto1("Toyota", "Corolla", 20000, 4);
    Motocicleta moto1("Honda", "CBR500R", 7500, 500);
    Camioneta camioneta1("Ford", "Ranger", 35000, 1000);

    // Crear cliente
    Cliente cliente1("Juan Perez", 30);

    // El cliente compra vehículos
    cliente1.comprarVehiculo(&auto1);
    cliente1.comprarVehiculo(&moto1);
    cliente1.comprarVehiculo(&camioneta1);

    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
