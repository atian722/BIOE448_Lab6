const int sensor_pin = 0;
int pulse_signal = 0;
float BPM = 0;

bool any_peak_detected = false;
bool first_peak_detected = false;
unsigned long first_pulse_time = 0;
unsigned long second_pulse_time = 0;

int upper_threshold = 1000;
int lower_threshold = 5;

int pulse_period = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  pulse_signal = analogRead(sensor_pin);
  //Serial.println(pulse_signal);
  delay(50);

  if (pulse_signal > upper_threshold && any_peak_detected ==
  false) {
  any_peak_detected = true;
  // Do something about this peak
    if (first_peak_detected == false) {
      first_pulse_time = millis();
      first_peak_detected = true;
    } 
    else {
      second_pulse_time = millis();
      pulse_period = second_pulse_time - first_pulse_time;
      first_peak_detected = false;

      BPM = 60000/pulse_period;
      Serial.println(BPM);
    }
  }

  if (pulse_signal < lower_threshold) {
  any_peak_detected = false;
  }
}
