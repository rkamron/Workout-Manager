#include "Manager.h"

//Overloaded Constructor for Manager.
Manager::Manager(string filename) {
    m_fileName = filename;
    MainMenu(); //Begins running the program.
}

//Manager Destructor
Manager::~Manager() {
    //Iterates through m_workouts and deletes every pointer then assigns it to nullptr.
    for (unsigned int i = 0; i < m_workouts.size(); i++) {
    delete m_workouts.at(i);
    m_workouts.at(i) = nullptr;
    }
}

//DisplayWorkouts
//Loops through m_workouts and outputs each Workout using the overloaded operator.
void Manager::DisplayWorkouts() {
  //Loop to iterate through m_workouts.
  for (unsigned int i = 0; i < m_workouts.size(); i++) {
    cout << endl
	 << "******************" << endl
	 << "Workout for " << m_workouts.at(i)->GetName() << endl
	 << m_workouts.at(i)->GetSize() << " exercises" << endl;
    
    cout << *m_workouts.at(i) << endl; //Using Overloaded operator << from Workouts.cpp to print every workout.
  }
}

//ReadFile
//Reads m_filename line by line and makes Workout linked lists and adds the appropriate Exercise nodes to them.
void Manager::ReadFile() {
  //Reading file m_fileName.
  ifstream workoutFile (m_fileName);
  if (workoutFile.is_open()) {
    string workoutName, category, exerciseName, inReps, inWeight; //Strings that are assigned to each element from each line of the file.
    int numWorkouts = 0; //Counts the number of Workouts that are in m_fileName.
    int numExercises = 0; //Counts the number of Exerciess in m_fileName.

    //While loop to read each line until it hits the delimeter ';'.
    while (getline(workoutFile, workoutName, ';') and
	   getline(workoutFile, category, ';') and
	   getline(workoutFile, exerciseName, ';') and
	   getline(workoutFile, inReps, ';') and
	   getline(workoutFile, inWeight)) {

      //Integers reps and weight convert in_reps and in_weight 
      int reps = stoi(inReps);
      int weight = stoi(inWeight);

      //Conditionals to check if workoutName already exists as a Workout in m_workouts.
      //If workoutName doesn't exist then it makes a new Workout and puts the following Exercise into it.
      //Else adds the Exercise into the Workout that already exists.
      if (FindWorkout(workoutName) == -1) {
	Workout *workoutPtr = new Workout(workoutName);
	Exercise *exercisePtr = new Exercise(category, exerciseName, reps, weight);
	workoutPtr->InsertEnd(exercisePtr);
	m_workouts.push_back(workoutPtr); //Adds the workout to m_workouts vector.
	numWorkouts++; //Adds to the counter of workouts.
	numExercises++; //Adds to the counter of exercises.
      } else {
	Exercise *exercisePtr = new Exercise(category, exerciseName, reps, weight); 
	m_workouts.at(FindWorkout(workoutName))->InsertEnd(exercisePtr); //Inserts the Exercise read into the Workout that already exists.
	numExercises++;
      }
    }
    cout << "Opened File" << endl;
    cout << numExercises << " exercises loaded across " << numWorkouts << " workouts." << endl;
  } else {
    cout << "Unable to open " << m_fileName << endl;
  }
  workoutFile.close();
}

