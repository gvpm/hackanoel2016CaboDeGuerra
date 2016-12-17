

#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 

int val=90;    // variable to read the value from the analog pin 

int inicio;
int fim;
int buttonPin1= 6;
int buttonPin2= 7;
int button1State;
int button2State;
int ledPin =  13; 
bool released1=true;
bool released2=true;
int step =10;

bool endGame = false;//Jogo termina se tempo acabar, ou se alcancar limite de um dos jogadores
float timeLimit = 30.0;//30s of game

void setup() 
{ 
  Serial.begin(9600); 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  pinMode(buttonPin1, INPUT); 
  pinMode(buttonPin2, INPUT);
  pinMode(ledPin, OUTPUT); 
  inicio=0;
  fim = 179;
  myservo.write(val);
}
 
void loop() 
{ 
  button1State = digitalRead(buttonPin1);
  button2State = digitalRead(buttonPin2);
  
  if ((button1State == HIGH)&&released1&&!endGame) {     
    // turn LED on
    val = val+step;
    released1=false;
    
    
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW); 
  } else if ((button1State == LOW)) {     
    
    released1=true;

  } 
  
  if ((button2State == HIGH)&&released2&&!endGame)  {
    val = val-step;
    released2=false;
  
    digitalWrite(ledPin, HIGH);
    delay(50);
    digitalWrite(ledPin, LOW);
  } 
  
  else if ((button2State == LOW)) 
  {  
    released2=true;
  } 
  
  //bounds
  if(val<inicio){
   val=inicio;
   Serial.println("Jogador 1 ganhou!");
   endGame=true;
  }
  if(val>fim){
   val=fim; 
   Serial.println("Jogador 2 ganhou!");
   endGame=true;
  }
  
 
  
  myservo.write(val); 
  delay(15);
  //Serial.println(released1);
 

  
} 
