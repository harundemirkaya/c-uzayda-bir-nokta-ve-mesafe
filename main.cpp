#include <iostream>
#include "MyPoint.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Turkish");  // Türkçe karakter kullanımı
	MyPoint *p1 = new MyPoint(); // Sınıfımızı bir pointer ve bellek tasarruflu olarak tanımladık
	int x,y,a,b,c,d,tmp; // Gerekli tutucuları tanımladık
	cout << "Nokta kordinatlarını elle belirlemek için lütfen 1'e basınız: ";
	cin >> tmp; // Eğer noktaları kullanıcı belirlemek isterse 1'e basacak. Eğer 0,0 olmasını isterse 1'den farklı bir sayı tuşlayacak
	if(tmp == 1){ // Noktaları kullanıcıdan alıyoruz
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		p1->setX(x); // setX fonksiyonu ile x'i gönderebiliyoruz
		p1->setY(y); // setY fonksiyonu ile y'yi gönderebiliyoruz
		p1->setXY(x,y); // setXY fonksiyonu ile x'i ve y'yi gönderebiliyoruz
	}
	cout << "İki değeri tek metodda döndürelim : ";
	cout << "(" << p1->getXY()[0] << "," << p1->getXY()[1] << ")" << endl; // getXY fonksiyonunu kullanarak tek metodda hem x'i hemde y'yi döndürdük.
	p1->toString(); // Noktalarımızı toString metodu ile yazdırdık
	cout << "İki nokta giriniz: " << endl << "a: "; // Uzaklık hesabı için kullanıcıdan iki nokta kordinatı girmesini istedik
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "(x,y) noktalarının (a,b) noktalarına olan uzaklığı: ";
	double mesafe = p1->distance(a,b); // Kullanıcının girdiği nokta kordinatlarını distance fonksiyonuna göndererek aradaki mesafeyi hesapladık
	cout << mesafe;
	cout << "\n(x,y) noktalarının (0,0) noktalarına olan uzaklığı: "; 
	double mesafe2 = p1->distance(); // X ve Y noktalarının (0,0) yani orijine olan uzaklığını distance fonksiyonu ile hesapladık
	cout << mesafe2 << endl;
	MyPoint *p2 = new MyPoint(); // Yeni bir nesne oluşturuldu
	cout << "\nFarklı bir nesne oluşturuldu. Lütfen yeni bir nokta kordinatı giriniz: " << endl << "x: ";
	cin >> c; // Yeni nesnenin x kordinatı alındı
	cout << "y: ";
	cin >> d; // Yeni nesnenin y kordinatı alındı
	p2->setXY(c,d); // Yeni nesneye x ve y kordinatları gönderildi
	cout << "(x,y) noktalarının yeni nesne kordinatlarına olan uzaklığı : ";
	double mesafe3 = p1->distance((*p2)); // İki nesnedeki noktalar arası mesafe hesaplandı ve mesafe3 değişkenine atandı
	double mesafe4 = p2->distance(*p1); // İki nesnedeki noktalar arası mesafe tersinden hesaplandı ve mesafe4 değişkenine atandı
	cout << mesafe3; // Mesafe3 yazdırıldı
	cout << "\nYeni nesne kordinatlarının (x,y) noktalarına olan uzaklığı: ";
	cout << mesafe4; // Mesafe4 Yazdırıldı.
	delete p2; // Bellekten p2'yi sildik
	delete p1; // Bellekten p1'i sildik
	MyPoint *points = new MyPoint[10]; // Yeni bir dizi oluşturduk. 11 elemanlı
	for(int i=0; i<10; i++)
		points[i].setXY(i+1,i+1); // İlk 10 elemanını kendimiz belirledik. 1,1 2,2 3,3 4,4 ... 10,10 olarak kaydettik
	points[10].setXY(x,y); // Son noktayı ilk belirlediğimiz X ve Y noktaları olarak ayarladık
	cout << "\n\nDizi Noktaları: " << endl;
	for(int i=0; i<=10; i++){
		cout << "(" << points[i].getX() << "," << points[i].getY() << ")" << endl; // Dizi noktalarını yazdırdık.
	}
	delete []points; // Diziyi bellekten sildik.
	return 0;
}
