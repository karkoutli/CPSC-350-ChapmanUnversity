#include <iostream>
#include <string>
//#include <fstream>
#include<limits>
#include "simulation.h"


using namespace std;

//Default constructor
simulation::simulation(){
  studentFile= "studentBST.txt";
  facultyFile= "facultyBST.txt";
  delimiter= "-";
  delimiter1=",";

}
//Destructor
simulation::~simulation(){

}
//write file function similiar to the print function in BST
//creates a pointer that points to the bst's root
// open the file to writ eto and
void simulation::writeFileFaculty1()
{

  TreeNode<Faculty>* root = masterFacultyBST.getRoot();

  ofstream writeFile1; //create file stream
  writeFile1.open(facultyFile.c_str()); //open up file
  writeFileFaculty(root, writeFile1);
}
void simulation::writeFileFaculty(TreeNode<Faculty>* root1, ofstream& writefile1) //pass in the root, and the file
{
  if(root1==NULL){ //similiar to printPreorder in BST, check if root is null first
    return;
  }

  //write each root's information onto the line in the following order
  writefile1 << root1->key.facultyID  <<"-" << root1->key.facultyName << "-" <<
  root1->key.facultyJob << "-" << root1->key.facultyDepartment << "-" << root1->key.listOfStudents.doublyToString() << endl;
  writeFileFaculty(root1->left, writefile1); //recursive from the left to print in preorder
  writeFileFaculty(root1->right,writefile1); //go to the right of the nod

}

void simulation::writeFileStudent1() //same thing as faculty write
{
  TreeNode<Student>* root = masterStudentBST.getRoot();
  ofstream writeFile2;
  writeFile2.open(studentFile.c_str());

writeFileStudent(root, writeFile2);

}
void simulation::writeFileStudent(TreeNode<Student>* root1, ofstream& writefile2) //same thing as faculty write (recursive)
{
  if(root1== NULL){

    return;
  }

  writefile2<< root1->key.studentID<< "-" <<  root1->key.studentName << "-" <<  root1->key.studentYear << "-"
  <<  root1->key.studentMajor << "-" <<  root1->key.studentGPA << "-" <<  root1->key.facultyID<< endl;
  writeFileStudent(root1->left, writefile2);
  writeFileStudent(root1->right,writefile2);
}

