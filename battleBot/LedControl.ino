//Color for specific light
void setPixelColor(int pixel, uint8_t red, uint8_t green, uint8_t blue) {
    strip.setPixelColor(pixel, strip.Color(red, green, blue));
    strip.show();
}

void setPixelByName(int pixel, int color[])
{
  strip.setPixelColor(pixel, strip.Color(color[0], color[1], color[2]));
  strip.show();
}

void blink(int pixel) 
{
  for(int i = 0; i < totalBlinks; i++)
  {
    setPixelByName(pixel, ORANGE);
    delay(250);
    setPixelColor(pixel, 255, 255, 255);
    delay(250);
  }
}
