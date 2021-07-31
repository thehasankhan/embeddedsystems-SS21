#include <MI0283QT2.h>
#include <PS2Keyboard.h>

int score;
const int DataPin = 2;
const int IRQpin =  3;

int wordlimit;
String letters[26]={"a", "b", "c", "d", "e", "f","g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
String alphamumeric[36]={"a", "b", "c", "d", "e", "f","g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z","1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
int  randNumber;
String current;
//String sequence="";
char input;

PS2Keyboard keyboard;

MI0283QT2 lcd; 

void setup() {
  // put your setup code here, to run once:

keyboard.begin(DataPin, IRQpin, PS2Keymap_US);
Serial.begin(9600);
randomSeed(analogRead(0));

uint8_t clear_bg=0x00;
lcd.begin();
lcd.setOrientation(0);
lcd.setCursor(0, 0);
score = 0;

//home screen
lcd.fillScreen(RGB(0,0,0));
lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  255,  255,  255));
lcd.fillRoundRect(60, 180, 200, 40, 8, RGB(  255,  0,  0));
lcd.drawRoundRect(60, 180, 200, 40, 8, RGB(  255,  255,  255)); 
lcd.fillRoundRect(60, 130, 200, 40, 8, RGB(  255,  0,  0));
lcd.drawRoundRect(60, 130, 200, 40, 8, RGB(  255,  255,  255));
lcd.fillRoundRect(60, 80, 200, 40, 8, RGB(  255,  0,  0));
lcd.drawRoundRect(60, 80, 200, 40, 8, RGB(  255,  255,  255));
lcd.setCursor(40, 20);
lcd.setTextSize(2);
lcd.setTextColor(RGB(255,0,0));
lcd.print("Typing Challenge");
lcd.setTextColor(RGB(0,0,0), RGB(255,255,255));
lcd.setCursor(100, 195);
lcd.print("3. Help");
lcd.setCursor(95, 145);
lcd.print("2. About");
lcd.setCursor(95, 95);
lcd.print("1. Start");
lcd.setCursor(45, 60);
lcd.setTextColor(RGB(0,0,255), RGB(255,255,255));
lcd.print("Press 1, 2 or 3");

delay(500);

//Setting up home screen

lcd.drawRoundRect(59, 79, 202, 42, 8, RGB(  255,  255,  255));
lcd.drawRoundRect(59, 129, 202, 42, 8, RGB(  0,  0,  0));
lcd.drawRoundRect(59, 179, 202, 42, 8, RGB(  0,  0,  0));
delay(250);

lcd.drawRoundRect(59, 79, 202, 42, 8, RGB(  0,  0,  0));
lcd.drawRoundRect(59, 129, 202, 42, 8, RGB(  255,  255,  255));
lcd.drawRoundRect(59, 179, 202, 42, 8, RGB(  0,  0,  0));
delay(250);

lcd.drawRoundRect(59, 79, 202, 42, 8, RGB(  0,  0,  0));
lcd.drawRoundRect(59, 129, 202, 42, 8, RGB(  0,  0,  0));
lcd.drawRoundRect(59, 179, 202, 42, 8, RGB(  255,  255,  255));
delay(250);

lcd.drawRoundRect(59, 79, 202, 42, 8, RGB(  255,  255,  255));
lcd.drawRoundRect(59, 129, 202, 42, 8, RGB(  255,  255,  255));
lcd.drawRoundRect(59, 179, 202, 42, 8, RGB(  255,  255,  255));
delay(250);

lcd.drawRoundRect(59, 79, 202, 42, 8, RGB(  0,  0,  0));
lcd.drawRoundRect(59, 129, 202, 42, 8, RGB(  0,  0,  0));
lcd.drawRoundRect(59, 179, 202, 42, 8, RGB(  0,  0,  0));

lcd.setCursor(120, 50);
lcd.setTextColor(RGB(0,0,0), RGB(255,255,255));

//Selecting options

while(true){ // remain here until told to break
    if(keyboard.available() > 0) // did something come in?
      if(keyboard.read() == '1'){ // is that something the char 1?
        loop();
        break;
      }

      if(keyboard.read() == '2'){ // is that something the char 2?
      loop2();
      break;
      }

      if(keyboard.read() == '3'){ // is that something the char 3?
      loop3();
      break;
      }
      
}
lcd.print("Nothing was selected");    
delay(1000);
setup();

}

void loop() { //To level select
      lcd.drawRoundRect(59, 79, 202, 42, 8, RGB(  255,  255,  255));
      lcd.drawRoundRect(59, 129, 202, 42, 8, RGB(  0,  0,  0));
      lcd.drawRoundRect(59, 179, 202, 42, 8, RGB(  0,  0,  0));
      delay(300);
      lcd.fillScreen(RGB(0,0,0));
      lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  255,  255,  255));
      lcd.setCursor(40, 20);
      lcd.setTextColor(RGB(0,0,255), RGB(255,255,255));
      lcd.print("Start the game");
      delay(1000);
      lcd.setCursor(10, 100);
      lcd.print("Press 1 for level 1\n\nPress 2 for level 2\n\nPress Y to go back");
            while(true){ // remain here until told to break
              if(keyboard.available() > 0) // did something come in?
                if(keyboard.read() == 'y' || keyboard.read() == 'Y') // is that something the char y or Y?
                {
                setup();
                }
                if(keyboard.read() == '1') // is that something the char 1?
                     { 
                      startgame1();
                     }
                        
                if(keyboard.read() == '2') // is that something the char 1?
                     { 
                      startgame2();
                     }
                
        }
}

