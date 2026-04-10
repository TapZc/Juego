#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de constantes para límites de la aplicación
#define MAX_PRODUCTS 6
#define MAX_CART_ITEMS 50
#define DELIVERY_FEE 5000.0 // Tarifa fija de domicilio

// Estructura para representar un producto del catálogo
typedef struct {
    int id;
    char name[30];
    float price;
} Product;

// Estructura para representar un ítem dentro del carrito
typedef struct {
    Product product;
    int quantity;
    float subtotal;
} CartItem;

// Prototipos de funciones (Estructura y Organización)
void showMenu();
void displayProducts(Product catalog[], int size);
void addToCart(Product catalog[], int catalogSize, CartItem cart[], int *cartSize);
void viewCart(CartItem cart[], int cartSize);
void checkout(CartItem cart[], int *cartSize);

int main() {
    // Inicialización del catálogo de productos (Mínimo 6 productos solicitados)
    Product catalog[MAX_PRODUCTS] = {
        {1, "Hamburguesa Clasica", 15000.0},
        {2, "Pizza Personal", 18000.0},
        {3, "Perro Caliente", 12000.0},
        {4, "Papas Fritas", 6000.0},
        {5, "Gaseosa 400ml", 4000.0},
        {6, "Jugo Natural", 5000.0}
    };

    CartItem cart[MAX_CART_ITEMS]; // Arreglo para almacenar los productos del carrito
    int cartSize = 0;              // Contador de ítems actuales en el carrito
    int option;                    // Variable para la opción del menú

    // Ciclo principal de la aplicación (do...while)
    do {
        showMenu();
        printf("\nSeleccione una opcion: ");
        
        // Validación básica de entrada
        if (scanf("%d", &option) != 1) {
            printf("Entrada invalida. Por favor ingrese un numero.\n");
            while(getchar() != '\n'); // Limpiar el buffer
            continue;
        }

        // Estructura condicional para manejar el flujo del menú (switch)
        switch (option) {
            case 1:
                displayProducts(catalog, MAX_PRODUCTS);
                break;
            case 2:
                addToCart(catalog, MAX_PRODUCTS, cart, &cartSize);
                break;
            case 3:
                viewCart(cart, cartSize);
                break;
            case 4:
                checkout(cart, &cartSize);
                break;
            case 5:
                printf("\nSaliendo del sistema. Gracias por preferirnos!\n");
                break;
            default:
                printf("\nOpcion no valida. Intente nuevamente.\n");
        }
    } while (option != 5);

    return 0;
}

// Función para mostrar el menú principal
void showMenu() {
    printf("\n==================================\n");
    printf("        SISTEMA DE DOMICILIOS       \n");
    printf("==================================\n");
    printf("1. Ver menu de productos\n");
    printf("2. Agregar producto al carrito\n");
    printf("3. Ver carrito y total\n");
    printf("4. Confirmar pedido\n");
    printf("5. Salir\n");
    printf("==================================\n");
}

// Función para mostrar el catálogo disponible
void displayProducts(Product catalog[], int size) {
    printf("\n--- MENU DE PRODUCTOS ---\n");
    printf("ID\t| Precio\t| Nombre\n");
    printf("----------------------------------\n");
    
    // Ciclo para iterar sobre el arreglo de productos (for)
    for (int i = 0; i < size; i++) {
        printf("%d\t| $%.2f\t| %s\n", catalog[i].id, catalog[i].price, catalog[i].name);
    }
}

// Función para agregar un producto al carrito
void addToCart(Product catalog[], int catalogSize, CartItem cart[], int *cartSize) {
    int productId, quantity;
    int found = 0;

    displayProducts(catalog, catalogSize);
    
    printf("\nIngrese el ID del producto que desea agregar: ");
    scanf("%d", &productId);

    // Buscar el producto en el catálogo
    for (int i = 0; i < catalogSize; i++) {
        if (catalog[i].id == productId) {
            found = 1; // Producto encontrado
            printf("Ingrese la cantidad para '%s': ", catalog[i].name);
            scanf("%d", &quantity);

            // Validar que la cantidad sea mayor a 0 (if/else)
            if (quantity > 0) {
                // Agregar al carrito
                cart[*cartSize].product = catalog[i];
                cart[*cartSize].quantity = quantity;
                cart[*cartSize].subtotal = catalog[i].price * quantity;
                (*cartSize)++; // Incrementar el tamaño del carrito
                
                printf("\nExito: %d x %s agregado(s) al carrito.\n", quantity, catalog[i].name);
            } else {
                printf("\nError: La cantidad debe ser mayor a 0.\n");
            }
            break; // Salir del ciclo una vez procesado el producto
        }
    }

    // Si el ciclo termina y no se encontró el producto
    if (!found) {
        printf("\nError: Producto con ID %d no encontrado.\n", productId);
    }
}

// Función para visualizar el carrito y calcular el subtotal
void viewCart(CartItem cart[], int cartSize) {
    if (cartSize == 0) {
        printf("\nEl carrito esta vacio.\n");
        return;
    }

    float total = 0.0;
    
    printf("\n--- CARRITO DE COMPRAS ---\n");
    printf("Cant.\t| Producto\t\t| Subtotal\n");
    printf("----------------------------------\n");

    // Recorrer el carrito para imprimir ítems y sumar (for)
    for (int i = 0; i < cartSize; i++) {
        printf("%d\t| %-20s\t| $%.2f\n", cart[i].quantity, cart[i].product.name, cart[i].subtotal);
        total += cart[i].subtotal;
    }
    
    printf("----------------------------------\n");
    printf("Subtotal:\t\t\t$%.2f\n", total);
    printf("Domicilio:\t\t\t$%.2f\n", DELIVERY_FEE);
    printf("TOTAL A PAGAR:\t\t\t$%.2f\n", total + DELIVERY_FEE);
}

// Función para simular la confirmación y pago del pedido
void checkout(CartItem cart[], int *cartSize) {
    if (*cartSize == 0) {
        printf("\nNo puede confirmar un pedido vacio. Agregue productos primero.\n");
        return;
    }

    viewCart(cart, *cartSize);
    
    char confirm;
    printf("\nDesea confirmar este pedido? (S/N): ");
    scanf(" %c", &confirm); // Espacio antes de %c para capturar el salto de línea previo

    // Condicional para validar la respuesta
    if (confirm == 'S' || confirm == 's') {
        printf("\n======================================================\n");
        printf(" PEDIDO CONFIRMADO. Su comida esta en preparacion.\n");
        printf("======================================================\n");
        *cartSize = 0; // Vaciar el carrito reiniciando el contador
    } else {
        printf("\nPedido cancelado. Puede seguir modificando su carrito.\n");
    }
}