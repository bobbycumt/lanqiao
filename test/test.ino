String s = "1q2w3e";
void setup()
{
  Serial.begin(115200);
  for (int i = 0; i < s.length(); i++)
  {
      Serial.print(s.charAt(i) + 1);
      Serial.println();
  }
}

void loop()
{
}
