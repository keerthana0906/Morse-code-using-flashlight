int input_val = 0; //value from ldr sensor
int cnt=0;   //cnt variable to identify no.of continous light intensities. It helps to identify end of morse code.
String morse="";             //for noting the light intensity values of ldr sensor values 
String morse_code="";
String final_text="";

//morse dictionary in morse1 array and their respective characeters in texts array
char *morse1[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----","/"};  
char *texts[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","1","2","3","4","5","6","7","8","9","0"," "};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Use torch or flash and show the morse code");
}

void loop() {
       
 input_val = analogRead(A0); //read the LDR value from A0 port 
 //Serial.println(input_val);
  if(input_val>500)
  {                       //if the intensity of light is more (greatr than 600) then append 'H' (high) to string
      morse=morse+"H";
      cnt=0;              //if we get a high intensity from sensore means user is still passing morse signal. So make cnt variable 0.
  }
  else
  {                      //if the intensity of light is less then append 'L' (low) to string
     morse=morse+"L";
     cnt=cnt+1;          //keep increasing cnt variable is light intensity is low
  }
  
    if(cnt==20)            //if we get more than 15 continous low signals then possibility user has completed morse code . So wait for 5 more transmissions to make sure and then move to next steps
    {  
        Serial.println("RECEIVED SIGNAL ....PLEASE WAIT CONVERTINF THE SIGNAL....");
        delay(2000); 
        //Serial.println(morse);
        morse_code=to_morse(morse);  //the morse string now has letters L and H where L represents low intensity(light off) and H represents high intensity (light on). We are passing this string to be converted into morse code
        Serial.print("MORSE CODE : ");
        Serial.println(morse_code);
        final_text=to_text(morse_code+" "); //after getting the morse code from to_morse function send it to to_text function to convert it to required text
        Serial.print("Morse signal Output : ");
        Serial.println(final_text);
    }
  delay(400);

  
  
}


String to_morse(String string) //input format ex: "LLHLHLHLLLHHHLHHHLHHHLLLHLHLHLLLLLLLLLLLLLLLLLLLL" OUTPUT : "... --- ..."
{
  Serial.print("Signal received : ");
  Serial.println(string);
  int n,i;
  int start,ending;   //starting and ending "L" (lows) in signal here string are not useful so we only have to operate on the first to last "H"(high) positions of the string
  n=string.length();
  for(i=0;i<n;i++)    //finding  which position has the first "H"
  {
   if(string[i]=='H')
   {
     start=i;
     break;
    } 
   }

ending=n-20-1;// as we saw always at the end there will be 20 'L' characters as we stop considering the inputs after 20 continous low signals

int stp=-1;   //to specify when to stop the while loop
int pos=start; //declaring and initialising pos variable variable to start
String morse_string=""; //this string consists of the morse code we need which we will later convert into text
while(stp==-1)
{ 
  int k;
  k=count(string,pos,ending); //to count no.of continous 'H' or 'L' we call count function
  //conditions for dot dash space
  if(string[pos]=='H' && k==1 || string[pos]=='H' && k==2)      //if there are either 1 or 2 contious H then consider it as dot (.) (for more precision we consider one or two high signals to be dot)
  {
    morse_string=morse_string+'.'; 
  }

  else if(string[pos]=='L' && k==1 || string[pos]=='L' && k==2) //if there are either 1 or 2 contious L then consider it as space between dot and das of same letter so need to append anything to string
   {
     morse_string=morse_string;
   }

   else if(string[pos]=='H' && k==3 || string[pos]=='H' && k==4) //if there are either 3 or 4 contious H then consider it as dash (-)
   {
     morse_string=morse_string+'-'; 
   }
   else if(string[pos]=='L' && k==3 || string[pos]=='L' && k==4) //if there are either 3 or 4 contious L then consider it as space between letters of same word 
   {
     morse_string=morse_string+' '; 
   }
    else if(string[pos]=='L' && k>4)                             //if there are more than 4 continous L consoder it as space between two words
   {
     morse_string=morse_string+" / "; 
   }
  pos=pos+k;
  if(pos>ending)// if the pos varible exceeds the the ending lenght of the strign then sto pthe while loop by setting stp=1
  stp=1;
}
 
 return morse_string; 
  
}


int count(String s,int p,int ending) //to count no.of contious H or L in the signal
{
  int cnt=0;
  int i;
  if(s[p]=='H')
  {
    for(i=p;i<=ending;i++)
    {
      if(s[i]=='H')
      {
        cnt=cnt+1;
        }
       else
       break;
    }
  }

  else if(s[p]=='L')
  {
    for(i=p;i<=ending;i++)
    {
      if(s[i]=='L')
      {
        cnt=cnt+1;
        }
       else
       break;
    }
  }

  return cnt;
}


String to_text(String m)     //to convert the morse code to text
{
  int i=0,l,j;
  String text="";  //to store the result and return it back
  l=m.length();
 
  String alphanumeric_char=""; //for loading each morse string and comparing it with each letter morse string presnt in the morse1 array
  for(i=0;i<l;i++)          //for loop for each character in morse code
  {
   if(m[i]!=' ')            //to append each dot and dash to the alphnumeric_char variable until a space ' ' appear. ' ' indicates space between letters of a word 
   {
    alphanumeric_char=alphanumeric_char+m[i];
   }
   else                   //if it is a spaace it means alphanumeric_char contains a letters morse code so check which letter it is
   {
    int flag=0;   
    for(j=0;j<37;j++)    //there are 37 letters morse morse strings oresent in morse1 array . Check which letter is matching
    {
      if(String(morse1[j])==alphanumeric_char)
      {
        flag=1;
        text=text+String(texts[j]);   //if the morse string morse1 array and the alphnumeric_char match then make flag 1 and append the corresponding english letter/number to the text 
        break;
      }
    }
     alphanumeric_char=""; //clear the alphanumeric_char after checking whcih letter it is
    if(flag!=1)  //if it doesnt match with any string in morse1 then print nit a valid morse code
    {
    Serial.println("Not Valid Morse Code");
    return "Not Valid Morse Code";
    }
   }
  }
  //Serial.println(text);
  return text;
}
