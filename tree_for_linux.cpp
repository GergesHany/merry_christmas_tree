// sorce code for the linux //

#include <iostream>
#include <unistd.h>
#include <time.h>
#define sz(x) (int)x.size()
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
using namespace std;


void sleep(double mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


void colorize(string text, int fg = 37, bool bold = 0, bool underline = 0, int bg = 40){
    cout <<  "\033[" << (bold ? "1;" : "0;") << (underline ? "4;" : "") << fg << ";" << bg << "m" << text << "\033[0m" << "";
}

const string red("\033[0;31m"), red_b("\033[1;31m"), red_u("\033[4;31m"), red_bu("\033[1;4;31m"); 
const string green("\033[0;32m"), green_b("\033[1;32m"), green_u("\033[4;32m"), green_bu("\033[1;4;32m");
const string yellow("\033[0;33m"), yellow_b("\033[1;33m"), yellow_u("\033[4;33m"), yellow_bu("\033[1;4;33m");
const string blue("\033[0;34m"), blue_b("\033[1;34m"), blue_u("\033[4;34m"), blue_bu("\033[1;4;34m");
const string magenta("\033[0;35m"), magenta_b("\033[1;35m"), magenta_u("\033[4;35m"), magenta_bu("\033[1;4;35m");
const string cyan("\033[0;36m"), cyan_b("\033[1;36m"), cyan_u("\033[4;36m"), cyan_bu("\033[1;4;36m");
const string white("\033[0;37m"), white_b("\033[1;37m"), white_u("\033[4;37m"), white_bu("\033[1;4;37m");
const string reset("\033[0m");

class Color {
public:
    // print red text
    void printRed(string text) { 
        cout << red << text << reset;
    }
    
    // print red text with bold
    void printRedB(string text) { 
        cout << red_b << text << reset;
    }

    // print red text with underline
    void printRedU(string text) { 
        cout << red_u << text << reset;
    }

   // print red text with bold and underline
    void printRedBU(string text) { 
        cout << red_bu << text << reset;
    }

    void printGreen(string text) {
        cout << green << text << reset;
    }

    void printGreenB(string text) {
        cout << green_b << text << reset;
    }

    void printGreenU(string text) {
        cout << green_u << text << reset;
    }

    void printGreenBU(string text) {
        cout << green_bu << text << reset;
    }

    void printYellow(string text) {
        cout << yellow << text << reset;
    }

    void printYellowB(string text) {
        cout << yellow_b << text << reset;
    }

    void printYellowU(string text) {
        cout << yellow_u << text << reset;
    }

    void printYellowBU(string text) {
        cout << yellow_bu << text << reset;
    }

    void printBlue(string text) {
        cout << blue << text << reset;
    }

    void printBlueB(string text) {
        cout << blue_b << text << reset;
    }

    void printBlueU(string text) {
        cout << blue_u << text << reset;
    }

    void printBlueBU(string text) {
        cout << blue_bu << text << reset;
    }

    void printMagenta(string text) {
        cout << magenta << text << reset;
    }

    void printMagentaB(string text) {
        cout << magenta_b << text << reset;
    }

    void printMagentaU(string text) {
        cout << magenta_u << text << reset;
    }

    void printMagentaBU(string text) {
        cout << magenta_bu << text << reset;
    }

    void printCyan(string text) {
        cout << cyan << text << reset;
    }

    void printCyanB(string text) {
        cout << cyan_b << text << reset;
    }

    void printCyanU(string text) {
        cout << cyan_u << text << reset;
    }

    void printCyanBU(string text) {
        cout << cyan_bu << text << reset;
    }

    void printWhite(string text) {
        cout << white << text << reset;
    }

    void printWhiteB(string text) {
        cout << white_b << text << reset;
    }

    void printWhiteU(string text) {
        cout << white_u << text << reset;
    }

    void printWhiteBU(string text) {
        cout << white_bu << text << reset;
    }

};


// print the star shape up the tree
void print_star(int n, float speed = 0.9){
  
  int star = 1, spase = n - 1, color = 31; 
  for (int i = 1; i <= n / 4 - 1; i++){
    sleep(speed); // make the program running slow for a specific time The time is in miliseconds
    cout << string(spase, ' '); // print the spase before the star 
    for (int i = 0; i < star; i++) colorize("*", color); // print the stars with color     
    cout << "\n";
    spase--, star += 2, color++; // change the number of the stars and the spase
    if (color == 36) color = 31; // if the color is 16 change it to 10 to make the color change again
  }
  color = 12;
  star -= 4, spase += 2; // change the number of the stars and the spase
  for (int i = 1; i <= n / 4 - 1; i++){
    sleep(speed);  // make the program running slow for a specific time The time is in miliseconds
    cout << string(spase, ' '); // print the spase before the star
    for (int i = 0; i < star; i++) colorize("*", color); // print the stars with color     
    cout << "\n";
    spase++, star -= 2, color++; // change the number of the stars and the spase
    if (color >= 36) color = 31; // if the color is 16 change it to 10 to make the color change again
  }

}

// print the text in the end of the tree
void print_in_end(int star){

  // calculate the number of spaces 
  string s = "Happy New Year!", t = "[meri christmas]";
  int Space ceill((star -  sz(s)), 2); // calculate the number of spaces before the text
  cout << string(Space , ' '); // print the spaces before the text
  colorize(s, 31); // print the text with color
  cout << "\n";
  Space = ceill((star -  sz(t)), 2); // calculate the number of spaces before the text
  cout << string(Space - 1, ' '); // print the spaces before the text 
  colorize(t + "\n\n", 32); // print the text with color
  colorize("", 7); // change the color of the text to white

}

// print the tree
void print_tree(int n, float speed = 0.9){

  int color = 31;
  print_star(n, speed); // print the stars shape
  // the print the first step in the tree 
  int star = 1, space = n - 1;
  for(int i = 0; i < n; i++){
   sleep(speed); 
    for(int j = 0; j < space; j++) cout << " "; 
    for(int j = 0; j < star; j++) colorize("*", color); 
    cout << "\n";
    star += 2, space--, color++; 
    if (color == 36) color = 31; 
  }

  color = 31; // change the color to 31
  // change the number of the stars and the spase
  star /= 2, star += 2; space = star / 2 - 2; 
  
  // the print the secound step in the tree 
  for(int i = 0; i < n / 2; i++){
    sleep(speed); 
    // print the spase before the star with for loop because the number of the spase is possible to be negative
    for(int j = 0; j < space; j++) cout << " "; 
    for (int j = 0; j < star; j++) colorize("*", color); 
    cout << "\n";
    star += 2, space--, color++;
    if (color == 36) color = 31; 
  }

  color = 31; // change the color to 10 to make the color change again
  // change the number of the stars and the spase
  star /= 2, star += 2; space = star / 2 - 2;
  // the print the third step in the tree 
  for(int i = 0; i < n / 2; i++){
    sleep(speed); 
    // print the spase before the star with for loop because the number of the spase is possible to be negative
    for(int j = 0; j < space; j++) cout << " "; 
    for (int j = 0; j < star; j++) colorize("*", color);
    star += 2, space--, color++; 
    if (color == 36) color = 31;
    cout << "\n"; 
  }
  
  print_in_end(star); // print the text in the end of the tree

}


// -------------------------------------------------------------------------------------------------------------- //

// print the other tree .. the same as the first tree but with different color

void print_star_1(int n, float speed = 0.9){
  
  int star = 1, spase = n - 1, color = 31;
  for (int i = 1; i <= n / 4 - 1; i++){
    sleep(speed);
    cout << string(spase, ' ');
    for (int i = 0; i < star; i++){
      colorize("*", color); color++; 
      if (color >= 36) color = 31;
    }
    color = 31;
    cout << "\n";
    spase--, star += 2;
  }

  star -= 4, spase += 2; color = 31;
  for (int i = 1; i <= n / 4 - 1; i++){
    sleep(speed);
    cout << string(spase, ' ');
    for (int j = 1; j <= star; j++) {
      colorize("*", color); color++;
      if (color >= 36) color = 31;
    }
    color = 31;
    cout << "\n";
    spase++, star -= 2;
  }

}

void print_tree_1(int n, float speed = 0.9){

  print_star_1(n);
  int color = 31;
   
  // print the first step in the tree
  int star = 1, space = n - 1;
  for(int i = 0; i < n; i++){
   sleep(speed);
    for(int j = 0; j < space; j++) cout << " ";
    for(int j = 0; j < star; j++){
      colorize("*", color);
      color++; 
      if (color >= 36) color = 31;
    }
    cout << "\n";
    star += 2, space --, color = 31;
  }

  color = 31;
  star /= 2, star += 2;
  space = star / 2 - 2;
  // print the secound step in the tree
  for(int i = 0; i < n / 2; i++){
    sleep(speed);
    for(int j = 0; j < space; j++) cout << " ";
    for(int j = 0; j < star; j++){
      colorize("*", color);
      color++; 
      if (color >= 36) color = 31;
    }

    cout << "\n";
    star += 2, space--, color = 31;
  }

  star /= 2, star += 2;
  space = star / 2 - 2;
  color = 31;
  // print the third step in the tree 
  for(int i = 0; i < n / 2; i++){
    sleep(speed);
    for(int j = 0; j < space; j++) cout << " ";
    for(int j = 0; j < star; j++){
      colorize("*", color);
      color++; 
      if (color >= 36) color = 31;
    }
    cout << "\n";
    star += 2, space-- , color = 31;
  }
  
   print_in_end(star); // print the text in the end of the tree
	
}

// print The string slowly
void print_slow(string s){
  for (int i = 0; i < sz(s); i++)
    cout << s[i], sleep(100.0);
}

bool is_good(string s){
  for (int i = 0; i < sz(s); i++)
    if (!isdigit(s[i])) return false;
   return true;   
}

void Accepted(){

  int n = 0;
  string s;
  char c;
  do{

    // print the text in the begining of the program
	  scan : 
	    colorize("", 3);
	    cout << "Enter the number\n";
	    colorize("", 15);
	    cout << "the number should be even and n >= 10\n\n";
	    cin >> s;
	    
	   n = (is_good(s) ? stoi(s) : 0);   
		  
	  if (n < 10){	
        colorize("", 4);
	     // print "invalid number...!" for slow
        print_slow("invalid number...!\a\n"); 
	    	    
	     colorize("", 7);
	     cout << "Enter the number again\n\n";
	    goto scan; // go to scan again if the number is invalid 
	  }

	else if (n % 2 == 0 and n >= 10){
          system("clear"); // clear screen 
          print_tree(n, 100); // print the shape for slow
          system("clear");
        
          print_tree_1(n, 100);
	        system("clear");
	  	   
       // print the shape for fast number of times to make it look like it's moving 
        for (int i = 0; i < 5; i++){ 
            print_tree(n, 1);
            system("clear");  
         }  
	     print_tree(n, 100);
	  }
	   
  	cout << "\n Want to draw again ? [y/n] :  ";
  	cin >> c;
  	cout << '\n';

    // check if the user enter y or n if not print "invalid input...!" and exit the program
    if (tolower(c) != 'y' && tolower(c) != 'n'){
      colorize("", 4);
      print_slow("invalid input...!\n");
      colorize("", 32);
      print_slow("made by : [Gerges Hany]..!\n");
      colorize("", 15);
      exit(0);
    }
   if (tolower(c) == 'y') system("clear"); // clear screen if the user want to try again
  }while(tolower(c) == 'y');


  colorize("", 32);
  print_slow("made by : [Gerges Hany]..!\n");

  //  return color to general color 
  colorize("", 15);
  return;
}

int main()
{ 

  int testcaces = 1;
  // cin >> testcaces;
  while (testcaces--){ 
    Accepted (); 
  }

return 0;
}
