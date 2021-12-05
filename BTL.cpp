#include<iostream>
#include<iomanip>//chinh do rong setw()
#include<vector>
#include<conio.h>//thu vien de su dung getch();
#include<fstream>
#include<windows.h>
#include <stdbool.h>
#include <bits/stdc++.h> //thu vien goi tat ca cac thu vien chuan 

using namespace std;
//------class connguoi------
class ConNguoi {							
		string HoVaTen,GioiTinh;
	public:
		virtual void Nhap();
		virtual void Xuat();
		string getTen(){
			return HoVaTen;
		}
		string getGioiTinh(){
			return GioiTinh;
		}
		
};
//https://tranhanhuy.wordpress.com/2011/07/10/c-ham-mau-dung-cho-vc-6-0-textcolor/
// ham mau chu
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle

	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void ConNguoi::Nhap(){
	cout << "Nhap Ho va ten: ";
	fflush(stdin);
	getline(cin, HoVaTen);
	cout<<"\n";
	cout << "Nhap Gioi Tinh: ";
	cin >> GioiTinh;
	cout<<"\n";
}

void ConNguoi::Xuat(){

	cout<<HoVaTen;
	cout<<right<<setw(12);
	cout<<GioiTinh;
	cout<<right<<setw(30);
}

//------class Diem------
class Diem {								
	private:
		float Toan,Van,Anh,dtb;
	public:
	
		// tra ve dtb
		float getDtb(){
			return dtb;
		};
		float Diemtb();
		void NhapD();
		void XuatD();
		string XepLoai();
		float getToan(){
			return Toan;
		};
		float getVan(){
			return Van;
		};
		float getAnh(){
			return Anh;
		};
		float getdtb(){
			return dtb;
		};
		string getXepLoai();				
};

string Diem::getXepLoai(){
	string ghi;
	if(dtb>=8.0){
        ghi="Gioi";
        return ghi;
    }else if (dtb>=7){
        ghi="Kha";
        return ghi;
    }else if (dtb>=5){
        ghi="Trung binh";
        return ghi;
    }else{ 
        ghi="Yeu";
        return ghi;
    }
}

string Diem::XepLoai(){
	double T = getDtb();
	
	if(T>=8.0)
        cout<<"Gioi";
    else if (T>=7)
        cout<<"Kha";
    else if (T>=5)
        cout<<"Trung binh";
    else   
        cout<<"Yeu";             
}

float Diem::Diemtb(){	
	this->dtb= (Toan+Van+Anh)/3;
}

void Diem::NhapD(){
	cout<<"\n";
	cout<<"------------------"<<endl;
	cout<<"Diem cua hoc sinh"<<endl;
	cout<<"Nhap diem Toan: ";
	cin>>Toan;
	cout<<"\n";
	cout<<"Nhap diem Van: ";
	cin>>Van;
	cout<<"\n";
	cout<<"Nhap diem Anh: ";
	cin>>Anh;
}


void Diem::XuatD(){
	
	cout<<Toan<<setw(10);
	cout<<Van<<setw(10);
	cout<<Anh<<setw(10);
	this->Diemtb();
	//cout<<setprecision(1)<<fixed<<dtb<<setw(13);
	cout<<dtb<<setw(16);
	XepLoai();
	//cout<<endl<<right<<setw(15)<<Toan<<setw(15)<<Van<<setw(15)<<Anh<<setw(15)<<dtb<<endl;	
}

//------Class SinhVien------
class SinhVien:public ConNguoi,public Diem {//class SinhVien ke thua Diem, ke thua va su dung tinh chat da hinh voi ConNguoi
	private:
		string MSSV;
	public:
		void Nhap();
		void Xuat();
		string getMSSV(){
			return MSSV;
		};
};

void SinhVien::Nhap() {	
	ConNguoi::Nhap();
	cout << "Nhap MSSV: ";
	fflush(stdin);
	getline(cin, MSSV);
	Diem::NhapD();
}
void SinhVien::Xuat() {
	ConNguoi::Xuat();
	cout << MSSV;
	cout<<setw(20);
	Diem::XuatD();
}


//---------------------------------//
//------ class QuanLySinhVien ------
class QuanLySinhVien{								
	private:
		vector<SinhVien*>SV;
		int STT;
	public:
		void NhapDS();
		void XuatDS();
		void hienThiTenCot();
		void SapXepD();
		void XoaSV();
		void XoaDS();
		void TimKiemTen();
		void EditSV();
		void ghiFile();
		void docFile();
		void TimKiemMSSV(); 
};

