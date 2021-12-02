bool ledState = false;
void setup()
{
  // definition du mode de l'I/O
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  digitalWrite(2, ledState);

  // def. de la vitesse du port serie
  Serial.begin(9600);

  // Ecriture sans retour chariot
  Serial.print("Projet 3");

  // Ecriture avec retour chariot
  Serial.println(" ecriture serie");
}

void loop()
{
  // lecture de l'etat de l'entrée
  bool isD3Pushed = digitalRead(3);
  if (isD3Pushed)
  {
    // Ecriture avec retour chariot
    Serial.println("button enfoncé");

    ledState = !ledState;

    // ecriture du nouvel etat d'allumage
    Serial.print("Etat d'allumage : ");
    Serial.println(ledState);

    // attente du relachement du button avant nouveau cycle de loop
    delay(800);
  }
  digitalWrite(2, ledState);
}