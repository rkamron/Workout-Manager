//Name: Workout.cpp
//Project: CMSC 202 Project 3, Fall 2023 
//Author: Kamronbek Rakhimov
//Date: 10/31/23
//Section: 20/24
//Desc: This file contains the function definitions for a workout

#include "Workout.h"

//Default constructor for Workout
Workout::Workout() {
  m_name = "Default";
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

//Overloaded constructor for Workout
Workout::Workout(string name) {
  m_name = name;
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

//Workout destructor
//Loops through all the nodes of Workout, and deallocate the memory.
Workout::~Workout() {
  Exercise *curr = m_head;
  while (curr != nullptr) {
    m_head = curr;
    curr = curr->GetNext();
    delete m_head;
  }
  m_head = nullptr;
  m_tail = nullptr;
  m_size = 0;
}

void Workout::InsertEnd(Exercise *newExercise){
  if (m_size == 0) {
    m_head = newExercise;
    m_tail = newExercise;
  } else {
    m_tail->SetNext(newExercise);
    m_tail = m_tail->GetNext();
  }
  m_size++;
}

string Workout::GetName() {
  return m_name;
}

int Workout::GetSize() {
  return m_size;
}

void Workout::ReverseWorkout() {
  if (m_size == 0) {
    cout << "The list is empty" << endl;
  } else {
    Exercise *prev = nullptr;
    Exercise *curr = m_head;
    Exercise *next = nullptr;

    while (curr != nullptr) {
      next = curr->GetNext();
      curr->SetNext(prev);
      prev = curr;
      curr = next;
    }
    m_tail = m_head;
    m_head = prev;
    
  }
}

Exercise * Workout::GetData(int nodeNum) {
  Exercise *temp = m_head;
  int counter = 0;
  while (counter != nodeNum) {
    temp = temp->GetNext();
    counter++;
  }
  
  return temp;
}

ostream &operator<< (ostream &output, Workout &myWorkout) {
  Exercise *temp = myWorkout.m_head;

  if(myWorkout.m_size == 0) {
    cout << "The Workout is empty." << endl;
  } else {
    for (int i = 0; i < myWorkout.GetSize(); i++) {
      output << *temp  << endl;
      temp = temp->GetNext();
    }
  }
  return output;
  
}
