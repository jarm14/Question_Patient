#include <conio.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class doctor{

	private:

		int id_doctor;
		char name[512];
		char surName[512];

	public:

		void setId_doctor(int id){
		
			id_doctor=id;
		}

		int getId_doctor(){
		
			return id_doctor;
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
};