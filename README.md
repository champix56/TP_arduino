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
