/**
 * @file Iterator.h
 * @brief Deklaracja klasy Iterator.
 *
 * Iterator sluzy do "chodzenia" po liscie.
 */

#pragma once
#include "Node.h" // Iterator musi wiedziec, czym jest "Node".

 /**
  * @class Iterator
  * @brief Iterator dwukierunkowy dla DoublyLinkedList.
  *
  * Umozliwia przechodzenie (++, --) i odczyt (*) elementow.
  */
class Iterator {
private:
    /**
     * @brief Wskaznik na biezacy wezel.
     * Przechowuje adres wezla, na ktory "patrzy" iterator.
     */
    Node* currentNode;

public:
    /**
     * @brief Konstruktor.
     * Tworzy iterator wskazujacy na podany wezel.
     * @param node Wezel startowy.
     */
    Iterator(Node* node);

    /**
     * @brief Operator dereferencji (*).
     * Zwraca referencje do danych (int&) w biezacym wezle.
     * @return Referencja do danych.
     */
    int& operator*();

    /**
     * @brief Operator pre-inkrementacji (++it).
     * Przesuwa iterator na nastepny wezel.
     * @return Referencja do *this (po przesunieciu).
     */
    Iterator& operator++();

    /**
     * @brief Operator pre-dekrementacji (--it).
     * Przesuwa iterator na poprzedni wezel.
     * @return Referencja do *this (po przesunieciu).
     */
    Iterator& operator--();

    /**
     * @brief Operator porownania (==).
     * Sprawdza, czy iteratory wskazuja na ten sam wezel.
     * @param other Inny iterator do porownania.
     * @return `true` jesli rowne, `false` wpp.
     */
    bool operator==(const Iterator& other);

    /**
     * @brief Operator nierownosci (!=).
     * Sprawdza, czy iteratory wskazuja na rozne wezly.
     * @param other Inny iterator do porownania.
     * @return `true` jesli rozne, `false` wpp.
     */
    bool operator!=(const Iterator& other);
};