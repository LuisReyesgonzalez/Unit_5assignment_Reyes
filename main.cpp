/*
Dr. Tyson McMillan School Cost Estimator Using C++. Students were tasked with creating a C++ program from an operational Excel Spreasheet. 
Nov 14, 2019
*/
#include <iostream>
#include <string>
using namespace std; 
 //prototype
 void showoptions();

class Semester
{
  private:
  //systems assumptions constants
  //static const variables keep their value even after multiple calls
    static const int hoursPerClass = 3; 
    static const int monthsInOneSemester = 4;
    static const int semestersInAYear = 3; 
    //user changeable settings (need: setters and getters)
    int hoursTheStudentTakes; 
    int hoursInTheDegree; 
    string schoolName; 
    double costPerCreditHour; 
    double bookCostsPerClass;
    double roomAndBoardCosts; 
    double foodCostsPerMonth; 
    double travelCostsPerMonth; 
  public:
    Semester() //default constructor TCC
    {
        //user changeable settings default values
        hoursTheStudentTakes = 12; //ft 12, pt 9, ht 6
        hoursInTheDegree = 60; 
        schoolName = "TCC"; 
        costPerCreditHour = 59.00; 
        bookCostsPerClass = 100.00;
        roomAndBoardCosts = 400.00; 
        foodCostsPerMonth = 150.00; 
        travelCostsPerMonth = 90.00; 
    } 
    //paramerterize constructor with initizlier list
    Semester(int hTST, int hID, string sN, double cPCH, double bCPC, double rABC, double fCPM, double tCPM) : 
    hoursTheStudentTakes(hTST), hoursInTheDegree(hID),
    schoolName(sN), costPerCreditHour(cPCH),
    bookCostsPerClass(bCPC), roomAndBoardCosts(rABC),
    foodCostsPerMonth(fCPM), travelCostsPerMonth(tCPM)
    { }
    void setHoursAStudentTakes(int h) { hoursTheStudentTakes = h; }
    int getHoursAStudentTakes() const { return hoursTheStudentTakes; }
    
/************************Setters and Getters**************************/
//setters  

