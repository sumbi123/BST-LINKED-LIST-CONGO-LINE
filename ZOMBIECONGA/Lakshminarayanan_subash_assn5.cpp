/*
Author: Subash Lakshminaryanan
Date: 11/26/22
Description: this file implements the code contained in Lakshminaryanan_list.h
*/

#include <iostream>
#include <stdlib.h>
#include <random>
#include "Lakshminarayanan_list.h"
using namespace std;

template <class T>
void LinkedList<T>::printList(){

  Node<T>* node = head;
  while(node != NULL){ // outputting the contents of list by looping through each node
    cout << node->getData() << ' ';
    node = node->next;
  }
  cout << endl;
}

template <class T>
int LinkedList<T>::length(){

  int cnt = 0;
  if(head == NULL && tail == NULL){
    return cnt;
  }
  
  Node<T>* node = head;
  while(node != NULL){ // counts the number of items in the list by looping through each node
    cnt++;
    node = node->next;
  }
  return cnt;
}

template <class T>
void LinkedList<T>::empty(){

  if(head == NULL && tail == NULL){
    // if nothing is in the list
  }
  else{
    Node<T>* node = head;
    head = NULL;
    while(node != NULL){
      node->next = NULL;
      free(node);
      node = node->next;
    }
  }
}

template <class T>
Node<T>::Node(T lData){

  data = lData;
  next = NULL;
  prev = NULL;
}

template <class T>
T Node<T>::getData(){

  return data;
}

template <class T>
void Node<T>::setData(T lData){

  data = lData;
}

template <class T>
void Node<T>::setNext(Node* lNext){

  next = lNext;
}

template <class T>
void Node<T>::setPrev(Node* lPrev){

  prev = lPrev;
}

template <class T>
LinkedList<T>::LinkedList(){

  head = NULL;
  tail = NULL;
}

template <class T>
void LinkedList<T>::addToFront(T lData){

  if(head == NULL && tail == NULL){
    Node<T>* node = new Node<T>(lData);
    head = node;
    tail = node;
  }
  else{
    Node<T>* node = new Node<T>(lData);
    node->setNext(head);
    head = node;
  }
}

template <class T>
void LinkedList<T>::addToEnd(T lData){

  if(head == NULL && tail == NULL){
    Node<T>* node = new Node<T>(lData);
    head = node;
    tail = node;
  }
  else{
    Node<T>* node = new Node<T>(lData);
    tail->setNext(node);
    tail = node;
  }
}

template <class T>
bool LinkedList<T>::addAtIndex(T lData, int ind){

  bool success = true;
  
  if(head == NULL && tail == NULL){
    addToFront(lData);
    return success;
  }
  
  Node<T>* indexNode = new Node<T>(lData);
  if(ind == 0){
    addToFront(lData);
    return success;
  }
  else if(ind == length() - 1){
    addToEnd(lData);
    return success;
  }

  Node<T>* node = head;
  int curr = 0;
  while(curr < ind - 1){ // until tracker reaches the index the loop continues
    node = node->next;
    curr++;
  }
  indexNode->next = node->next;
  node->next = indexNode;
 
  return success;
}


template<class T>
void LinkedList<T>::addBefore(Node<T>* n, T lData){

  
}

template<class T>
void LinkedList<T>::addAfter(Node<T>* n, T lData){
  
}

template<class T>
T LinkedList<T>::removeFromFront(){
  T value = head->getData();
  Node<T>* node = head;
  head = head->next;
  free(node);
  return value;
}

template<class T>
T LinkedList<T>::removeFromEnd(){

  T value = tail->getData();
  Node<T>* node = head;
  while(node != NULL){
    if(node->next->next == NULL){
      Node<T>* end = tail;
      node->next = NULL;
      free(end);
      break;
    }
    else {
      node = node->next;
    }
  }
  return value;
}

template<class T>
void LinkedList<T>::removeTheFirst(T lData){

  Node<T>* node = head;
  bool deleted = false;
  if(node->next == NULL){
    head = NULL;
  }

  while(!deleted && (node->next != NULL)){
    if(node->next->getData() == lData){
      Node<T>* node2 = node->next;
      node->next = node->next->next;
      free(node2);
      deleted = true;
      break;
    }
    else{
      node = node->next;
    } 
  }
}

template<class T>
void LinkedList<T>::removeAllOf(T lData){

  Node<T>* node = head;
  if(node->next == NULL) {
    head = NULL;
  }
  while(node->next != NULL){
    if(node->next->getData() == lData){
      Node<T>* node2 = node->next;
      node->next = node->next->next;
      free(node2);
    } 
    else{
      node = node->next;
    }
  }
}


