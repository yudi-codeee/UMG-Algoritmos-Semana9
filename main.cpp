#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Producto {
    string codigo;
    string nombre;
    double precio;
    int existencia;
};

int main()
{
    ifstream archivo("datos/productos.csv");

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo productos.csv" << endl;
        return 1;
    }

    string linea;
    int validos = 0;
    int invalidos = 0;
    double valorInventario = 0;

    vector<Producto> productos;

    // Omitir el encabezado
    getline(archivo, linea);

    // Leer el archivo línea por línea
    while (getline(archivo, linea))
    {
        string codigo, nombre, precioTexto, existenciaTexto;

        stringstream ss(linea);

        getline(ss, codigo, ',');
        getline(ss, nombre, ',');
        getline(ss, precioTexto, ',');
        getline(ss, existenciaTexto, ',');

        try
        {
            double precio = stod(precioTexto);
            int existencia = stoi(existenciaTexto);

            if (codigo.empty() || nombre.empty() || precio <= 0 || existencia < 0)
            {
                invalidos++;
                continue;
            }

            Producto producto;
            producto.codigo = codigo;
            producto.nombre = nombre;
            producto.precio = precio;
            producto.existencia = existencia;

            productos.push_back(producto);

            validos++;
            valorInventario += precio * existencia;
        }
        catch (...)
        {
            invalidos++;
        }
    }

    archivo.close();

    cout << "Registros validos: " << validos << endl;
    cout << "Registros invalidos: " << invalidos << endl;
    cout << "Valor total del inventario: Q" << valorInventario << endl;

    // Buscar un producto
    string codigoBuscado;
    cout << "\nIngrese el codigo del producto a buscar: ";
    cin >> codigoBuscado;

    bool encontrado = false;

    for (const Producto& producto : productos)
    {
        if (producto.codigo == codigoBuscado)
        {
            cout << "\nProducto encontrado:" << endl;
            cout << "Codigo: " << producto.codigo << endl;
            cout << "Nombre: " << producto.nombre << endl;
            cout << "Precio: Q" << producto.precio << endl;
            cout << "Existencia: " << producto.existencia << endl;

            encontrado = true;
            break;
        }
    }

    if (!encontrado)
    {
        cout << "\nEl producto no existe." << endl;
    }

    // Crear el reporte
    ofstream reporte("reportes/resumen.txt");

    if (!reporte.is_open())
    {
        cout << "No se pudo crear el archivo de reporte." << endl;
        return 1;
    }

    reporte << "RESUMEN DEL INVENTARIO" << endl;
    reporte << "Registros validos: " << validos << endl;
    reporte << "Registros invalidos: " << invalidos << endl;
    reporte << "Valor total del inventario: Q" << valorInventario << endl;

    reporte << "\nRESULTADO DE LA BUSQUEDA" << endl;

    if (encontrado)
    {
        for (const Producto& producto : productos)
        {
            if (producto.codigo == codigoBuscado)
            {
                reporte << "Codigo: " << producto.codigo << endl;
                reporte << "Nombre: " << producto.nombre << endl;
                reporte << "Precio: Q" << producto.precio << endl;
                reporte << "Existencia: " << producto.existencia << endl;
                break;
            }
        }
    }
    else
    {
        reporte << "El producto no existe." << endl;
    }

    reporte.close();

    cout << "\nReporte generado correctamente." << endl;

    return 0;
}