#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
char str[128];
float b;
  while (scanf("%s" , str))
	{

	if (!strcmp(str, "\"temperature\":"))
		{
		scanf("%f", &b);
		printf("%f \n",b);
		}
	if (b<0)
	{
	}

		else
		{
			if (b>= 10,0)
			{
		system ("mosquitto_pub -h  \"10.96.4.11\" -t \"devices/lora/807B85902000069B/gpio\" -m \"set 1 1\" -q 1");
			}
			else
			{
		system ("mosquitto_pub -h  \"10.96.4.11\" -t \"devices/lora/807B85902000069B/gpio\" -m \"set 1 0\" -q 1");
			}
		}

	}
  return 0;
}
