/**
 * @file DoublyLinkedList.cpp
 * @brief Implementacja metod dla klasy DoublyLinkedList.
 *
 * Ten plik zawiera definicje metod zadeklarowanych w `DoublyLinkedList.h`.
 */

#include "DoublyLinkedList.h"
#include <iostream>    // Potrzebne do wyswietlania (std::cout)
#include <stdexcept>   // Potrzebne do rzucania wyjatkow (bledow)

 /**
  * @brief Konstruktor domyslny.
  * Tworzy nowa, pusta liste. Ustawia head/tail na nullptr i count na 0.
  */
DoublyLinkedList::DoublyLinkedList() {
    head = nullptr; // Na starcie pusta lista nie ma glowy
    tail = nullptr; // Ani ogona
    count = 0;      // Licznik jest 0
}

/**
 * @brief Destruktor.
 * Zwalnia cala pamiec (wywoluje clear()).
 */
DoublyLinkedList::~DoublyLinkedList() {
    clear(); // Sprzata pamiec
}

/**
 * @brief Zwraca iterator na poczatek listy.
 * @return Iterator wskazujacy na 'head'.
 */
Iterator DoublyLinkedList::begin() {
    return Iterator(head); // Iterator zaczyna od glowy
}

/**
 * @brief Zwraca iterator "za koncem" listy (nullptr).
 * Uzywany do oznaczania konca w petlach.
 * @return Iterator wskazujacy na `nullptr`.
 */
Iterator DoublyLinkedList::end() {
    return Iterator(nullptr); // Iterator konczy na nullptr
}

/**
 * @brief Sprawdza, czy lista jest pusta.
 * @return `true` jesli 'count == 0', `false` w przeciwnym razie.
 */
bool DoublyLinkedList::isEmpty() {
    return count == 0; // Lista jest pusta, jesli licznik jest 0
}

/**
 * @brief Dodaje element na poczatek listy (przed 'head').
 * @param data Wartosc do dodania.
 */
void DoublyLinkedList::addFront(int data) {
    Node* newNode = new Node(data); // Stworz nowy wezel
    if (isEmpty()) {
        head = tail = newNode; // Jest to jedyny element
    }
    else {
        newNode->next = head; // Nowy wezel wskazuje na stara glowe
        head->prev = newNode; // Stara glowa wskazuje wstecz na nowy wezel
        head = newNode;       // Nowy wezel staje sie glowa
    }
    count++; // Zwieksz licznik
}

/**
 * @brief Dodaje element na koniec listy (za 'tail').
 * @param data Wartosc do dodania.
 */
void DoublyLinkedList::addBack(int data) {
    Node* newNode = new Node(data); // Stworz nowy wezel
    if (isEmpty()) {
        head = tail = newNode; // Jest to jedyny element
    }
    else {
        tail->next = newNode;    // Stary ogon wskazuje na nowy wezel
        newNode->prev = tail;    // Nowy wezel wskazuje wstecz na stary ogon
        tail = newNode;          // Nowy wezel staje sie ogonem
    }
    count++; // Zwieksz licznik
}

/**
 * @brief Usuwa element z poczatku listy ('head').
 * @throws std::runtime_error Jesli lista jest pusta.
 */
void DoublyLinkedList::removeFront() {
    if (isEmpty()) {
        throw std::runtime_error("Blad: Proba usuniecia z pustej listy!");
    }
    Node* nodeToDelete = head; // Zapamietaj stara glowe
    if (count == 1) {
        head = tail = nullptr; // Lista staje sie pusta
    }
    else {
        head = head->next;     // Drugi element staje sie glowa
        head->prev = nullptr;  // Nowa glowa nie ma nic przed soba
    }
    delete nodeToDelete; // Usun stara glowe
    count--; // Zmniejsz licznik
}

/**
 * @brief Usuwa element z konca listy ('tail').
 * @throws std::runtime_error Jesli lista jest pusta.
 */
void DoublyLinkedList::removeBack() {
    if (isEmpty()) {
        throw std::runtime_error("Blad: Proba usuniecia z pustej listy!");
    }
    Node* nodeToDelete = tail; // Zapamietaj stary ogon
    if (count == 1) {
        head = tail = nullptr; // Lista staje sie pusta
    }
    else {
        tail = tail->prev;     // Przedostatni element staje sie ogonem
        tail->next = nullptr;  // Nowy ogon nie ma nic po sobie
    }
    delete nodeToDelete; // Usun stary ogon
    count--; // Zmniejsz licznik
}

