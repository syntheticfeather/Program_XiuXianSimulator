//#include<stdio.h>
//#include<easyx.h>
//
//char* NumToText(float Num) {
//	char text[10];
//	int Count = 0;
//	float Cnum = Num;
//	while (Cnum > 10)
//	{
//		Cnum = Cnum / 10;
//		Count++;
//	}
//	while (Num > 10)
//	{
//		int a = (int)Num % 10;
//		text[Count] = (char)(a + 48);
//		Num = (int)Num / 10;
//		Count--;
//	}
//	text[Count] = (char)(Num + 48);
//	//for (int i = 0; i < 6; i++)
//	//{
//	//	printf("%c", text[i]);
//	//}
//	return text;
//}
//
//
//int main() {
//
//
//	initgraph(500, 500);
//	////ascill转换，48对应0
//	////对应位数+48
//	
//
//	char text[10];
//	float a = 123456;
//	sprintf(text, "%d", (int)a);
//
//	outtextxy(100, 100, text);
//
//	getchar();
//	return 0;
//}