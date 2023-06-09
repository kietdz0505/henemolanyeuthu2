#include<iostream>
#include<string>
using namespace std;
class SanPham {
private:
	char Masp[11];
	string Tensp;
	double Dongia;
	int Sltonkho;
public:
	void setMSP(SanPham &a)
	{
		cout << " Nhap ma san pham: ";
		cin.getline(a.Masp, 11);
	}
	void setTensp(SanPham &a)
	{
		cout << " Nhap ten san pham: ";
		getline(cin, a.Tensp);
	}
	void setDongia(SanPham &a)
	{
		cout << " Nhap don gia san pham: ";
		cin >> a.Dongia;
	}
	void setSL( SanPham &a)
	{
		cout << " Nhap so luong ton kho: ";
		cin >> a.Sltonkho;
	}
	void setSanpham(SanPham& a)
	{
		setMSP(a);
		setTensp(a);
		setDongia(a);
		setSL(a);
	}
	void getSanpham(SanPham a)
	{
		cout << " Ma san pham: " << a.Masp << "\n";
		cout << " Ten san pham: " << a.Tensp << "\n";
		cout << " Don gia: " << a.Dongia << "\n";
		cout << " So luong ton kho: " << a.Sltonkho << "\n";
	}
	void setDSSP(SanPham*& dssp, int& n)
	{
		for (int i = 0; i < n; i++) {
			cin.ignore();
			cout << " Nhap san pham thu " << i + 1 << ":\n";
			setSanpham(*(dssp + i));
			cout << "\n";
		}
	}
	void setaddDSSP(SanPham*& dssp, int &n , int &t)
	{
		n = n + t;
		for (int i = n-t; i < n; i++) {
			cin.ignore();
			cout << " Nhap san pham thu " << i + 1 << ":\n";
			setSanpham(*(dssp + i));
			cout << "\n";
		}
	}
	void getDSSP(SanPham* dssp, int &n) {
		for (int i = 0; i < n; i++) {
			cout << " Thong tin san pham thu " << i + 1 << ":\n";
			getSanpham(*(dssp + i));
			cout << "\n";
		}
	}
	void sortTonkho(SanPham*& dssp, int &n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				if (dssp[j].Sltonkho > dssp[j + 1].Sltonkho)
				{
					swap(dssp[j].Masp, dssp[j + 1].Masp);
					swap(dssp[j].Tensp, dssp[j + 1].Tensp);
					swap(dssp[j].Dongia, dssp[j + 1].Dongia);
					swap(dssp[j].Sltonkho, dssp[j + 1].Sltonkho);
				}
			}
		}
		cout << " Thu tu tu thap den cao so luong ton kho la: \n";
		getDSSP(dssp, n);
	}
};
int main() {
	int add = 0;
	int chon;
	int stt;
	int tiep = 0;
	int count = 0;
	int n;
	int opt;
	SanPham SP;
	SanPham* sp = new SanPham[30];;
	do {
		system("cls");
		cout << "================= MENU ==================\n"
			<< "1. Nhap thong tin cho san pham.\n"
			<< "2. Xuat thong tin cua cac san pham.\n"
			<< "3. Sua thong tin cua mot san pham.\n"
			<< "4. Xoa thong tin cua mot san phan.\n"
			<< "5. Sap xep lai toan bo san pham theo trinh tu so luong ton kho tang dan.\n"
			<< "6. Them san pham quan li.\n"
			<< "7. Thoat chuong trinh.\n"
			<< "==========================================\n";
		do {
			cout << " Chon chuc nang >>> ";
			cin >> chon;
		} while (chon < 1 || chon>7);
		system("cls");
		switch (chon)
		{
		case 1:
			do {
				cout << " Nhap so luong san pham thuc te: ";
				cin >> n;
			} while (n < 0 || n > 30);
			system("cls");
			SP.setDSSP(sp, n);
			count++;
			break;
		case 2:
			if (count == 0) cout << " Ban chua nhap du lieu!\n";
			else SP.getDSSP(sp, n);
			break;
		case 3:
			if (count == 0) cout << "Ban chua nhap du lieu!\n";
			else
			{
				do {
					system("cls");
					SP.getDSSP(sp, n);
					cout << "Nhap thu tu san pham ban muon sua thong tin: ";
					cin >> stt;
					do {
						do {
							system("cls");
							SP.getSanpham(sp[stt - 1]); 
							cout << "\n";
							cout << "Chon thanh phan ban muon sua:\n"
								<< "1. Ma san pham.\n"
								<< "2. Ten san pham.\n"
								<< "3. Don gia.\n"
								<< "4. So luong trong kho.\n"
								<< "5. Thoat.\n";
							cout << " >>> ";
							cin >> opt;
						} while (opt < 1 || opt > 5);
						system("cls");
						if (opt == 1)
						{
							cin.ignore();
							SP.setMSP(sp[stt - 1]);
							cout << " Sua thong tin san pham thanh cong!\n";
							cout << " Ban co muon sua tiep? Co: 1 / Khong: 0 >>> ";
							cin >> tiep;
						}
						else if (opt == 2)
						{
							cin.ignore();
							SP.setTensp(sp[stt - 1]);
							cout << " Sua thong tin san pham thanh cong!\n";
							cout << " Ban co muon sua tiep? Co: 1 / Khong: 0 >>> ";
							cin >> tiep;
						}
						else if (opt == 3) {
							cin.ignore();
							SP.setDongia(sp[stt - 1]);
							cout << " Sua thong tin san pham thanh cong!\n";
							cout << " Ban co muon sua tiep? Co: 1 / Khong: 0 >>> ";
							cin >> tiep;
						}
						else if (opt == 4) {
							cin.ignore();
							SP.setSL(sp[stt - 1]);
							cout << " Sua thong tin san pham thanh cong!\n";
							cout << " Ban co muon sua tiep? Co: 1 / Khong: 0 >>> ";
							cin >> tiep;
						}
						else {
							break;
						}
					} while (tiep);
					cout << " Sang chuc nang khac? Co: 1 / Khong: 0 >> ";
					cin >> tiep;
				} while (!tiep);
			}
			break;
		case 4:
			if (count == 0 || n == 0)
			{
				cout << "Ban chua nhap du lieu!\n";
				cout << " Khong con san pham de xoa!\n";
			}
			else
			{
				do {
					cout << " Nhap thu tu san pham ban muon xoa thong tin: ";
					cin >> stt;
				} while (stt > n || stt < 0);
				for (int i = stt - 1; i < n - 1; i++) {
					*(sp + i) = *(sp + i + 1);
				}
				n--;
				if (n < 0) cout << " Khong con san pham nao!\n";
				else {
					cout << " Thong tin san pham da duoc xoa!\n";
					cout << " So san pham con lai: " << n << " san pham\n";
					cout << "\n";
					SP.getDSSP(sp, n);
				}
			}
			break;
		case 5:
			if (count == 0) cout << "Ban chua nhap du lieu!\n";
			else SP.sortTonkho(sp, n);
			break;
		case 6:	
			if (count == 0) cout << " Ban chua nhap du lieu!\n";
			else 
			{
				do{
				cout<<" Nhap so luong san pham can them: ";
			    cin >> add;
					} while ( add + n > 30);
					SP.setaddDSSP(sp, n , add);
                    cout << " Them san pham thanh cong!\n";
            }
			break;
		case 7:
			cout << " Cam on ban da su dung CT! ";
			delete[] sp;
			return 0;
			break;
		}
		cout << "Quay lai MENU? (Yes: 1/ No: 0)\n"
			<< ">>> ";
		cin >> tiep;
	} while (tiep);
	return 0;
}
