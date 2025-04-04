// C++ code
//
//7,8,9 + GND  and 
void setup()
{
  pinMode(15, OUTPUT);  
  pinMode(2, OUTPUT);  
  pinMode(14, OUTPUT);  
  pinMode(27, OUTPUT);  
  pinMode(26, OUTPUT);  
  pinMode(25, OUTPUT);   
  pinMode(33, OUTPUT);   
  pinMode(32, OUTPUT); 
  pinMode(35, OUTPUT);  
  pinMode(34, OUTPUT);   
  pinMode(39, OUTPUT);   
  //pinMode(18, OUTPUT);   
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(14, HIGH);
  delay(1000);
  digitalWrite(27, HIGH);
  delay(1000);
  digitalWrite(26, HIGH);
  delay(1000);
  digitalWrite(25, HIGH);
  delay(1000);
  digitalWrite(33, HIGH);
  delay(1000);
  digitalWrite(32, HIGH);
  delay(1000);
  digitalWrite(35, HIGH);
  delay(1000);
  digitalWrite(34, HIGH);
  delay(1000);
  digitalWrite(39, HIGH);
  delay(1000);
  //digitalWrite(, HIGH);

/*
  digitalWrite(11, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(10, LOW);
  delay(1000);
  digitalWrite(8, LOW);
  delay(1000);
  digitalWrite(7, LOW);
  delay(1000);
  digitalWrite(6, LOW);
  delay(1000);
  digitalWrite(12, LOW);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
*/
}