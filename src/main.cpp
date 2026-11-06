#include <Arduino.h>
#include <WiFi.h>
#include <ezTime.h>

// prototipo das funções
// void conexaoWiFi();
// void reconexaoWiFi();

// const char *SSID = "SENAI EDUCACIONAL";
// const char *SENHA = "info@134";

//  const unsigned long tempoConexao = 10000; // 10 seconds
//   const unsigned long tempoReconexao = 5000; // 5 seconds



// void setup() {
//   Serial.begin(115200);

//   conexaoWiFi();
// }

// void loop() {
//   reconexaoWiFi();
// }



// void conexaoWiFi() {
//   Serial.printf("Conectando a rede WiFi: %s", SSID);

//   WiFi.begin(SSID, SENHA);
  
//   unsigned long tempoWifi = millis();

//   while (WiFi.status() != WL_CONNECTED && millis() - tempoWifi < tempoConexao) {
//     delay(500);
//     Serial.print(".");
//   }

//   if (WiFi.status() == WL_CONNECTED) {
//     Serial.println("\nConectado com sucesso!");
//     Serial.print("Endereço IP: ");
//     Serial.println(WiFi.localIP());
//   } else {
//     Serial.println("\nFalha na conexão WiFi.");
//   }
// }


// void reconexaoWiFi() {
//   unsigned long tempoAtual = millis();
//   unsigned long tempoUltimaconexao = 0;

//   if(tempoAtual - tempoUltimaconexao >= tempoReconexao) {
    
//     if (WiFi.status() != WL_CONNECTED)
//      {
//       Serial.println("wifi perdeu a conexão");
//      conexaoWiFi();
//       WiFi.begin(SSID, SENHA);
//      }
//      tempoUltimaconexao = tempoAtual;
//     }


// }




// ----------------timezone---------------------

// void conexaoWiFi();
// void reconexaoWiFi();

// const char *SSID = "SENAI EDUCACIONAL";
// const char *SENHA = "info@134";

//  const unsigned long tempoConexao = 10000; // 10 seconds
//   const unsigned long tempoReconexao = 5000; // 5 seconds


// Timezone sp;


// void setup() {
//   Serial.begin(115200);
//   conexaoWiFi();

//   waitForSync();

//   sp.setLocation("America/Sao_Paulo");

//   Serial.println(sp.dateTime("d/m/Y H:i:s"));
//   // CARACTERES UTEIS
//   // Y -> ANO COMPLETO (2026)
//   // y -> ANO ABREVIADO (26)
//   // m -> MÊS (01-12)
//   // n -> MÊS (1-12)
//   // d -> DIA (01-31)
//   // j -> DIA (1-31)
//   // H -> HORA (00-23)
//   // i -> MINUTO (00-59)
//   // s -> SEGUNDO (00-59)
//   // L -> DIA DA SEMANA (0-6) 0 = DOMINGO
//   // d -> DIA DA SEMANA (1-7) 1 = DOMINGO ABREVIADO
//   // f -> NOME COMPLETO DO MÊS (Janeiro, Fevereiro, Março...)
//   // M -> NOME ABREVIADO DO MÊS (Jan, Fev
//   // A -> AM/PM
//   // T -> SIGLA DO FUSO HORÁRIO (BRT, UTC, GMT...)
//   // Z -> DIA DO ANO (1-365)


//   Serial.println(sp.minute());
//   Serial.println(sp.hour());
//   Serial.println(sp.day());
//   Serial.println(sp.month());
//   Serial.println(sp.year());
//   Serial.println(sp.second());
//   Serial.println(sp.dayOfYear());
//   Serial.println(sp.hourFormat12());
//   Serial.println(sp.isAM());
//   Serial.println(sp.isPM());
// }

// void loop() {
//   reconexaoWiFi();
// }



// void conexaoWiFi() {
//   Serial.printf("Conectando a rede WiFi: %s", SSID);

