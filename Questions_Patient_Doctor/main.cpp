#include "doctor.h"
#include "patient.h"
#include "question.h"
#include <time.h>

void main(){

	int flag,i=1;//declaracion de variables
	char op;
	question question;
	doctor doctor;
	patient patient;
	
	do{//creacion del menu
		
		do{
			
			system("cls");
	
			cout<<"\t\t============PACIENTE============";
			cout<<"\n1.- Crear Pregunta";
			cout<<"\n2.- Ver Preguntas";
			cout<<"\n0.- Salir";
			cout<<"\nEscoja una opcion: ";
			cin>>(op); 

		}while(op!='1' && op!='2' && op!='0');

		if(op=='0'){
			
			break;
		}

		switch(op){
			case '1'://peticion del ingreso de preguntas

				
				system("cls");
				cout<<"\t\t============PREGUNTA NUEVA============";
				
				patient.setName();
				patient.setSurName();
				patient.setEmail();
				patient.setId(i);
				doctor.setId_doctor(1);
				question.setIdQuestion(i);
				question.setIdPatient(patient.getId());
				question.setIdDoctor(doctor.getId_doctor());
				question.setContext();
				question.setAnswer();
				question.setDate();
				
				i++;
				getch(); break;

			case '2'://impresion de preguntas
			
				system("cls");
				cout<<"\t\t============PREGUNTAS RESPONDIDAS============";
				
				getch(); break;

		}

	}while(op);   

}


