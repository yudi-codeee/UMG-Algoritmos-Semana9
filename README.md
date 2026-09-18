# Tarea Semana 9 - Manipulación de archivos CSV en C++

## Descripción
El programa permite leer un archivo CSV de productos, validar sus datos, calcular el valor total del inventario y buscar productos por su código.

## Estructura del archivo CSV
El archivo productos.csv contiene cuatro campos:

- codigo
- nombre
- precio
- existencia

Los datos están separados por comas.

## Validaciones
Un registro es válido cuando:
- El código no está vacío.
- El nombre no está vacío.
- El precio es mayor que 0.
- La existencia es mayor o igual que 0.

Los registros que no cumplen estas condiciones se cuentan como inválidos y no se utilizan para calcular el inventario.

## Ejecución
El programa abre el archivo usando la ruta relativa:

datos/productos.csv

Después lee los registros, valida los datos, calcula el inventario y permite ingresar un código para realizar una búsqueda.

Finalmente genera el archivo:

reportes/resumen.txt

## Resultados de las pruebas
Con el archivo proporcionado se obtuvieron:
- Registros válidos: 5
- Registros inválidos: 3
- Valor total del inventario: Q7179

También se realizaron búsquedas de un código existente (P003) y uno inexistente (P999).

## Manejo de errores
Si el archivo CSV no puede abrirse, el programa muestra un mensaje de error y termina de forma controlada.

## Uso de inteligencia artificial
Se consultó ChatGPT como apoyo para comprender la estructura del programa, la validación de datos y el manejo de archivos en C++. El código fue revisado y probado para comprender su funcionamiento.

## Video Explicativo
Puede ver la explicación del código en el siguiente enlace:
[Haz clic aquí para ver el video en Google Drive](https://drive.google.com/file/d/121EAh2pY5aXKXA4yTsETAoX78eW8T7pR/view?usp=drivesdk)
