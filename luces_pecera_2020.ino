int LED1 = 9; // PIN LUZ ROJA
int LED2 = 10; // PIN LUZ AZUL
int LED3 = 11; // PIN LUZ VERDE

char DATO = 4;      // variable para almacenar caracter recibido
char NOMBRE[21] = "LUCES_PECERA"; //NOMBRE DE 20 CARACTERES MAXIMO PARA EL BLUETOOTH


void setup() {
   pinMode(7,OUTPUT);
   pinMode(8,OUTPUT);
   pinMode(9,OUTPUT);
   Serial1.begin(9600);
   Serial1.print("AT+NAME");
   Serial1.print(NOMBRE);
    }

int r=200,g=200,b=200,T=10;
bool rojo=true, verde=true, azul=false;   //valores inciales

void loop() {
  while(Serial1.available())
  { DATO = Serial1.read();
    Serial.print("dato recibido es : ");  Serial.write(DATO); Serial.println(" ");
  }

    if (DATO == '1')  { 
      Serial.print("LUZ ROJA \n");//ROJO
    analogWrite(LED1,0);
    analogWrite(LED2,255);
    analogWrite(LED3,255);
    }
    if (DATO == '3')  { 
      Serial.print("LUZ AZUL \n");//AZUL
    analogWrite(LED2,0);
    analogWrite(LED1,255);
    analogWrite(LED3,255);
    }
    if (DATO == '2')  { 
      Serial.print("LUZ VERDE \n");//VERDE
    analogWrite(LED3,0);
    analogWrite(LED1,255);
    analogWrite(LED2,255);
    }
    if (DATO == '5'){  Serial.print("RGB CICLICO \n"); //RGB CICLICO
    for (r=255; r>80; r--){
      analogWrite(LED1,r);
      analogWrite(LED2,g); 
      analogWrite(LED3,b);
      delay(T);   
      }
    for (r=80; r<255; r++){
      analogWrite(LED1,r);
      analogWrite(LED2,g); 
      analogWrite(LED3,b);   
      delay(T);
      }    
    for (g=255; g>80; g--){
      analogWrite(LED1,r);
      analogWrite(LED2,g); 
      analogWrite(LED3,b);   
      delay(T);
      }
    for (g=80; g<255; g++){
      analogWrite(LED1,r);
      analogWrite(LED2,g); 
      analogWrite(LED3,b);   
      delay(T);
      }    
    for (b=255; b>80; b--){
      analogWrite(LED1,r);
      analogWrite(LED2,g); 
      analogWrite(LED3,b);   
      delay(T);
      }
    for (b=80; b<255; b++){
      analogWrite(LED1,r);
      analogWrite(LED2,g); 
      analogWrite(LED3,b);   
      delay(T);
      }   
    }
    if (DATO == '4'){   //APAGADOS
      Serial.print("APAGADOS \n");//AZUL
      analogWrite(LED1,255);
      analogWrite(LED2,255); 
      analogWrite(LED3,255);   
    }
    delay (T*10); 
  }