//read file
void simulation::readFile()
{

//create ifstreams for reading
  ifstream myFile(facultyFile); //faculty
  ifstream myFile1(studentFile); //student
  string line = " ";
  int startPos= 0;
  string extractedWord= " ";
  int idCounter=0;
  int positionCounter=0;


  //student

  int tempStudentID=0;
  string tempStudentName= " ";
  string tempStudentYear = " ";
  string tempStudentMajor = " ";
  double tempStudentGPA= 0;
  int tempFacultyID= 0;
  //if file does not exist, then create a new file
  if(!fileExist(studentFile))
  {
    ofstream out(studentFile); //create new student file


  }
  else //if it does exist then read it in
  {

    while(getline(myFile1, line))
    {
      startPos=0;
      extractedWord= " ";
      positionCounter=0;

      //assign parsed data into the respective variables
      while ((startPos = line.find(delimiter)) != -1){ //keep parsing the line based on the delimiter until it reaches -1 or the end of the line
          extractedWord = line.substr(0, startPos);
          //assign extracted data into the correct variables
        if(positionCounter==0)
        {
          tempStudentID= stoi(extractedWord);
        }
        else if(positionCounter==1)
        {
          tempStudentName = extractedWord;
        }
        else if(positionCounter==2)
        {
          tempStudentYear= extractedWord;
        }
        else if(positionCounter==3)
        {
        tempStudentMajor = extractedWord;
        }
        else if(positionCounter==4)
        {
        tempStudentGPA = stod(extractedWord); //stod to convert into a double
        }
        positionCounter++;
          line.erase(0, startPos + delimiter.length()); //erase required start the loop again
      }
      //convert faculty id into a int
      tempFacultyID= stoi(line);
      //create a new student and insert it into the student tree
      Student s(tempStudentID,tempStudentName,tempStudentYear,tempStudentMajor,tempStudentGPA,tempFacultyID);
      masterStudentBST.insert(s);

    }


  }

//reset for faculty
  startPos=0;
  extractedWord= " ";
  positionCounter=0;
  line= " ";

//faculty read

  int tempfacultyID1=0;
  string listofIds= " ";
  string tempfacultyName;
  string tempfacultyJob;
  string tempfacultyDepartment;



  //faculty
  if(!fileExist(facultyFile))
  {
    ofstream out(facultyFile); //create new faculty file

  }
  else //if it does exist then read it in
  {

    while(getline(myFile, line))
    {
      startPos=0;
      extractedWord= " ";
      positionCounter=0;

      while ((startPos = line.find(delimiter)) != -1){ //read line by line
          extractedWord = line.substr(0, startPos);
        if(positionCounter==0)
        {
          tempfacultyID1 = stoi(extractedWord);

        }
        else if(positionCounter==1)
        {
          tempfacultyName = extractedWord;

        }
        else if(positionCounter==2)
        {
          tempfacultyJob= extractedWord;

        }
        else if(positionCounter==3)
        {
        tempfacultyDepartment = extractedWord;

        }
        positionCounter++;
          line.erase(0, startPos + delimiter.length());
      }
        Faculty f(tempfacultyID1, tempfacultyName, tempfacultyJob, tempfacultyDepartment); //create a new faculty and insert into tree
        masterFacultyBST.insert(f);

      listofIds=line;

      while ((startPos = listofIds.find(delimiter1)) != -1) //loop through and read the list of students based ont he comma delimiter
      {

        extractedWord = listofIds.substr(0, startPos);
        int id= stoi(extractedWord);
        masterFacultyBST.find(tempfacultyID1)->key.listOfStudents.insertBack(id);
        listofIds.erase(0,startPos + delimiter1.length());
      }

    }



  }

}

//checks if file exists
bool simulation::fileExist(string file1) //check if the file exists method
{
  ifstream file(file1);
  if(file){
    return true;
  }
  return false;
}

void simulation::run()
{


  menu();

  //BST<int> s;

  //s.insert(5);

}




void simulation::menu()
{
  readFile();
  cout << "Welcome to the data base." << endl;
  cout << "-----------------------------------------------------------------" << endl;
  cout << "Main Menu" << endl;


  int userInput=0;;

  while (userInput != 16)
  {
    cout << "-----------------------------------------------------------------" << endl;
    cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id." << endl;
    cout << "4. Find and display faculty information given the faculty id." << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor." << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
    cout << "7. Add a new student." << endl;
    cout << "8. Delete a student given the id." << endl;
    cout << "9. Add a new faculty member." << endl;
    cout << "10. Delete a faculty member given the id." << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "12. Remove an advisee from a faculty member given the ids." << endl;
    cout << "13. Rollback." << endl;
    cout << "14. Change student name" << endl;
    cout << "15. Change faculty name" << endl;
    cout << "16. Exit." << endl;
    cout << "Please select one of the options by typing the respective number" << endl;
    cout << "----------------------------------------------------------------" << endl;
    //cin >> userInput;

    while(!(cin >> userInput)){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "[WARNING!] Please only type numbers to select an option: ";
    }

    //1. Print all students and their information (sorted by ascending id #)
    if(userInput == 1){
    printStudent();
    }
    //2 Prints all faculty in ascending order
    else if(userInput == 2){
    printFaculty();
    }
    //3 Find and display student information given the student id
    else if(userInput == 3){
        studentInfo();
    }
    //4 Find and display faculty information given the student id
    else if(userInput == 4){
    facultyInfo();
    //  studentInfo();

    }
    //5 Given a student's id, print the name and info of their faculty advisor
    else if(userInput == 5){
      studentFacultyInfo();


    }
    //6 Given a faculty id, print ALL the names and info of his/her advisees.
    else if(userInput == 6){
      facultyStudentID();
  }


    //7. Add a new student
    else if(userInput == 7){
        addStudent();

    }
    //8. Delete a student given the id
    else if(userInput == 8){
        deleteStudent();
    }
    //9. Add a new faculty member
    else if(userInput == 9){
      addFaculty();
    }
    //10. Delete a faculty member given the id.
    else if(userInput == 10){
      deleteFaculty();
    }
    //11. Change a student’s advisor given the student id and the new faculty id
    else if(userInput == 11){
      changeStudentAdvisor();


    }
    //12. Remove an advisee from a faculty member given the ids
    else if(userInput == 12){
      removeAdvisee();

    }

    //13. Rollback
    else if(userInput == 13){
      cout << "///////**ERROR-NAME**///////" << endl;
      cout << "***STEAK_AND_LOBSTERS_CANNOT_EXECUTE_COMMAND***" << endl;

    }
    //Change student name
    else if(userInput == 14){
      changeStudentName();

    }
    //Change faculty name
    else if(userInput == 15){
      changeFacultyName();
    }

    //15. Exit
    else if(userInput == 16){
      writeFileStudent1();
      writeFileFaculty1();
      break;
    }
    else{

      cout << "[WARNING!] You did not type one of the options. Please Try Again " << endl;
    }


  }
}


