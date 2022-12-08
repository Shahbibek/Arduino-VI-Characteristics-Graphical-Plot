double Vout = 0;
double Current = 0;
const double scale_factor = 0.1;
int ledPin=13;
float R1 = 193.00;



// Constants for A/D converter resolution
// Arduino has 10-bit ADC, so 1024 possible values
// Reference voltage is 5V if not using AREF external reference
// Zero point is half of Reference Voltage

const double vRef = 5.00;
const double resConvert = 1024;
double resADC = vRef/resConvert;
double zeroPoint = vRef/2;


void setup(){ 
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);   
}

void loop(){
  
  // Vout is read 1000 Times for precision
  digitalWrite(ledPin,HIGH);  
  for(int i = 0; i < 1000; i++) {
    Vout = (Vout + (resADC * analogRead(13))*3.25);   
    delay(1);
  }
  
  // Get Vout in mv
  Vout = Vout /1000;
  
  // Convert Vout into Current using Scale Factor
  // Current = ((Vout - zeroPoint)/ scale_factor)/1000000;                   
  Current = (Vout / R1)*1000 ;                   

  // Print Vout and Current to two Current = ");                  

  Serial.print("Vout = ");           
  Serial.print(Vout,2); 
  Serial.print(" Volts");                            
  Serial.print("\t Current = ");                  
  Serial.print(Current,2);
  Serial.println(" mA");                             

  delay(1000); 
 
}