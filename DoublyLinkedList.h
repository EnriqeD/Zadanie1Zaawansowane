/**
 * @file DoublyLinkedList.h
 * @brief Deklaracja klasy DoublyLinkedList. TAK
 */

#pragma once
#include "Node.h"
#include "Iterator.h"

 /**
  * @class DoublyLinkedList
  * @brief Implementuje liste dwukierunkowa.
  */
class DoublyLinkedList {
private:
    Node* head;  ///< Wskaznik na poczatek (glowe).
    Node* tail;  ///< Wskaznik na koniec (ogon).
    int count; ///< Liczba elementow.

    /**
     * @brief Pomocnik: Pobiera wezel o zadanym indeksie.
     * @param index Indeks (0-based) wezla.
     * @return Wskaznik (Node*) do wezla lub nullptr.
     */
    Node* getNode(int index);

public:
    /**
     * @brief Konstruktor. Tworzy pusta liste.
     */
    DoublyLinkedList();

    /**
     * @brief Destruktor. Zwalnia pamiec (wywoluje clear()).
     */
    ~DoublyLinkedList();

    /**
     * @brief Zwraca iterator na poczatek listy.
     * @return Iterator na 'head'.
     */
    Iterator begin();

    /**
     * @brief Zwraca iterator "za koncem" (nullptr).
     * @return Iterator na 'nullptr' (koniec petli).
     */
    Iterator end();

    /**
     * @brief Dodaje element na poczatek.
     * @param data Wartosc do dodania.
     */
    void addFront(int data);

    /**
     * @brief Dodaje element na koniec.
     * @param data Wartosc do dodania.
     */
    void addBack(int data);

    /**
     * @brief Dodaje element na indeks.
     * @param data Wartosc do dodania.
     * @param index Indeks (0-based) wstawienia.
     */
    void addAt(int data, int index);

    /**
     * @brief Usuwa element z poczatku.
     */
    void removeFront();

    /**
     * @brief Usuwa element z konca.
     */
    void removeBack();

    /**
     * @brief Usuwa element z indeksu.
     * @param index Indeks (0-based) do usuniecia.
     */
    void removeAt(int index);

    /**
     * @brief Wyswietla liste (Head -> Tail).
     */
    void display();

    /**
     * @brief Wyswietla liste odwrotnie (Tail -> Head).
     */
    void displayReverse();

    /**
     * @brief Czysci liste (usuwa wszystkie elementy).
     */
    void clear();

    /**
     * @brief Zwraca liczbe elementow.
     * @return Liczba elementow (int).
     */
    int getSize();

    /**
     * @brief Sprawdza, czy lista jest pusta.
     * @return `true` jesli pusta, `false` w innym razie.
     */
    bool isEmpty();
};
