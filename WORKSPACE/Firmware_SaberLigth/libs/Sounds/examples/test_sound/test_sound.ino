#define SPEAKER_PIN 9  // Pin donde está conectado el parlante

void setup() {
    pinMode(SPEAKER_PIN, OUTPUT);  // Configurar el pin como salida
}

void loop() {
    tone(SPEAKER_PIN, 1000);  // Genera un tono de 1000 Hz
    delay(500);               // Lo mantiene durante 500ms
    noTone(SPEAKER_PIN);      // Apaga el sonido
    delay(500);               // Espera 500ms antes de repetir
}
