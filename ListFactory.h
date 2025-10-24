/**
 * @file ListFactory.h
 * @brief Definicja klasy ListFactory (wzorzec Fabryki).
 *
 * Plik zawiera prosta Fabryke (Factory)
 * do tworzenia instancji DoublyLinkedList na stercie.
 */

#pragma once
#include "DoublyLinkedList.h" // Fabryka musi wiedziec, co tworzy

 /**
  * @class ListFactory
  * @brief Implementacja wzorca Fabryki (Factory) dla DoublyLinkedList.
  *
  * Dostarcza statyczna metode `createList()` do tworzenia obiektow.
  * Ukrywa uzycie `new` przed klientem (np. `main.cpp`).
  */
class ListFactory {
public:
    /**
     * @brief Statyczna metoda fabryczna tworzaca nowa liste na stercie.
     *
     * Moze byc wywolana jako `ListFactory::createList()`.
     *
     * @return Wskaznik (DoublyLinkedList*) na nowo utworzony obiekt
     * na stercie (przez `new`).
     */
    static DoublyLinkedList* createList() {

        // "new" tworzy obiekt na stercie
        // Fabryka zwraca wskaznik (*) na ten obiekt.
        return new DoublyLinkedList();
    }
};