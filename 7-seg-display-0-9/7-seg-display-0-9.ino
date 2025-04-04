void setup()
{
  //int no=0;
  Serial.begin(9600);
  pinMode(11, OUTPUT);  //a
  pinMode(10, OUTPUT);  //b
  pinMode(9, OUTPUT);  //DP point
  pinMode(8, OUTPUT);  //c
  pinMode(7, OUTPUT);   //d
  pinMode(6, OUTPUT);   //e
  pinMode(12, OUTPUT);   //f
  pinMode(13, OUTPUT);   //g
}

void one(){
  digitalWrite(10, HIGH);
  digitalWrite(8, HIGH);
  delay(2000);
  digitalWrite(10, LOW);
  digitalWrite(8, LOW);
}

void two(){
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(6, HIGH); 
  digitalWrite(7, HIGH);
  delay(2000);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(13, LOW);
  digitalWrite(6, LOW); 
  digitalWrite(7, LOW);
}

void three(){
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(8, HIGH); 
  digitalWrite(7, HIGH);
  delay(2000);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(13, LOW);
  digitalWrite(8, LOW); 
  digitalWrite(7, LOW);
}

void four(){
  digitalWrite(12, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(8, HIGH); 
  delay(2000);
  digitalWrite(12, LOW);
  digitalWrite(10, LOW);
  digitalWrite(13, LOW);
  digitalWrite(8, LOW); 
}

void five(){
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(8, HIGH); 
  digitalWrite(7, HIGH);
  delay(2000);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(8, LOW); 
  digitalWrite(7, LOW);
}

void six(){
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(6, HIGH); 
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  delay(2000);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(6, LOW); 
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
}

void seven(){
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(8, HIGH);
  delay(2000);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW); 
  digitalWrite(8, LOW);
}

void eight(){
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(6, HIGH); 
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(12,HIGH);
  delay(2000);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(13, LOW);
  digitalWrite(6, LOW); 
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(12, LOW);
}

void nine(){
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH); 
  digitalWrite(8, HIGH);
  delay(2000);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW); 
  digitalWrite(8, LOW);
}

void loop()
{
  one();
  //delay(500);
  two();
  //delay(500);
  three();
  four();
  five();
  six();
  seven();
  eight();
  nine();
  //(Serial.available()>0);//{
   //char no;
   //no=Serial.read();
   //Serial.print("no is: ");
   //Serial.print(no);
  //}
  //if (no==char(1)){
   // one();
  //} else{
    //two();
  //}
  //digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  //two();// Wait for 1000 millisecond(s)
  //digitalWrite(LED_BUILTIN, LOW);
  //delay(1000); // Wait for 1000 millisecond(s)
}