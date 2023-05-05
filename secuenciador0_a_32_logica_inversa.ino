int soldador = 2;
int luz_led = 3;
int luz_halogena = 4;
int ordenador = 5;
int ventilador = 6;

unsigned long tiempoEncendidoTotal = 0; // tiempo total que se va invirtiendo en milisegundos

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando ..");
 
  pinMode(soldador, OUTPUT);
  pinMode(luz_led, OUTPUT);
  pinMode(luz_halogena, OUTPUT);
  pinMode(ordenador, OUTPUT);
  pinMode(ventilador, OUTPUT);
  
  randomSeed(analogRead(A0));


  digitalWrite(soldador, HIGH); // apaga el soldador
    digitalWrite(luz_led, HIGH); // apaga la luz LED
 digitalWrite(luz_halogena, HIGH); // apaga la luz halógena
   digitalWrite(ordenador, HIGH); // apaga el ordenador
digitalWrite(ventilador, HIGH); // apaga el ventilador


 delay (1000);
}

void loop() {
  long tiempo_pausa = random(10000, 60000); // tiempo aleatorio entre 10 y 60 segundos en milisegundos
  int dispositivo = random(0, 33); // número aleatorio entre 0 y 32
  Serial.print("Numero generado: ");
  Serial.println(dispositivo);
  String binaryString = String(dispositivo, BIN);
     Serial.print("Cadena:");
      Serial.println(binaryString);
      
  

   

  if (dispositivo & (1 << 0)) { // verifica si el bit 0 está activado
    digitalWrite(soldador, LOW); // enciende el soldador
    Serial.println("Soldador encendido");
  } else {
    digitalWrite(soldador, HIGH); // apaga el soldador
  }

  if (dispositivo & (1 << 1)) { // verifica si el bit 1 está activado
    digitalWrite(luz_led, LOW); // enciende la luz LED
    Serial.println("Luz LED encendida");
  } else {
    digitalWrite(luz_led, HIGH); // apaga la luz LED
  }

  if (dispositivo & (1 << 2)) { // verifica si el bit 2 está activado
    digitalWrite(luz_halogena, LOW); // enciende la luz halógena
    Serial.println("Luz halógena encendida");
  } else {
    digitalWrite(luz_halogena, HIGH); // apaga la luz halógena
  }

  if (dispositivo & (1 << 3)) { // verifica si el bit 3 está activado
    digitalWrite(ordenador, LOW); // enciende el ordenador
        Serial.println("Ordenador encendido");
  } else {
    digitalWrite(ordenador, HIGH); // apaga el ordenador
  }

  if (dispositivo & (1 << 4)) { // verifica si el bit 4 está activado
    digitalWrite(ventilador, LOW); // enciende el ventilador
       Serial.println("Ventilador encendido");
  } else {
    digitalWrite(ventilador, HIGH); // apaga el ventilador
  }



 
long tiempoEncendido = random(6000, 300000); //genera un número aleatorio entre 1 minuto (60000ms) y 5 minutos (300000ms)
  
Serial.print("Tiempo encendido nuevo estado: ");
Serial.println(tiempoEncendido/1000);


 Serial.print(" Tiempo de pausa tras nuevo estado: ");
  Serial.print(tiempo_pausa/1000); // muestra el tiempo en segundos
  Serial.println(" segundos");

  tiempoEncendidoTotal += tiempoEncendido;
  unsigned long tiempoAcumulado = tiempoEncendidoTotal / 1000;
  unsigned int horas = tiempoAcumulado / 3600;
  unsigned int minutos = (tiempoAcumulado % 3600) / 60;
  unsigned int segundos = tiempoAcumulado % 60;

 

delay(tiempoEncendido); //espera el tiempo aleatorio generado


  

  
  digitalWrite(soldador, HIGH);
  digitalWrite(luz_led, HIGH);
  digitalWrite(luz_halogena, HIGH);
  digitalWrite(ordenador, HIGH);
  digitalWrite(ventilador, HIGH);

  




  delay(tiempo_pausa);
   Serial.print("Tiempo encendido total: ");
  Serial.print(horas);
  Serial.print(":");
  if (minutos < 10) {
    Serial.print("0");
  }
  Serial.print(minutos);
  Serial.print(":");
  if (segundos < 10) {
    Serial.print("0");
  }
  Serial.println(segundos);
}