void loop2() { //Display about
      lcd.drawRoundRect(59, 79, 202, 42, 8, RGB(  0,  0,  0));
      lcd.drawRoundRect(59, 129, 202, 42, 8, RGB(  255,  255,  255));
      lcd.drawRoundRect(59, 179, 202, 42, 8, RGB(  0,  0,  0));
      delay(300);
      lcd.fillScreen(RGB(0,0,0));
      lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  255,  255,  255));
      lcd.setCursor(120, 20);
      lcd.setTextColor(RGB(0,0,255), RGB(255,255,255));
      lcd.print("About");
      lcd.setCursor(20, 200);
      lcd.print("Do you want to go back? Press Y");
      lcd.setTextColor(RGB(255,255,255), RGB(0,0,0));
      lcd.setTextSize(2);
      lcd.setCursor(10, 60);
      lcd.print("The typing challenge has been ");
      lcd.print("designedby Muhammad Hasan\nKhan");
      lcd.print(" and Ramsha\nMunir under the\nsupervision ");
      lcd.print("of\nMaxmilian Hammer");
      delay(1000);
      while(true){ // remain here until told to break
        if(keyboard.available() > 0) // did something come in?
          if(keyboard.read() == 'y' || keyboard.read() == 'Y'){ // is that something the char y or Y?
          setup();
          }
}
}

void loop3() { //display game guidelines
      lcd.drawRoundRect(59, 79, 202, 42, 8, RGB(  0,  0,  0));
      lcd.drawRoundRect(59, 129, 202, 42, 8, RGB(  0,  0,  0));
      lcd.drawRoundRect(59, 179, 202, 42, 8, RGB(  255,  255,  255));
      delay(300);
      lcd.fillScreen(RGB(0,0,0));
      lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  255,  255,  255));
      lcd.setCursor(120, 20);
      lcd.setTextColor(RGB(0,0,255), RGB(255,255,255));
      lcd.print("Help");
      lcd.setCursor(20, 200);
      lcd.print("Do you want to go back? Press Y");
      lcd.setTextColor(RGB(255,255,255), RGB(0,0,0));
      lcd.setTextSize(2);
      lcd.setCursor(10, 60);
      lcd.print("A series of letterswill be shown to\nyou. Memorize them\n");
      lcd.print("and enter them whenthey disappear from");
      lcd.print("the screen. You winwhen you enter\nthem correctly!\n");
      delay(1000);
      while(true){ // remain here until told to break
        if(keyboard.available() > 0) // did something come in?
          if(keyboard.read() == 'y' || keyboard.read() == 'Y'){ // is that something the char y or Y?
          setup();
          }
}
}
void startgame1(){ // Level 1
      lcd.fillScreen(RGB(0,0,0));
      lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  255,  255,  255));
      lcd.setCursor(100, 20);
      lcd.setTextColor(RGB(0,0,255), RGB(255,255,255));
      lcd.print("Level 1"); 
      delay(2000);

      lcd.fillScreen(RGB(255,255,255));
      lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  0,  0,  0));
      lcd.setOrientation(0);
      lcd.setCursor(55, 20);
      lcd.setTextColor(RGB(0,0,255), RGB(255,255,255));
      lcd.print("Memorize this\n  Sequence");
        String sequence="";
        wordlimit=5;
        char IN[wordlimit];
        char SEQ[wordlimit];
        for (int i=0;i< wordlimit ;i++){ 
          randNumber = random(0, 26);
          current=letters[randNumber];

          sequence+=current;
          delay(50);
          } 
        lcd.setCursor(100, 90);
        lcd.setTextSize(3);
        lcd.setTextColor(RGB(0,0,255), RGB(255,255,255));
        lcd.print(sequence);
        delay(10000);
        sequence.toCharArray(SEQ, wordlimit+1);
        //Serial.println("Enter the words\n");
        lcd.fillScreen(RGB(255,255,255));
        lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  0,  0,  0));
        lcd.setOrientation(0);
        lcd.setCursor(70, 10);
        lcd.setTextSize(2);
        lcd.print("\n Now Guess\n");
        lcd.setOrientation(0);
        lcd.setCursor(60, 60);
        for (int i=0;i< wordlimit ;i++){


          delay(3000);
          if(keyboard.available()){ 
            delay(3000);
            input= keyboard.read();

            if(input==SEQ[i]){//Serial.println("correct next");
              lcd.setTextColor(RGB(0,255,0), RGB(255,255,255));
              lcd.print(input);
              lcd.setTextColor(RGB(0,0,255), RGB(255,255,255));
              lcd.print(" is correct \n");
              score = score +1;
              lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  0,  0,  255));}
            else{
              lcd.setTextColor(RGB(255,0,0), RGB(255,255,255));
              lcd.print(input);
              lcd.setTextColor(RGB(0,0,255), RGB(255,255,255));
              lcd.print(" is incorrect\n   Try again");
              lcd.print("\n\nYour score is: ");
              lcd.print(score);
              lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  255,  0,  0));
              delay(3000); 
              setup();
                 }
              
              
          }
            else{
              lcd.fillScreen(RGB(255,255,255));
              lcd.setOrientation(0);
              lcd.setCursor(10, 20);
              lcd.print("You took too long to make a choice.");
              delay(3000);
              setup();
              } 
        
     
              
          }
        lcd.fillScreen(RGB(255,255,255));
        lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  0,  255,  0));
        lcd.drawRoundRect(0, 0, 317, 238, 8, RGB(  0,  255,  0));
        lcd.setOrientation(0);
        lcd.setCursor(40, 30);
        lcd.setTextSize(2);
        lcd.print("Congratulations, you win!\nYour score is: ");
        lcd.print(score);
        lcd.setCursor(20, 200);
        lcd.print("Do you want to try again? Press Y");
        while(true){ // remain here until told to break
          if(keyboard.available() > 0) // did something come in?
            if(keyboard.read() == 'y' || keyboard.read() == 'Y'){ // is that something the char y or Y?
            startgame1();
          }else break;
}
        delay(3000);
        setup();
}

