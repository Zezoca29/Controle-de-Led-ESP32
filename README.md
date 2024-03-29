# Controle de LED com ESP32

Este é um projeto simples que utiliza um ESP32 para controlar um LED através de uma página web. O estado do LED pode ser alterado remotamente usando a interface web.

## Requisitos

- Hardware:
  - ESP32 Dev Module
  - LED
  - Resistor (opcional, para limitar a corrente do LED)
  - Fios de conexão

- Software:
  - PlatformIO (ou Arduino IDE)
  - Bibliotecas ESPAsyncWebServer e WiFi

## Configuração

1. Clone ou faça o download deste repositório.
2. Abra o projeto na sua IDE (PlatformIO ou Arduino IDE).
3. Configure as credenciais Wi-Fi no código (`ssid` e `password`).
4. Compile e faça o upload do código para o ESP32.

## Uso

1. Conecte-se à rede Wi-Fi configurada no ESP32.
2. Abra o Monitor Serial para obter o endereço IP atribuído ao ESP32.
3. Acesse o ESP32 pelo navegador usando o endereço IP.
4. Você será direcionado para uma página de controle do LED.

## Personalização

- Para adicionar mais funcionalidades, sinta-se à vontade para modificar o código.
- Explore outras bibliotecas do ESP32 para estender as capacidades do projeto.

## Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou pull requests.

## Licença

Este projeto está licenciado sob a [Licença MIT](LICENSE).
