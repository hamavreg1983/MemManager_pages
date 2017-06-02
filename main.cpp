#include <iostream> /* cout */
#include <stdio.h> 
#include "memManager_t.h"
#include "memPage_t.h"
#include "memPool_t.h"


/* ~~~ Defines ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
using std::cout;
using namespace std;

/* ~~~ Struct ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




/* ~~~ Function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


//void interactiveTest(Car_t& _str,const size_t _select);
//void OperatorTest( Car_t& _Lstr, Car_t& _Rstr, size_t _select);
void NormalTest(void);

void NormalTest(void)
{
	
	{
		char buffer[128];
		MemPage_t pageA;
		cout << "size" << pageA.GetSize() << "capacity" << pageA.GetCapacity() << '\n';
		cout << "isEmpty" << pageA.IsEmpty() << " isFull" << pageA.IsFull() << '\n';
		
		cout << "read #bytes: " << pageA.Read(buffer, 5) << '\n';
		
		char msg[] = "hello lotem";
		cout << "write #bytes: " << pageA.Write(msg, 10 ) << '\n';
		
		cout << "read #bytes: " << pageA.Read(buffer, 7, 0) << ". and got: " << buffer << '\n';
		cout << "position" << pageA.GetPosition() << '\n';
		pageA.SetPosition(6);
		cout << "position" << pageA.GetPosition() << '\n';
		cout << "read #bytes: " << pageA.Read(buffer, 7) << ". and got: " << buffer << '\n';
		
		pageA.SetPosition(6);
		cout << "write #bytes: " << pageA.Write(msg, 10 ) << '\n';
		cout << "write #bytes: " << pageA.Write(msg, 10 ) << '\n';
		
		cout << "defualt size: " << pageA.GetDefaultSize() << '\n';
		cout << "new defualt size: " << pageA.SetDefaultSize(25) << '\n';
	}
	cout << "\n";
	{
		MemPool_t mypool;
		
		char buffer[128];
		char msg[] = "hello lotem";
		
		cout << "defualt size: " << mypool.GetDefaultSize() << '\n';
		cout << "defualt size: " << mypool.SetDefaultSize(18) << '\n';
		
		
		cout << "isEmpty" << mypool.IsEmpty() << '\n';
		cout << "size" << mypool.GetSize() << '\n';
		
		cout << "write #bytes: " << mypool.Write(msg, 11) << '\n';
		cout << "write #bytes: " << mypool.Write(msg, 11) << '\n';
		cout << "write #bytes: " << mypool.Write(msg, 8) << '\n';
//		cout << "write #bytes: " << mypool.Write(msg, 3) << '\n';
		
		cout << "read #bytes: " << mypool.Read(buffer, 11, 0) << ". and got: " << buffer << '\n';
		cout << "read #bytes: " << mypool.Read(buffer, 11) << ". and got: " << buffer << '\n';
		cout << "read #bytes: " << mypool.Read(buffer, 11) << ". and got: " << buffer << '\n';
		cout << "read #bytes: " << mypool.Read(buffer, 11) << ". and got: " << buffer << '\n';
	
	}
	
	{
	}
	
	
	
	return;
}	


int main()
{
	printf("---START---\n");
	
	NormalTest();
	
	
	
//	Car_t str;
//	size_t select = 0;
//		cout  <<endl <<endl <<endl <<endl;

//		cout <<"Welcome to interactive Test" <<endl;
//	do
//	{

//		cout <<"Please select option" <<endl;
//		cout <<"1: set string "<<endl;
//		cout <<"2: Print string "<<endl;
//		cout <<"3: Print string Length "<<endl;
//		cout <<"4: compare Option "<<endl;
//		cout <<"5: upper string "<<endl;
//		cout <<"6: lower string "<<endl;
//		cout <<"0: exit "<<endl;
//		cin>>select;

//		interactiveTest(str,select);

//	}while( 0 != select);
	
	
	printf("\n---END---\n");
	return 0;
}



//void interactiveTest(Car_t& _str , const size_t _select)
//{
//	char line[BUFFER];
//	size_t option;
//	Car_t s2;
//	switch(_select)
//	{
//		case 1:
//				cout << "Enter new string to enter" <<endl;
//				 cin >> line;
//				_str.SetString(line);
//				break;
//		case 2:
//				_str.Print();
//				break;
//		case 3:
//				cout<< "String Lenght "<< _str.Lenght() << endl;
//				break;
//		case 4:
//				cout<< "Enter String to Compare"<<endl;
//				cin>>line;
//				cout<< "Select Compare Option between user string and new string"<<endl;
//				cout<< "1: <  "<<endl;
//				cout<< "2: > "<<endl;
//				cout<< "3: =="<<endl;
//				cout<< "4: != "<<endl;
//				cout<< "5: <= "<<endl;
//				cout<< "6: >= "<<endl;
//				cin>> option;
//				s2.SetString(line);
//				OperatorTest(_str,s2,option);
//				break;
//		case 5:
//				_str.UpperCase();
//				break;
//		case 6:
//				_str.LowerCase();
//				break;
//	}

//return;
//}

//void OperatorTest( Car_t& _Lstr, Car_t& _Rstr, size_t _select)
//{
//	switch(_select)
//	{
//		case 1:
//				( _Lstr<_Rstr)?(cout <<"RIGHT SIZE BIGGER" <<endl): (cout <<"RIGHT SIZE NOT BIGGER" <<endl);
//				break;

//		case 2:
//				( _Lstr>_Rstr)?(cout <<"LEFT SIZE BIGGER" <<endl): (cout <<"LEFT SIZE NOT BIGER" <<endl);
//				break;

//		case 3:
//				( _Lstr==_Rstr)?(cout <<"EQUAL" <<endl): (cout <<"NOT EQUAL" <<endl);
//				break;

//		case 4:
//				( _Lstr !=_Rstr)?(cout <<"NOT EQUAL" <<endl): (cout <<" EQUAL" <<endl);
//				break;

//		case 5:
//				( _Lstr <=_Rstr)?(cout <<"RIGHT SIZE BIGGER OR EQUAL"  <<endl): (cout <<" LEFT SIZE BIGGER" <<endl);
//				break;
//		case 6:
//				( _Lstr >=_Rstr)?(cout <<"LEFT SIZE BIGGER OR EQUAL" <<endl): (cout <<" RIGHT SIZE BIGGER" <<endl);
//				break;
//	}
//}

//	

