int reflab;
float u=0.0;
float u_1=0.0;    //Acción de Control
float e=0.0;
float e_1=0.0;
float ref=0.0;
float s0=195.61;  
float s1=-104.44;
int voltaje;
float valor;
unsigned long tiempo;
float tiempo2;
String cadena = "";
String dato = "";
String resta = "";

void setup() {
  
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(9,OUTPUT);

}


void loop() {
  
}

void serialEvent()
{
if(Serial.available())
{
  reflab=Serial.parseInt();
  if(Serial.read()==char(13))
  {
    if(Serial.available())
  {
    
    ref=float(reflab)/1000;
    
   
  tiempo = millis();
  tiempo2 = (float)tiempo / 1000.0;
  voltaje = analogRead(A0);
  
  valor = voltaje * (5.0 / 1023.0);
  
    //Serial.println(cadena);
    
  e=(ref-valor);
  // Controle PID
  u = s0*e + s1*e_1 + u_1 ; //Ley del controlador PID discreto
  //Retorno a los valores reales
  e_1=e;
  u_1=u;
 
 
//Serial.println("error");
//Serial.println(e);
//resta = String(ref)+"-"+String(valor);
//Serial.println("resta");
//Serial.println(resta);
//Serial.println("control");
//
if(u < 0.0){
      
      analogWrite(9,0);
      u_1=0.0;
    }

    else if(u > 11){
    
      analogWrite(9,map(u, 11, 25, 100, 255));
     
     u_1=2;
    }
    
    else
    {
      analogWrite(9,map(u, 0, 10, 20, 255));
     
    }
    cadena = String(ref*100)+"|"+String(valor*100)+"|"+String(e*1000)+"|"+String(u*100);
     Serial.println(cadena);
//    Serial.println(ref);
//    Serial.println(",");
//    Serial.println(valor);
//    Serial.println(",");
//    Serial.println(e);
//    Serial.println(",");
//    Serial.println(u);
  
    delay(50);
    
  }
    }
}
}
  
