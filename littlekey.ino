/*
Keyer
*/

//Morse Characters 
char MChar[43] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?/-&";
String Keys[43] = {".-","-...","-.-.","-..",".","..-.","--.","....",
                "..",".---","-.-",".-..","--","-.","---",".--.",
                "--.-",".-.","...","-","..-","...-",".--","-..-",
                "-.--","--..","-----",".----","..---","...--",
                "....-",".....","-....","--...","---..","----.",
                ".-.-.-","--..--","..--..","-..-.","-....-",".-..."};
                
const int PIN_DIT = 6;
const int PIN_DAH = 5;
const int PIN_SPEAKER = 10;

int dit_length = 80;
int dah_length = dit_length * 3;
int wpm = 20;
int tone_freq = 1000;

//button flags
int dit_pushed = 0;
int dah_pushed = 0;

//timers
int last_char = 0;
int last_word = 0;

//incoming keys
String GetKeyFromChar (String chars){

  return Keys[0];
} 

char GetCharFromKey(String chars) {
  
  
  return chars.charAt(0);
  
}

void SendChars(String chars) {
  for (auto c : chars){
    
  }
}

void Flash(int length) {
  digitalWrite(LED_BUILTIN,HIGH);
  delay (length);
  digitalWrite(LED_BUILTIN, LOW);
}

void Dit() {
  tone(PIN_SPEAKER,tone_freq, dit_length);
  Flash(dit_length);
}

void Dah() {
  tone(PIN_SPEAKER,tone_freq, dah_length);
  Flash(dah_length);
}

void ReadDitDahPins(){
  dit_pushed = digitalRead(PIN_DIT);
  dah_pushed = digitalRead(PIN_DAH);
}

void setup() {
 
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_DIT, INPUT_PULLUP);
  pinMode(PIN_DAH, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(PIN_DIT), ReadDitDahPins, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_DAH), ReadDitDahPins, CHANGE);
  
  
  Serial.begin(9600); 
  delay(1000);

  //test
  Dit();
  delay (dit_length);
  Dah();
  delay (dit_length);

  //print all charaters and keys
  Serial.println("Morse Code");
  Serial.println("---------------------------");
  for (int i=0; i<42; i++) {
     Serial.print(MChar[i]);
     Serial.print(" = "); 
     Serial.println(Keys[i]); 
  }

}

void loop() {

  if (dit_pushed == LOW){
    Dit();
    delay(dit_length);
  }

  if (dah_pushed == LOW){
    Dah();
    delay(dit_length);
  } 
  
}
