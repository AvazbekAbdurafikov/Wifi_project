#include <Arduino.h>


#include "WiFi.h"
#include <WebServer.h>

const char *ssid = "Redmi";  // Имя вашей точки доступа
const char *password = "noname12";  // Пароль (может быть пустым, если безопасность не требуется)


// Прототип функции handleRoot
void handleRoot();

// Создание объекта сервера на порту 80
WebServer server(80);

void setup() {
  Serial.begin(115200);

  // Настройка и запуск точки доступа
  WiFi.softAP(ssid, password);

  Serial.println();
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());  // Вывод IP-адреса точки доступа

  // Определение маршрута, сервер будет обрабатывать корневой URL "/"
  server.on("/", handleRoot);

  // Начало работы сервера
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Обработка входящих клиентских запросов
  server.handleClient();
}

// Функция для обработки запросов к корню сайта
void handleRoot() {
  String message = "<!DOCTYPE html><html lang='ru'><head><meta charset='UTF-8'><title>TURIN IOT LEGENDS</title></head><body>";
  message += "hello turin!!!!!!!!!!!!";
  message += "</body></html>";

  server.send(200, "text/html", message);  // Отправка ответа клиенту
}