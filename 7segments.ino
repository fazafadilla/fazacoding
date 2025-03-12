// Pin segmen pada Arduino
const int segA = 6;
const int segB = 5;
const int segC = 4;
const int segD = 3;
const int segE = 2;
const int segF = 1;
const int segG = 0;
const int segDP = 12; // Opsional untuk titik desimal (DP), jika digunakan

// Daftar angka (0-9) dalam bentuk biner untuk 7-segment
// Nilai LOW menyalakan segmen, dan HIGH mematikan segmen
const byte angka[10] = {
  B11000000,  // 0
  B11111001,  // 1
  B10100100,  // 2
  B10110000,  // 3
  B10011001,  // 4
  B10010010,  // 5
  B10000010,  // 6
  B11111000,  // 7
  B10000000,  // 8
  B10010000   // 9
};

void setup() {
  // Set setiap pin segmen sebagai output
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segDP, OUTPUT); // Optional, hanya jika DP digunakan
}

void loop() {
  for (int i = 0; i < 10; i++) {
    tampilkanAngka(i);
    delay(1000);  // Tampilkan angka selama 1 detik
  }
}

void tampilkanAngka(int num) {
  digitalWrite(segA, bitRead(angka[num], 0) ? HIGH : LOW);
  digitalWrite(segB, bitRead(angka[num], 1) ? HIGH : LOW);
  digitalWrite(segC, bitRead(angka[num], 2) ? HIGH : LOW);
  digitalWrite(segD, bitRead(angka[num], 3) ? HIGH : LOW);
  digitalWrite(segE, bitRead(angka[num], 4) ? HIGH : LOW);
  digitalWrite(segF, bitRead(angka[num], 5) ? HIGH : LOW);
  digitalWrite(segG, bitRead(angka[num], 6) ? HIGH : LOW);
  digitalWrite(segDP, HIGH);  // Matikan titik desimal (opsional)
}