void startgame2(){ //Level 2
      lcd.fillScreen(RGB(0,0,0));
      lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  255,  255,  255));
      lcd.setCursor(100, 20);
      lcd.setTextColor(RGB(0,0,255), RGB(255,255,255));
      lcd.print("Level 2"); 
      delay(2000);

      lcd.fillScreen(RGB(255,255,255));
      lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  0,  0,  0));
      lcd.setOrientation(0);
      lcd.setCursor(55, 20);
      lcd.setTextColor(RGB(0,0,255), RGB(255,255,255));
      lcd.print("Memorize this\n  Sequence");
        String sequence="";
        wordlimit=7;
        char IN[wordlimit];
        char SEQ[wordlimit];
        for (int i=0;i< wordlimit ;i++){ 
          randNumber = random(0, 36);
          current=alphamumeric[randNumber];

          sequence+=current;
          delay(50);
          } 
        lcd.setCursor(80, 90);
        lcd.setTextSize(3);
        lcd.print(sequence);
        delay(10000);
        sequence.toCharArray(SEQ, wordlimit+1);
        //Serial.println("Enter the words\n");
        lcd.fillScreen(RGB(255,255,255));
        lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  0,  0,  0));
        lcd.setOrientation(0);
        lcd.setCursor(70, 10);
        lcd.setTextSize(2);
        lcd.print("\n Now Guess\n");
        lcd.setOrientation(0);
        lcd.setCursor(60, 60);
        for (int i=0;i< wordlimit ;i++){


          delay(3000);
          if(keyboard.available()){ 
            delay(3000);
            input= keyboard.read();

            if(input==SEQ[i]){
              lcd.setTextColor(RGB(0,255,0), RGB(255,255,255));
              lcd.print(input);
              lcd.setTextColor(RGB(0,0,255), RGB(255,255,255));
              lcd.print(" is correct \n");
              score=score+1;
              lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  0,  0,  255));}
            else{
              lcd.setTextColor(RGB(255,0,0), RGB(255,255,255));
              lcd.print(input);
              lcd.setTextColor(RGB(0,0,255), RGB(255,255,255));
              lcd.print(" is incorrect\n   Try again");
              lcd.print("\n\nYour score is: ");
              lcd.print(score);
              lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  255,  0,  0));
              delay(3000); 
              setup();
                 }
                           
          }
            else{
              lcd.fillScreen(RGB(255,255,255));
              lcd.setOrientation(0);
              lcd.setCursor(10, 20);
              lcd.print("You took too long to make a choice.");
              delay(3000);
              setup();
              } 
                      
          }
        lcd.fillScreen(RGB(255,255,255));
        lcd.drawRoundRect(0, 0, 319, 240, 8, RGB(  0,  255,  0));
        lcd.drawRoundRect(0, 0, 317, 238, 8, RGB(  0,  255,  0));
        lcd.setOrientation(0);
        lcd.setCursor(40, 30);
        lcd.setTextSize(2);
        lcd.print("Congratulations, you win!\nYour score is: ");
        lcd.print(score);
        lcd.setCursor(20, 200);
        lcd.print("Do you want to try again? Press Y");
        while(true){ // remain here until told to break
          if(keyboard.available() > 0) // did something come in?
            if(keyboard.read() == 'y' || keyboard.read() == 'Y'){ // is that something the char y or Y?
            startgame2();
          }else break;
}
        delay(3000);
        setup();
}
