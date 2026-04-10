# Sistema de Domicilios en C

Esta es una aplicación de consola desarrollada en C que simula el flujo de un sistema de pedidos a domicilio. Fue diseñada aplicando programación estructurada, modularidad e implementando diferentes tipos de ciclos y condicionales.

## Características
- **Menú interactivo:** Navegación sencilla utilizando estructuras `do...while` y `switch`.
- **Catálogo de productos:** Arreglo estructurado de más de 6 opciones de comida.
- **Gestión de carrito:** Permite agregar ítems validando la existencia mediante el ID y asegurando que las cantidades ingresadas sean mayores a 0.
- **Cálculo de totales:** Genera un subtotal dinámico de los productos y añade una tarifa fija de domicilio para entregar un total final exacto.

## Estructura del Proyecto
El repositorio contiene los siguientes archivos:
- `main.c`: Contiene todo el código fuente, la lógica de negocio y las estructuras de datos (`struct`).
- `README.md`: Documentación del proyecto.

## Instrucciones de Compilación y Ejecución

Para compilar y ejecutar este programa, necesitas tener instalado el compilador GCC en tu entorno (Windows, Linux o macOS).

1. Clona este repositorio o descarga el archivo `main.c`.
2. Abre una terminal y navega hasta el directorio donde se encuentra el archivo.
3. Compila el código ejecutando el siguiente comando:
   ```bash
   gcc main.c -o domicilios