//-------------------------------------------------------------------------------
//FUNCTIONS
void simulation::printStudent(){
  if(!masterStudentBST.isEmpty()){
  //masterStudentBST.printPreorder();
  masterStudentBST.printTree();
}
else{
  cout << "Your tree is empty." << endl;
}
}

void simulation::printFaculty(){
  if(!masterFacultyBST.isEmpty()){
  //masterFacultyBST.printPreorder();
  masterFacultyBST.printTree();
}

}

void simulation::studentInfo(){
  int tempStudentID1= 0;
  cout << "Please enter the student id number." << endl;
  cin >> tempStudentID1;

  //Student s(tempStudentID1);

  if(masterStudentBST.contains(tempStudentID1) != true){
    //masterStudentBST.findData(s);
    cout << "Student does not exist. Please try again." << endl;
  }
  else{
    masterStudentBST.findData(tempStudentID1);
    //cout << "Student does not exist. Please try again." << endl;
  }
}

void simulation::facultyInfo(){
  int tempfacuID1= 0;
  cout << "Please enter the faculty's id number." << endl;
  cin >> tempfacuID1;

  //Student s(tempStudentID1);

  if(masterFacultyBST.contains(tempfacuID1) != true){
    //masterStudentBST.findData(s);
    cout << "Faculty does not exist. Please try again:" << endl;
  }
  else{
    cout << masterFacultyBST.find(tempfacuID1)->key << endl;
    //cout << "Student does not exist. Please try again." << endl;
  }
}


void simulation::addStudent(){
  int tempStudentID1 = 0;
  string tempStudentName1;
  string tempStudentYear1;
  string tempStudentMajor1;
  double tempStudentGPA1 = 0;
  int tempFacultyID1 = 0;
  while(true){
  cout << "What is your student id?" << endl; ;
  while(!(cin >> tempStudentID1)){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "You did not type in an integer. Please try again: ";
  }

  if(masterStudentBST.contains(tempStudentID1)==true){

    cout << "Student ID inputted already exists. Please Try Again: ";
  }
  else{

    break;
  }
}

  cout << "What is your student name?" << endl;
  cin >> tempStudentName1;
  cout << "What year is your student?" << endl;
  cin >> tempStudentYear1;
  cout << "What is your major?" << endl;
  cin >> tempStudentMajor1;
  cout << "What is the student GPA?" << endl;
  while(!(cin >> tempStudentGPA1)){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "You did not type in a double value. Please try again: ";
  }
  //cin >> tempStudentGPA1;
  int checker = 0;
  while (checker == 0){
    cout << "What is the faculty ID?" << endl;
    while(!(cin >> tempFacultyID1)){
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "You did not type in a double value. Please try again: " << endl;
    }
    //cin >> tempFacultyID1;
    Faculty f(tempFacultyID1);
    if(masterFacultyBST.contains(f) == true){
      checker = 1;

    }
    else{
      cout << "Faculty member does not exist. Please enter one that does." << endl;
    }
  }
    Student s(tempStudentID1,tempStudentName1,tempStudentYear1,tempStudentMajor1,tempStudentGPA1,tempFacultyID1);
    masterStudentBST.insert(s);
    masterFacultyBST.find(tempFacultyID1)->key.listOfStudents.insertBack(tempStudentID1);
    cout << "Student added to the Faculty list of advisees: " << " ";
    masterFacultyBST.find(tempFacultyID1)->key.listOfStudents.printList();

}