/**
 * @brief Usuwa wszystkie elementy z listy.
 * Zwalnia pamiec i resetuje liste do stanu pustego.
 */
void DoublyLinkedList::clear() {
    // Usuwaj pierwszy element, dopoki lista nie bedzie pusta
    while (!isEmpty()) {
        removeFront();
    }
}

/**
 * @brief Zwraca liczbe elementow na liscie.
 * @return Aktualna liczba elementow (int).
 */
int DoublyLinkedList::getSize() {
    return count;
}

/**
 * @brief Wyswietla liste od poczatku do konca (Head -> Tail).
 * Wypisuje elementy na konsole.
 */
void DoublyLinkedList::display() {
    std::cout << "Lista (Head -> Tail): ";
    Node* current = head; // Zacznij od glowy
    while (current != nullptr) { // Idz do przodu, az dojdziesz do konca
        std::cout << current->data << " <-> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

/**
 * @brief Wyswietla liste od konca do poczatku (Tail -> Head).
 * Wypisuje elementy na konsole.
 */
void DoublyLinkedList::displayReverse() {
    std::cout << "Lista (Tail -> Head): ";
    Node* current = tail; // Zacznij od ogona
    while (current != nullptr) { // Idz do tylu, az dojdziesz do poczatku
        std::cout << current->data << " <-> ";
        current = current->prev;
    }
    std::cout << "NULL" << std::endl;
}

/**
 * @brief Prywatna metoda pomocnicza do pobierania wezla o zadanym indeksie.
 * Optymalizacja: szuka od 'head' lub 'tail' (co blizej).
 * @param index Indeks (0-based) wezla.
 * @return Wskaznik (Node*) do wezla lub `nullptr` (zly indeks).
 */
Node* DoublyLinkedList::getNode(int index) {
    if (index < 0 || index >= count) {
        return nullptr; // Zly indeks
    }
    // Optymalizacja: Szukaj od poczatku lub od konca
    if (index < count / 2) {
        // Blizej od glowy
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current;
    }
    else {
        // Blizej od ogona
        Node* current = tail;
        for (int i = count - 1; i > index; --i) {
            current = current->prev;
        }
        return current;
    }
}

/**
 * @brief Dodaje element pod wskazany indeks.
 * @param data Wartosc (int) do wstawienia.
 * @param index Indeks (0-based), [0, count].
 * @throws std::out_of_range Jesli indeks jest poza zakresem [0, count].
 */
void DoublyLinkedList::addAt(int data, int index) {
    if (index < 0 || index > count) {
        throw std::out_of_range("Blad: Nieprawidlowy indeks dla addAt.");
    }
    // Uzyj istniejacych metod dla krancow
    if (index == 0) {
        addFront(data);
        return;
    }
    if (index == count) {
        addBack(data);
        return;
    }
    // Dodawanie w srodku
    Node* prevNode = getNode(index - 1); // Wezel "przed" miejscem wstawienia
    Node* nextNode = prevNode->next;
    Node* newNode = new Node(data);

    // Przepinanie wskaznikow
    newNode->prev = prevNode;
    newNode->next = nextNode;
    prevNode->next = newNode;
    nextNode->prev = newNode;

    count++;
}

/**
 * @brief Usuwa element o wskazanym indeksie.
 * @param index Indeks (0-based) elementu do usuniecia, [0, count-1].
 * @throws std::out_of_range Jesli indeks jest poza zakresem [0, count-1].
 */
void DoublyLinkedList::removeAt(int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Blad: Nieprawidlowy indeks dla removeAt.");
    }
    // Uzyj istniejacych metod dla krancow
    if (index == 0) {
        removeFront();
        return;
    }
    if (index == count - 1) {
        removeBack();
        return;
    }
    // Usuwanie ze srodka
    Node* nodeToRemove = getNode(index);
    Node* prevNode = nodeToRemove->prev;
    Node* nextNode = nodeToRemove->next;

    // "Omin" usuwany wezel
    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete nodeToRemove; // Usun wezel z pamieci
    count--;
}