int guess = 200;
int randomN;
int counter =0;
int buttonPin8 = 8;
int buttonPin9 = 9;
int buttonPin10 = 10;

int buttonStateTest = 0;         
int lastButtonStateTest = 0;     

int buttonStateTrue = 0; 
int lastButtonStateTrue = 0;

int buttonStateFalse = 0;
int lastButtonStateFalse = 0;

void win();
void correctGuess();
void statusShow();
void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, INPUT);
  randomSeed(analogRead(0));
  
  randomN =random(2);
  Serial.print("First random number: ");
  Serial.print(randomN);
  Serial.println("\nRest random numbers");
  delay(1000);
  digitalWrite(13, HIGH);
  delay(2000);
   digitalWrite(13, LOW);
  delay(1000);
  
}

void loop(){
  
 statusShow(randomN, guess);
 
 buttonStateTest = digitalRead(buttonPin8);
  if (buttonStateTest != lastButtonStateTest) {
    if (buttonStateTest == HIGH) {
     counter++;
    }
  }
  lastButtonStateTest = buttonStateTest;
 
  
  buttonStateTrue= digitalRead(buttonPin9);
  if (buttonStateTrue != lastButtonStateTrue) {
    if (buttonStateTrue == HIGH) {
    guess = 1;
    }
  }
  lastButtonStateTrue = buttonStateTrue;
  
    
  buttonStateFalse= digitalRead(buttonPin10);
  if (buttonStateFalse != lastButtonStateFalse) {
    if (buttonStateFalse == HIGH) {
    guess = 0;
    }
  }
  lastButtonStateFalse = buttonStateFalse;
  
  if(guess == randomN){
  correctGuess(13);
  
    guess = 999;
    counter++;
    randomN=random(2);
  }else if(guess != randomN && guess != 999){
    digitalWrite(13, LOW);
    counter = 0;
    guess = 999;
    randomN=random(2);
 
  }

  if(counter == 0){
     digitalWrite(2, LOW);  
     digitalWrite(3, LOW);
     digitalWrite(4, LOW);
  }
  

  if(counter == 1){
    digitalWrite(2, HIGH);
  }else if(counter == 2){
     digitalWrite(2, HIGH); 
     digitalWrite(3, HIGH);
    }else if(counter == 3){
   digitalWrite(2, HIGH); 
     digitalWrite(3, HIGH);
     digitalWrite(4, HIGH);
     randomN=random(2);
     win(2,3,4);
 
    counter = 4;
    }else if(counter >=4){
    counter = 0;
    }
 
}


void win(int i, int j, int k){

   
     digitalWrite(i, LOW);  
     digitalWrite(j, LOW);
     digitalWrite(k, LOW);
     delay(200);
     digitalWrite(i, HIGH); 
     digitalWrite(j, HIGH);
     digitalWrite(k, HIGH);
     delay(200);
     digitalWrite(i, LOW);  
     digitalWrite(j, LOW);
     digitalWrite(k, LOW);
     delay(200);
     digitalWrite(i, HIGH); 
     digitalWrite(j, HIGH);
     digitalWrite(k, HIGH);
     delay(200);
     digitalWrite(i, LOW);  
     digitalWrite(j, LOW);
     digitalWrite(k, LOW);
     delay(200);
}

void correctGuess(int i){

digitalWrite(i, HIGH);
  delay(80);
  digitalWrite(i, LOW);
  delay(80);
   digitalWrite(i, HIGH);
  delay(80);
  digitalWrite(i, LOW);
  
}

void statusShow(int random, int guess){

 Serial.print("Now random is: ");
 Serial.print(random);
 Serial.print(" | The guess is: ");
 Serial.print(guess); 
 Serial.print("\n");
 delay(100);

}
