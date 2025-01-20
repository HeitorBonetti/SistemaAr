// Inicializa a Biblioteca
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Declara variáveis para os Pinos.
int pin8 = 8;
int gasPin = A0; 
int temperaturaPin = A1;
int sensorValue = 0;
int temperaturaValue = 0;

void setup() {
// Inicializa os Pinos e declara como entrada ou saída.
  pinMode(gasPin, INPUT);
  pinMode(temperaturaPin, INPUT);
  pinMode(pin8, OUTPUT);
 // Inicializa o LCD e declara o número de colunas e linhas.
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.display();
}
void loop() {
 // Declara variáveis para os valores dos Sensores
 int sensorValue = analogRead(gasPin);
 int temperaturaValue = analogRead(temperaturaPin);
// Transforma o valor do Sensor de Temperatura em Celsius (ºC)
  float voltagem = temperaturaValue * (5.0 / 1000.0);
  int celsiusValue = (voltagem - 0.5) * 100;
  delay(300);

// Seleciona o Cursor na posição 0,0 e escreve o Valor da Qualidade do Ar.  
  lcd.setCursor(0,0);
  lcd.print ("Indice: ");
  lcd.print (sensorValue);
  lcd.print (" PPM");
 
// Determina a Qualidade do Ar utilizando o número do sensor
  if (sensorValue<=400)
   {
// Seleciona o Cursor na posição 0,1 e descreve o ar.  
   lcd.setCursor(0,1);
   lcd.print("Ar Fresco ");
// Escreve o Valor da Temperatura.  
   lcd.print (celsiusValue)/
   lcd.print (char(178));
   lcd.print ("C   "); 
   }
  else if( sensorValue>=400 && sensorValue<=550 )
   {
// Seleciona o Cursor na posição 0,1 e descreve o ar.  
   lcd.setCursor(0,1);
   lcd.print("Ar Pobre  ");
// Escreve o Valor da Temperatura.  
   lcd.print (celsiusValue);
   lcd.print (char(178));
   lcd.print ("C   "); 
   }
    else if( sensorValue>=550 && sensorValue<=650 )
   {
// Seleciona o Cursor na posição 0,1 e descreve o ar.  
   lcd.setCursor(0,1);
   lcd.print("Ar Nocivo ");
// Escreve o Valor da Temperatura.  
   lcd.print (celsiusValue);
   lcd.print (char(178));
   lcd.print ("C   "); 
   }
  else if (sensorValue>=650 )
   {
// Seleciona o Cursor na posição 0,1 e descreve o ar.  
   lcd.setCursor(0,1);
   lcd.print("Ar Toxico ");
   lcd.print (celsiusValue);
// Escreve o Valor da Temperatura.  
   lcd.print (char(178));
   lcd.print ("C   "); 
   }
  
  if (sensorValue >650) {
    // Ativa Saída Digital
    digitalWrite(pin8, HIGH);
  }
  else {
    // Desativa Saída Digital
    digitalWrite(pin8, LOW);
  }
}
