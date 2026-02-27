
// Configurações clinoscópio
const int passosPorBloco = 16; //Quantos passos por bloco, usar multiplos de 4!
const int passosPorRotação = 1024; //Quantos passos por rotação completa 

const float RPM = 0.2; //Velocidade em metros por segundo

const float millisPorPasso = 10; //milissegundos por passo 

const int portasMotorDePasso[4] = {IN1, IN2, IN3, IN4}; //Portas do motor de passo

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

const float MillisPorBloco = passosPorBloco / ((RPM / 60000) * passosPorRotação);

void setup() {
  for (int i = 0; i<4; i++){
    pinMode(portasMotorDePasso[i], OUTPUT);
  }
}

void updMotor(const int pins[], float step){
  int state = int(step) % 4;
  if (state < 0) state += 4;
  
  for (int i = 0; i<4; i++){
    digitalWrite(pins[i], padraoMotor[state][i]);
  }
}

void updMotorForte(const int pins[], float step){
  int state = int(step) % 4;
  if (state < 0) state += 4;
  
  for (int i = 0; i<4; i++){
    digitalWrite(pins[i], padraoMotorForte[state][i]);
  }
}

void pararMotor(const int pins[]){
  for (int i = 0; i<4; i++){
    digitalWrite(pins[i], 0);
  }
}

void loop() {
  unsigned long time = millis();
  unsigned long blocoMs = (unsigned long)MillisPorBloco;
  unsigned long cicle = time % blocoMs;
  
  if (cicle < (unsigned long)(passosPorBloco * millisPorPasso)){
    updMotor(portasMotorDePasso, cicle / (unsigned long)millisPorPasso);
  } else {
    pararMotor(portasMotorDePasso);
  }
}




