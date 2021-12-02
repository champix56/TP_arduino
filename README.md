# TP arduino

# Projet 0

decouverte du code arduino minimum

## 0.1. composants

- Aucun

## 0.2. code

~~~c
    void setup(){
        //code executer au depart de l'execution du code
    }
    void loop(){
        boucle d'execution infinie 
    }
~~~

### 0.2.1. ***void setup ()***

>**fonction obligatoire** pour l'appel de tous les   >constructeurs d'instances diverses.
>
>cette fonction est executer une seul fois au demarrage de la puce

### 0.2.2 ***void loop()***

>**fonction obligatoire** executer en boucle lorsque la puce est allumé. cette fonction commence a etre executé q'une fois le setup achevé

----------

# projet 1 : clignotement d'une LED

clignotement continue d'un Diode electroluminescente

Decouverte des sorties *Tout Ou Rien*.

## 1.1. composants

- arduino uno
- 1x LED
- une resistance *(*facultatif)*

## 1.2. code

~~~c

    void setup() {
        //definition du mode de l'I/O
        pinMode(2, OUTPUT);
    }

    void loop() {
        //ecriture sur le port
        digitalWrite(2, HIGH);
        delay(750);
        digitalWrite(2, LOW);
        delay(750);
    }
~~~

### 1.2.1 ***pinMode(*IOPin*, *digitalValue*)***

Def. du type d'usage d'un port numerique. Cette fonction permet de fixer des resistance a VCC ou GND

- #### *IOPin*

  - Valeur ou nom de l'entrée
    >
    >- 1, 2, ..., 13 : pour les ports digitaux
    >- A0, A1, ..., A5 : pour les ports digitaux. attention certaines cartes possèdent 2 ports CAN en plus (A6 / A7)

- #### *digitalValue*

  - Def. des PULLUP / PULLDOWN res sur les entrées / sorties :
    >
    >- OUTPUT : PULLUP resistance interne sur VCC
    >- INPUT  : PULLDOWN resistance interne sur GND

### 1.2.2. **digitalWrite(*IOPin*, *digitalValue*)**

Ecriture etat numerique HAUT ou BAS *simple et constant ou remplissage cyclique PWM* sur une sortie digital (TOR)

