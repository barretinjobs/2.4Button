int but = 8;              //porta botão
int state = 0;            //váriavel de leitura do botão

int i = 0;                //variável de impressões do botão
int lasti = 0;            //variável para comparar a impressão anterior com a atual


void setup() {
  
pinMode(but, INPUT);      //determina a porta do botao para receber sinal

Serial.begin(9600);       //liga o serial
Serial.println(i);        //imprime o primeiro valor de "i"

}

void loop() {
state = digitalRead(but); //lê o sinal do botão

 
if (lasti < i){           //impede que o serial fique atualizando com o mesmo valor 
  Serial.println(i);      //imprime quantas vezes o botão foi pressionado no Serial
}


lasti = i;


while (state == LOW){     //cria uma condição de que, para somar uma unidade em "i", precisa primeiro despressionar o botão. Sem isso, "i" fica somando valores ao segurar o botão.
state = digitalRead(but);
  
  if (state == HIGH){
  
    i += 1;
    
    }
  }

}
