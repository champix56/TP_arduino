    void setup() {
        //definition du mode de l'I/O
        pinMode(2, OUTPUT);
        pinMode(3, INPUT);
        //def. de la vitesse du port serie
        Serial.begin(9600);
    }

    void loop() {
        //lecture de l'etat de l'entrée
        bool isD3Pushed=digitalRead(3);
        if(isD3Pushed){
            digitalWrite(2, HIGH);
            Serial.println("DIODE allumée");
        }
        else {
            digitalWrite(2, LOW);
            Serial.println("DIODE eteinte");
        }
    }