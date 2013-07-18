  

    boolean lastButton = LOW;
    boolean currentButton = LOW;
    boolean shifting = false;
     
    void setup()
    {
      Serial.begin(57600);
      pinMode(8, INPUT);
    }
     
    boolean debounce(boolean last, int switchPin)
    {
      boolean current = digitalRead(switchPin);
      if (last != current)
      {
        delay(50);
        current = digitalRead(switchPin);
      }
      return current;
    }
     
    void loop()
    {
      if (lastButton == LOW && debounce(lastButton,5))
      {
        Serial.write('q');
      }
      else if (lastButton == LOW && debounce(lastButton,9))
      {
        Serial.write("w");
      }
      else if (lastButton == LOW && debounce(lastButton,8))
      {
        Serial.write("e");
      }
      else if (lastButton == LOW && debounce(lastButton,4))
      {
        Serial.write("a");
      }
      else if (lastButton == LOW && debounce(lastButton,2))
      {
        Serial.write("s");
      }
      else if (lastButton == LOW && debounce(lastButton,7))
      {
        Serial.write("d");
      }
      else if (lastButton == LOW && debounce(lastButton,12))
      {
        Serial.write("z");
      }
      else if (lastButton == LOW && debounce(lastButton,13))
      {
        Serial.write("x");
      }
      else if (lastButton == LOW && debounce(lastButton,10))
      {
        Serial.write("c");
      }
      else if (lastButton == LOW && debounce(lastButton,11))
      {
        Serial.write("v");
        /*shifting = !shifting;
        Serial.print(shifting);
        if (shifting == 1)
        {
          digitalWrite(5,HIGH);
        }
        else
        {
          digitalWrite(5,LOW);
        }*/
      }
      lastButton = currentButton;
      delay(100);
    }

