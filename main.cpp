#include <iostream>
#include<conio.h>
#include <fstream>
using namespace std;
struct warung{ // struct
	long harga, biaya, diskon, total, bayar, kembalian;
	int jumlah;
  	char paket;	
}wrg;

long tot(long h, long j){ // fungsi
	  long b = h * j;
	  return b;
}
	FILE * pFile;
	ofstream Nota ("Nota.txt");
	string Menu [5] = {"A. Ayam Geprek		Rp.21000", "B. Ayam Goreng		Rp.17000", "C. Udang Goreng		Rp.19000", "D. Cumi Goreng		Rp.20000", "E. Ayam Bakar		Rp.25000" };

int main(){
	int i, ongkir,bayar;
	char pilih, jarak;
	pilihan:
	cout<<"========================"<<endl;
	cout<<"    RUMAH MAKAN  "<<endl;
	cout<<"========================"<<endl;
	cout<<endl;
	
	cout<<"MENU:              "<<endl;
	for (i=0; i < 5; i++){
		cout << Menu[i] << endl;
	}
	cout<<endl<<endl;

	cout<<"Pilih Menu [ A/B/C/D/E ] = "; cin>>wrg.paket;
	cout<<"Jumlah          = "; cin>>wrg.jumlah;
	

switch(wrg.paket)
{
	case 'A':
    	case 'a'  :
    		wrg.harga=21000;
   break;
   	case 'B':
    	case 'b'   :
    		wrg.harga=17000;
    break;
    	case 'C':
    	case 'c'   :
    		wrg.harga=19000;
    break;
    	case 'D':
    	case 'd'   :
    		wrg.harga=20000;
    break;
    	case 'E':
    	case 'e'   :
    		wrg.harga=25000;
    break;
  }
	cout<<"ingin pesan lagi?(y/n)";
	cin>>pilih;
	if(pilih=='y'||pilih=='Y'){
		system("cls");
		goto pilihan;
	}
	wrg.biaya = tot (wrg.harga, wrg.jumlah);
  
  	if (wrg.biaya>=50000){
		wrg.diskon=0.15*wrg.biaya;
	}
	else if (wrg.biaya>=150000){
		wrg.diskon=0.35*wrg.biaya;
	}else {
		wrg.diskon=0;
	}
  wrg.total=wrg.biaya-wrg.diskon;
  
  cout <<"jarak rumah anda "<<endl;
  cout <<"A. <=3KM Rp.15000"<< endl;
  cout <<"B. >=3KM Rp.25000"<< endl;
  cin >> jarak;
  
  if (jarak == 'a'||'A')
  {
  	ongkir = 15000;
	if (wrg.biaya >= 150000)
	{
		ongkir -= 8000;
	}
	else if (wrg.biaya >= 50000)
	{
		ongkir -= 5000;
	}
	else if (wrg.biaya>=25000)
	{
		ongkir -= 3000;
	}
  }
  else if (jarak == 'b'||'B')
  {
  	ongkir = 25000;
  	if (wrg.biaya >= 25000)
	{
		ongkir -= 3000;
	}
	else if (wrg.biaya >= 50000)
	{
		ongkir -= 5000;
	}
	else if (wrg.biaya >= 150000)
	{
		ongkir -= 8000;
	}
  }
  bayar=wrg.total+ongkir;
  cout <<bayar;
Nota<<endl;
Nota<<"Total Pembayaran     = "<<bayar<<endl;
  fclose (pFile);
	return 0;
}
