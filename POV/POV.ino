int C[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1};
int I[] = {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1};
int P[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};
int H[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};
int E[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1};
int R[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1};
int S[] = {1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
int a2[] = {1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1};
int a0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int a1[] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1};
int a7[] = {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};

int as[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};



char ch;
int acount = 0;
int letterSpace, loopDelay, dotTime, count;

int x = 1;
void setup()
{
  // setting the ports of the leds to OUTPUT
  Serial.begin(38400);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  dotTime = 2;
  letterSpace = 3;
  loopDelay = 25;
}
void printLetter(int letter[])
{
  int y;

  // printing the first y row of the letter
  for (y = 0; y < 8; y++)
  {
    digitalWrite(y + 2, letter[y]);
  }
  delay(dotTime);

  // printing the second y row of the letter
  for (y = 0; y < 8; y++)
  {
    digitalWrite(y + 2, letter[y + 8]);
  }
  delay(dotTime);

  // printing the third y row of the letter
  for (y = 0; y < 8; y++)
  {
    digitalWrite(y + 2, letter[y + 16]);
  }
  delay(dotTime);

  // printing the 4th y row of the letter
  for (y = 0; y < 8; y++)
  {
    digitalWrite(y + 2, letter[y + 24]);
  }
  delay(dotTime);

  // printing the sspace between the letters
  for (y = 0; y < 8; y++)
  {
    digitalWrite(y + 2, 0);
  }
  delay(letterSpace);
}
void loop()
{
  // you can print your own text by modifing here :)

  if (Serial.available() > 0) {
    ch = Serial.read();
    Serial.println(ch);
    acount = 1;
  }
  if (acount == 1 && ch == 'a') {

    printLetter(C);
    printLetter(I);
    printLetter(P);
    printLetter(H);
    printLetter(E);
    printLetter(R);
    printLetter(as);

    printLetter(a1);
    printLetter(a7);

    printLetter(as);
    printLetter(as);


    if (x == 5500000) {

      delay(loopDelay);
      x = 0;
    }
    else
      x++;
  }
  else if (acount == 1 && ch == 'c')
  {
    acount = 0;
    for (int i = 2; i <= 9; i++) {
      digitalWrite(i, LOW);
    }
  }
}