- *IOPin* : [cf. : valeur ou nom de l'entrée](#iopin)
  
- *digitalValue*
  - Valeur à ecrire sur le port : {#digital-value}
    >
    >- HIGH / LOW : etat fixe et constant
    >- 0, 25, ..., 254, 255 : etat de remplissage de cycle PWM, remplissage continu (sur les ports compatible uniquement indiqués par '~' )

## 1.3. Montage

projet1.fzz

![projet 1](./img/projet1.png)

----------

# Projet 2

lecture numerique TOR sans gestion d'interruption, et ecriture en fonction de l'etat de l'entrée

## 2.1. composants

- arduino uno
- 1x push button
- 1x led
- 2x resistances

## 2.2. code

~~~c
    void setup() {
        //definition du mode de l'I/O
        pinMode(2, OUTPUT);
        pinMode(3, INPUT);
    }

    void loop() {
        //lecture de l'etat de l'entrée
        bool isD3Pushed=digitalRead(3);
        if(isD3Pushed){
            digitalWrite(2, HIGH);
        }
        else {
            digitalWrite(2, LOW);
        }
    }
~~~

### 2.2.1. **digitalRead(*IOPin*)**

Lecture d'etat numerique HAUT ou BAS simple sur une entrée numerique (TOR)

- *IOPin* : [cf. : valeur ou nom de l'entrée](#iopin)

## 2.3. montage

projet.fzz
![projet 2](img/projet2.png)

----------

# Projet 3

Découverte de la liaison serie *HardwareSerial*.

Ecriture vers le port serie materiel

## 3. ennoncé

- recuperer et stocker l'etat d'allumage
- stocker & modiffier l'etat d'allumage uniquement lors d'un nouveaux click sur le boutton
- afficher l'etat d'allumage en cas de changement

## 3.1. composants

- arduino uno
- 1x push button
- 1x led
- 2x resistances

## 3.2. code

~~~c
    bool ledState = false;
    void setup()
    {
        // definition du mode de l'I/O
        pinMode(2, OUTPUT);
        pinMode(3, INPUT);
        digitalWrite(2, ledState);

        // def. de la vitesse du port serie
        Serial.begin(9600);

        //Ecriture sans retour chariot
        Serial.print("Projet 3");
        
        //Ecriture avec retour chariot
        Serial.println(" ecriture serie");
    }

    void loop()
    {
        // lecture de l'etat de l'entrée
        bool isD3Pushed = digitalRead(3);
        if (isD3Pushed)
        {
            //Ecriture avec retour chariot 
            Serial.println("button enfoncé");
            
            ledState=!ledState;

            //ecriture du nouvel etat d'allumage
            Serial.print("Etat d'allumage : ");
            Serial.println(ledState);

            //attente du relachement du button avant nouveau cycle de loop
            delay(800);
        }
         digitalWrite(2, ledState);
    }
~~~

### 3.2.1 **Serial.begin(*serialSpeed*)**

Instanciation de l'objet ***Serial*** et ouverture du port serie et def. de la vitesse de transmition.

- *serialSpeed*
  
  Vitesse en bits/sec (bauds)
  
  >- 300, 1200, 2400, 4800, **9600**, 19200, 38400, **57600**, **115200** : valeurs admises. les valeurs en gras (**9600, 57600, 115200**) sont des valeurs standard fortement utilisées

**doc** : [https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/]([https://link](https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/))

### 3.2.2 **Serial.print(*printableValue*) / Serial.println(*printableValue*)**

Ecriture de contenu vers la sortie serie. **Serial.println** ajoute un saut de ligne en fin d'impression de contenu vers la sortie

- *printableValue*
    Contenu imprimable a difuser de n'importe quel type de données
    >
    >- "const char" : chaine de caractere constante
    >- 123 ou 123.45 : entier ou float
    >- *varName* : variable de tous types. les chaines de **char** doivent finir par le caractere **'\0'**

**doc** :

  - [https://www.arduino.cc/reference/en/language/functions/communication/serial/println/]([https://link](https://www.arduino.cc/reference/en/language/functions/communication/serial/println/))
  - [https://www.arduino.cc/reference/en/language/functions/communication/serial/print/]([https://link](https://www.arduino.cc/reference/en/language/functions/communication/serial/print/))

### 3.3. montage

projet.fzz

![alt](img/projet2.png)

### 3.4. doc officiel

- **HarwareSerial** [https://www.arduino.cc/reference/en/language/functions/communication/serial/](https://www.arduino.cc/reference/en/language/functions/communication/serial/)

----------

# Projet 4

Découverte de la liaison serie *HardwareSerial*.

Lecture depuis le port serie materiel

## 4. ennoncé

- base : [projet 3](#projet-3)
- modiffier l'etat d'allumage lors d'une saisie '1' ou 'on' sur le port serie
  - la saisie sera effectuer sans string uniquement par tableau **char [ ]**
- afficher l'etat d'allumage en cas de changement

## 4.1. composants

- arduino uno
- 1x led
- 1x resistances

## 4.2. code

~~~c
bool ledState = false;
void flushSerialInput();
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
  if (Serial.available())
  {
    // attente du remplissage du buffer avant lecture
    delay(100);
    char str[5] = "";
    int i=0;
    //strlen(str)< (taille Max - caractere d'arret de chaine)
    while (Serial.available() && strlen(str) < 4)
    {
      char aChar ='\0';
      aChar=Serial.read();
      //si le caractere recu est imprimable
      if(isPrintable(aChar)){
        str[i++]=aChar;
      }
    }
    //vidange du buffer de lecture
    flushSerialInput();
    str[i]='\0';
    //si la chaine est "on" ou "1"
    if(strcmp(str,'on') || strcmp(str,"1")){
      ledState=true;
    }
    //sinon si la chaine est "off" ou "0"
    else if (strcmp(str,"off")|| strcmp(str,"0"))
    {
        ledState=false;
    }
  }
  digitalWrite(2, ledState);
}
void flushSerialInput(){
  while(Serial.available()){Serial.read();}
}
~~~

### 4.2.1. **Serial.available()**

Fonction qui *retourne le nombre d'octet(s) (caractere(s)) disponible* dans le buffer de reception de la lisaison serie. A chaque execution de lecture sur le buffer le nb disponible descend
    
- **retour** : entier du nb d'octet disponible a la lecture

**doc :**
- [https://www.arduino.cc/reference/en/language/functions/communication/serial/available/](https://www.arduino.cc/reference/en/language/functions/communication/serial/available/)
  
### 4.2.2. **Serial.read()**

Fonction de lecture octet par octet du buffer d'entree de Serial. un equivalent existe pour lire un stringcomplet jusqu'a un retour chariot ***serial.readString()***

- **retour** : premier octet disponible a la lecture ou -1 si aucune valeur existe

**doc :**

- read : [https://www.arduino.cc/reference/en/language/functions/communication/serial/read/](https://www.arduino.cc/reference/en/language/functions/communication/serial/read/)
- readString : [https://www.arduino.cc/reference/en/language/functions/communication/serial/readstring/](https://www.arduino.cc/reference/en/language/functions/communication/serial/readstring/)

### 4.2.3. **isPrintable(aChar)**

fonction de verification de l'existance d'un symbole affichable pour la valeur d'un caractere

- **retour** : vrai si le caractere est imprimable et faux si c'est un caractere de controle non affichable

- *aChar* : un caractere unique à tester

### 4.3. montage

projet.fzz

![alt](img/projet1.png)

----------
