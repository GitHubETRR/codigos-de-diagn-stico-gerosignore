#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehiculo {
protected:
    string marca;

public:
    Vehiculo(const string& m) : marca(m) {}

    virtual void arrancar() {
        cout << marca << " está arrancando..." << endl;
    }

    virtual string getTipo() {
        return "Vehículo";
    }

    string getMarca() {
        return marca;
    }

    virtual ~Vehiculo() {}
};

class Auto : public Vehiculo {
public:
    Auto(const string& m) : Vehiculo(m) {}

    void arrancar() override {
        cout << marca << " (Auto) enciende el motor" << endl;
    }

    string getTipo() override {
        return "Auto";
    }
};

class Moto : public Vehiculo {
public:
    Moto(const string& m) : Vehiculo(m) {}

    void arrancar() override {
        cout << marca << " (Moto) arranca" << endl;
    }

    string getTipo() override {
        return "Moto";
    }
};

void mostrarMenu() {
    cout << "\n=== GARAGE ===\n";
    cout << "1. Agregar Auto\n";
    cout << "2. Agregar Moto\n";
    cout << "3. Mostrar Vehículos\n";
    cout << "4. Arrancarlos\n";
    cout << "5. Salir\n";
    cout << "Opción: ";
}

int main() {
    vector<Vehiculo*> garage;
    int opcion;
    string marca;

    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
            case 1:
                cout << "Marca del auto: ";
                getline(cin, marca); 
                garage.push_back(new Auto(marca));
                break;

            case 2:
                cout << "Marca de la moto: ";
                getline(cin, marca);
                garage.push_back(new Moto(marca));
                break;

            case 3:
                cout << "\nVehículos en el garage:\n";
                for (size_t i = 0; i < garage.size(); ++i) {
                    cout << i + 1 << ". " << garage[i]->getTipo()
                         << " - " << garage[i]->getMarca() << endl;
                }
                break;

            case 4:
                cout << "\nTodos los vehículos arrancan:\n";
                for (Vehiculo* v : garage) {
                    v->arrancar();
                }
                break;

            case 5:
                cout << "Saliendo del garage..." << endl;
                break;

            default:
                cout << "Opción inválida, intenta otra vez." << endl;
        }

    } while (opcion != 5);

    for (Vehiculo* v : garage) {
        delete v;
    }

    return 0;
}