template <class T>
T LinkedList<T>::remove(Node<T>* n){

  if(n == NULL){
    return;
  }
  if(n->next != NULL){
    n->next->prev = n->prev;
  }
  if(n->prev != NULL){
    n->prev->next = n->next;
  }
  if(head == n){
    head = n->next;
  }
  if(tail == n){
    tail = n->prev;
  }
}

template <class T>
T LinkedList<T>::removeBefore(Node<T>* n){

  remove(n->prev);
  return n->prev;
}

template <class T>
T LinkedList<T>::removeAfter(Node<T>* n){

  remove(n->next);
  return n->next;
}

template <class T>
bool LinkedList<T>::elementExists(T lData){

  bool exists = false;
  Node<T>* node = head;
  while(node != NULL)
  {
    if(node->getData() == lData)
    {
      exists = true;
    }
    node = node->next;
  }
  return exists;
}

template <class T>
Node<T>* LinkedList<T>::find(T lData){

  Node<T>* temp = new Node<T>();
  temp = head;

  while(temp != NULL)
  {
    if(temp->value == lData)
    {
      return temp;
    }
    temp = temp->next;
  }
  return NULL;
}

template <class T>
int LinkedList<T>::indexOf(T lData){

  int curr = 0;
  if(head == NULL && tail == NULL){
    return curr;
  }

  Node<T>* node = head;
  bool cont = true;
  while(cont || (node != NULL)){
    if(lData == node->getData()){
      cont = false;
      break;
    }
    else{
      curr++;
      node = node->next;
    }
  }
  return curr;
}

template<class T>
T LinkedList<T>::retrieveFront(){

  return head->getData();
}

template<class T>
T LinkedList<T>::retrieveEnd(){

  return tail->getData();
}

template<class T>
T LinkedList<T>::retrieve(int ind){  

  int cnter = 0;
  Node<T>* node = head;
  while(node != NULL) {
    if(cnter == ind){
      return node->getData();
    }
    else {
      cnter++;
      node = node->next;
    }
  }
  return cnter;
}

Zombie::Zombie(){// generates a random color for initial zombie

  int ran;
  random_device rand;
  mt19937 gen(rand());
  uniform_int_distribution<> rate(1, 5);
  ran = rate(gen);

  color = 'A';
  if(ran == 1){
    color = 'R';
  }
  else if(ran == 2){
    color = 'Y';
  }
  else if(ran == 3){
    color = 'G';
  }
  else if(ran == 4){
    color = 'B';
  }
  else if(ran == 5){
    color = 'M';
  }
  else{
    color = 'C';
  }
}

Zombie::Zombie(char zomCol){
  color = zomCol;
}

char Zombie::getColor(){
  return color;
}

void Zombie::engine(LinkedList<Zombie>* list, Zombie zom){
  list->addToFront(zom);
}

void Zombie::caboose(LinkedList<Zombie>* list, Zombie zom){
  list->addToEnd(zom);
}

void Zombie::jumpInTheLine(LinkedList<Zombie>* list, Zombie zom){
  int length = list->length();
  int ran;
  random_device rand;
  mt19937 gen(rand());
  uniform_int_distribution<> rate(0, length - 1);
  ran = rate(gen);
  list->addAtIndex(zom, ran);
}

void Zombie::everyoneOut(LinkedList<Zombie>* list, Zombie zom){
  list->removeAllOf(zom);
}

void Zombie::youAreDone(LinkedList<Zombie>* list, Zombie zom){
  list->removeTheFirst(zom);
}

void Zombie::brains(LinkedList<Zombie>* list, Zombie zom){
  int center = (list->length())/2;
  Zombie zomFront(zom.getColor());
  Zombie zomCenter(zom.getColor());
  Zombie zomEnd(zom.getColor());
  list->addToFront(zomFront);
  list->addAtIndex(zomCenter, center);
  list->addToEnd(zomEnd);
}

void Zombie::rainbowBrains(LinkedList<Zombie>* list, Zombie zom){
  list->addToFront(zom);
  Zombie zomR('R');
  Zombie zomY('Y');
  Zombie zomG('G');
  Zombie zomB('B');
  Zombie zomM('M');
  Zombie zomC('C');
  list->addToEnd(zomR);
  list->addToEnd(zomY);
  list->addToEnd(zomG);
  list->addToEnd(zomB);
  list->addToEnd(zomM);
  list->addToEnd(zomC);
}

void Zombie::everyFive(LinkedList<Zombie>* list){
  list->removeFromFront();
  list->removeFromEnd();
}

ostream& operator<<(ostream& out, Zombie zom){   //this formats the zombie colors with brackets around them

  out << '[';
  out << zom.getColor();
  out << ']';
  return out;
}

bool operator==(Zombie zom1, Zombie zom2){
  return zom1.getColor() == zom2.getColor();
}