//Ghi file
void QuanLySinhVien::ghiFile(){
	ofstream luufile; //xuat file
	luufile.open("C:\\Users\\nguye\\OneDrive\\Desktop\\ghifilebtl.txt",ios::out|ios::in);
	for(int i=0; i<SV.size(); i++){
		luufile << SV.at(i)->getTen()<<"\t";
		luufile << SV.at(i)->getGioiTinh()<<"\t";
		luufile << SV.at(i)->getMSSV()<<"\t";	
		luufile << SV.at(i)->getToan()<<"\t";
		luufile << SV.at(i)->getVan()<<"\t";
		luufile << SV.at(i)->getAnh()<<"\t";
		luufile << SV.at(i)->getdtb()<<"\t";
		luufile << SV.at(i)->getXepLoai();
		luufile << endl;
	}
	cout<<"Ghi danh sach vao file thanh cong!!!";
	luufile.close();
}


// Them Thong tin SV
void QuanLySinhVien::EditSV(){
	string ten;
//	int tim =0;
	textcolor(13);
	cout<<"Nhap ten sinh vien muon sua: ";
	//cin.ignore();
	fflush(stdin);
	getline(cin, ten);
	cout<<"-------------------------------------------"<<endl;
	textcolor(13);
	cout<<"Chinh sua thong tin cua hoc sinh "<<ten<<endl;
	for(int i=0; i<SV.size(); i++){
		//tim = 1;
		if (SV.at(i)->getTen() == ten){
			SV.at(i)->Nhap();
			cout <<"\n Da chinh sua thong tin hoc sinh "<<ten<<endl;
			cout << "\n\t\t\t\t\t\t\t -Danh Sach Sau Khi Cap Nhat La- "<<endl;
			XuatDS();
			break;
		}else{
			textcolor(4);
			system("cls");
			cout<<"\n\t\t\t\t\t\t Khong tim thay ma sinh vien!";
			break;
		}
	}if(SV.size()==0){
		textcolor(4);
		system("cls");
		cout<<"\n\t\t\t\t\t\t Danh sach rong, ko thuc hien duoc!"<<endl;
	}
}

void QuanLySinhVien::TimKiemMSSV(){
	string ms;
	cout<<"Nhap MSSV sinh vien can tim:";
	fflush(stdin);
	getline(cin,ms);	
	cout<<endl;
	for(int i=0;i<SV.size();i++){ 
		STT=i;		          
		if(ms.compare(SV.at(i)->getMSSV())==0){
			hienThiTenCot();
			cout<<endl<<STT<<setw(20); 
			SV.at(i)->Xuat();
		}	
	}
}

//TimKiemSinhVienTheoTen
void QuanLySinhVien::TimKiemTen(){
	if( SV.size() == 0 ){
		textcolor(4);
		system("cls");
		cout <<"\t\t\t\t\t ----|Danh sach trong, khong the tim!|----"<<endl;
		textcolor(11);
		cout<<"\t\t\t\t -VUI LONG NHAP THONG TIN HOC SINH DE THUC HIEN CHUC NANG-";
		return;
	}
	string ten;
	cout<<"Nhap ten sinh vien can tim:";
	fflush(stdin);
	getline(cin,ten);	
	cout<<endl;
	for(int i=0;i<SV.size();i++){ 
		STT=i;		          
		if(ten.compare(SV.at(i)->getTen())==0){
			hienThiTenCot();
			cout<<endl<<STT<<setw(20); 
			SV.at(i)->Xuat();
		}	
	}
}

//XoaToanBoDanhSach
void QuanLySinhVien::XoaDS(){
	bool value=true;
	SV.clear();
	cout<<"Ban co chac muon xoa toan bo danh sach!\n";
	cout<<"Nhap 1 or 0: ";
	cin>>value;
	//kiem tra 
	if(value==true){
		cout<<"Ban Hay doi trong giay lat. Chuong Trinh dang xu ly!!";
		for(int i=0;i<6;i++){
			cout<<".";
			Sleep(700);
		}
		cout<<"\n";
		cout<<right<<"Yeu Cau xoa toan bo danh sach cua ban da hoan tat!";
		Sleep(2800);
		system("cls");
	}else if(value==0){	
		cout<<"Yeu cau xoa toan bo danh sach cua ban da huy!!\n";
		cout<<"Ban se quay lai chuong trinh trong gia lat";
		for(int i=0;i<4;i++){
			cout<<".";
			Sleep(700);
		}
	
	}
	system("cls");
	}

//Xoa SV
void QuanLySinhVien::XoaSV(){
	int n;
	XuatDS();
	if(SV.size()==0){
		cout<<"\n\n";
		textcolor(12);
		system("cls");
		cout<<"\t\t\t\t\t\t Danh sach hien dang trong !!!"<<endl;
		textcolor(11);
		cout<<"\t\t\t\t -VUI LONG NHAP THONG TIN HOC SINH DE THUC HIEN CHUC NANG-";
	}else{	
	textcolor(11);	
	cout<<endl<<"Nhap STT sinh vien can xoa: ";
	cin>>n;
	if(n >= SV.size() ){
		cout<<"Khong co sinh vien tai vi tri do";
		system("cls");
	}else{
	SV.erase(SV.begin()+n);
	cout<<"Da xoa sinh vien thanh cong !!!";
	}
	system("cls");
	}
}


