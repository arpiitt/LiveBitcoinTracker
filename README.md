# LiveBitcoinTracker
My latest project where I created a real-time Bitcoin price tracker using the Espressif ESP32-C3 module and a 16x2 LCD display. 

Project Highlights:

📊 Working: The project fetches the latest Bitcoin price data using a public API. The ESP32-C3 processes this data and displays it on the LCD screen. You'll be able to see the Bitcoin price right at your fingertips, updating in real time!
💼 Hardware: I utilized the ESP32-C3 module, a powerful microcontroller with Wi-Fi capabilities, and a 16x2 character LCD display. The pins on the ESP32-C3 were cleverly used to control the LCD without I2C communication.
⚡ API: To get the live Bitcoin price, I leveraged the CoinDesk API. This API provides real-time and historical data on Bitcoin prices. The ESP32-C3 fetches this data, processes it, and presents it on the display.
🌐 Technology: Arduino IDE was the go-to platform for coding and development. I had the freedom to manage Wi-Fi connectivity, make HTTP requests to the API, and handle LCD display interactions, all in a single project.

The LCD constantly updates with the most recent Bitcoin price, keeping you informed about the cryptocurrency market trends.
