/**
 * @file main.cpp
 * @brief Testy dla DoublyLinkedList.
 */

#include <iostream>
#include "ListFactory.h"
#include "DoublyLinkedList.h"

 /**
  * @brief Funkcja main() testujaca liste.
  *
  * Testy:
  * 1. Dodawanie
  * 2. Usuwanie
  * 3. Wyswietlanie
  * 4. Iterator
  * 5. Czyszczenie
  * 6. Obsluga bledow
  *
  * @return 0 po zakonczeniu.
  */
int main() {
    std::cout << "Testy Listy Dwukierunkowej" << std::endl;

    // Test 1: Tworzenie
    DoublyLinkedList* list = ListFactory::createList();
    std::cout << "Stworzono liste." << std::endl;

    // Test 2: Dodawanie (kraje)
    std::cout << "\n Dodawanie (addBack, addFront):" << std::endl;
    list->addBack(10);
    list->addBack(20);
    list->addFront(5);
    // Lista: 5 <-> 10 <-> 20
    list->display();
    std::cout << "Rozmiar: " << list->getSize() << std::endl;

    // Test 3: Wyswietlanie (odwrotnie)
    std::cout << "\n Wyswietlanie (displayReverse):" << std::endl;
    list->displayReverse();

    // Test 4: Dodawanie (indeks)
    std::cout << "\n Dodawanie (addAt):" << std::endl;
    list->addAt(15, 2); // 5 <-> 10 <-> 15 <-> 20
    list->addAt(0, 0);  // 0 <-> 5 <-> 10 <-> 15 <-> 20
    list->addAt(25, 5); // 0 <-> 5 <-> 10 <-> 15 <-> 20 <-> 25
    list->display();

    // Test 5: Usuwanie (kraje)
    std::cout << "\n Usuwanie (removeFront, removeBack):" << std::endl;
    list->removeFront(); // Usuwa 0
    list->removeBack();  // Usuwa 25
    // Lista: 5 <-> 10 <-> 15 <-> 20
    list->display();

    // Test 6: Usuwanie (indeks)
    std::cout << "\n Usuwanie (removeAt):" << std::endl;
    list->removeAt(1); // Usuwa 10
    // Lista: 5 <-> 15 <-> 20
    list->display();

    // Test 7: Iterator (for-each)
    std::cout << "\n Iterator (petla for-each):" << std::endl;
    std::cout << "Zawartosc listy: ";
    for (int value : *list) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Test 8: Iterator (manualnie)
    std::cout << "\n Iterator (manualna obsluga):" << std::endl;

    Iterator it = list->begin(); // it -> 5
    std::cout << "Poczatek: " << *it << std::endl; // 5

    // Nastepny
    ++it; // it -> 15
    std::cout << "Nastepny (++it): " << *it << std::endl; // 15

    // Poprzedni
    --it; // it -> 5
    std::cout << "Poprzedni (--it): " << *it << std::endl; // 5

    // Test 9: Czyszczenie
    std::cout << "\n Czyszczenie (clear):" << std::endl;
    list->clear();
    std::cout << "Lista po clear() (isEmpty? " << std::boolalpha << list->isEmpty() << "):" << std::endl;
    list->display(); // Pusta lista

    // Test 10: Bledu
    std::cout << "\n Obsluga bledow:" << std::endl;
    try {
        list->removeFront(); // Usun z pustej
    }
    catch (const std::exception& e) {
        // Oczekiwany blad
        std::cout << "Blad: " << e.what() << std::endl;
    }

    // Test 11: Sprzatanie
    delete list;
    list = nullptr;

    std::cout << "\n Zakonczono" << std::endl;
    return 0;
}