//SapXep
//thuat toan sap xep noi bot
void QuanLySinhVien::SapXepD(){
	if(SV.size()==0){
		textcolor(12);
		system("cls");
		cout<<"\t\t\t\t\t\t\t Danh sach trong, khong the sap xep!!!"<<endl;
		textcolor(11);
		cout<<"\t\t\t\t\t\t-VUI LONG NHAP THONG TIN HOC SINH DE THUC HIEN CHUC NANG-";
	}else{		
		for(int i=0;i<SV.size()-1;i++){
            for(int j=i+1;j<SV.size();j++){
            	//kiem tra
                if(SV.at(i)->getdtb() < SV.at(j)->getdtb()){
                	//Bien tam
                    SinhVien *t= SV.at(i);
                    SV.at(i)=SV.at(j);
                    SV.at(j)=t;
                }
            }
        }
    }
XuatDS();
}

void QuanLySinhVien::hienThiTenCot() {
	cout<<"-----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<endl<<"STT"<<setw(17)<<"HO & TEN"<<setw(20)<<"GIOI TINH "<<setw(18)<<"MSSV "<<setw(28)<<"TOAN "<<setw(9)<<"VAN "<<setw(10)<<"ANH "<<setw(14)<<"DiemTBC"<<setw(10)<<"XEPLOAI";
}

void QuanLySinhVien::NhapDS(){
	SinhVien *sv; //khai bao 1 doi tuong sv
    int n;
    cout<<"Nhap so luong sinh vien muon them vao danh sach: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"\n";
        cout<<"--- Nhap sinh vien thu "<<i+1<<" muon them vao danh sach --- "<<endl;
        sv=new SinhVien;  	//tinh da hinh, cap phat bo nho sinh vien, tro toi sinh vien
        sv->Nhap();			// tinh da hinh 
        SV.push_back(sv);// dua vao push back
        cout<<endl;
    }           
}

void QuanLySinhVien::XuatDS(){
	textcolor(10);
    cout<<endl<<setw(70)<<"\t\t Danh sach sinh vien"<<endl;
    hienThiTenCot();
    //size trong vector
    for(int i=0; i< this->SV.size();i++){		// so sanh voi kich thuoc phan tu cua vector      
		STT=i;
		cout<<endl<<STT<<setw(20);     	
        this->SV.at(i)->Xuat();			//at(i) goi sinh vien tai vi tri i de xuat du lieu sinh vien tai i
        cout<<endl;	
    }
}

void menu(){
	QuanLySinhVien dssv;
	int luachon; 
	char sobatky; 
	do {
		//menu da sua
		
		textcolor(9);
		cout <<"\t\t===================== Quan Ly Hoc Sinh ==================="<<endl;
		cout <<"\t\t||		1. Nhap thong tin sinh vien.		||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		2. Hien thi danh sach sinh vien. 	||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		3. Sap xep theo diem trung binh giam dan||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		4. Xoa hoc sinh theo so thu tu.		||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		5. Xoa toan bo danh sach hoc sinh	||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		6. Tim kiem sinh vien theo ten.		||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		7. Chinh Sua thong tin sinh vien.	||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;	
		cout <<"\t\t||		8. Ghi ket qua vao file.		||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		9. Tim kiem mssv.			||"<<endl;
		cout <<"\t\t||------------------------------------------------------||"<<endl;
		cout <<"\t\t||		0. THOAT!!				||"<<endl;
		cout <<"\t\t=========================================================="<<endl;
		
		cout <<"\t\t\t\t\nVui long chon: ";
		cin>>luachon; 
switch(luachon){
			case 0:
				textcolor(11);
				system("cls");
				cout<<"\t\t\t\t -----------------------------------------------------"<<endl;
				cout<<"\t\t\t\t |CAM ON BAN DA SU DUNG CHUONG TRINH QUAN LY HOC SINH|"<<endl;
				cout<<"\t\t\t\t -----------------------------------------------------"<<endl;
				cout<<"\t\t\t\t\t #An phim bat ky de thoat chuong trinh!#"<<endl;
				exit(0);
				break;
			case 1: 
				dssv.NhapDS();
				break; 
			case 2:
				dssv.XuatDS(); 
				break;
			case 3:
				dssv.SapXepD();
				break;
			case 4:
				dssv.XoaSV();
				break;
			case 5:
				dssv.XoaDS();
				break;
			case 6:
				dssv.TimKiemTen();
				break;
			case 7:
				dssv.EditSV();
				break;		
			case 8:
				dssv.ghiFile();
				break;
		
		case 9:
				dssv.TimKiemMSSV();
				break;
		}
		textcolor(15);
		cout<<endl<<"\t\t\t\t\t---Nhan phim bat ky de tiep tuc chuong trinh!---";
		getch(); 
		system("cls");
	}while(luachon);
}
int main(){
	menu();
};
