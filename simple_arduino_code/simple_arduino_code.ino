
// Configurações clinoscópio
const int passosPorBloco = 16; //Quantos passos por bloco, usar multiplos de 4!
const int passosPorRotacao = 1024; //Quantos passos por rotação completa 

float RPM = 3; //Velocidade em rotações por minuto

const float millisPorPasso = 15; //milissegundos por passo 

const int portasMotorDePasso[4][4] = {
  {4, 5, 6, 7},
  {8, 9, 10, 11},
  {22, 24, 26, 28},
  {30, 32, 34, 36}
}; //Portas dos motores de passo

// Código
const int padraoMotor[4][4] = {
  {1, 0, 0, 0},
  {0, 1, 0, 0},
  {0, 0, 1, 0},
  {0, 0, 0, 1}
};

const int padraoMotorForte[4][4] = {
  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1}
};



void setup() {
  for (int i = 0; i<4; i++){
    pinMode(portasMotorDePasso[i], OUTPUT);
  }
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);

  Serial.begin(9600);
}

void updMotor(float step){
  int state = int(step) % 4;
  if (state < 0) state += 4;
  
  for (int i = 0; i<4; i++){
    for (int j = 0; j<4; j++){
      digitalWrite(portasMotorDePasso[j][i], padraoMotor[state][i]);
    }
  }
}

void updMotorForte(float step){
  int state = int(step) % 4;
  if (state < 0) state += 4;
  
  for (int i = 0; i<4; i++){
    for (int j = 0; j<4; j++){
      digitalWrite(portasMotorDePasso[j][i], padraoMotorForte[state][i]);
    }
  }
}

void pararMotor(){
  for (int i = 0; i<4; i++){
    for (int j = 0; j<4; j++){
      digitalWrite(portasMotorDePasso[j][i], 0);
    }
  }
}

int configVelocidade(){
  int max = 0;
  int speed = 0;
  int count = 0;
  for (int p = 0; p<9; p++){
    int v = analogRead(A0 + p);
    if (v > max){
      max = v;
      speed = p;
    }
  }
  if(max < 1000){
    speed = 0;
  }
  return speed;
}

void loop(){
  RPM = configVelocidade() * 0.5;
  float MillisPorBloco = passosPorBloco / ((RPM / 60000) * passosPorRotacao);
  unsigned long time = millis();
  unsigned long blocoMs = (unsigned long)MillisPorBloco;
  unsigned long cicle = time % blocoMs;

  


  
  if (cicle < (unsigned long)(passosPorBloco * millisPorPasso)){
    updMotor(cicle / (unsigned long)millisPorPasso);
  } else {
    pararMotor();
  }
}




