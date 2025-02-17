#include <iostream>
#include <string>
using namespace std;

// Clase base Vehiculo
class Vehiculo {
private:
    string marca;  // Atributo privado para la marca del vehículo
    string modelo; // Atributo privado para el modelo del vehículo
    double precio; // Atributo privado para el precio del vehículo

public:
    // Constructor que inicializa los atributos del vehículo
    Vehiculo(string m, string mod, double p) : marca(m), modelo(mod), precio(p) {}

    // Métodos getter y setter para acceder a los atributos privados
    string getMarca() { return marca; }
    void setMarca(string m) { marca = m; }

    string getModelo() { return modelo; }
    void setModelo(string mod) { modelo = mod; }

    double getPrecio() { return precio; }
    void setPrecio(double p) { precio = p; }

    // Método que muestra la información básica del vehículo
    virtual void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Precio: $" << precio << endl;
    }
};

// Clase derivada Automovil
class Automovil : public Vehiculo {
private:
    int numPuertas; // Atributo específico para el número de puertas

public:
    // Constructor que inicializa los atributos de Vehiculo y el número de puertas
    Automovil(string m, string mod, double p, int puertas)
        : Vehiculo(m, mod, p), numPuertas(puertas) {}

    // Métodos getter y setter para el número de puertas
    int getNumPuertas() { return numPuertas; }
    void setNumPuertas(int puertas) { numPuertas = puertas; }

    // Sobrescribimos el método mostrarInfo para incluir el número de puertas
    void mostrarInfo() override {
        Vehiculo::mostrarInfo();  // Llamamos al método de la clase base
        cout << "Número de puertas: " << numPuertas << endl; // Mostramos el número de puertas
    }
};

// Clase derivada Motocicleta
class Motocicleta : public Vehiculo {
private:
    int cilindrada; // Atributo específico para la cilindrada de la motocicleta

public:
    // Constructor que inicializa los atributos de Vehiculo y la cilindrada
    Motocicleta(string m, string mod, double p, int c)
        : Vehiculo(m, mod, p), cilindrada(c) {}

    // Métodos getter y setter para la cilindrada
    int getCilindrada() { return cilindrada; }
    void setCilindrada(int c) { cilindrada = c; }

    // Sobrescribimos el método mostrarInfo para incluir la cilindrada
    void mostrarInfo() override {
        Vehiculo::mostrarInfo();  // Llamamos al método de la clase base
        cout << "Cilindrada: " << cilindrada << " cc" << endl; // Mostramos la cilindrada
    }
};

// Clase derivada Camioneta
class Camioneta : public Vehiculo {
private:
    int capacidadCarga; // Atributo específico para la capacidad de carga

public:
    // Constructor que inicializa los atributos de Vehiculo y la capacidad de carga
    Camioneta(string m, string mod, double p, int carga)
        : Vehiculo(m, mod, p), capacidadCarga(carga) {}

    // Métodos getter y setter para la capacidad de carga
    int getCapacidadCarga() { return capacidadCarga; }
    void setCapacidadCarga(int carga) { capacidadCarga = carga; }

    // Sobrescribimos el método mostrarInfo para incluir la capacidad de carga
    void mostrarInfo() override {
        Vehiculo::mostrarInfo();  // Llamamos al método de la clase base
        cout << "Capacidad de carga: " << capacidadCarga << " kg" << endl; // Mostramos la capacidad de carga
    }
};

// Clase Cliente
class Cliente {
private:
    string nombre; // Atributo para el nombre del cliente
    int edad;      // Atributo para la edad del cliente

public:
    // Constructor para inicializar los atributos del cliente
    Cliente(string n, int e) : nombre(n), edad(e) {}

    // Métodos getter y setter para acceder a los atributos del cliente
    string getNombre() { return nombre; }
    void setNombre(string n) { nombre = n; }

    int getEdad() { return edad; }
    void setEdad(int e) { edad = e; }

    // Método para simular la compra de un vehículo
    void comprarVehiculo(Vehiculo* v) {
        cout << nombre << " ha comprado el siguiente vehículo:" << endl;
        v->mostrarInfo();  // Llamamos al método mostrarInfo del vehículo
        cout << endl;
    }
};

int main() {
    // Crear objetos de las clases derivadas
    Automovil auto1("Toyota", "Corolla", 20000, 4);
    Motocicleta moto1("Honda", "CBR500R", 7500, 500);
    Camioneta camioneta1("Ford", "Ranger", 35000, 1000);

    // Crear un objeto de la clase Cliente
    Cliente cliente1("Juan Pérez", 30);

    // Simular la compra de vehículos por parte del cliente
    cliente1.comprarVehiculo(&auto1);
    cliente1.comprarVehiculo(&moto1);
    cliente1.comprarVehiculo(&camioneta1);

    return 0;
}

