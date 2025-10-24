/**
 * @file Iterator.cpp
 * @brief Implementacja Iterator.
 *
 * Definicje operatorow iteratora.
 */

#include "Iterator.h"
#include <stdexcept> // Dla std::runtime_error

 /**
  * @brief Konstruktor.
  * @param node Startowy wezel.
  */
Iterator::Iterator(Node* node) : currentNode(node) {
    // Puste cialo
}

/**
 * @brief Operator dereferencji (*).
 * Zwraca dane (int&).
 * @return Dane (int&).
 * @throws std::runtime_error Jesli nullptr.
 */
int& Iterator::operator*() {
    // Sprawdz, czy nie nullptr
    if (currentNode == nullptr) {
        // Blad
        throw std::runtime_error("Blad: Proba odczytu danych z iteratora wskazujacego na nullptr!");
    }
    // Zwroc dane
    return currentNode->data;
}

/**
 * @brief Operator ++it.
 * Przesun na nastepny (next).
 * @return *this.
 */
Iterator& Iterator::operator++() {
    // Jesli nie null
    if (currentNode) {
        // Idz do przodu
        currentNode = currentNode->next;
    }
    // Zwroc *this
    return *this;
}

/**
 * @brief Operator --it.
 * Przesun na poprzedni (prev).
 * @return *this.
 */
Iterator& Iterator::operator--() {
    // Jesli nie null
    if (currentNode) {
        // Idz do tylu
        currentNode = currentNode->prev;
    }
    // Zwroc *this
    return *this;
}

/**
 * @brief Operator ==.
 * Sprawdza rownosc wezlow.
 * @param other Drugi iterator.
 * @return true jesli te same, false wpp.
 */
bool Iterator::operator==(const Iterator& other) {
    // Porownaj wskazniki
    return currentNode == other.currentNode;
}

/**
 * @brief Operator !=.
 * Sprawdza nierownosc wezlow.
 * @param other Drugi iterator.
 * @return true jesli rozne, false wpp.
 */
bool Iterator::operator!=(const Iterator& other) {
    // Uzyj operatora ==
    return !(*this == other);
}