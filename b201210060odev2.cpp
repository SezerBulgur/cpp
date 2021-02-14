/**********************************************************************************************************************************************************
***													SAKARYA ÜNİVERSİTESİ
***											BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
***												BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
***													PROGRAMLAMAYA GİRİŞ DERSİ
***
***								ÖDEV NUMARASI...: 2. Ödev
***								ÖĞRENCİ ADI.....: Sezer Bulgur
***								ÖĞRENCİ NUMARASI: b201210060
***								DERS GRUBU......: A grubu
**********************************************************************************************************************************************************/

#include <iostream>
#include <Windows.h>

using namespace std;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class ev {
private:
	int kapiGenislik = 6;
	int catiYukseklik = 3;

public:
	int genislik = 20;
	int yukseklik = 10;
	char damga = char(219);
	int x = 0;
	int y = 0;

	ev()
	{
		damga = '^';

		//çatı çiziminin yüksekliğini ayarlar
		for (int i = catiYukseklik - 1; i >= 0; i--)
		{
			//ne kadar boşluk bırakacağını ayarlar
			for (int j = i; j > 0; j--)
			{
				cout << ' ';
			}

			//çatı çiziminde kullanılan damganın kaç tane çizileceğini ayarlar
			for (int j = 0; j < genislik - (i * 2); j++)
			{
				cout << damga;
			}
			cout << endl;
		}

		y = y + 3;

		damga = char(219);

		//katın tavanını çizer
		for (int i = 0; i < genislik; i++)
		{
			gotoxy(x++, y);
			cout << damga;
		}

		//katın sağ duvarını çizer
		for (int i = 0; i < yukseklik - 1; i++)
		{
			gotoxy(x - 1, ++y);
			cout << damga;
		}

		x = x - genislik;

		//katın tabanını çizer
		for (int i = 0; i < genislik; i++)
		{
			gotoxy(x++, y);

			//kapı çizimi için alan bırakır
			if (i < 7)
			{
				continue;
			}

			cout << damga;
		}

		x = x - genislik;

		//katın sol duvarını çizer
		for (int i = 1; i < yukseklik; i++)
		{
			gotoxy(x, y--);
			cout << damga;
		}
		y = y + yukseklik - 1;

		damga = '#';

		//kapıyı ayarlanan genişlikte çizer
		for (int i = 0; i < kapiGenislik; i++)
		{
			gotoxy(++x, y);
			cout << damga;
		}

		y--;

		//kapının devamı
		for (int i = 0; i < kapiGenislik; i++)
		{
			gotoxy(x--, y);
			cout << damga;
		}

		y--;

		//kapının devamı
		for (int i = 0; i < kapiGenislik; i++)
		{
			gotoxy(++x, y);
			cout << damga;
		}

		y--;

		//kapının devamı
		for (int i = 0; i < kapiGenislik; i++)
		{
			gotoxy(x--, y);
			cout << damga;
		}

		gotoxy(0, y + 8);


	}
};

class kat :public ev {
public:
	kat()
	{
		genislik = 15;
		yukseklik = 5;
		damga = char(219);
		system("cls");
	}

	void katYap()
	{
		//katın tavanını istenilen genişlikte çizer
		for (int i = 0; i < genislik; i++)
		{
			gotoxy(x++, y);
			cout << damga;
			Sleep(25);
		}

		//katın sağ duvarını istenilen yükseklikte çizer
		for (int i = 0; i < yukseklik - 1; i++)
		{
			gotoxy(x-1, ++y);
			cout << damga;
			Sleep(25);
		}

		x = x - genislik;

		//katın tabanını istenilen genişlikte çizer
		for (int i = 0;i<genislik;i++)
		{
			gotoxy(x++, y);

			//kapı çizimi için alan bırakır
			if (i < 7)
			{
				continue;
			}
				
			cout << damga;
			Sleep(25);
		}

		x = x - genislik;

		//katın sol duvarını istenilen yükseklikte çizer
		for (int i = 1; i < yukseklik; i++)
		{
			gotoxy(x, y--);
			cout << damga;
			Sleep(25);
		}
		y = y + yukseklik - 1;
	}
};

class cati :public ev {
public:
	cati()
	{
		yukseklik = 3;
		damga = '^';
		system("cls");
	}

	void catiYap()
	{
		//çatı çiziminin yüksekliğini ayarlar
		for (int i = yukseklik - 1; i >= 0; i--)
		{
			gotoxy(x, y++);

			//ne kadar boşluk bırakacağını ayarlar
			for (int j = i; j > 0; j--)

			{
				cout << ' ';
				Sleep(25);
			}

			//çatı çiziminde kullanılan damganın kaç tane çizileceğini ayarlar
			for (int j = 0; j < genislik - (i * 2); j++)
			{
				cout << damga;
				Sleep(25);
			}
			cout << endl;
		}
	}
};

class kapi :public ev {
	

public:
	kapi()
	{
		genislik = 6;	
		damga = '#';
		system("cls");
	}
	
	void kapiYap()
	{
		//kapıyı ayarlanan genişlikte çizer
		for (int i = 0; i < genislik; i++)
		{
			gotoxy(++x, y);
			cout << damga;
			Sleep(25);
		}

		y--;
			
		//kapının devamı
		for (int i = 0; i < genislik; i++)
		{
			gotoxy(x--, y);
			cout << damga;
			Sleep(25);
		}

		y--;
				
		//kapının devamı
		for (int i = 0; i < genislik; i++)
		{
			gotoxy(++x, y);
			cout << damga;
			Sleep(25);
		}

		y--;
				
		//kapının devamı
		for (int i = 0; i < genislik; i++)
		{
			gotoxy(x--, y);
			cout << damga;
			Sleep(25);
		}
				
		gotoxy(0, y + 8);
	}
};

int main()
{	
	kat kat1;
	cati cati1;
	kapi kapi1;

	cout << "Yukseklik: ";
	cin >> kat1.yukseklik;

	//çizimde sorun olmaması için katın yüksekliğini kontrol eder
	if (kat1.yukseklik > 19)
		kat1.yukseklik = 19;

	cout << "Genislik: ";
	cin >> kat1.genislik;

	//çizimde sorun olmaması için katın genişliğini kontrol eder
	if (kat1.genislik > 79)
		kat1.genislik = 79;

	else if (kat1.genislik < 9)
		kat1.genislik = 9;

	cout << "Cati Yuksekligi: ";
	cin >> cati1.yukseklik;

	//çizimde sorun olmaması için çaçtı ve katın yüksekliği kontrol eder
	if (kat1.yukseklik + cati1.yukseklik > 20)
		cati1.yukseklik = 20 - kat1.yukseklik;

	cout << "X: ";
	cin >> cati1.x;

	//çizimde sorun olmaması için verilen x değerini kontrol eder
	if (cati1.x + kat1.genislik > 80)
		cati1.x = 80 - kat1.genislik;

	cout << "Y: ";
	cin >> cati1.y;

	//çizimde sorun olmaması için verilen x değerini kontrol eder
	if (cati1.y + kat1.yukseklik + cati1.yukseklik > 80)
		cati1.y = 80 - kat1.yukseklik - cati1.yukseklik;

	--cati1.x;
	--cati1.y;

	cati1.genislik = kat1.genislik;

	system("cls");

	cati1.catiYap();

	kat1.x = cati1.x;
	kat1.y = cati1.y;

	kat1.katYap();

	kapi1.x = kat1.x;
	kapi1.y = kat1.y;

	kapi1.kapiYap();

	system("pause");

	return(0);
}