int sinal=3; 
float distancia;
void leitura();

void setup()
{
  Serial.begin(9600);
  pinMode(sinal, OUTPUT); //aciona a porta do sensor
  digitalWrite(sinal , LOW);
 pinMode(5, OUTPUT); //aciona a porta do led
   
}

void loop()
{leitura();
 distancia=distancia/2; //divide o valor por 2 por ser a ida e a volta
 distancia=distancia*0.034; //a distancia tem Velocidade do som 340 m/s ,multiplicando pelo tempo teremos CM/S
  Serial.println(distancia); //programa nosso vibrador , aqui no caso o led
  delay(100);
 if(distancia>=10 && distancia<=300){
    digitalWrite(5,HIGH);
 }
 else
    digitalWrite(5,LOW);
}

void leitura(){
//aqui mandamos o sinal
pinMode(sinal, OUTPUT);
digitalWrite(sinal, HIGH);
delayMicroseconds(5);
digitalWrite(sinal, LOW);
//aqui recebemos o sinal
pinMode(sinal, INPUT);
distancia=pulseIn(sinal, HIGH);
}