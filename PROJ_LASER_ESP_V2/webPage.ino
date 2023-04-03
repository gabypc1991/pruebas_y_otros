void webExc(){
  WiFiClient client = server.available();
  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();         
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
//            read_dht();
//            read_balanza();
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();            
            
            if(header.indexOf("GET /index") >= 0){pagina = "index";}
            if(header.indexOf("GET /factor_cien") >= 0){delay_micro += 1; EEPROM.put(0, delay_micro); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /factor_mil") >= 0){delay_micro += 10; EEPROM.put(0, delay_micro); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /factor_dmil") >= 0){delay_micro += 100; EEPROM.put(0, delay_micro); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /factor_cmil") >= 0){delay_micro += 1000; EEPROM.put(0, delay_micro); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /factor_mcien") >= 0){delay_micro -= 1; EEPROM.put(0, delay_micro); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /factor_mmil") >= 0){delay_micro -= 10; EEPROM.put(0, delay_micro); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /factor_mdmil") >= 0){delay_micro -= 100; EEPROM.put(0, delay_micro); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /factor_mcmil") >= 0){delay_micro -= 1000; EEPROM.put(0, delay_micro); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /2factor_cien") >= 0){delay_micro2 += 1; EEPROM.put(10, delay_micro2); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /2factor_mil") >= 0){delay_micro2 += 10; EEPROM.put(10, delay_micro2); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /2factor_dmil") >= 0){delay_micro2 += 100; EEPROM.put(10, delay_micro2); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /2factor_cmil") >= 0){delay_micro2 += 1000; EEPROM.put(10, delay_micro2); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /2factor_mcien") >= 0){delay_micro2 -= 1; EEPROM.put(10, delay_micro2); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /2factor_mmil") >= 0){delay_micro2 -= 10; EEPROM.put(10, delay_micro2); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /2factor_mdmil") >= 0){delay_micro2 -= 100; EEPROM.put(10, delay_micro2); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /2factor_mcmil") >= 0){delay_micro2 -= 1000; EEPROM.put(10, delay_micro2); EEPROM.commit(); pagina = "index";}
            if(header.indexOf("GET /3factor_cien") >= 0){n_linea += 1; EEPROM.put(20, n_linea); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /3factor_mil") >= 0){n_linea += 10; EEPROM.put(20, n_linea); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /3factor_dmil") >= 0){n_linea += 100; EEPROM.put(20, n_linea); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /3factor_cmil") >= 0){n_linea += 1000; EEPROM.put(20, n_linea); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /3factor_mcien") >= 0){n_linea -= 1; EEPROM.put(20, n_linea); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /3factor_mmil") >= 0){n_linea -= 10; EEPROM.put(20, n_linea); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /3factor_mdmil") >= 0){n_linea -= 100; EEPROM.put(20, n_linea); EEPROM.commit();  pagina = "index";}
            if(header.indexOf("GET /3factor_mcmil") >= 0){n_linea -= 1000; EEPROM.put(20, n_linea); EEPROM.commit(); pagina = "index";}
            if(header.indexOf("GET /edit_hora_1") >= 0){pagina = "edit_hora_1";}
            if(header.indexOf("GET /edit_hora_2") >= 0){pagina = "edit_hora_2";}
            if(header.indexOf("GET /edit_hora_3") >= 0){pagina = "edit_hora_3";}
            if(header.indexOf("GET /edit_hora_4") >= 0){pagina = "edit_hora_4";}
            if(header.indexOf("GET /edit_hora_5") >= 0){pagina = "edit_hora_5";}
            if(pagina == "index"){html_inicio(client);}            

            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop 
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");  
          }
  }