     void sethoursTheStudentTakes(int hTST){hoursTheStudentTakes=hTST;} 
    void  sethoursInTheDegree(int hID){ hoursInTheDegree=hID;}      
    void setschoolName(string sN){schoolName=sN;}  
    void setcostPerCreditHour(double cPCH) {costPerCreditHour=cPCH;} 
    void setbookCostsPerClass(double bCPC){ bookCostsPerClass=bCPC;} 
    void setroomAndBoardCosts(double rABC){roomAndBoardCosts=rABC;} 
    void setfoodCostsPerMonth (double fCPM){foodCostsPerMonth=fCPM;}  
    void settravelCostsPerMonth(double tCPM) {travelCostsPerMonth=tCPM;} 
// getters
    int getHoursTheStudentTakes ()const {return hoursTheStudentTakes;}
    int gethoursInTheDegree ()const {return hoursInTheDegree;}
    string getSchoolName ()const {return schoolName;}
    double getcostPerCreditHour ()const {return costPerCreditHour;}
    double getBookCostPerClass() const{ return bookCostsPerClass;}
    double getRoomAndBoardCosts ()const {return roomAndBoardCosts;}
    double getFoodCostsPerMonth ()const {return foodCostsPerMonth;}
    double getTravelCostsPerMonth ()const {return travelCostsPerMonth;}
/**************************calculations******************************/
    //calculate tution
 double calculateTuition()
    {return (hoursTheStudentTakes*costPerCreditHour);}
    //calculate room and Board
  double calculateRoomBoard (){return (monthsInOneSemester * roomAndBoardCosts);}
    //caculate travel
 double calculatetravel() {return (travelCostsPerMonth *monthsInOneSemester);}
    //calculate food
  double calculateFood(){return (foodCostsPerMonth*monthsInOneSemester);}
    //calculate books
  double calculateBooks(){return (bookCostsPerClass * (hoursTheStudentTakes/hoursPerClass));}
    //caculate total cost per semester
    double calculateTotalSemester() {return  (calculateTuition()+calculateRoomBoard()+calculatetravel()+calculateFood()+calculateBooks());}

};
void handleOptions (Semester &ft ,Semester &pt,Semester &ht,char option);
void ShowMenu(Semester ftTCC ,Semester ptTCC,Semester htTCC);
                
                
                
                
                int main() 
{
  char option;
  //instances of the 3 types of semesters
   Semester ftTCC; //call default constructor
   Semester ptTCC; //calls default constuctor 
   Semester htTCC; //call default constructor



    //local assumptions for user input
    const int hoursAFullTimeStudent = 12;
    const int hoursAPartTimeStudent = 9;
    const int hoursAHalfTimeStudent = 6;

   //set hours a student a student takes per semester types
   ftTCC.setHoursAStudentTakes(hoursAFullTimeStudent);
   ptTCC.setHoursAStudentTakes(hoursAPartTimeStudent);
   htTCC.setHoursAStudentTakes(hoursAHalfTimeStudent);
   
 while(option!='x'&& option!='X'){
   system("clear");
 ShowMenu(ftTCC , ptTCC, htTCC);
  showoptions();
  cout<<"enter a option: ";
  cin>>option;
  handleOptions(ftTCC,ptTCC,htTCC, option);
 };
cout << "\033[2J\033[1;1H";
cout << "Bye";

  return 0; 
}
void showoptions()
{
cout<< "Which Information would you like to change? "<<endl;
cout<<"A:Cost per Credit hour"<<endl;
cout<<"B:Book cost per Class"<<endl;
cout<<"C:Room and Board "<<endl;
cout<<"D:Food cost per month "<<endl;
cout<<"E:Travel costs per month"<<endl;
cout<< "X: EXIT"<<endl;
  
}
void handleOptions(Semester &ft ,Semester &pt,Semester &ht , char option) {
double input =0.0;

  if (option =='A' || option == 'a')
  {
    cout<<"What is the new cost per hour?"<<endl;
    cin>> input;
    ft.setcostPerCreditHour(input);
     pt.setcostPerCreditHour(input);
      ht.setcostPerCreditHour(input);

  }
  else   if (option =='B' || option == 'b')
  {
    cout<<"What is the new book cost?"<<endl;
    cin>> input;
    ft.setbookCostsPerClass(input);
    pt.setbookCostsPerClass(input);
     ht.setbookCostsPerClass(input);

  }
  else   if (option =='C' || option == 'c')
  {
    cout<<"What is the new room and board cost?"<<endl;
    cin>> input;
    ft.setroomAndBoardCosts(input);
   pt.setroomAndBoardCosts(input);
   ht.setroomAndBoardCosts(input);
  }
  else   if (option =='D' || option == 'd')
  {
    cout<<"What is the new food cost?"<<endl;
    cin>> input;
    ft.setfoodCostsPerMonth(input);
    pt.setfoodCostsPerMonth(input);
      ht.setfoodCostsPerMonth(input);
  }
 else   if (option =='E' || option == 'e')
  {
    cout<<"What is the new travel cost?"<<endl;
    cin>> input;
    ft.settravelCostsPerMonth(input);
      pt.settravelCostsPerMonth(input);
        ht.settravelCostsPerMonth(input);
  }
}
void ShowMenu(Semester ftTCC ,Semester ptTCC,Semester htTCC)
 {
//--------------------Variables------------------------
cout<< "\n-------VARIABLES------"<<endl;
cout << "COST PER CREDIT HOUR: $" <<ftTCC.getcostPerCreditHour() << endl;
cout<<"COST BOOK COST PER CLASS: $" <<ftTCC.getBookCostPerClass()<<endl;
cout << "ROOM & BOARD COST PER MONTH: $"<<ftTCC.getRoomAndBoardCosts() << endl;
cout<< "FOOD COST PER MONTH : $" << ftTCC.getFoodCostsPerMonth()<<endl;
cout<< "TRAVEL COSTS PER MONTH : $"<<ftTCC.getTravelCostsPerMonth()<<endl;
cout<< "----------------------------------------"<<endl;

//------------------------Full time------------------------------
cout<< "\n-------FULLTIME------"<<endl;
cout << "TUITION: $" <<ftTCC.calculateTuition()<< endl;
cout<<"BOOKS: $" <<ftTCC.calculateBooks()<<endl;
cout << "ROOM & BOARD: $"<<ftTCC.calculateRoomBoard() << endl;
cout<< "FOOD: $" << ftTCC.calculateFood()<<endl;
cout<< "TRAVEL: $"<<ftTCC.calculatetravel()<<endl;
cout<< "-----------------------"<<endl;

//------------------------Part-time------------------------------
cout<< "\n-------PART-TIME------"<<endl;
cout << "TUITION: $" <<ptTCC.calculateTuition()<<endl;
cout<<"BOOKS: $" <<ptTCC.calculateBooks()<<endl;
cout << "ROOM & BOARD: $"<<ptTCC.calculateRoomBoard() << endl;
cout<< "FOOD: $" << ptTCC.calculateFood()<<endl;
cout<< "TRAVEL: $"<<ptTCC.calculatetravel()<<endl;
cout<< "----------------------"<<endl;
//------------------------Half-time------------------------------
cout<< "\n-------HALF-TIME------"<<endl;
cout << "TUITION: $" <<htTCC.calculateTuition()<<endl;
cout<<"BOOKS: $" <<htTCC.calculateBooks()<<endl;
cout << "ROOM & BOARD: $"<<htTCC.calculateRoomBoard() << endl;
cout<< "FOOD: $" << htTCC.calculateFood()<<endl;
cout<< "TRAVEL: $"<<htTCC.calculatetravel()<<endl;
cout<< "----------------------"<<endl;


}