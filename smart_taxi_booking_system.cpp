#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;

// global variable
string tolowercase(string str);
void displayInfo();
void customer(string id[], string password[],int& c);
void rides(double& distance,string& location,double per_Km_charge,double& fare);
void add_driver(string id[],string password[],int veh_number[],string name[],int& d);
void driver(string id[], string password[],int veh_number[],string name[],int& d);
void admin(string id[],string password[],int veh_number[],string name[],int& d);
void getinfo(int&d);
void remove_driver(string id[],string password[],int veh_number[],string name[],int& d);

string tolowercase(string str){
    for(char& c:str){
        c=tolower(c);
          }
    return str;
}

void displayInfo(){
    cout<<"1-LOGIN AS CUSTOMER..."<<endl;
    cout<<"2-LOGIN AS A RIDER..."<<endl;
    cout<<"3-LOGIN AS A ADMIN..."<<endl;
 }

//  CUSTOMER...
void customer(string id[], string password[],int& c){
    cin.ignore();
    cin.clear();
    cout<<"ENTER THE USER ID: ";
    getline(cin,id[c]);
    cin.clear();
    cout<<"ENTER THE PASSWORD: ";
    getline(cin,password[c]);
    cout<<"LOGIN SUCCESSFULLY...."<<endl;
     c++;
    ofstream inputfile("customer.txt",ios::app);
    inputfile<<"LOGIN DETAILS"<<endl;
    for(int i=0;i<c;i++){
    inputfile<<"ID: "<<id[i]<<endl;
    inputfile<<"PASSWORD: "<<password[i]<<endl;
    }
    inputfile.close();
}
void rides(double& distance,string& location,double per_Km_charge,double& fare){
 
    string choice;
    // BOOKING RIDE
    cin.clear();
    cout<<"ENTER THE DROP LOCATION: ";
    getline(cin,location);
    cout<<"ENTER THE DISTANCE: ";
    cin>>distance;

    fare=distance*per_Km_charge;
    cout<<"YOUR FARE IS "<<fare<<endl;
    cout<<"ARE YOU SURE...YES/NO? "<<endl;
    cin>>choice;
    if(tolowercase(choice)=="yes"){
        cout<<"YOUR RIDE BOOKED SUCCESSFULLY..."<<endl;
        cout<<"YOU RIDER WITH ID WILL REACH YOU SOON"<<endl;
    }
    else if(tolowercase(choice)=="no"){
        cout<<"YOU CANCELLED RIDE..."<<endl;
        cout<<"TRY AGAIN"<<endl;
    }
    else{
        cout<<"INVALID INPUT..RE-ENTER..."<<endl;
    }
  
     ofstream inputfile("customer.txt",ios::app);
     inputfile<<"LOCATION: "<<location<<endl;
     inputfile<<"FARE: "<<fare<<endl;
     inputfile.close();
}

// DRIVER
//  CUSTOMER...
void driver(string id[], string password[],int veh_number[],string name[],int& d){
    add_driver(id,password,veh_number,name,d);  
    cout<<"LOGIN SUCCESSFULLY...."<<endl;
}

void driver_rides(string location,double per_Km_charge,double& fare){
    string choice;
    string status;
    // Accepting RIDE
    cin.clear();
    cin.ignore();
    cout<<"ENTER YOUR LOCATION: ";
    getline(cin,location);
    while(true){
    cout<<"FARE OFFERED IS:  "<<fare<<endl;
    cout<<"ARE YOU OKAY WITH THAT...YES/NO? "<<endl;
    cin>>choice;
    if(tolowercase(choice)=="yes"){
        cout<<"YOUR RIDE STARTED SUCCESSFULLY..."<<endl;
        status="SUCCESFUL";
        break;
    }
    else if(tolowercase(choice)=="no"){
        cout<<"OFFER YOUR FARE PRESS 1 TO CANCEL RIDE.... ";
        cin>>fare;
        if(fare==1){
            cout<<"RIDE CANCELLED..."<<endl;
            status="CANCEL";
            break;
        }
    }
    else{
        cout<<"INVALID INPUT..RE-ENTER..."<<endl;
    }
}
  
     ofstream inputfile("driver.txt",ios::app);
     inputfile<<"LOCATION: "<<location<<endl;
     inputfile<<"FARE: "<<fare<<endl;
     inputfile.close();
}

