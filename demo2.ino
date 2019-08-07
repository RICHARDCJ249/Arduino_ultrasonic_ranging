#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);//设置接口
int light = 6;
//int time = 60;
int echo = 3;
int trig = 2;
int warn = 5;
int jidianqi = 4;
int t = 50;
int tiaojie = 0;
void setup()
{
	pinMode(trig,OUTPUT);
	pinMode(echo, INPUT);
	pinMode(warn, OUTPUT);
	pinMode(jidianqi, OUTPUT);
        pinMode(tiaojie,INPUT);
	lcd.begin(16, 2);
	lcd.clear(); //清屏
	delay(1000); //延时1000ms
}

void loop()
{
	digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(2);
	digitalWrite(trig, LOW);
	float timelengh = float(pulseIn(echo, HIGH));
	float lengh = (timelengh * 17) / 1000;
	analogWrite(light, 110);
	//lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("lenght = ");
	lcd.print(lengh);
	lcd.setCursor(14, 0);
	lcd.print("cm");
        lcd.setCursor(0,1);
        t = analogRead(tiaojie)/5;
        lcd.print("Warn distance:");
        lcd.print(t);
	if (lengh <= t)
	{
		if (lengh <= (t-20))
		{
			digitalWrite(jidianqi, LOW);
		}else{

                digitalWrite(jidianqi, HIGH);
                      }
			for (int x = 0; x < 4; x++)
			{
				digitalWrite(warn, HIGH);
				delay(lengh*3);
				digitalWrite(warn, LOW);
                                delay(lengh*3);

			}
                    
            /*   if(lengh >= (t-20))
               {
                 digitalWrite(jidianqi,LOW);
		}*/
	}
else{

                digitalWrite(jidianqi, HIGH);}
	delay(150);


}