void simulation::deleteStudent(){
  int tempStudentID1= 0;
  cout << "Please enter the student id number of the student that you'd like to delete." << endl;
  cin >> tempStudentID1;

  int tempFacultyID= 0;



  Student s(tempStudentID1);



  if(masterStudentBST.contains(s) == true){
    tempFacultyID = masterStudentBST.find(tempStudentID1)->key.facultyID;
    masterFacultyBST.find(tempFacultyID)->key.listOfStudents.remove(tempStudentID1);


    masterStudentBST.deleteNode(s);


    cout << "Student has been deleted." << endl;
  }
  else {
    cout << "Student does not exist." << endl;
  }


}

void simulation::addFaculty(){
  int tempFacultyID1 = 0;
  string tempFacultyName1;
  string tempFacultyJob1;
  string tempFacultyDepartment1;

while(true){
cout << "What is your faculty id number?" << endl; ;
while(!(cin >> tempFacultyID1)){
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "You did not type in an integer. Please try again: ";
}

if(masterFacultyBST.contains(tempFacultyID1)==true){

  cout << "Faculty ID inputted already exists. Please Try Again: ";
}
else{

  break;
}
}

  cout << "Faculty name?" << endl;
  cin >> tempFacultyName1;
  cout << "What is the facultys job?" << endl;
  cin >> tempFacultyJob1;
  cout << "What department does your faculty work in?" << endl;
  cin >> tempFacultyDepartment1;
  Faculty f(tempFacultyID1, tempFacultyName1, tempFacultyJob1, tempFacultyDepartment1);
  masterFacultyBST.insert(f);


}

void simulation::deleteFaculty(){
  int tempFacultyID1= 0;
  cout << "Please enter the faculty id number of the faculty that you'd like to delete." << endl;
  cin >> tempFacultyID1;

  Faculty f(tempFacultyID1);
  if(masterFacultyBST.contains(f) == true){

  if(masterFacultyBST.find(tempFacultyID1)->key.listOfStudents.isEmpty())
  {
    masterFacultyBST.deleteNode(f);
    cout << "Faculty has been deleted." << endl;
  }
  else{
    cout << "Faculty could not be deleted, since it contains student advisees. Please remove students before deleting a faculty" << endl;
      }
    }
  else {
    cout << "Faculty does not exist." << endl;
  }

}

void simulation::removeAdvisee(){
  int tempStudentID1 = 0;
  int tempFacultyID1 = 0;
  cout << "Enter the Facutly ID that you'd like to delete a student from." << endl;
  cin >> tempFacultyID1;



  if(masterFacultyBST.contains(tempFacultyID1) == true){
    ListNode<int> *curr = masterFacultyBST.find(tempFacultyID1)->key.listOfStudents.frontPointer();
    if(curr == NULL){
      cout << "The Faculty has no student advisees " << endl;
    }
    else
    {
    masterFacultyBST.find(tempFacultyID1)->key.listOfStudents.printList();
    cout << "Enter the Student  number." << endl;
    cin >> tempStudentID1;
    cout << "find:  " << masterFacultyBST.find(tempFacultyID1)->key.listOfStudents.findData(tempStudentID1) <<endl;

    if(masterFacultyBST.find(tempFacultyID1)->key.listOfStudents.findData(tempStudentID1) == true)
    {
    Student s(tempStudentID1);

    masterFacultyBST.find(tempFacultyID1)->key.listOfStudents.remove(tempStudentID1);
    masterStudentBST.deleteNode(s);
    cout << "Student deleted" << endl;

    }
    else{
      cout << "Student does not exist." << endl;
    }
  }

  }

  else
  {
    cout << "Faculty does not exist." << endl;
  }


}

