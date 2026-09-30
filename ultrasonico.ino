// Definimos los pines a usar
#define TRIG_PIN 18 
#define ECHO_PIN 19

//Configuramos la tasa de transmisión y los modos de los pines
void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);//TRIG emite el ultrasonido
  pinMode(ECHO_PIN, INPUT);//ECHO lo capta
}

void loop() {
  //Configuramos el loop para emitir ultrasonido por 10 microsegundos
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duracion = pulseIn(TRIG_PIN, HIGH, 3000); //Declaramos una variable que detecte los pulsos 
  
  // Calculamos la distancia con la duración del pulso e imprimimos (Si hay pulso)
  if (duracion == 0){
    Serial.print("No se detectó eco");
  } else {
    float distancia = (0.0343 * duracion) / 2; 

    Serial.print("Duración: ");
    Serial.print(duracion);
    Serial.print(" microsegundos. Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm.");
  }

  delay(500);
}
