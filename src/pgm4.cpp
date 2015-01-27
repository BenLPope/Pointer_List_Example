//--------------------------------------------------------------
//
// Ben Pope
// CS3350 1pm Tue-Thurs
// Due date:   Thursday, November 1st 2012
//
// Compile command: g++ pgm4.cpp
// Input:
//  None
// Output: outputs the combination found 
// Process - creates 4 lists of different types, populates it with various
// data and then uses a set of rules to find the combination at the end.
// 
// Filename: hw4.cpp
//--------------------------------------------------------------

#include <iostream>
#include <list>
#include <time.h>
#include <cstdlib>

using namespace std;

void clue1(list<string>&);           // Hide 1
void clue2(list<char>&);             // Hide 2
void clue3(list<int>&);              // Hide 3
void clue4(list<unsigned long>&);    // Hide 4
void sortList(list<unsigned long>&); // sort 4


char clueOne(list<string>&);                      // clue 1
int clueTwo(list<char>&, char);                   // clue 2
int clueThree(list<int>&, int);                   // clue 3
unsigned long clueFour(list<unsigned long>&, int);// clue 4

int main()
{
list<string> listClue1;       // First list
list<char> listClue2;         // Second list
list<int> listClue3;          // Third list
list<unsigned long> listClue4;// Fourth list

unsigned long temp = 0;       // Holds final Combination
int count = 0;                // Used for counting

srand (time(NULL));           // seed 

list<string>::iterator i;       // iterator for string list
list<char>::iterator j;         // iterator for character list
list<int>::iterator k;          // iterator for integer list
list<unsigned long>::iterator l;// iterator for unsigned long list


clue1(listClue1); // Hides clue 1
clue2(listClue2); // Hides clue 2
clue3(listClue3); // Hides clue 3
clue4(listClue4); // Hides clue 4

sortList(listClue4); // Sorts clue 4 list

// Output

cout << "##-------------------------------##" << endl <<
        "             Clue 1 List           " << endl <<
        "##-------------------------------##" << endl;

for (i = listClue1.begin(); i != listClue1.end(); i++) // Prints List
	{ cout << count << "  " << *i << endl;
          count++;}
cout << "-----------------------------------" << endl;
cout << "Clue 1 - 'Linky' found!" << endl;
cout << "Letter of 'Linky' to look for is '" << clueOne(listClue1) << "'" << endl;
cout << "-----------------------------------" << endl;
cout << "##-------------------------------##" << endl <<
        "             Clue 2 List           " << endl <<
        "##-------------------------------##" << endl;
count = 0;
for (j = listClue2.begin(); j != listClue2.end(); j++) // Prints List
	{ cout << count << "  " << *j << endl;
          count ++;}
cout << "-----------------------------------" << endl;
cout << "Clue 2 - letter '" << clueOne(listClue1)<< "' found in location " << clueTwo(listClue2, clueOne(listClue1)) << endl;
cout << "-----------------------------------" << endl;
cout << "##-------------------------------##" << endl <<
        "             Clue 3 List           " << endl <<
        "##-------------------------------##" << endl;
count = 0;
for (k = listClue3.begin(); k != listClue3.end(); k++) // Prints List
	{ cout << count << "  " << *k << endl;
          count ++;}
cout << "-----------------------------------" << endl;
cout << "Clue 3 - '" << clueThree(listClue3, clueTwo(listClue2, clueOne(listClue1))) 
     << "' found at position " << (10 - clueTwo(listClue2, clueOne(listClue1))) << endl;
cout << "-----------------------------------" << endl;
cout << "##-------------------------------##" << endl <<
        "             Clue 4 List           " << endl <<
        "##-------------------------------##" << endl;
count = 0;
for (l = listClue4.begin(); l != listClue4.end(); l++) // Prints List
        { cout << count << "  " << *l << endl;
          count ++;}
temp =  clueFour(listClue4,clueThree(listClue3, clueTwo(listClue2, clueOne(listClue1))));
cout << "-----------------------------------" << endl;
cout << "Found combination! - '" << temp << "'" << endl;
cout << "-----------------------------------" << endl;


return 0;
}

void clue1(list<string>& l) // Populates list with words
{
 string message[] = {"Search", "the", "lists", "for", "clues"};
 int randNum = rand()%5;

 list<string>::iterator i;

 for (int j = 0; j < 10; j++)
  {
   randNum = rand()%5;
   l.push_back(message[randNum]);
  }

 randNum = rand()%11; // Inserts "linky" randomly
 i = l.begin(); 
 for(int j = 1; j < randNum; j++)
        i++;
 *i = "Linky";
}

void clue2(list<char>& l) // Populates list with characters
{
 char letters[] = {'l', 'i', 'n', 'k', 'y'};
 int randNum = rand()%5;

 for(int i = 0; i < 10; i++)
  {
   randNum = rand()%5;
   l.push_back(letters[randNum]);
  }
}


void clue3(list<int>& l) // Populates list with integers
{
 int randNum = rand()%50;
 for (int i = 0; i < 10; i++)
  {
   randNum = rand()%50;
   l.push_back(randNum);
  }
}
void clue4(list<unsigned long>& l) // Populates list with unsigned long integers
{
 unsigned long randNum;
 for (int i = 0; i < 50; i++)
  {
   randNum = rand() * (123456789 + 100000000);
   l.push_back(randNum);
  }

}
void sortList(list<unsigned long>& l) // List sort
{
 l.sort(); // Sort ascending
 l.reverse(); // Reverses to descending
}
char clueOne(list<string>& l) // find linky, return position
{
 string name = "linky";
 int position = 0;
 list<string>::iterator i;
 for(i = l.begin(); i != l.end(); i++)
  {	 if( *i == "Linky")
		break;
	 position ++;
  }
 return name[position%5];

}
int clueTwo(list<char>& l, char letter) // find last position of letter found in clue 1
{
  list<char>::iterator i;
  int position = 0;
  int foundAt = 0;
  for(i = l.begin(); i != l.end(); i++)
   {	if (*i == letter)
		 foundAt = position;
	position ++;
   }
  return foundAt;
}
int clueThree(list<int>& l, int pos) // find number in position n from bottom using number
{                                    // found in clue two
 list<int>::iterator i;
 int j = 0;
 i = l.end();
 while(j < pos)
	{i--;
         j++;}
 return *i;
}
unsigned long clueFour(list<unsigned long>& l, int pos) // Return unsigned long using position
{                                                       // found in clue three
 list<unsigned long>::iterator i;
 int j = 0;
 i = l.begin();
 while (j < (pos -1))
	{i++;
	 j++;}
 return *i;
}


