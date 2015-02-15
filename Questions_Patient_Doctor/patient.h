#include <conio.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class patient{

	private:
		
		int id_patient;
		char name[512];
		char surName[512];
		char email[320];

	public:
		
		void setId( int id){
		
			id_patient=id;
		}

		int getId(){
		
			return id_patient;
		
		}

		void setName(){
			
			cout<<"\nIngrese su Nombre: ";
			fflush(stdin);
			gets(name);
		}

		char *getName(){
		
			char *nam=name;
			return nam;
		
		}

		void setSurName(){
		
			cout<<"\nIngrese su Apellido Paterno: ";
			fflush(stdin);
			gets(surName);
		}

		char *getSurName(){
		
			char *surNam=surName;
			return surNam;
		
		}

		void setEmail(){
		
			cout<<"\nIngrese su Email: ";
			fflush(stdin);
			gets(email);
		}

		char *getEmail(){
		
			char *ema=email;
			return ema;
		
		}
};