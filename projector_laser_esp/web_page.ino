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
            if(header.indexOf("GET /calibrar") >= 0){pagina = "calibrar";}
            if(header.indexOf("GET /limite_viento") >= 0){pagina = "limite_viento";}
            if(header.indexOf("GET /factor_cien") >= 0){factorK += 0.01; EEPROM.put(0, factorK); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factor_mil") >= 0){factorK += 0.1; EEPROM.put(0, factorK); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factor_dmil") >= 0){factorK += 1; EEPROM.put(0, factorK); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factor_cmil") >= 0){factorK += 10; EEPROM.put(0, factorK); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factor_mcien") >= 0){factorK -= 0.01; EEPROM.put(0, factorK); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factor_mmil") >= 0){factorK -= 0.1; EEPROM.put(0, factorK); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factor_mdmil") >= 0){factorK -= 1; EEPROM.put(0, factorK); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factor_mcmil") >= 0){factorK -= 10; EEPROM.put(0, factorK); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factort_cien") >= 0){factorKt += 0.01; EEPROM.put(0, factorKt); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factort_mil") >= 0){factorKt += 0.1; EEPROM.put(0, factorKt); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factort_dmil") >= 0){factorKt += 1; EEPROM.put(0, factorKt); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factort_cmil") >= 0){factorKt += 10; EEPROM.put(0, factorKt); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factort_mcien") >= 0){factorKt -= 0.01; EEPROM.put(0, factorKt); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factort_mmil") >= 0){factorKt -= 0.1; EEPROM.put(0, factorKt); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factort_mdmil") >= 0){factorKt -= 1; EEPROM.put(0, factorKt); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factort_mcmil") >= 0){factorKt -= 10; EEPROM.put(0, factorKt); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factorh_cien") >= 0){factorKh += 0.01; EEPROM.put(0, factorKh); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factorh_mil") >= 0){factorKh += 0.1; EEPROM.put(0, factorKh); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factorh_dmil") >= 0){factorKh += 1; EEPROM.put(0, factorKh); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factorh_cmil") >= 0){factorKh += 10; EEPROM.put(0, factorKh); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factorh_mcien") >= 0){factorKh -= 0.01; EEPROM.put(0, factorKh); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factorh_mmil") >= 0){factorKh -= 0.1; EEPROM.put(0, factorKh); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factorh_mdmil") >= 0){factorKh -= 1; EEPROM.put(0, factorKh); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /factorh_mcmil") >= 0){factorKh -= 10; EEPROM.put(0, factorKh); EEPROM.commit(); pagina = "calibrar";}
            if(header.indexOf("GET /viento_min") >= 0){viento_min += 1; EEPROM.put(12, viento_min); EEPROM.commit(); pagina = "limite_viento";}
            if(header.indexOf("GET /vientom_min") >= 0){viento_min -= 1; EEPROM.put(12, viento_min); EEPROM.commit(); pagina = "limite_viento";}
            if(header.indexOf("GET /viento_med") >= 0){viento_med += 1; EEPROM.put(16, viento_med); EEPROM.commit(); pagina = "limite_viento";}
            if(header.indexOf("GET /vientom_med") >= 0){viento_med -= 1; EEPROM.put(16, viento_med); EEPROM.commit(); pagina = "limite_viento";}
            if(header.indexOf("GET /viento_max") >= 0){viento_max += 1; EEPROM.put(20, viento_max); EEPROM.commit(); pagina = "limite_viento";}
            if(header.indexOf("GET /vientom_max") >= 0){viento_max -= 1; EEPROM.put(20, viento_max); EEPROM.commit(); pagina = "limite_viento";}
            if(pagina == "index"){html_inicio(client);}
            if(pagina == "calibrar"){html_calibrar(client);}
            if(pagina == "limite_viento"){html_limite_viento(client);}              

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
            client.println("<body><h1>ESTACION METEOROLOGICA MOVIL ID.002</h1>");
            client.println("<p class =\"humedad\">Humedad: " + String(h) + " %</p>");
            client.println("<p class =\"humedad\">Temperatura: " + String(t) + " C</p>");
            client.println("<p class =\"humedad\">Delta T: " + String(dt, 1) + " u.</p>");
            client.println("<p class =\"humedad\">Viento: " + String(flow_Lmin, 1) + " km.</p>");            
            client.println("<p class =\"humedad\">Condicion para Aplicar: </p>");
            client.println("<td><a href=\"/calibrar\"><button class=\"button\">CALIBRAR</button></a></td>");
            client.println("<td><a href=\"/limite_viento\"><button class=\"button\">LIMITES VIENTO</button></a></td>");
             
            client.println("</body></html>");
  }

 void html_calibrar(WiFiClient client){
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
            client.println("<body><h1>ESTACION METEOROLOGICA MOVIL ID.002</h1>");
            client.println("<p class =\"humedad\">Humedad: " + String(h) + " %</p>");
            client.println("<p class =\"humedad\">Temperatura: " + String(t) + " C</p>");
            client.println("<p class =\"humedad\">Delta T: " + String(dt, 1) + " u.</p>");
            client.println("<p class =\"humedad\">Viento: " + String(flow_Lmin, 1) + " km.</p>");                        
            client.println("<p class =\"humedad\">Factor K viento: " + String(factorK) + " u.</p>");
            client.println("<p class =\"humedad\">Factor K temperatura: " + String(factorKt) + " u.</p>");
            client.println("<p class =\"humedad\">Factor K humedad: " + String(factorKh) + " u.</p>");
            client.println("<td><a href=\"/index\"><button class=\"button\">VOLVER</button></a></td>");

             client.println("<table class=\"tabla1\">");
             client.println("<caption>Calibrar Factor K Viento</caption>");
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
             client.println("<td><a href=\"/factor_cien\"><button class=\"button4\">+0,01</button></a></td>");
             client.println("<td><a href=\"/factor_mil\"><button class=\"button4\">+0,1</button></a></td>");
             client.println("<td><a href=\"/factor_dmil\"><button class=\"button4\">+1</button></a></td>");             
             client.println("<td><a href=\"/factor_cmil\"><button class=\"button4\">+10</button></a></td>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>2</th>");
             client.println("<td><a href=\"/factor_mcien\"><button class=\"button4\">-0,01</button></a></td>");
             client.println("<td><a href=\"/factor_mmil\"><button class=\"button4\">-0,1</button></a></td>");
             client.println("<td><a href=\"/factor_mdmil\"><button class=\"button4\">-1</button></a></td>");
             client.println("<td><a href=\"/factor_mcmil\"><button class=\"button4\">-10</button></a></td>");
             client.println("</tr>");         
             client.println("</tbody>");
             client.println("</table>");

             client.println("<table class=\"tabla2\">");
             client.println("<caption>Calibrar Factor K Temperatura</caption>");
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
             client.println("<td><a href=\"/factort_cien\"><button class=\"button4\">+0,01</button></a></td>");
             client.println("<td><a href=\"/factort_mil\"><button class=\"button4\">+0,1</button></a></td>");
             client.println("<td><a href=\"/factort_dmil\"><button class=\"button4\">+1</button></a></td>");             
             client.println("<td><a href=\"/factort_cmil\"><button class=\"button4\">+10</button></a></td>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>2</th>");
             client.println("<td><a href=\"/factort_mcien\"><button class=\"button4\">-0,01</button></a></td>");
             client.println("<td><a href=\"/factort_mmil\"><button class=\"button4\">-0,1</button></a></td>");
             client.println("<td><a href=\"/factort_mdmil\"><button class=\"button4\">-1</button></a></td>");
             client.println("<td><a href=\"/factort_mcmil\"><button class=\"button4\">-10</button></a></td>");
             client.println("</tr>");         
             client.println("</tbody>");
             client.println("</table>");

             client.println("<table class=\"tabla3\">");
             client.println("<caption>Calibrar Factor K Humedad</caption>");
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
             client.println("<td><a href=\"/factorh_cien\"><button class=\"button4\">+0,01</button></a></td>");
             client.println("<td><a href=\"/factorh_mil\"><button class=\"button4\">+0,1</button></a></td>");
             client.println("<td><a href=\"/factorh_dmil\"><button class=\"button4\">+1</button></a></td>");             
             client.println("<td><a href=\"/factorh_cmil\"><button class=\"button4\">+10</button></a></td>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>2</th>");
             client.println("<td><a href=\"/factorh_mcien\"><button class=\"button4\">-0,01</button></a></td>");
             client.println("<td><a href=\"/factorh_mmil\"><button class=\"button4\">-0,1</button></a></td>");
             client.println("<td><a href=\"/factorh_mdmil\"><button class=\"button4\">-1</button></a></td>");
             client.println("<td><a href=\"/factorh_mcmil\"><button class=\"button4\">-10</button></a></td>");
             client.println("</tr>");         
             client.println("</tbody>");
             client.println("</table>");
             
             client.println("</body></html>");
  }

 void html_limite_viento(WiFiClient client){
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
            client.println("<body><h1>ESTACION METEOROLOGICA MOVIL ID.002</h1>");
            client.println("<p class =\"humedad\">Humedad: " + String(h) + " %</p>");
            client.println("<p class =\"humedad\">Temperatura: " + String(t) + " C</p>");
            client.println("<p class =\"humedad\">Delta T: " + String(dt, 1) + " u.</p>");
            client.println("<p class =\"humedad\">Viento: " + String(flow_Lmin, 1) + " km.</p>");                        
            client.println("<p class =\"humedad\">Viento minimo: " + String(viento_min) + " km.</p>");
            client.println("<p class =\"humedad\">Viento medio: " + String(viento_med) + " km.</p>");
            client.println("<p class =\"humedad\">Viento maximo: " + String(viento_max) + " km.</p>");
            client.println("<td><a href=\"/index\"><button class=\"button\">VOLVER</button></a></td>");

             client.println("<table class=\"tabla1\">");
             client.println("<caption>Viento Minimo</caption>");
             client.println("<tbody>");
             client.println("<tr>");
             client.println("<td></td>");
             client.println("<th>Edit 1</th>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>1</th>");             
             client.println("<td><a href=\"/viento_min\"><button class=\"button4\">+1</button></a></td>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>2</th>");
             client.println("<td><a href=\"/vientom_min\"><button class=\"button4\">-1</button></a></td>");
             client.println("</tr>");         
             client.println("</tbody>");
             client.println("</table>");

             client.println("<table class=\"tabla2\">");
             client.println("<caption>Viento Medio</caption>");
             client.println("<tbody>");
             client.println("<tr>");
             client.println("<td></td>");
             client.println("<th>Edit 1</th>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>1</th>");             
             client.println("<td><a href=\"/viento_med\"><button class=\"button4\">+1</button></a></td>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>2</th>");
             client.println("<td><a href=\"/vientom_med\"><button class=\"button4\">-1</button></a></td>");
             client.println("</tr>");         
             client.println("</tbody>");
             client.println("</table>");

             client.println("<table class=\"tabla3\">");
             client.println("<caption>Viento Maximo</caption>");
             client.println("<tbody>");
             client.println("<tr>");
             client.println("<td></td>");
             client.println("<th>Edit 1</th>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>1</th>");             
             client.println("<td><a href=\"/viento_max\"><button class=\"button4\">+1</button></a></td>");
             client.println("</tr>");
             client.println("<tr>");
             client.println("<th>2</th>");
             client.println("<td><a href=\"/vientom_max\"><button class=\"button4\">-1</button></a></td>");
             client.println("</tr>");         
             client.println("</tbody>");
             client.println("</table>");
             
             client.println("</body></html>");
  }
