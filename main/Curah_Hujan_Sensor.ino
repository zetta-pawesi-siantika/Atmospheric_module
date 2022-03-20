//Curah hujan adalah jumlah air yang jatuh di permukaan tanah selama periode tertentu yang diukur dengan satuan tinggi milimeter (mm) di atas permukaan horizontal.
//Curah hujan 1 mm adalah jumlah air hujan yang jatuh di permukaan per satuan luas (m2) dengan volume sebanyak 1 liter tanpa ada yang menguap, meresap atau mengalir.
// Lebih lengkap silahkan dipelajari lebih lanjut disini https://www.climate4life.info/2015/12/hujan-1-milimeter-yang-jatuh-di-jakarta.html

//Perhitungan rumus
//Tinggi curah hujan (cm) = volume yang dikumpulkan (mL) / area pengumpulan (cm2)
//Luas kolektor (Corong) 5,5cm x 3,5cm = 19,25 cm2
//Koleksi per ujung tip kami dapat dengan cara menuangkan 100ml air ke kolektor kemudian menghitung berapa kali air terbuang dari tip,
//Dalam perhitungan yang kami lakukan air terbuang sebanyak 70 kali. 100ml / 70= 1.42mL per tip.
//Jadi 1 tip bernilai 1.42 / 19.25 = 0,07cm atau 0.70 mm curah hujan.

// PENTING
// Nilai kalibrasi yang kami lakukan berlaku untuk semua sensor curah hujan yang kami jual tentu Anda dapat melakukan kalibrasi ulang sendiri jika dibutuhkan.

// Gunakan pin D18 pada Arduino Mega, Tegangan 5V Kemudian upload code ini
long int jumlah_tip = 0;
long int temp_jumlah_tip = 0;
float milimeter_per_tip = 0.70;

volatile boolean flag = false;

void hitung_gCurahhujan()
{
  flag = true;
}

void setupCurahhujansensor()
{
  pinMode(CURAHHUJANPIN_INTERUPT, INPUT);
  attachInterrupt(digitalPinToInterrupt(CURAHHUJANPIN_INTERUPT), hitung_gCurahhujan, FALLING); // Akan menghitung tip jika pin berlogika dari HIGH ke LOW
  printSerial();
}

void curahHujan()
{
  if (flag == true) // don't really need the == true but makes intent clear for new users
  {
    gCurahhujan += milimeter_per_tip; // Akan bertambah nilainya saat tip penuh
    jumlah_tip++;
    delay(500);
    flag = false; // reset flag
  }
  gCurahhujan = jumlah_tip * milimeter_per_tip;
  printSerial();
}

void printSerial()
{
 #if defined DEBUG_CURAH_HUJAN || defined DEBUG_ALL
//  Serial.print("Jumlah tip=");
//  Serial.print(jumlah_tip);
//  Serial.println(" kali ");
  Serial.print("Curah hujan=");
  Serial.print(gCurahhujan, 1);
  Serial.print(" mm");
  Serial.println();
  #endif
}
