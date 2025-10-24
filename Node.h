/**
 * @file Node.h
 * @brief Definiuje strukture wezla (Node) dla listy dwukierunkowej.
 *
 * Ten plik zawiera definicje podstawowego bloku budujacego liste.
 */

 // #pragma once to dyrektywa, ktora mowi kompilatorowi,
 // aby wczytal ten plik tylko jeden raz.
#pragma once

/**
 * @struct Node
 * @brief Reprezentuje pojedynczy element (wezel) w liscie dwukierunkowej.
 *
 * Przechowuje wartosc (data) oraz wskazniki na nastepny (next)
 * i poprzedni (prev) element listy.
 * W 'struct' wszystko jest domyslnie publiczne.
 */
struct Node {
    int data;     ///< Dane (typu int) przechowywane w wezle.
    Node* next;   ///< Wskaznik na nastepny wezel (lub `nullptr`, jesli to ogon).
    Node* prev;   ///< Wskaznik na poprzedni wezel (lub `nullptr`, jesli to glowa).

    /**
     * @brief Konstruktor wezla.
     *
     * Inicjalizuje wezel podana wartoscia (val).
     * Wskazniki `next` i `prev` sa domyslnie ustawiane na `nullptr`.
     * Uzywamy "listy inicjalizacyjnej" (po dwukropku).
     *
     * @param val Wartosc (typu int) do przechowania w wezle.
     */
    Node(int val) : data(val), next(nullptr), prev(nullptr) {

        // "nullptr" to specjalna wartosc oznaczajaca "wskaznik donikad".
        // Nowy wezel domyslnie nie jest polaczony z innymi.
    }
};