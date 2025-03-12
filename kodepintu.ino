#include <Servo.h>   // Library untuk servo
#include <Keypad.h>  // Library untuk keypad

// Konfigurasi servo
Servo myServo;
const int servoPin = 13; // Pin servo

// Konfigurasi buzzer
const int buzzerPin = 4; // Pin buzzer

// Konfigurasi lampu
const int greenLightPin = 3; // Pin lampu hijau
const int redLightPin = 2;   // Pin lampu merah

// Konfigurasi keypad
const byte ROWS = 4; // Jumlah baris keypad
const byte COLS = 4; // Jumlah kolom keypad
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Pin baris
byte colPins[COLS] = {5, 10, 11, 12}; // Pin kolom

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Kode untuk membuka loker
String correctCode = "1234"; // Kode default
String inputCode = "";

void setup() {
  myServo.attach(servoPin);      // Hubungkan servo
  myServo.write(0);              // Posisi awal servo (terkunci)
  pinMode(buzzerPin, OUTPUT);    // Konfigurasi buzzer
  pinMode(greenLightPin, OUTPUT); // Konfigurasi lampu hijau
  pinMode(redLightPin, OUTPUT);   // Konfigurasi lampu merah
  digitalWrite(buzzerPin, LOW);  // Matikan buzzer
  digitalWrite(greenLightPin, LOW); // Matikan lampu hijau
  digitalWrite(redLightPin, LOW);   // Matikan lampu merah
  Serial.begin(9600); // Untuk debugging
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '#') { // Tombol '#' untuk mengonfirmasi kode
      if (inputCode == correctCode) {
        unlockLocker(); // Fungsi buka loker
      } else {
        wrongCodeAlert(); // Fungsi peringatan
      }
      inputCode = ""; // Reset input kode
    } else if (key == '*') { // Tombol '*' untuk menghapus input
      inputCode = "";
      Serial.println("Input cleared");
    } else {
      inputCode += key; // Tambahkan input ke kode
      Serial.println(inputCode);
    }
  }
}

// Fungsi untuk membuka loker
void unlockLocker() {
  Serial.println("Correct Code! Locker Unlocked.");
  digitalWrite(greenLightPin, HIGH); // Nyalakan lampu hijau
  tone(buzzerPin, 1000, 500);        // Buzzer bunyi sebentar
  myServo.write(90);                 // Servo bergerak membuka
  delay(5000);                       // Tunggu 5 detik
  myServo.write(0);                  // Servo kembali terkunci
  digitalWrite(greenLightPin, LOW);  // Matikan lampu hijau
}

// Fungsi untuk peringatan kode salah
void wrongCodeAlert() {
  Serial.println("Wrong Code!");
  digitalWrite(redLightPin, HIGH); // Nyalakan lampu merah
  for (int i = 0; i < 6; i++) {    // Buzzer bunyi cepat 6 kali
    digitalWrite(buzzerPin, HIGH);
    delay(100);                    // Durasi bunyi
    digitalWrite(buzzerPin, LOW);
    delay(100);                    // Jeda
  }
  digitalWrite(redLightPin, LOW);  // Matikan lampu merah
}
