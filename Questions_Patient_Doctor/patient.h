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

		void setName(char nam[512]){
			
			strcpy(name,nam);
		}

		char *getName(){
		
			char *nam=name;
			return nam;
		
		}

		void setSurName(char sur[512]){
		
			strcpy(surName,sur);
		}

		char *getSurName(){
		
			char *surNam=surName;
			return surNam;
		
		}

		void setEmail(char ema[320]){
		
			strcpy(email,ema);
		}

		char *getEmail(){
		
			char *ema=email;
			return ema;
		
		}
};