/*Rules:
 
The length of a dot is 1 time unit.

A dash is 3 time units.

The space between symbols (dots and dashes) of the same letter is 1 time unit.

The space between letters is 3 time units.

The space between words is 7 time units.

*/
String text = "";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //setting port 13 of arduino as output 
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  
  Serial.println("Enter the text to be converted to Morse:"); //taking inout from user 
  while (Serial.available() == 0)    //waiting till the user enters texts
  {}
  text = Serial.readString();       //reading user inputted string
  Serial.println("ENTERED TEXT:" + text);
  String morse;
  morse=to_morse(text); //calling function to_morse to convert given string into morse
  Serial.println("MORSE TEXT:  " + morse);
  
  Serial.println("\nConverting to morse please wait....\n");
  Serial.println("\n");
  delay(2000);
  Serial.println("\nPLEASE LOOK AT THE LED.....\n");
  Serial.println("\n");
  delay(4000);
  int l=morse.length();
 
  int i;
  for(i=0;i<l-1;i++)     //running loop for every chararacter in morse code we encrypted
  {
    if(morse[i]=='.'){              //if character is a dot(.) then blink the LED for 200ms
      //Serial.println(".");
      digitalWrite(13, HIGH);   
      delay(200);              
      digitalWrite(13, LOW);
      delay(200);  }
    else if(morse[i]=='-'){         //if character is a dash(-) then blink the LED for 600ms
      //Serial.println("-");
      digitalWrite(13, HIGH);   
      delay(600);              
      digitalWrite(13, LOW);
      delay(200);}
    else if(morse[i]==' '){         //if character is a space between each letter (ex: Hello  ~  .... . .-.. .-.. --- ) then off the LED for 600ms to signify end of each letter in a word
      //Serial.println(" ");
      digitalWrite(13, LOW);   
      delay(600);
      }
     else if(morse[i]=='/'){        //if character is a '/' space between words then off the LED for 700ms to signify end of word
      //Serial.println("/");
      digitalWrite(13, LOW);   
      delay(700);   }
    
    }

}

