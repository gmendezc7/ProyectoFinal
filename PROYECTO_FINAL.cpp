#include <iostream>

using namespace std;

double convertirGradosARadianes(double grados);
double calcularSeno(double radianes);
double calcularCoseno(double radianes);
double calcularTangente(double radianes);
double calcularCotangente(double radianes);
double calcularSecante(double radianes);
double calcularCosecante(double radianes);

const double PI = 3.14159265358979323846;

int main() {
    double anguloGrados;
    char opcion;

    do {
        cout << "Ingrese el ángulo en grados: ";
        cin >> anguloGrados;

        double anguloRadianes = convertirGradosARadianes(anguloGrados);

        cout << "\nMenú de Opciones:\n";
        cout << "1. Seno\n";
        cout << "2. Coseno\n";
        cout << "3. Tangente\n";
        cout << "4. Cotangente\n";
        cout << "5. Secante\n";
        cout << "6. Cosecante\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                cout << "Resultado (Seno): " << calcularSeno(anguloRadianes) << "\n";
                break;
            case '2':
                cout << "Resultado (Coseno): " << calcularCoseno(anguloRadianes) << "\n";
                break;
            case '3':
                cout << "Resultado (Tangente): " << calcularTangente(anguloRadianes) << "\n";
                break;
            case '4':
                cout << "Resultado (Cotangente): " << calcularCotangente(anguloRadianes) << "\n";
                break;
            case '5':
                cout << "Resultado (Secante): " << calcularSecante(anguloRadianes) << "\n";
                break;
            case '6':
                cout << "Resultado (Cosecante): " << calcularCosecante(anguloRadianes) << "\n";
                break;
            case '0':
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida.\n";
        }

    } while (opcion != '0');

    return 0;
}

double convertirGradosARadianes(double grados) {
    return grados * (PI / 180.0);
}

double calcularSeno(double radianes) {
    double resultado = radianes;
    double termino = radianes;
    double signo = -1.0;
    for (int i = 2; i <= 10; i += 2) {
        termino *= radianes * radianes / ((i + 1) * i);
        resultado += signo * termino;
        signo *= -1.0;
    }
    return resultado;
}

double calcularCoseno(double radianes) {
    double resultado = 1.0;
    double termino = 1.0;
    double signo = -1.0;
    for (int i = 2; i <= 10; i += 2) {
        termino *= radianes * radianes / ((i + 1) * i);
        resultado += signo * termino;
        signo *= -1.0;
    }
    return resultado;
}

double calcularTangente(double radianes) {
    return calcularSeno(radianes) / calcularCoseno(radianes);
}

double calcularCotangente(double radianes) {
    return 1.0 / calcularTangente(radianes);
}

double calcularSecante(double radianes) {
    return 1.0 / calcularCoseno(radianes);
}

double calcularCosecante(double radianes) {
    return 1.0 / calcularSeno(radianes);
}

