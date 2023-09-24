#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

class SALESREC2
{
public:
 char OrderDate[200];
 char Region[200];
 char Rep[200];
 char Item[200];
 int Units;
 float UnitCost;
 float Total;

/*public:
void setOrderDate(char a[]){
  OrderDate=a;
}
void setRegion(char b[]){
  Region=b;
}
void setRep(char c[]){
  Rep=c;
}
void setItem(char d[]){
  Item=d;
}
void setUnits(int e){
  Units=e;
}
void setUnitCost(float f){
  UnitCost=f;
}
void setTotal(float g){
  Total=g;
}
char getOrderDate(){
return OrderDate;
}
char getRegion(){
  return Region;
}
char getRep(){
  return Rep;
}
char getItem(){
  return Item;
}
int getUnits(){
  return Units;
}
double getUnitCost(){
  return UnitCost;
}
double getTotal(){
  return Total;
}*/
};

class SALESREC
{
  public:
	char     date[256];
	char     region[256];
	char     rep[256];
	char     item[256];
	int      units;
	float    unitCost;
	float    Total;
};

void simpleSortTotal( SALESREC* s[] , int c);

int main()
{
	ifstream infile;
	int i=0;
	char cNum[256] ;
	SALESREC salesArr[40];
  string header;
	int   salesArrayCount = 0;
	SALESREC* s[40];

  //cout << "start\n";
		//infile.open ("SalesDataPt2.csv", ifstream::in);
    infile.open ("SalesDataPt2.csv");
		if (infile.is_open())
		{
		int   c=0;
   
    getline(infile,header);
    //cout<<header<<endl;
		while (infile.good())
		{
      //cout << "start\n";
			infile.getline(salesArr[c].date, 256, ',');
      //cout << "start1\n";
			infile.getline(salesArr[c].region, 256, ',');
      //cout << "start2\n";
			infile.getline(salesArr[c].rep, 256, ',');
      //cout << "start3\n";
			infile.getline(salesArr[c].item, 256, ',');
      //cout << "start4\n";
			infile.getline(cNum, 256, ',');
      //cout << "start5\n";
			salesArr[c].units = atoi(cNum);
			infile.getline(cNum, 256, '\n');
      //cout << "start6\n";
			salesArr[c].unitCost = atof(cNum);
			//infile.getline(cNum, 256, '\n');
			salesArr[c].Total = salesArr[c].units*salesArr[c].unitCost;
      //cout << "start7\n";

			i++ ;
			c++;
     //cout << "salesArrdate "<<salesArr[c-1].date<<endl;
     //cout << "salesArrregion "<<salesArr[c-1].region<<endl;
     //cout << "salesArrrep"<<salesArr[c-1].rep<<endl;
     //cout << "salesArritem "<<salesArr[c-1].item<<endl;
     //cout << "salesArrunits "<<salesArr[c-1].units<<endl;
     //cout << "salesArruc "<<salesArr[c-1].unitCost<<endl;
     //cout << "salesArrtotal "<<salesArr[c-1].Total<<endl;
     //cout << "read next line\n";

		}
		salesArrayCount = c-1;
    //cout << "salesArrCount"<<salesArr[c-1].region;
		infile.close();
	}
	else
	{
		cout << "Error opening file";
	}
	//cout << "salesArrayCout "<< salesArrayCount<<endl;
	// Initialize the sort array pointers
	for (int i=0; i < salesArrayCount; i++)
		s[i] = &salesArr[i];
	/*for (int i=0; i < salesArrayCount; i++)
		cout << "Record: " << s[i]->date <<", " << s[i]->region << ", " << s[i]->rep << ", " << s[i]->item << ", " << s[i]->units << ", " << s[i]->unitCost << ", " << s[i]->Total << endl;*/
	simpleSortTotal (s, salesArrayCount);
  //cout << endl;
cout<<"OrderDate,Region,Rep,Item,Units,UnitCost,Total"<<endl;
char* removeSpaces(char * s);	  
	for (int i=0; i < salesArrayCount; i++)
		cout << s[i]->date <<"," << removeSpaces(s[i]->region) << "," << removeSpaces(s[i]->rep )<< "," << removeSpaces(s[i]->item) << "," << s[i]->units << "," << s[i]->unitCost << "," << s[i]->Total << endl;
  
}
 
// arguments will be an array of pointers and a count

//void removeSpaces(char* s) {
//    *std::remove(s, s + strlen(s), ' ') = 0;
//}
char* removeSpaces(char * s) {
    return s+1;
}

void simpleSortTotal( SALESREC* s[] , int c)
{
	SALESREC* temp;
	for (int i=0; i < c; i++)
		for (int j=i; j < c; j++)
		if (s[i]->Total < s[j]->Total)
		{
      temp=s[i];
      s[i]=s[j];
      s[j]=temp;
			//swap pointer to record i with pointer to record j;
		}
} 
/*
int main() {

 	char cNum[11] ;
  //cout<<"OrderDate,Region,Rep,Item,Units,UnitCost,Total"<<endl;
  ifstream infile("SalesDataPt2.csv");
  char line[2000];
  SALESREC salesArr[1000];
  SALESREC* s[1000];
  int c=0;
  int   salesArrayCount = 0;
  string header;
  getline(infile,header);
  cout<< header<<endl;
  while (infile.good()){
//    infile.getline(line,2000);
//    cout << line<<endl;
    
    	infile.getline(salesArr[c].OrderDate, 256, ',');
			infile.getline(salesArr[c].Region, 256, ',');
      infile.getline(salesArr[c].Rep, 256, ',');
			infile.getline(salesArr[c].Item, 256, ',');
      //cout<<salesArr[c].Item<<endl;
			infile.getline(cNum, 256, ',');
			salesArr[c].Units = atoi(cNum);
			infile.getline(cNum, 256, ',');
			salesArr[c].UnitCost = atof(cNum);
			infile.getline(cNum, 256, '\n');
			salesArr[c].Total = salesArr[c].UnitCost*salesArr[c].Units;
      c++;
      cout<<c<<endl;
  }
  	salesArrayCount = c-1;
    //cout << "salesArrCount"<<salesArr[c-1].region;
		infile.close();
	

	
	// Initialize the sort array pointers
	for (int i=0; i < salesArrayCount; i++)
		s[i] = &salesArr[i];
//for (int i=0; i < salesArrayCount; i++)
//		cout << "Record: " << s[i]->date <<", " << s[i]->region << ", " << s[i]->rep << ", " << s[i]->item << ", " << s[i]->units << ", " << s[i]->unitCost << ", " << s[i]->Total << endl;
	simpleSortTotal (s, salesArrayCount);
  //cout << endl;
	  cout<< salesArrayCount<<endl;
	for (int i=0; i <= salesArrayCount; i++){
    cout<<i<<" ";
		cout << "Record: " << s[i]->OrderDate <<", " << s[i]->Region << ", " << s[i]->Rep << ", " << s[i]->Item << ", " << s[i]->Units << ", " << s[i]->UnitCost << ", " << s[i]->Total << endl;
  }
}
 
// arguments will be an array of pointers and a count


void simpleSortTotal( SALESREC* s[] , int c)
{
	SALESREC* temp;
	for (int i=0; i < c; i++)
		for (int j=i; j < c; j++)
		if (s[i]->Total < s[j]->Total)
		{
      temp=s[i];
      s[i]=s[j];
      s[j]=temp;
			//swap pointer to record i with pointer to record j;
		}
} 

//need a code that separates the spaces and the commas from the other stuff
//need a code that checks if the first part of the array is the first line of data
//need code that puts the data in the class then sorts it
//sorting by the total value

*/