void html_inicio(WiFiClient client){
  // Display the HTML web page
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons 
            // Feel free to change the background-color and font-size attributes to fit your preferences
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}");
            client.println(".button3 { background-color: #AFFF33; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button32 {background-color: #358220;}");
            client.println("table {table-layout: fixed;width: 100%;border-collapse: collapse;border: 3px solid purple;}");
            client.println("th, td {padding: 10px;}");
            client.println(".button4 { background-color: #195B6A; border: none; color: white; padding: 6px 12px;}");
            client.println(".humedad {font-family: Helvetica;color: black;font-size: 18px;text-align: left;font-weight: bold;}");
            client.println(".fechaHora {font-family: Helvetica;color: black;font-size: 18px;text-align: right;}</style></head>");
            

            // Web Page Heading
            client.println("<body><h1>PROJECTOR LASER</h1>");
            client.println("<p class =\"humedad\">Posicion: " + String(delay_micro) + " uS</p>");

             client.println("<table class=\"tabla1\">");
             client.println("<caption>DESPLAZAR IMAGEN</caption>");
             client.println("<tbody>");
             client.println("<tr>");
             client.println("<td></td>");
             client.println("<th>Edit 1</th>");
             client.println("<th>Edit 2</th>");
             client.println("<th>Edit 3</th>");             
             client.println("<th>Edit 4</th>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>1</th>");             
             client.println("<td><a href=\"/factor_cien\"><button class=\"button4\">+1</button></a></td>");
             client.println("<td><a href=\"/factor_mil\"><button class=\"button4\">+10</button></a></td>");
             client.println("<td><a href=\"/factor_dmil\"><button class=\"button4\">+100</button></a></td>");             
             client.println("<td><a href=\"/factor_cmil\"><button class=\"button4\">+1000</button></a></td>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>2</th>");
             client.println("<td><a href=\"/factor_mcien\"><button class=\"button4\">-1</button></a></td>");
             client.println("<td><a href=\"/factor_mmil\"><button class=\"button4\">-10</button></a></td>");
             client.println("<td><a href=\"/factor_mdmil\"><button class=\"button4\">-100</button></a></td>");
             client.println("<td><a href=\"/factor_mcmil\"><button class=\"button4\">-1000</button></a></td>");
             client.println("</tr>");         
             client.println("</tbody>");
             client.println("</table>");

             client.println("<p class =\"humedad\">Posicion 2: " + String(delay_micro2) + " uS</p>");

             client.println("<table class=\"tabla2\">");
             client.println("<caption>DESPLAZAR IMAGEN 2</caption>");
             client.println("<tbody>");
             client.println("<tr>");
             client.println("<td></td>");
             client.println("<th>Edit 1</th>");
             client.println("<th>Edit 2</th>");
             client.println("<th>Edit 3</th>");             
             client.println("<th>Edit 4</th>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>1</th>");             
             client.println("<td><a href=\"/2factor_cien\"><button class=\"button4\">+1</button></a></td>");
             client.println("<td><a href=\"/2factor_mil\"><button class=\"button4\">+10</button></a></td>");
             client.println("<td><a href=\"/2factor_dmil\"><button class=\"button4\">+100</button></a></td>");             
             client.println("<td><a href=\"/2factor_cmil\"><button class=\"button4\">+1000</button></a></td>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>2</th>");
             client.println("<td><a href=\"/2factor_mcien\"><button class=\"button4\">-1</button></a></td>");
             client.println("<td><a href=\"/2factor_mmil\"><button class=\"button4\">-10</button></a></td>");
             client.println("<td><a href=\"/2factor_mdmil\"><button class=\"button4\">-100</button></a></td>");
             client.println("<td><a href=\"/2factor_mcmil\"><button class=\"button4\">-1000</button></a></td>");
             client.println("</tr>");         
             client.println("</tbody>");
             client.println("</table>");
             
             client.println("</body></html>");
             client.println("<p class =\"humedad\">N Linea: " + String(n_linea) + " n</p>");

             client.println("<table class=\"tabla2\">");
             client.println("<caption>numero lineas</caption>");
             client.println("<tbody>");
             client.println("<tr>");
             client.println("<td></td>");
             client.println("<th>Edit 1</th>");
             client.println("<th>Edit 2</th>");
             client.println("<th>Edit 3</th>");             
             client.println("<th>Edit 4</th>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>1</th>");             
             client.println("<td><a href=\"/3factor_cien\"><button class=\"button4\">+1</button></a></td>");
             client.println("<td><a href=\"/3factor_mil\"><button class=\"button4\">+10</button></a></td>");
             client.println("<td><a href=\"/3factor_dmil\"><button class=\"button4\">+100</button></a></td>");             
             client.println("<td><a href=\"/3factor_cmil\"><button class=\"button4\">+1000</button></a></td>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>2</th>");
             client.println("<td><a href=\"/3factor_mcien\"><button class=\"button4\">-1</button></a></td>");
             client.println("<td><a href=\"/3factor_mmil\"><button class=\"button4\">-10</button></a></td>");
             client.println("<td><a href=\"/3factor_mdmil\"><button class=\"button4\">-100</button></a></td>");
             client.println("<td><a href=\"/3factor_mcmil\"><button class=\"button4\">-1000</button></a></td>");
             client.println("</tr>");         
             client.println("</tbody>");
             client.println("</table>");
             
             client.println("</body></html>");
  }
