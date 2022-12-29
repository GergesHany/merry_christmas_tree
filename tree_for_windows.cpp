#include <windows.h>
#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
using namespace std;



// Sleep() ->> to make the program running slow for a specific time

// --------------------------------------------------------------
// SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n)
// ->> change the color of the text .. n is the color number
// to know more check the link
// https://stackoverflow.com/questions/30645675/how-to-change-colour-of-a-specific-output-on-console-in-c
// --------------------------------------------------------------

// print the star shape up the tree
void print_star(int n, int speed){
  
  int star = 1, spase = n - 1, color = 12; 
  for (int i = 1; i <= n / 4 - 1; i++){
    Sleep(speed); // make the program running slow for a specific time The time is in miliseconds
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); // change the color of the text
    cout << string(spase, ' '); // print the spase before the star 
    cout << string(star, '*'); // print the stars 
    cout << "\n";
    spase--, star += 2, color++; // change the number of the stars and the spase
    if (color == 16) color = 10; // if the color is 16 change it to 10
  }
  color = 12;
  star -= 4, spase += 2; // change the number of the stars and the spase
  for (int i = 1; i <= n / 4 - 1; i++){
    Sleep(speed);  // make the program running slow for a specific time The time is in miliseconds
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); // change the color of the text
    cout << string(spase, ' '); // print the spase before the star
    // print the stars with for loop because the number of the stars is possible to be negative
    for (int j = 1; j <= star; j++) cout << "*"; 
    cout << "\n";
    spase++, star -= 2, color++; // change the number of the stars and the spase
    if (color >= 16) color = 10; // if the color is 16 change it to 10
  }

}

void print_in_end(int star){

  // calculate the number of spaces 
  string s = "Happy New Year!", t = "[meri christmas]";
  int Space ceill((star -  sz(s)), 2); // calculate the number of spaces before the text
  cout << string(Space , ' '); // print the spaces before the text
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
  cout << s << "\n";
  Space = ceill((star -  sz(t)), 2); // calculate the number of spaces before the text
  cout << string(Space - 1, ' '); // print the spaces before the text 
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
  cout << t << "\n\n";
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}

// print the tree
void print_tree(int n, int speed){

  int color = 10;
  print_star(n, speed); // print the stars shape
  // the print the first step in the tree 
  int star = 1, space = n - 1;
  for(int i = 0; i < n; i++){
   Sleep(speed);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); // change the color of the text
    // print the spase before the star with for loop because the number of the spase is possible to be negative
    for(int j = 0; j < space; j++) cout << " "; 
    cout << string(star, '*');
    cout << "\n";
    star += 2, space--, color++;
    if (color == 16) color = 10; 
  }

  color = 10; 
  star /= 2, star += 2; 
  space = star / 2 - 2;
  
  // the print the secound step in the tree 
  for(int i = 0; i < n / 2; i++){
   Sleep(speed); 
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    for(int j = 0; j < space; j++) cout << " "; 
    cout << string(star, '*');
    cout << "\n";
    star += 2, space--, color++; 
	if (color == 16) color = 10;
  }

  color = 10; 
  star /= 2, star += 2; 
  space = star / 2 - 2; 
  // the print the third step in the tree 
  for(int i = 0; i < n / 2; i++){
   Sleep(speed);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    for(int j = 0; j < space; j++) cout << " "; 
    cout << string(star, '*'); 
    star += 2, space--, color++; 
    if (color == 15) color = 10;
    cout << "\n"; 
  }
  
  print_in_end(star); // print the text in the end of the tree

}

// print the other tree .. the same as the first tree but with different color

