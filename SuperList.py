from enum import Enum
from datetime import datetime

lista_compras = []

class Menu(Enum):
    AGREGAR = "1"
    VER = "2"
    ELIMINAR = "3"
    SALIR = "4"

def mostrar_menu():
    print("\n--- LISTA DE COMPRAS ---")
    print(f"{Menu.AGREGAR.value}. Agregar producto")
    print(f"{Menu.VER.value}. Ver lista")
    print(f"{Menu.ELIMINAR.value}. Eliminar producto")
    print(f"{Menu.SALIR.value}. Salir")

def agregar_producto():
    producto = input("Nombre del producto: ")
    cantidad = input("Cantidad: ")
    fecha = datetime.now().strftime("%d/%m/%Y %H:%M")
    lista_compras.append(f"{producto} x{cantidad} (agregado el {fecha})")
    print("Producto agregado correctamente.")

def ver_lista():
    if not lista_compras:
        print("La lista está vacía.")
    else:
        print("\nProductos en la lista:")
        for i, p in enumerate(lista_compras, start=1):
            print(f"{i}. {p}")

def eliminar_producto():
    if not lista_compras:
        print("No hay productos para eliminar.")
        return

    print("\n--- ELIMINAR PRODUCTO ---")
    ver_lista()
    indice = input("Escribí el número del producto a eliminar(numero): ")

    try:
        indice = int(indice) - 1
        if 0 <= indice < len(lista_compras):
            eliminado = lista_compras.pop(indice)
            print(f"Se eliminó: {eliminado}")
        else:
            print("Número inválido.")
    except ValueError:
        print("Debés escribir un número válido.")

while True:
    mostrar_menu()
    opcion = input("Elegí una opción: ")

    match opcion:
        case Menu.AGREGAR.value:
            agregar_producto()
        case Menu.VER.value:
            ver_lista()
        case Menu.ELIMINAR.value:
            eliminar_producto()
        case Menu.SALIR.value:
            print("Saliendo del programa...")
            break
        case _:
            print("Opción inválida, intentá nuevamente.")
