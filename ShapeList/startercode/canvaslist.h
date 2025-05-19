//  @author Muhammad Hakim
//  @date CS 251, Spring 2023.
//  @brief Project 4 - Shape List, University of Illinois Chicago
//  @description CanvasList class that maintains a linked list of shapes to be drawn to the screen.
//  The shapes include Circle, RightTriangle, and Rectangle classes, which are derived from the base Shape class. 

#pragma once

#include "shape.h"
#include <iostream>
#include <iomanip> 


using namespace std;

class ShapeNode
{
    public:
        Shape *value;
        ShapeNode *next;
};

class CanvasList
{
    private:
        int listSize;
        ShapeNode *listFront;

    public:
        // Constructors and Assignment Operator
        CanvasList(); // Initializes an empty list
        CanvasList(const CanvasList&); // Copy constructor
        CanvasList operator=(const CanvasList&); // Assignment operator

        virtual ~CanvasList(); // Destructor

        // List Modification Functions
        void clear(); // Deletes all nodes in the list

        void insertAfter(int, Shape*); // Inserts a shape after a given position
        void push_front(Shape*); // Inserts a shape at the front of the list
        void push_back(Shape*); // Inserts a shape at the end of the list

        void removeAt(int); // Removes the shape at a given position
        Shape* pop_front(); // Removes and returns the shape at the front of the list
        Shape* pop_back(); // Removes and returns the shape at the end of the list

        // List Information Functions
        ShapeNode* front() const; // Returns a pointer to the front node
        bool isempty() const; // Returns true if the list is empty
        int size() const; // Returns the number of nodes in the list

        int find(int x, int y) const; // Returns the position of the shape at a given point
        Shape* shapeAt(int) const; // Returns the shape at a given position

        // Drawing Functions
        void draw() const; // Draws all the shapes in the list
        void printAddresses() const; // Prints the memory addresses of all the nodes in the list
};

// Default constructor
CanvasList::CanvasList() {
    listSize = 0;
    listFront = nullptr;
}

// Copy constructor
CanvasList::CanvasList(const CanvasList& other) {
    listSize = 0;
    listFront = nullptr;
    ShapeNode* curr = other.listFront;
    while (curr != nullptr) {
        push_back(curr->value->copy());
        curr = curr->next;
    }
}

// Copy assignment operator
CanvasList CanvasList::operator=(const CanvasList& other) {
    if (this != &other) {
        clear();
        ShapeNode *current = other.listFront;
        while (current != nullptr) {
            push_back(current->value->copy());
            current = current->next;
        }
    }
    return *this;
}

// Destructor
CanvasList::~CanvasList() {
    clear();
}

// Remove all elements in the list
void CanvasList::clear() {
    while (listFront) {
        ShapeNode* next = listFront->next;
        delete listFront->value;
        delete listFront;
        listFront = next;
    }
    listSize = 0;
}

// Insert a shape after the i-th element
void CanvasList::insertAfter(int i, Shape* shape) {
    if (i < 0 || i >= listSize) {
        return;
    }
    ShapeNode* curr = listFront;
    for (int j = 0; j < i; j++) {
        curr = curr->next;
    }
    ShapeNode* newNode = new ShapeNode();
    newNode->value = shape->copy();
    newNode->next = curr->next;
    curr->next = newNode;
    listSize++;
}

// Add a shape to the front of the list
void CanvasList::push_front(Shape* shape) {
    ShapeNode* newNode = new ShapeNode();
    newNode->value = shape->copy();
    newNode->next = listFront;
    listFront = newNode;
    listSize++;
}

// Add a shape to the back of the list
void CanvasList::push_back(Shape* shape) {
    ShapeNode* newNode = new ShapeNode();
    newNode->value = shape->copy();
    newNode->next = nullptr;
    if (listFront == nullptr) {
        listFront = newNode;
    }
    else {
        ShapeNode* curr = listFront;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    listSize++;
}

// Remove the i-th element from the list
void CanvasList::removeAt(int i) {
    if (i < 0 || i >= listSize) {
        return;
    }
    ShapeNode* curr = listFront;
    ShapeNode* prev = nullptr;
    for (int j = 0; j < i; j++) {
        prev = curr;
        curr = curr->next;
    }
    if (prev == nullptr) {
        if (curr == nullptr) {
            return;
        }
        listFront = curr->next;
    }
    else {
        if (curr == nullptr) {
            return;
        }
        prev->next = curr->next;
    }

    delete curr->value;
    delete curr;
    listSize--;
}

// Remove the first element from the list
Shape* CanvasList::pop_front() {
    if (listFront == nullptr) {
        return nullptr;
    }
    ShapeNode* node = listFront;
    listFront = listFront->next;
    Shape* result = node->value;
    delete node;
    listSize--;
    return result;
}

Shape* CanvasList::pop_back() {
    if (listFront == nullptr) {
        return nullptr;
    }
    if (listFront->next == nullptr) {
        Shape* result = listFront->value;
        delete listFront;
        listFront = nullptr;
        listSize--;
        return result;
    }
    ShapeNode* node = listFront;
    while (node->next->next != nullptr) {
        node = node->next;
    }
    Shape* result = node->next->value;
    delete node->next;
    node->next = nullptr;
    listSize--;
    return result;
}

ShapeNode* CanvasList::front() const {
    return listFront;
}

bool CanvasList::isempty() const {
    return listFront == nullptr;
}

int CanvasList::size() const {
    return listSize;
}

int CanvasList::find(int x, int y) const {
    int index = 0;
    ShapeNode* current = listFront;
    while (current != nullptr) {
        if (current->value->getX() == x && current->value->getY() == y) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}


Shape* CanvasList::shapeAt(int index) const {
    if (index < 0 || index >= listSize) {
        return nullptr;
    }
    ShapeNode* node = listFront;
    for (int i = 0; i < index; i++) {
        node = node->next;
    }
    return node->value;
}

void CanvasList::draw() const {
    ShapeNode* currNode = listFront;
    int index = 0;
    while (currNode != nullptr) {
        currNode->value->printShape();
        currNode = currNode->next;
    }
}


void CanvasList::printAddresses() const {
    ShapeNode* node = listFront;
    while (node != nullptr) {
        cout << "Node Address: " << hex << node << "\tShape Address: " << hex << node->value << endl;
        node = node->next;
    }
}