//   WiFi.begin(SSID, SENHA);
  
//   unsigned long tempoWifi = millis();

//   while (WiFi.status() != WL_CONNECTED && millis() - tempoWifi < tempoConexao) {
//     delay(500);
//     Serial.print(".");
//   }

//   if (WiFi.status() == WL_CONNECTED) {
//     Serial.println("\nConectado com sucesso!");
//     Serial.print("Endereço IP: ");
//     Serial.println(WiFi.localIP());
//   } else {
//     Serial.println("\nFalha na conexão WiFi.");
//   }
// }


// void reconexaoWiFi() {
//   unsigned long tempoAtual = millis();
//   unsigned long tempoUltimaconexao = 0;

//   if(tempoAtual - tempoUltimaconexao >= tempoReconexao) {
    
//     if (WiFi.status() != WL_CONNECTED)
//      {
//       Serial.println("wifi perdeu a conexão");
//      conexaoWiFi();
//       WiFi.begin(SSID, SENHA);
//      }
//      tempoUltimaconexao = tempoAtual;
//     }


// }




void conexaoWiFi();
void reconexaoWiFi();

const char *SSID = "SENAI EDUCACIONAL";
const char *SENHA = "info@134";

const unsigned long tempoConexao = 10000;
const unsigned long tempoReconexao = 5000;

Timezone sp;

void setup() {
  Serial.begin(115200);

  conexaoWiFi();

  sp.setLocation("America/Sao_Paulo");
  waitForSync();
}

void loop() {
  reconexaoWiFi();

  if (WiFi.status() == WL_CONNECTED) {
    events();

    int diasRestantes = 365 - sp.dayOfYear();

    Serial.print("Hoje e ");
    Serial.print(sp.day());
    Serial.print(" de ");

    Serial.print(sp.dateTime("F"));

    Serial.print(" de ");
    Serial.print(sp.year());

    Serial.print(", ");

    // Dias da semana em portugues
    int diaSemana = sp.weekday();

    switch (diaSemana) {
      case 1: Serial.print("Domingo"); break;
      case 2: Serial.print("Segunda-feira"); break;
      case 3: Serial.print("Terca-feira"); break;
      case 4: Serial.print("Quarta-feira"); break;
      case 5: Serial.print("Quinta-feira"); break;
      case 6: Serial.print("Sexta-feira"); break;
      case 7: Serial.print("Sabado"); break;
    }

    Serial.print(" e faltam ");
    Serial.print(diasRestantes);
    Serial.println(" dias para o ano novo.");


    String mes = sp.month();

    switch (mes) {
      case 1: Serial.print("janeiro"); break;
      case 2: Serial.print("fevereiro"); break;
      case 3: Serial.print("março"); break;
      case 4: Serial.print("abril"); break;
      case 5: Serial.print("maio"); break;
      case 6: Serial.print("junho"); break;
      case 7: Serial.print("julho"); break;
      case 8: Serial.print("agosto"); break;
      case 9: Serial.print("setembro"); break;
      case 10: Serial.print("outubro"); break;
      case 11: Serial.print("novembro"); break;
      case 12: Serial.print("dezembro"); break;
    }

    delay(10000);
  }
}

void conexaoWiFi() {
  Serial.printf("Conectando a rede WiFi: %s", SSID);

  WiFi.begin(SSID, SENHA);

  unsigned long tempoWifi = millis();

  while (WiFi.status() != WL_CONNECTED &&
         millis() - tempoWifi < tempoConexao) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConectado com sucesso!");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nFalha na conexao WiFi.");
  }
}

void reconexaoWiFi() {
  static unsigned long tempoUltimaconexao = 0;

  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoUltimaconexao >= tempoReconexao) {
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("WiFi perdeu a conexao!");
      conexaoWiFi();

      if (WiFi.status() == WL_CONNECTED) {
        waitForSync();
      }
    }

    tempoUltimaconexao = tempoAtual;
  }
}