void simulation::studentFacultyInfo(){
  cout << "Type in the student's ID number?" << endl;
  int tempStudentID1= 0;
  cin >> tempStudentID1;
  int tempFacultyID1 = 0;
  if(masterStudentBST.contains(tempStudentID1) != true){
    cout << "Student ID inputted does not exist" << endl;

  }
  else{
  tempFacultyID1 = masterStudentBST.find(tempStudentID1)->key.facultyID;
  cout << masterFacultyBST.find(tempFacultyID1)->key << endl;
}


}

void simulation::facultyStudentID(){
  cout << " Type in the Faculty's id" << endl;
  int tempfacID = 0;
  cin >> tempfacID;
  if(masterFacultyBST.contains(tempfacID) != true)
  {
    cout << " faculty ID inputted does not exists" << endl;
  }
  else{
  ListNode<int> *curr = masterFacultyBST.find(tempfacID)->key.listOfStudents.frontPointer();
  //cout << " front data: " << curr->data << endl;
  int tempStudentID1=0;
  if(curr == NULL){
    cout << "The Faculty has no student advisees " << endl;
  }

 while (curr !=NULL){
   tempStudentID1= curr->data;
   masterStudentBST.findData(tempStudentID1);
   cout << endl;
   curr= curr->next;
}

}
}

void simulation::changeStudentAdvisor(){
  int tempStudentID1 = 0;
  int tempFacultyID1 = 0;
  int tempFacultyID2= 0;
  cout << "Type in the ID number of the student you'd like to change faculty advisors for.";
  cin >> tempStudentID1;
  Student s(tempStudentID1);
  if(masterStudentBST.contains(s) == true){
    tempFacultyID2 = masterStudentBST.find(s)->key.facultyID;
  //  masterFacultyBST.find(tempFacultyID1)->key.listOfStudents.remove(tempStudentID1); //removing student from old faculty
    cout << "Enter the faculty member that you'd like to add the student to." << endl;
    cin >> tempFacultyID1;
    Faculty f(tempFacultyID1);
    int checker =  0;
  //while (checker == 0){


    if(masterFacultyBST.contains(f) == true){
      masterFacultyBST.find(tempFacultyID2)->key.listOfStudents.remove(tempStudentID1);
      masterFacultyBST.find(tempFacultyID1)->key.listOfStudents.insertBack(tempStudentID1);
      masterStudentBST.find(s)->key.facultyID = tempFacultyID1;
      checker = 1;



    }
    else{
      cout << "Faculty member does not exist" << endl;

    }


  }
  else{
    cout << "Student does not exist." << endl;
  }

}

void simulation::changeStudentName(){
  int tempStudentID1;
  string tempStudenName;
  cout << "Type in the student ID of the student you'd like to change the name of." << endl;
  cin >> tempStudentID1;

  if(masterStudentBST.contains(tempStudentID1) == true){
    cout << "What is the new name of the student?"<< endl;
    cin >> tempStudenName;
    masterStudentBST.find(tempStudentID1)->key.studentName = tempStudenName;
    cout << "Student name has been changed to " << masterStudentBST.find(tempStudentID1)->key.studentName << endl;

  }
  else{
    cout << "Student does not exist." << endl;
  }

}


void simulation::changeFacultyName(){
  int tempFacultyID1;
  string tempFacultyName;
  cout << "Type in the faculty ID of the faculty you'd like to change the name of." << endl;
  cin >> tempFacultyID1;

  if(masterFacultyBST.contains(tempFacultyID1) == true){
    cout << "What is the name of the faculty?" << endl;
    cin >> tempFacultyName;
    masterFacultyBST.find(tempFacultyID1)->key.facultyName = tempFacultyName;
    cout << "Faculty name has been changed to " << masterFacultyBST.find(tempFacultyID1)->key.facultyName << endl;
  }

  else{
    cout << "Faculty does not exist." << endl;
  }

}