int chooseRandomNumber(){
  int ran;
  random_device rand;
  mt19937 gen(rand());
  uniform_int_distribution<> rate(2, 5); // this is to choose the number of rounds to be randomly generated
  ran = rate(gen);
  return ran;
}

int chooseAction(){
  int ran;
  random_device rand;
  mt19937 gen(rand());
  uniform_int_distribution<> rate(1, 7); // this randomly chooses one of the seven methods that can be performed during the rounds
  ran = rate(gen);
  return ran;
}

int chooseZombie(int max){
  int ran;
  random_device rand;
  mt19937 gen(rand());
  uniform_int_distribution<> rate(0, max - 1);
  ran = rate(gen);
  return ran;
}

void Conga::congaLine(){
  LinkedList<Zombie>* list = new LinkedList<Zombie>();
  
  Zombie start;
  Zombie::rainbowBrains(list, start);
  list->printList();
  
  int ran = chooseRandomNumber();
  for(int i = 0; i < ran; i++){
    Zombie brain;
    Zombie::brains(list, brain);
  }
  list->printList();

  bool run = true;
  int rounds;
  bool party = true;
  int cnt = 0;

  cout << "Welcome to Zombie Congo Line!" << endl;

  while(run){
    cout << "How many rounds do you want to run?: ";
    cin >> rounds;
    cout << endl;
    
    for(int i = 0; i < rounds; i++){
      //does a different group of actions if the number can be divisbile by 5
      if((cnt != 0) && (cnt%5 == 0)){
	cout << "Round: " + to_string(cnt) << endl;
        cnt++;
        cout << "The Zombie Party keeps on groaning!" << endl;
        cout << "Size: " + to_string(list->length()) << endl;
        list->printList();
	Zombie::everyFive(list);
	cout << "The first and last zombie have been removed" << endl;
      }
      else{
	cout << "Round: " + to_string(cnt) << endl;
	cnt++;
	cout << "The Zombie Party keeps on groaning!" << endl;
	cout << "Size: " + to_string(list->length()) << endl;
	list->printList();
	
	// generates random messages for the appropriate command
	int command = chooseAction();
	int zomIndex = chooseZombie(list->length());
	if(command == 1){
	  Zombie z = list->retrieve(zomIndex);
	  Zombie::engine(list, list->retrieve(zomIndex));
	  cout << z;
	  cout << " zombie jumps in front of the line! (ENGINE!)" << endl;
	}
	else if (command == 2){
	  Zombie z = list->retrieve(zomIndex);
	  Zombie::caboose(list, list->retrieve(zomIndex));
	  cout << z;
	  cout << " zombie pulls up the rear! (CABOOSE!)" << endl;
	}
	else if (command == 3){
	  Zombie z = list->retrieve(zomIndex);
	  Zombie::jumpInTheLine(list, list->retrieve(zomIndex));
	  cout << z;
	  cout << " zombie jumps into the line! (JUMP IN THE LINE!)" << endl;
	}
	else if (command == 4){
	  Zombie z = list->retrieve(zomIndex);
	  Zombie::everyoneOut(list, list->retrieve(zomIndex));
	  cout << z;
	  cout << " zombie and all of his friends are kicked out of the party! (EVERYONE OUT!)" << endl;
	}
	else if (command == 5){
	  Zombie z = list->retrieve(zomIndex);
	  Zombie::youAreDone(list, list->retrieve(zomIndex));
	  cout << z;
	  cout << " zombie's friend is kicked out of the party! (YOU'RE DONE!)" << endl;
	}
	else if (command == 6){
	  Zombie z = list->retrieve(zomIndex);
	  Zombie::brains(list, list->retrieve(zomIndex));
	  cout << z;
	  cout << " zombie brings its friends to the party! (BRAINS!)" << endl;
	}
	else if (command == 7){
	  Zombie z = list->retrieve(zomIndex);
	  Zombie::rainbowBrains(list, list->retrieve(zomIndex));
	  cout << z;
	  cout << " zombie brought a whole party itself! (RAINBOW BRAINS!)" << endl;
	}
	
      }
      if(list->length() == 0){
	cout << "The zombie conga line party is over!" << endl;
	party = false;
	break;
      }
      cout << "The conga line is now:" << endl;
      cout << "Size: " + to_string(list->length()) + " :: ";
      list->printList();      
      cout << "***************************" << endl;
      cout << endl;
    }
    
    // the loop ends if the party ends
    if(!party){
      break;
    }

    int yesParty = 0;
    cout << "Would you like to continue the party? Enter 1 if yes, and any other number if no: ";
    cin >> yesParty;
    if (yesParty == 1){
      // keeps the loop going
    }
    else{
      cout << "Okay! The zombie conga line party is now over!" << endl;
      run = false;
    } 
  }
}
