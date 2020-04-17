#include <iostream>
#include "MyPoint.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Turkish");  // T�rk�e karakter kullan�m�
	MyPoint *p1 = new MyPoint(); // S�n�f�m�z� bir pointer ve bellek tasarruflu olarak tan�mlad�k
	int x,y,a,b,c,d,tmp; // Gerekli tutucular� tan�mlad�k
	cout << "Nokta kordinatlar�n� elle belirlemek i�in l�tfen 1'e bas�n�z: ";
	cin >> tmp; // E�er noktalar� kullan�c� belirlemek isterse 1'e basacak. E�er 0,0 olmas�n� isterse 1'den farkl� bir say� tu�layacak
	if(tmp == 1){ // Noktalar� kullan�c�dan al�yoruz
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		p1->setX(x); // setX fonksiyonu ile x'i g�nderebiliyoruz
		p1->setY(y); // setY fonksiyonu ile y'yi g�nderebiliyoruz
		p1->setXY(x,y); // setXY fonksiyonu ile x'i ve y'yi g�nderebiliyoruz
	}
	cout << "�ki de�eri tek metodda d�nd�relim : ";
	cout << "(" << p1->getXY()[0] << "," << p1->getXY()[1] << ")" << endl; // getXY fonksiyonunu kullanarak tek metodda hem x'i hemde y'yi d�nd�rd�k.
	p1->toString(); // Noktalar�m�z� toString metodu ile yazd�rd�k
	cout << "�ki nokta giriniz: " << endl << "a: "; // Uzakl�k hesab� i�in kullan�c�dan iki nokta kordinat� girmesini istedik
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "(x,y) noktalar�n�n (a,b) noktalar�na olan uzakl���: ";
	double mesafe = p1->distance(a,b); // Kullan�c�n�n girdi�i nokta kordinatlar�n� distance fonksiyonuna g�ndererek aradaki mesafeyi hesaplad�k
	cout << mesafe;
	cout << "\n(x,y) noktalar�n�n (0,0) noktalar�na olan uzakl���: "; 
	double mesafe2 = p1->distance(); // X ve Y noktalar�n�n (0,0) yani orijine olan uzakl���n� distance fonksiyonu ile hesaplad�k
	cout << mesafe2 << endl;
	MyPoint *p2 = new MyPoint(); // Yeni bir nesne olu�turuldu
	cout << "\nFarkl� bir nesne olu�turuldu. L�tfen yeni bir nokta kordinat� giriniz: " << endl << "x: ";
	cin >> c; // Yeni nesnenin x kordinat� al�nd�
	cout << "y: ";
	cin >> d; // Yeni nesnenin y kordinat� al�nd�
	p2->setXY(c,d); // Yeni nesneye x ve y kordinatlar� g�nderildi
	cout << "(x,y) noktalar�n�n yeni nesne kordinatlar�na olan uzakl��� : ";
	double mesafe3 = p1->distance((*p2)); // �ki nesnedeki noktalar aras� mesafe hesapland� ve mesafe3 de�i�kenine atand�
	double mesafe4 = p2->distance(*p1); // �ki nesnedeki noktalar aras� mesafe tersinden hesapland� ve mesafe4 de�i�kenine atand�
	cout << mesafe3; // Mesafe3 yazd�r�ld�
	cout << "\nYeni nesne kordinatlar�n�n (x,y) noktalar�na olan uzakl���: ";
	cout << mesafe4; // Mesafe4 Yazd�r�ld�.
	delete p2; // Bellekten p2'yi sildik
	delete p1; // Bellekten p1'i sildik
	MyPoint *points = new MyPoint[10]; // Yeni bir dizi olu�turduk. 11 elemanl�
	for(int i=0; i<10; i++)
		points[i].setXY(i+1,i+1); // �lk 10 eleman�n� kendimiz belirledik. 1,1 2,2 3,3 4,4 ... 10,10 olarak kaydettik
	points[10].setXY(x,y); // Son noktay� ilk belirledi�imiz X ve Y noktalar� olarak ayarlad�k
	cout << "\n\nDizi Noktalar�: " << endl;
	for(int i=0; i<=10; i++){
		cout << "(" << points[i].getX() << "," << points[i].getY() << ")" << endl; // Dizi noktalar�n� yazd�rd�k.
	}
	delete []points; // Diziyi bellekten sildik.
	return 0;
}