void print_star_1(int n){
  
  int star = 1, spase = n - 1, color = 12;
  for (int i = 1; i <= n / 4 - 1; i++){
   Sleep(200);
    cout << string(spase, ' ');
    for (int i = 0; i < star; i++){
       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << "*"; color++; 
	if (color >= 16) color = 12;
    }
    color = 12;
    cout << "\n";
    spase--, star += 2;
  }

  star -= 4, spase += 2; color = 12;
  for (int i = 1; i <= n / 4 - 1; i++){
    cout << string(spase, ' ');
    for (int j = 1; j <= star; j++) {
  	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << "*"; color++; 
	if (color >= 16) color = 12;
    }
   color = 12;
    cout << "\n";
    spase++, star -= 2;
  }

}

void print_tree_1(int n){

  print_star_1(n);
  int color = 10;
   
  // print the first step in the tree
  int star = 1, space = n - 1;
  for(int i = 0; i < n; i++){
   Sleep(200);
    for(int j = 0; j < space; j++) cout << " ";
    for(int j = 0; j < star; j++){
     // change colors in the loop to make every color take a diagonal
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
       cout << "*"; color++; 
      if (color >= 16) color = 10;
    }
    
    cout << "\n";
    star += 2, space --, color = 10;
  }

  star /= 2, star += 2;
  space = star / 2 - 2;
  color = 10;
  // print the secound step in the tree
  for(int i = 0; i < n / 2; i++){
    Sleep(200);
    for(int j = 0; j < space; j++) cout << " ";
    for(int j = 0; j < star; j++) {
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
      cout << "*"; color++; 
      if (color >= 16) color = 10;
    }
    cout << "\n";
    star += 2, space--, color = 10;
  }

  star /= 2, star += 2;
  space = star / 2 - 2;
  color = 10;
  // print the third step in the tree 
  for(int i = 0; i < n / 2; i++){
    Sleep(200);
    for(int j = 0; j < space; j++) cout << " ";
    for(int j = 0; j < star; j++) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << "*"; color++; 
        if (color >= 16) color = 12;
    }
    cout << "\n";
    star += 2, space-- , color = 10;
  }
  
   print_in_end(star); // print the text in the end of the tree
	
}

// print The string slowly
void print_slow(string s){
  for (int i = 0; i < sz(s); i++)
    cout << s[i], Sleep(100);
}

bool is_valid(string s){
  for (int i = 0; i < sz(s); i++)
    if (!isdigit(s[i])) return false;
  return true;  
}

void Accepted(){

  int n;
  char c;
  string s;
  do{

    // print the text in the begining of the program
  scan : 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    cout << "Enter the number\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    cout << "the number should be even and n >= 10\n\n";
    cin >> s;

    if (!is_valid(s)) n = 0;
    else n = stoi(s);  
	  
   if (n < 10 || n & 1){	
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    // print "invalid number...!" for slow
     print_slow("invalid number...!\a\n"); 

     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "Enter the number again\n\n";
    goto scan; // go to scan again if the number is invalid 
      }

  else if (n % 2 == 0 and n >= 10){
	system("cls"); // clear screen 
        print_tree(n, 150); // print the shape for slow
        system("cls"); 
        
        print_tree_1(n);
        system("cls");
	  	   
       // print the shape for fast number of times to make it look like it's moving 
	  for (int i = 0; i < 25; i++){ 
		 print_tree(n, 0);
		 system("cls");  
	   }  
	  print_tree(n, 150);
     }
	   
  	cout << "\nWant to try again ? y : n :  ";
  	cin >> c;
  	cout << '\n';
    if (tolower(c) != 'y' && tolower(c) != 'n'){
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
      print_slow("invalid input...!\n");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176); 
       print_slow("made by : [Gerges Hany]..!\n");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
      exit(0);
    }
  	if (tolower(c) == 'y') system("cls"); // clear screen if the user want to try again
  }while(tolower(c) == 'y');


  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 176); 
  print_slow("made by : [Gerges Hany]..!\n");

  //  return color to general color 
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
  return;
}

int main()
{ 

  //cout << "YES\n";
  int testcaces = 1;
  // cin >> testcaces;
  while (testcaces--){ 
    Accepted (); 
  }
return 0;
}