//function to convert text into morse code
String to_morse(String msg){
  //defining all letters and numbers in morse
  String A = ".- ";
  String B = "-... ";
  String C = "-.-. ";
  String D = "-.. ";
  String E = ". ";
  String F = "..-. ";
  String G = "--. ";
  String H = ".... ";
  String I = ".. ";
  String J = ".--- ";
  String K = "-.- ";
  String L = ".-.. ";
  String M = "-- ";
  String N = "-. ";
  String O = "--- ";
  String P = ".--. ";
  String Q = "--.- ";
  String R = ".-. ";
  String S = "... ";
  String T = "- ";
  String U = "..- ";
  String V = "...- ";
  String W = ".-- ";
  String X = "-..- ";
  String Y = "-.-- ";
  String Z = "--.. ";
  String zero = "----- ";
  String one = ".---- ";
  String two = "..--- ";
  String three = "...-- ";
  String four = "....- ";
  String five = "..... ";
  String six = "-.... ";
  String seven = "--... ";
  String eight = "---.. ";
  String nine = "----. ";
  String space = "/";
  
  msg.toUpperCase();  //converting user inputted string into upper case
  Serial.println("TEXT:  "+msg);
  int n=msg.length(); //finding lenght if the user inputtd text
 
  int i;
  String res="";    //declaring "res" variable to store morse code
  
  for(i=0;i<n-1;i++)   //running a for loop for every letter in user inputted text
  {
    if(msg[i]=='A'){                 //if letter is A then append the morse code of letter A to the "res" string
      res=res+A;}
    else if(msg[i]=='B'){            //if letter is B then append the morse code of letter B to the "res" string
      res=res+B;}
    else if(msg[i]=='C'){            //if letter is C then append the morse code of letter C to the "res" string
      res=res+C;}
    else if(msg[i]=='D'){            //if letter is D then append the morse code of letter D to the "res" string
      res=res+D;}
    else if(msg[i]=='E'){            //if letter is E then append the morse code of letter E to the "res" string
      res=res+E;}
    else if(msg[i]=='F'){            //if letter is F then append the morse code of letter F to the "res" string
      res=res+F;}
    else if(msg[i]=='G'){            //if letter is G then append the morse code of letter G to the "res" string
      res=res+G;}
    else if(msg[i]=='H'){            //if letter is H then append the morse code of letter H to the "res" string
      res=res+H;}
    else if(msg[i]=='I'){            //if letter is I then append the morse code of letter I to the "res" string
      res=res+I;}
    else if(msg[i]=='J'){            //if letter is J then append the morse code of letter J to the "res" string
      res=res+J;}
    else if(msg[i]=='K'){            //if letter is K then append the morse code of letter K to the "res" string
      res=res+K;}
    else if(msg[i]=='L'){            //if letter is L then append the morse code of letter L to the "res" string
      res=res+L;}
    else if(msg[i]=='M'){            //if letter is M then append the morse code of letter M to the "res" string
      res=res+M;}
    else if(msg[i]=='N'){            //if letter is N then append the morse code of letter N to the "res" string
      res=res+N;}
    else if(msg[i]=='O'){            //if letter is O then append the morse code of letter O to the "res" string
      res=res+O;}
    else if(msg[i]=='P'){            //if letter is P then append the morse code of letter P to the "res" string
      res=res+P;}
    else if(msg[i]=='Q'){            //if letter is Q then append the morse code of letter Q to the "res" string
      res=res+Q;}
    else if(msg[i]=='R'){            //if letter is R then append the morse code of letter R to the "res" string
      res=res+R;}
    else if(msg[i]=='S'){            //if letter is S then append the morse code of letter S to the "res" string
      res=res+S;}
    else if(msg[i]=='T'){            //if letter is T then append the morse code of letter T to the "res" string
      res=res+T;}
    else if(msg[i]=='U'){            //if letter is U then append the morse code of letter U to the "res" string
      res=res+U;}
    else if(msg[i]=='V'){            //if letter is V then append the morse code of letter V to the "res" string
      res=res+V;}
    else if(msg[i]=='W'){            //if letter is W then append the morse code of letter W to the "res" string
      res=res+W;}
    else if(msg[i]=='X'){            //if letter is X then append the morse code of letter X to the "res" string
      res=res+X;}
    else if(msg[i]=='Y'){            //if letter is Y then append the morse code of letter Y to the "res" string
      res=res+Y;}
    else if(msg[i]=='Z'){            //if letter is Z then append the morse code of letter Z to the "res" string
      res=res+Z;}
    else if(msg[i]=='0'){            //if letter is 0 then append the morse code of letter 0 to the "res" string
      res=res+zero;}
    else if(msg[i]=='1'){            //if letter is 1 then append the morse code of letter 1 to the "res" string
      res=res+one;}
    else if(msg[i]=='2'){            //if letter is 2 then append the morse code of letter 2 to the "res" string
      res=res+two;}
    else if(msg[i]=='3'){            //if letter is 3 then append the morse code of letter 3 to the "res" string
      res=res+three;}
    else if(msg[i]=='4'){            //if letter is 4 then append the morse code of letter 4 to the "res" string
      res=res+four;}
    else if(msg[i]=='5'){            //if letter is 5 then append the morse code of letter 5 to the "res" string
      res=res+five;}
    else if(msg[i]=='6'){            //if letter is 6 then append the morse code of letter 6 to the "res" string
      res=res+six;}
    else if(msg[i]=='7'){            //if letter is 7 then append the morse code of letter 7 to the "res" string
      res=res+seven;}
    else if(msg[i]=='8'){            //if letter is 8 then append the morse code of letter 8 to the "res" string
      res=res+eight;}
    else if(msg[i]=='9'){            //if letter is 9 then append the morse code of letter 9 to the "res" string
      res=res+nine;}
    else if(msg[i]==' '){            //if letter is ' '(SPACE) then append the morse code of SPACE to the "res" string
      res=res+space;}
    
    }
  return res;
  }
