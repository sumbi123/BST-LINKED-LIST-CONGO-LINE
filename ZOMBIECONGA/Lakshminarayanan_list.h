/*
Author: Subash Lakshminarayanan
Date: 11/26/22
Description: this will be the header file that defines the methods of Node, LinkedList, zombie and conga classes.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class Node{
protected:
  T data;

public:
  Node* next;
  Node* prev;

public:
  Node(T listData); // constructor
  T getData(); // getter
  void setData(T listData); // setter
  void setNext(Node* listNext); // setter     
  void setPrev(Node* listPrev); // setter     
};

template <class T>
class LinkedList{
protected:
  Node<T>* head;
  Node<T>* tail;

public:
  LinkedList(); // this is the constructor
  ~LinkedList(); // this if the destructor
  void printList(); // this prints the list of zombies
  int length(); // this returns the length of the list
  void empty(); // this removes the items in the list
  void addToFront(T listData); // this adds a zombie to the front of the line
  void addToEnd(T listData); // this adds a zombies to the end of the line
  bool addAtIndex(T listData, int index); // this adds the zombie to the given index
  void addBefore(Node<T>*, T listData); // this adds the zombie before the node
  void addAfter(Node<T>*, T listData); // this adds zombie after the node
  T removeFromFront(); // this removes the zombie from the front of the list and returns its value
  T removeFromEnd(); // this removes the zombie from the end of the list and returns its value
  void removeTheFirst(T listData); // this removes the first matching zombie
  void removeAllOf(T listData); // this removes all matching zombies
  T remove(Node<T>*); // this is the method to remove the node given and return the value of that zombie
  T removeBefore(Node<T>*); // this removes the previous node and returns the value of that zombie
  T removeAfter(Node<T>*); // this removes the next node and returns the value of that zombie
  bool elementExists(T listData); // this finds if the given zombie exists in the list
  Node<T>* find(T listData); // returns the pointer to whichever node the zombie is at
  int indexOf(T listData); // this returns the index of the zombie
  T retrieveFront(); //this returns the zombi in the first node
  T retrieveEnd(); // this returns the zombie in last node
  T retrieve(int index); // this returns data at the given index of the node
};

class Zombie{
protected:
  char color; // characters represent the color of the zombies

public:
  Zombie(); // default constructor
  Zombie(char zombieColor); // secondory constructor
  static void engine(LinkedList<Zombie>* list, Zombie zom); // this zombie turns into the first zombie
  static void caboose(LinkedList<Zombie>* list, Zombie zom); // this zombie turns into the last zombie
  static void jumpInTheLine(LinkedList<Zombie>* list, Zombie zom); //this zombie gets added to the list randomly
  static void everyoneOut(LinkedList<Zombie>* list, Zombie zom); // all similar zombies are removed
  static void youAreDone(LinkedList<Zombie>* list, Zombie zom); //the first similar zombie is removed
  static void brains(LinkedList<Zombie>* list, Zombie zom); // a similar zombie is added to the front, middle, and end of the list
  static void rainbowBrains(LinkedList<Zombie>* list, Zombie zom); // this zombie is added to the front of the list and a zombie of each color is added to the end of the list
  static void makingNewFriends(LinkedList<Zombie>* list, Zombie zom); // finds the first similar zombie and adds a zombie before or after that zombie
  static void unstableZombie(LinkedList<Zombie>* list, Zombie zom); // removes the first zombie of this color and adds a zombie for each color
  static void everyFive(LinkedList<Zombie>* list); // this removes the head and tail zombies in the list
  char getColor(); // returns the character representing each zombie
  friend ostream& operator<<(ostream& out, Zombie zom); // overloads the cout operator
  friend bool operator==(Zombie zom1, Zombie zom2); // overloads the == operator
};

class Conga{
  friend class Zombie; 

public:
  void congaLine(); // this will run the conga line sim
};
