#include "Exercise.h"

//Exercise constructor
Exercise::Exercise() {
  SetCategory("");
  SetName("");
  SetReps(0);
  SetWeight(0);
  m_next = nullptr;
}

//Overloaded Exercise constructor.
//Uses the given paramenters to make a new Exercise object.
Exercise::Exercise(string category, string name, int reps, int weight) {
  SetCategory(category);
  SetName(name);
  SetReps(reps);
  SetWeight(weight);
  m_next = nullptr;
}

//GetCategory
//Getter method for m_category.
string Exercise::GetCategory(){
  return m_category;
}

//GetName
//Getter method for m_name.
string Exercise::GetName() {
  return m_name;
}

//GetReps
//Getter method for m_reps.
int Exercise::GetReps() {
  return m_reps;
}

//GetWeight
//Getter method for m_weight.
int Exercise::GetWeight() {
  return m_weight;
}

//GetNext
//Getter method for m_next.
Exercise* Exercise::GetNext() {
  return m_next;
}

//SetCategory
//Setter method for m_category.
void Exercise::SetCategory(string category) {
  m_category = category;
}

//SetName
//Setter method for m_name.
void Exercise::SetName(string name) {
  m_name = name;
}

//SetReps
//Setter method for m_reps.
void Exercise::SetReps(int reps) {
  m_reps = reps;
}

//SetWeight
//Setter method for m_weight.
void Exercise::SetWeight(int weight) {
  m_weight = weight;
}

//SetNext
//Setter method for m_next.
void Exercise::SetNext(Exercise *next) {
  m_next = next;
}
