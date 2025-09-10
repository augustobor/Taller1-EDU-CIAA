#define SPEAKER_PIN 9  // Pin donde está conectado el parlante

void setup() {
    pinMode(SPEAKER_PIN, OUTPUT);  // Configurar el pin como salida
}

void playTone(int frequency, int duration) {
    tone(SPEAKER_PIN, frequency);  // Genera un tono con la frecuencia especificada
    delay(duration);               // Lo mantiene durante el tiempo especificado
    noTone(SPEAKER_PIN);           // Apaga el sonido
}

void loop() {
    // Test 1: Tono de 1000 Hz durante 500ms
    playTone(1000, 500);
    delay(500);  // Espera 500ms antes de repetir

    // Test 2: Tono de 1500 Hz durante 300ms
    playTone(1500, 300);
    delay(500);  // Espera 500ms antes de repetir

    // Test 3: Tono de 2000 Hz durante 200ms
    playTone(2000, 200);
    delay(500);  // Espera 500ms antes de repetir

    // Test 4: Tono de 2500 Hz durante 100ms
    playTone(2500, 100);
    delay(500);  // Espera 500ms antes de repetir

    // Test 5: Frecuencia cambiante de 500 Hz a 3000 Hz en incrementos de 100 Hz
    for (int freq = 500; freq <= 3000; freq += 100) {
        playTone(freq, 100);
        delay(100);  // Espera 100ms antes de cambiar la frecuencia
    }
}
