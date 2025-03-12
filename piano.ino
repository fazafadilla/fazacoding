// Pin definitions for piano keys
const int BUZZER_PIN = 3;  // Buzzer pin

// Piano key pins
const int pinC = 2;     // C (Do)
const int pinCS = 4;    // C# (Do#)
const int pinD = 5;     // D (Re)
const int pinDS = 6;    // D# (Re#)
const int pinE = 7;     // E (Mi)
const int pinF = 8;     // F (Fa)
const int pinFS = 9;    // F# (Fa#)
const int pinG = 10;    // G (Sol)
const int pinGS = 11;   // G# (Sol#)
const int pinA = 12;    // A (La)
const int pinAS = 13;   // A# (La#)
const int pinB = A0;    // B (Si)
const int pinC2 = A1;   // C (Do - higher octave)
const int pinCS2 = A2;  // C# (Do# - higher octave)
const int pinD2 = A3;   // D (Re - higher octave)
const int pinDS2 = A4;  // D# (Re# - higher octave)
const int pinE2 = A5;   // E (Mi - higher octave)

// Frequencies for each note
#define NOTE_C4  262   // C4 (middle C)
#define NOTE_CS4 277   // C#4/Db4
#define NOTE_D4  294   // D4
#define NOTE_DS4 311   // D#4/Eb4
#define NOTE_E4  330   // E4
#define NOTE_F4  349   // F4
#define NOTE_FS4 370   // F#4/Gb4
#define NOTE_G4  392   // G4
#define NOTE_GS4 415   // G#4/Ab4
#define NOTE_A4  440   // A4
#define NOTE_AS4 466   // A#4/Bb4
#define NOTE_B4  494   // B4
#define NOTE_C5  523   // C5
#define NOTE_CS5 554   // C#5/Db5
#define NOTE_D5  587   // D5
#define NOTE_DS5 622   // D#5/Eb5
#define NOTE_E5  659   // E5

void setup() {
  // Configure buzzer pin as output
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Configure all piano key pins as inputs with pull-up resistors
  pinMode(pinC, INPUT_PULLUP);
  pinMode(pinCS, INPUT_PULLUP);
  pinMode(pinD, INPUT_PULLUP);
  pinMode(pinDS, INPUT_PULLUP);
  pinMode(pinE, INPUT_PULLUP);
  pinMode(pinF, INPUT_PULLUP);
  pinMode(pinFS, INPUT_PULLUP);
  pinMode(pinG, INPUT_PULLUP);
  pinMode(pinGS, INPUT_PULLUP);
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinAS, INPUT_PULLUP);
  pinMode(pinB, INPUT_PULLUP);
  pinMode(pinC2, INPUT_PULLUP);
  pinMode(pinCS2, INPUT_PULLUP);
  pinMode(pinD2, INPUT_PULLUP);
  pinMode(pinDS2, INPUT_PULLUP);
  pinMode(pinE2, INPUT_PULLUP);
}

void loop() {
  // Check each key and play corresponding note if pressed
  if (digitalRead(pinC) == LOW) {
    tone(BUZZER_PIN, NOTE_C4);
  }
  else if (digitalRead(pinCS) == LOW) {
    tone(BUZZER_PIN, NOTE_CS4);
  }
  else if (digitalRead(pinD) == LOW) {
    tone(BUZZER_PIN, NOTE_D4);
  }
  else if (digitalRead(pinDS) == LOW) {
    tone(BUZZER_PIN, NOTE_DS4);
  }
  else if (digitalRead(pinE) == LOW) {
    tone(BUZZER_PIN, NOTE_E4);
  }
  else if (digitalRead(pinF) == LOW) {
    tone(BUZZER_PIN, NOTE_F4);
  }
  else if (digitalRead(pinFS) == LOW) {
    tone(BUZZER_PIN, NOTE_FS4);
  }
  else if (digitalRead(pinG) == LOW) {
    tone(BUZZER_PIN, NOTE_G4);
  }
  else if (digitalRead(pinGS) == LOW) {
    tone(BUZZER_PIN, NOTE_GS4);
  }
  else if (digitalRead(pinA) == LOW) {
    tone(BUZZER_PIN, NOTE_A4);
  }
  else if (digitalRead(pinAS) == LOW) {
    tone(BUZZER_PIN, NOTE_AS4);
  }
  else if (digitalRead(pinB) == LOW) {
    tone(BUZZER_PIN, NOTE_B4);
  }
  else if (digitalRead(pinC2) == LOW) {
    tone(BUZZER_PIN, NOTE_C5);
  }
  else if (digitalRead(pinCS2) == LOW) {
    tone(BUZZER_PIN, NOTE_CS5);
  }
  else if (digitalRead(pinD2) == LOW) {
    tone(BUZZER_PIN, NOTE_D5);
  }
  else if (digitalRead(pinDS2) == LOW) {
    tone(BUZZER_PIN, NOTE_DS5);
  }
  else if (digitalRead(pinE2) == LOW) {
    tone(BUZZER_PIN, NOTE_E5);
  }
  else {
    noTone(BUZZER_PIN);  // Stop sound if no key is pressed
  }
  
  delay(10);  // Small delay to prevent switch bouncing
}