//InsertNewExercise
//Inputs information from the user about the new exercise, then makes the new exercise, and adds it to asked Workout.
void Manager::InsertNewExercise() {
  string workoutName, category, exerciseName; //Strings that will be filled with user input.
  int reps = -1; //Integers that will hold reps and weight inputted.
  int weight = -1; //Set to -1 for user input verification.
  
  cout << "What is the name of the workout you would like to insert into?" << endl;
  cin >> workoutName;
  cout << "What is the category of the exercise?" << endl;
  cin >> category;
  cout << "What is the name of the exercise?" << endl;
  cin >> exerciseName;

  //Loops to check user input for reps and weight.
  while (reps < 0) {
    cout << "How many reps did you do?" << endl;
    cin >> reps;
  }
  while (weight < 0) {
    cout << "How much weight did you use? (in lbs.)" << endl;
    cin >> weight;
  }

  //Checks if the workoutName is in m_workouts
  //If the workoutName does not exist then it makes a new Workout.
  //Else it will add the new Exercise into the workoutName.
  if (FindWorkout(workoutName) == -1) {
    Workout *workoutPtr = new Workout(workoutName);
    Exercise *exercisePtr = new Exercise(category, exerciseName, reps, weight);
    workoutPtr->InsertEnd(exercisePtr);
    m_workouts.push_back(workoutPtr);
  } else {
    Exercise *exercisePtr = new Exercise(category, exerciseName, reps, weight);
    m_workouts.at(FindWorkout(workoutName))->InsertEnd(exercisePtr);
  }
}

//FindWorkout
//Iterates through m_workouts and checks if the name matches schedName.
int Manager::FindWorkout(string schedName) {
  int indexFound = -1; //Int to be returned, -1 if schedName doesnt match any Workout names.
  for (unsigned int i = 0; i < m_workouts.size(); i++) {
    if (m_workouts[i]->GetName() == schedName) {
      indexFound = i; //If it finds the right Workout, it returns its index in m_workouts
    }
  }
  return indexFound;
}

//MainMenu
//Reads the given file then runs the Main loop for the program.
void Manager::MainMenu() {
  ReadFile(); //Reads the file.
  int unsigned userOption = 0; //Stores user input.

  //Loop to print the main menu until the user enters in 4.
  while(userOption != 4) {
    cout << "What would you like to do?:" << endl
	 << "1. Display Workouts" << endl
	 << "2. Reverse Workouts" << endl
	 << "3. Insert New Exercise" << endl
	 << "4. Exit" << endl;
    cin >> userOption; //Stores the user input in UserOption.

    if (userOption == 1) {
      DisplayWorkouts();
    } else if (userOption == 2) {
      ReverseWorkout();
    } else if (userOption == 3)	{
      InsertNewExercise();
    } else if (userOption == 4)	{
      cout << "Workouts removed from memory" << endl;
      cout << "Deleting Workouts" << endl;
    }
  }
}

//ReverseWorkout
//Reverses a workout using Workout::ReverseWorkout().
void Manager::ReverseWorkout() {
  int userInput = 0;

  //Conditional if there is only one Workout in m_workouts, then it will automatically reverse the only Workout.
  //Else it will ask the user which workout they would like to reverse and it reverses that. 
  if (m_workouts.size() == 1) {
    m_workouts.at(0)->ReverseWorkout();
    cout << "Done reversing Workout 1" << endl;
  } else {
    cout << "Which workout to reverse?" << endl; 
    while (1 > userInput or (unsigned int)userInput > m_workouts.size()) {
      cout << "Choose 1 - " << m_workouts.size() << endl;
      cin >> userInput;
    }
    m_workouts.at(userInput - 1)->ReverseWorkout();
    cout << "Done reversing Workout " << userInput << endl;
  }
}
/*
void Manager::ExportWorkouts() {
  string newFileName;
  cout << "What would you like to name the new file?" << endl;
  cin >> newFileName;

  ofstream myFile;
  myFile.open(newFileName);

  for (unsigned int i = 0; i < m_workouts.size(); i++) {
    for (int j = 0; j < m_workouts.at(i)->GetSize(); j++) {
      myFile << m_workouts.at(i)->GetName() << ";"
	     << m_workouts.at(i)->GetData(j)->GetCategory() << ";"
	     << m_workouts.at(i)->GetData(j)->GetName() << ";"
	     << m_workouts.at(i)->GetData(j)->GetReps() << ";"
	     << m_workouts.at(i)->GetData(j)->GetWeight() << endl;
    }
  }
  myFile.close();
}

*/