// ADMIN...
void admin(string id[],string password[],int veh_number[],string name[],int& d){
  int  choice; 
  cout<<"WELCOME TO SMART TAXI..."<<endl;
  cout<<"1.ADD A DRIVER."<<endl;
  cout<<"2.REMOVE A DRIVER."<<endl;
  cout<<"3.HISTORY DETAILS."<<endl;

  cout<<"WHAT YOU WANT TO DO...";
  cin>>choice;
 if(choice==1){
   add_driver(id,password,veh_number,name,d);
   cout<<"ADDED SUCCESSFULLY"<<endl;
   }
 else if(choice==2){
  remove_driver(id,password,veh_number,name,d);
  cout<<"ADDED SUCCESSFULLY"<<endl;
   }
   else if(choice==3){
   getinfo(d);
   }

   }

void remove_driver(string id[],string password[],int veh_number[],string name[],int& d){
    string id_num;
    cin.clear();
    cin.ignore();
    cout<<"ENTER THE DRIVER ID: ";
    getline(cin,id_num);


for(int i=0;i<d;i++){
    string x = tolowercase(id_num);
    string y = tolowercase(id[i]);


    if(x == y){
      id[i] = " ";
      name[i] = " ";
      password[i] = " ";
      veh_number[i] = 0;
    }
    else{
        cout<<"ID NOT FOUND..."<<endl;
    }
}

 ofstream inputfile("driver.txt",ios::app);
    inputfile<<"LOGIN DETAILS"<<endl;
    for(int i=0;i<d;i++){
    inputfile<<"ID: "<<id[i]<<endl;
    inputfile<<"NAME: "<<name[i]<<endl;
    inputfile<<"PASSWORD: "<<password[i]<<endl;
    inputfile<<"VEHICLE NUMBER: "<<veh_number[i]<<endl;
    }
    inputfile.close();
}


void add_driver(string id[],string password[],int veh_number[],string name[],int& d){
    cin.ignore();
    cout<<"ENTER THE DRIVER ID: ";
    getline(cin,id[d]);
    cin.clear();
    cout<<"ENTER THE DRIVER NAME: ";
    getline(cin,name[d]);
    cin.clear();
    cout<<"ENTER THE PASSWORD: ";
    getline(cin,password[d]);
    cout<<"ENTER THE VEHICLE NUMBER: ";
    cin>>veh_number[d];
    d++;

   ofstream inputfile("driver.txt");
    inputfile<<"LOGIN DETAILS"<<endl;
    for(int i=0;i<d;i++){
    inputfile<<"ID: "<<id[i]<<endl;
    inputfile<<"NAME: "<<name[i]<<endl;
    inputfile<<"PASSWORD: "<<password[i]<<endl;
    inputfile<<"VEHICLE NUMBER: "<<veh_number[i]<<endl;
    }
    inputfile.close();
}

void getinfo(int&d){
  string id;
  string password;
  string veh_number;
  string name;

  ifstream infile("driver.txt");
   while(!infile.eof()){
   getline(infile,id);
   getline(infile,name);
   getline(infile,password);
   getline(infile,veh_number);

   cout<<"ID: "<<id<<endl;
   cout<<"NAME: "<<name<<endl;
   cout<<"PASSWORD: "<<password<<endl;
   cout<<"VEHICLE NUMBER: "<<veh_number<<endl;
   }
   }
    


int main(){
    int d=0;
    int c=0;
    string name[100];
    string customer_id[100];
    string customer_password[100];
    double distance;
    string location;
    double fare=0;
    double per_Km_charge=10;
    string driver_id[100];
    string driver_password[100];
    string driver_location;
    int veh_number[100];
    int choice;
  
    displayInfo();
    cout<<"ENTER YOUR CHOICE: ";
    cin>>choice;
     
    if(choice==1){
    customer(customer_id,customer_password,c);
    rides(distance,location,per_Km_charge,fare);
    }
    else if(choice==2){
    driver(driver_id,driver_password,veh_number,name,d);
    driver_rides(location,per_Km_charge,fare);
    }
    else if(choice==3){
    admin(driver_id,driver_password,veh_number,name,d);
    }
    else{
        cout<<"INVALID INPUT...."<<endl;
    }

}
