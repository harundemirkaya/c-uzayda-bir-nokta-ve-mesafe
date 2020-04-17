#include <iostream>
#include "MyPoint.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Turkish");  // Türkçe karakter kullanýmý
	MyPoint *p1 = new MyPoint(); // Sýnýfýmýzý bir pointer ve bellek tasarruflu olarak tanýmladýk
	int x,y,a,b,c,d,tmp; // Gerekli tutucularý tanýmladýk
	cout << "Nokta kordinatlarýný elle belirlemek için lütfen 1'e basýnýz: ";
	cin >> tmp; // Eðer noktalarý kullanýcý belirlemek isterse 1'e basacak. Eðer 0,0 olmasýný isterse 1'den farklý bir sayý tuþlayacak
	if(tmp == 1){ // Noktalarý kullanýcýdan alýyoruz
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		p1->setX(x); // setX fonksiyonu ile x'i gönderebiliyoruz
		p1->setY(y); // setY fonksiyonu ile y'yi gönderebiliyoruz
		p1->setXY(x,y); // setXY fonksiyonu ile x'i ve y'yi gönderebiliyoruz
	}
	cout << "Ýki deðeri tek metodda döndürelim : ";
	cout << "(" << p1->getXY()[0] << "," << p1->getXY()[1] << ")" << endl; // getXY fonksiyonunu kullanarak tek metodda hem x'i hemde y'yi döndürdük.
	p1->toString(); // Noktalarýmýzý toString metodu ile yazdýrdýk
	cout << "Ýki nokta giriniz: " << endl << "a: "; // Uzaklýk hesabý için kullanýcýdan iki nokta kordinatý girmesini istedik
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "(x,y) noktalarýnýn (a,b) noktalarýna olan uzaklýðý: ";
	double mesafe = p1->distance(a,b); // Kullanýcýnýn girdiði nokta kordinatlarýný distance fonksiyonuna göndererek aradaki mesafeyi hesapladýk
	cout << mesafe;
	cout << "\n(x,y) noktalarýnýn (0,0) noktalarýna olan uzaklýðý: "; 
	double mesafe2 = p1->distance(); // X ve Y noktalarýnýn (0,0) yani orijine olan uzaklýðýný distance fonksiyonu ile hesapladýk
	cout << mesafe2 << endl;
	MyPoint *p2 = new MyPoint(); // Yeni bir nesne oluþturuldu
	cout << "\nFarklý bir nesne oluþturuldu. Lütfen yeni bir nokta kordinatý giriniz: " << endl << "x: ";
	cin >> c; // Yeni nesnenin x kordinatý alýndý
	cout << "y: ";
	cin >> d; // Yeni nesnenin y kordinatý alýndý
	p2->setXY(c,d); // Yeni nesneye x ve y kordinatlarý gönderildi
	cout << "(x,y) noktalarýnýn yeni nesne kordinatlarýna olan uzaklýðý : ";
	double mesafe3 = p1->distance((*p2)); // Ýki nesnedeki noktalar arasý mesafe hesaplandý ve mesafe3 deðiþkenine atandý
	double mesafe4 = p2->distance(*p1); // Ýki nesnedeki noktalar arasý mesafe tersinden hesaplandý ve mesafe4 deðiþkenine atandý
	cout << mesafe3; // Mesafe3 yazdýrýldý
	cout << "\nYeni nesne kordinatlarýnýn (x,y) noktalarýna olan uzaklýðý: ";
	cout << mesafe4; // Mesafe4 Yazdýrýldý.
	delete p2; // Bellekten p2'yi sildik
	delete p1; // Bellekten p1'i sildik
	MyPoint *points = new MyPoint[10]; // Yeni bir dizi oluþturduk. 11 elemanlý
	for(int i=0; i<10; i++)
		points[i].setXY(i+1,i+1); // Ýlk 10 elemanýný kendimiz belirledik. 1,1 2,2 3,3 4,4 ... 10,10 olarak kaydettik
	points[10].setXY(x,y); // Son noktayý ilk belirlediðimiz X ve Y noktalarý olarak ayarladýk
	cout << "\n\nDizi Noktalarý: " << endl;
	for(int i=0; i<=10; i++){
		cout << "(" << points[i].getX() << "," << points[i].getY() << ")" << endl; // Dizi noktalarýný yazdýrdýk.
	}
	delete []points; // Diziyi bellekten sildik.
	return 0;
}
